<!--
 * @Author: Ken Kaneki
 * @Date: 2021-11-10 09:26:55
 * @LastEditTime: 2021-11-22 20:37:56
 * @Description: README
-->
# Program Description
* **进入文件根目录**
* **执行配置脚本**
```sh
sh elf_config.sh
```
## 开发环境
1. **Debian GNU/Linux 10 (64bit buster)**
2. **VS Code**
3. **C Language & sh**
## 功能
* -h
```sh
./bin/ELF -h filename
```
* -S
```sh
./bin/ELF -h filename
```
* -l
```sh
./bin/ELF -h filename
```
* -d
```sh
./bin/ELF -d filename
```
## 配置及命令测试
* 进入根目录
* 运行测试脚本
```sh
sh elf_config.sh
```
## 测试脚本[elf_config.sh](./elf_config.sh)
- 测试内容
1. -h
2. -S
3. -l
4. -d
- 测试用例
1. 动态链接库[libmymath.so](./telf/libmymath.so)
2. 目标文件[main.o](./telf/main.o)
3. 可执行文件[main.so](./telf/main)

## [ELF](./bin/ELF)
* 进入根目录后
* 通过**sh elf_config.sh**直接测试命令
* 也可以通过./bin/ELF -h/S/l/d filename分析任意ELF文件
## 源码
- include
1. [head.h](./include/head.h)
```txt
分析ELF文件用到的变量、结构体和函数
```
2. [myelf.h](./include/myelf.h)
```txt
引用debian系统自带的elf.h
```
- source
1. [elf.c](./source/elf.c)
```txt
实现ELF文件分析的函数
```
2. [main.c](./source/main.c)
```txt
主函数, 根据命令执行相应的ELF文件分析
```
- bin
```txt
存放ELF指令
```
- telf
```txt
存放测试文件
```
