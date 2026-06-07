cmake_minimum_required(VERSION 3.16)
project(veriroot LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# --------------------------------------------------------------------------
# Função para verilatar um módulo como top-level independente.
# Uso: verilate_module(NomeDoModulo arquivo1.sv arquivo2.sv ...)
# Gera em obj_dir/<NomeDoModulo>/ e registra o target verilate_<NomeDoModulo>.
# --------------------------------------------------------------------------
function(verilate_module MODULE_NAME)
    set(OUTPUT_DIR ${CMAKE_SOURCE_DIR}/obj_dir/${MODULE_NAME})
    set(OUTPUT_CPP ${OUTPUT_DIR}/V${MODULE_NAME}.cpp)

    add_custom_command(
            OUTPUT ${OUTPUT_CPP}
            COMMAND verilator --cc --trace
            --top-module ${MODULE_NAME}
            -Mdir ${OUTPUT_DIR}
            -I${CMAKE_SOURCE_DIR}/include
            ${ARGN}
            DEPENDS ${ARGN}
            COMMENT "Running Verilator for ${MODULE_NAME}..."
    )

    add_custom_target(verilate_${MODULE_NAME} DEPENDS ${OUTPUT_CPP})

    include_directories(${OUTPUT_DIR})

    set_property(GLOBAL APPEND PROPERTY VERILATED_MODULE_DIRS ${OUTPUT_DIR})
    set_property(GLOBAL APPEND PROPERTY VERILATE_TARGETS verilate_${MODULE_NAME})
endfunction()

# --------------------------------------------------------------------------
# Includes base
# --------------------------------------------------------------------------
include_directories(
        ${CMAKE_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/tests
        ${CMAKE_SOURCE_DIR}/tests/unit_tests
        /usr/share/verilator/include
        /usr/share/verilator/include/vltstd
)

# --------------------------------------------------------------------------
# Módulos verilados
# --------------------------------------------------------------------------
file(GLOB ALL_RTL_SOURCES
        CONFIGURE_DEPENDS
        ${CMAKE_SOURCE_DIR}/include/*.svh
        ${CMAKE_SOURCE_DIR}/rtl/top.sv
)

verilate_module(Top ${ALL_RTL_SOURCES})

# --------------------------------------------------------------------------
# Meta-target que verilata todos os módulos de uma vez
# --------------------------------------------------------------------------
get_property(ALL_VERILATE_TARGETS GLOBAL PROPERTY VERILATE_TARGETS)
add_custom_target(verilate DEPENDS ${ALL_VERILATE_TARGETS})

# --------------------------------------------------------------------------
# Compilar o simulador (C++ + Testes)
# --------------------------------------------------------------------------
get_property(ALL_VERILATED_DIRS GLOBAL PROPERTY VERILATED_MODULE_DIRS)
set(VERILATOR_SOURCES "")
foreach(DIR ${ALL_VERILATED_DIRS})
    file(GLOB DIR_SOURCES CONFIGURE_DEPENDS ${DIR}/*.cpp)
    list(APPEND VERILATOR_SOURCES ${DIR_SOURCES})
endforeach()

file(GLOB TEST_SOURCES
        CONFIGURE_DEPENDS
        ${CMAKE_SOURCE_DIR}/tests/*.cpp
)

set(VERILATOR_RUNTIME
        /usr/share/verilator/include/verilated.cpp
        /usr/share/verilator/include/verilated_vcd_c.cpp
        /usr/share/verilator/include/verilated_threads.cpp
)

add_executable(veriroot
        ${VERILATOR_SOURCES}
        ${VERILATOR_RUNTIME}
        ${TEST_SOURCES}
)

add_dependencies(veriroot verilate)

# --------------------------------------------------------------------------
# Dependências e flags adicionais
# --------------------------------------------------------------------------
find_package(Threads REQUIRED)
target_link_libraries(veriroot PRIVATE Threads::Threads)

target_include_directories(veriroot SYSTEM PRIVATE /usr/share/verilator/include)

set_source_files_properties(
        ${VERILATOR_SOURCES}
        ${VERILATOR_RUNTIME}
        PROPERTIES COMPILE_FLAGS "-w"
)

target_compile_options(veriroot PRIVATE
        -Wall -Wextra
        $<$<CONFIG:Debug>:-O0 -g>
        $<$<CONFIG:Release>:-O2>
)

# --------------------------------------------------------------------------
# Mensagem final para o usuário
# --------------------------------------------------------------------------
message(STATUS "CMake configured successfully.")
message(STATUS "Targets available:")
message(STATUS "  verilate         — verilata todos os módulos")
message(STATUS "  verilate_Top     — verilata apenas o Top")
message(STATUS "  veriroot         — compila e roda os testes")
