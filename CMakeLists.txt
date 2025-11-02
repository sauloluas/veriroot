cmake_minimum_required(VERSION 4.0)
project(veriroot LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(
        ${CMAKE_SOURCE_DIR}/obj_dir
        ${CMAKE_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/tests
        /usr/share/verilator/include
        /usr/share/verilator/include/vltstd
)

# --------------------------------------------------------------------------
# Arquivos HDL e geração automática de código com Verilator
# --------------------------------------------------------------------------
file(GLOB VERILOG_SOURCES
        ${CMAKE_SOURCE_DIR}/include/*.svh
        ${CMAKE_SOURCE_DIR}/rtl/peripherals/*.sv
        ${CMAKE_SOURCE_DIR}/rtl/core/*.sv
        ${CMAKE_SOURCE_DIR}/rtl/core/*.v
        ${CMAKE_SOURCE_DIR}/rtl/top.sv
)
set(VERILATED_OUTPUT_DIR ${CMAKE_SOURCE_DIR}/obj_dir)

# Chama o Verilator
add_custom_command(
        OUTPUT ${VERILATED_OUTPUT_DIR}/VTop.cpp
        COMMAND verilator --cc --trace
        --top-module Top
        -Mdir ${VERILATED_OUTPUT_DIR}
        -I${CMAKE_SOURCE_DIR}/include
        ${VERILOG_SOURCES}
        DEPENDS ${VERILOG_SOURCES}
        COMMENT "🏗️  Running Verilator to regenerate C++ model..."
)

# Define o alvo que só gera o C++ (sem compilar o resto)
add_custom_target(verilate
        DEPENDS ${VERILATED_OUTPUT_DIR}/VTop.cpp
)

# --------------------------------------------------------------------------
# Compilar o simulador (C++ + Testes)
# --------------------------------------------------------------------------
file(GLOB VERILATOR_SOURCES
        CONFIGURE_DEPENDS
        ${VERILATED_OUTPUT_DIR}/*.cpp
)

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

# Garante que o código do Verilator seja gerado antes da compilação
add_dependencies(veriroot verilate)

# --------------------------------------------------------------------------
# Dependências e flags adicionais
# --------------------------------------------------------------------------
find_package(Threads REQUIRED)
target_link_libraries(veriroot PRIVATE Threads::Threads)

target_compile_options(veriroot PRIVATE -Wall -Wextra -O2)

# --------------------------------------------------------------------------
# Mensagem final para o usuário
# --------------------------------------------------------------------------
message(STATUS "✅ CMake configured successfully.")
message(STATUS "Targets available:")
message(STATUS "  - verilate : gera código C++ a partir do HDL")
message(STATUS "  - veriroot : compila e roda os testes (depende do verilate)")
