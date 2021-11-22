/*
 * @Author: Ken Kaneki
 * @Date: 2021-11-10 10:45:35
 * @LastEditTime: 2021-11-14 13:56:24
 * @Description: main function
 */
#include "head.h"

int main(int argc, char **argv)
{
    int fd;            //处理文件
    struct stat st;    //存储相关文件状态信息，用于获取文件内容
    Elf_64_Parse epar; //存储elf文件相关信息及elf文件分析函数
    //检查参数个数
    if (argc != 3)
    {
        printf("Parameters number Error(ELF -h/S/l/d filename)\n");
        exit(1);
    }
    //打开ELF文件
    if ((fd = open(argv[2], O_RDONLY)) < 0)
    {
        perror("open");
        exit(-1);
    }
    //获取文件状态信息
    if (fstat(fd, &st) < 0)
    {
        perror("fstat");
        exit(-1);
    }
    //初始化epar结构体
    if (ELF_Init(&epar, argv, mmap(NULL, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0)))
    {
        printf("ELF init failed\n");
        exit(1);
    }
    //分析ELF文件
    elf_file_64_print(epar);
    return 0;
}
