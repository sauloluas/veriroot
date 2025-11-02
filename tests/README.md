# Projeto Veriroot

Este projeto utiliza **CMake** e **Ninja** para gerenciar a compilação de código **SystemVerilog** via **Verilator** e
os testes em **C++**.

---

## ⚙️ Primeira configuração

Para configurar o projeto pela primeira vez (gerar o diretório de build e preparar o ambiente):

```bash
cmake -B cmake-build-debug -S . -DCMAKE_BUILD_TYPE=Debug
```

---

## 🔧 Recompilar os Verilog

Para regenerar os arquivos C++ a partir dos módulos SystemVerilog (target `verilate`):

```bash
cmake --build cmake-build-debug --target verilate
```

---

## 🧱 Compilar o projeto

Para compilar o projeto completo (incluindo os arquivos Verilog se tiverem mudado):

```bash
cmake --build cmake-build-debug
```

> O CMake recompila automaticamente os módulos Verilog se eles tiverem sido alterados.

---

## 🧪 Executar os testes

O executável gerado fica em:

```
cmake-build-debug/veriroot
```

Para executar um teste, passe o nome como argumento. Exemplo:

```bash
./cmake-build-debug/veriroot system
```

---

## 📈 Abrir o GTKWave

Após a execução do teste, um arquivo de waveform é gerado em:

```
obj_dir/waves/<nome_do_teste>.vcd
```

Abra com:

```bash
gtkwave obj_dir/waves/system.vcd
```

---

## 🚀 Execução simplificada

Há também um script auxiliar `./run` que automatiza o processo:

```bash
./run system
```

Esse script executa:

1. O *target* padrão (`cmake --build cmake-build-debug`);
2. O binário `cmake-build-debug/veriroot` passando o argumento informado (`system` no exemplo);
3. E abre automaticamente o GTKWave para o arquivo `.vcd` correspondente.

---

## 🧩 Resumo dos comandos principais

| Ação                       | Comando                                        |
|----------------------------|------------------------------------------------|
| Configurar o projeto       | `cmake -B cmake-build-debug -S . -DCMAKE_BUILD_TYPE=Debug` |
| Recompilar Verilog         | `cmake --build cmake-build-debug --target verilate`        |
| Compilar tudo              | `cmake --build cmake-build-debug`                          |
| Executar teste             | `./cmake-build-debug/veriroot system`                      |
| Abrir waveform             | `gtkwave obj_dir/waves/system.vcd`             |
| Executar tudo (automático) | `./run system`                                 |

---
