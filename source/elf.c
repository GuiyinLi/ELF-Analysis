/*
 * @Author: Ken Kaneki
 * @Date: 2021-11-10 11:40:07
 * @LastEditTime: 2021-11-14 15:20:13
 * @Description: Parse ELF file
 */
#include "head.h"

const char machine[MACHINE_LEN][60] = {
    "No machine",
    "AT&T WE 32100",
    "SUN SPARC",
    "Intel 80386",
    "Motorola m68k family",
    "Motorola m88k family",
    "Intel MCU",
    "Intel 80860",
    "MIPS R3000 big-endian",
    "IBM System/370",
    "MIPS R3000 little-endian",
    "",
    "",
    "",
    "",
    "HPPA",
    "",
    "Fujitsu VPP500",
    "Sun's v8plus",
    "Intel 80960",
    "PowerPC",
    "PowerPC 64-bit",
    "IBM S390",
    "IBM SPU/SPC",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "NEC V800 series",
    "Fujitsu FR20",
    "TRW RH-32",
    "Motorola RCE",
    "ARM",
    "Digital Alpha",
    "Hitachi SH",
    "SPARC v9 64-bit",
    "Siemens Tricore",
    "Argonaut RISC Core",
    "Hitachi H8/300",
    "Hitachi H8/300H",
    "Hitachi H8S",
    "Hitachi H8/500",
    "Intel Merced",
    "Stanford MIPS-X",
    "Motorola Coldfire",
    "Motorola M68HC12",
    "Fujitsu MMA Multimedia Accelerator",
    "Siemens PCP",
    "Sony nCPU embeeded RISC",
    "Denso NDR1 microprocessor",
    "Motorola Start*Core processor",
    "Toyota ME16 processor",
    "STMicroelectronic ST100 processor",
    "Advanced Logic Corp. Tinyj emb.fam",
    "AMD x86-64 architecture",
    "Sony DSP Processor",
    "Digital PDP-10",
    "Digital PDP-11",
    "Siemens FX66 microcontroller",
    "STMicroelectronics ST9+ 8/16 mc",
    "STmicroelectronics ST7 8 bit mc",
    "Motorola MC68HC16 microcontroller",
    "Motorola MC68HC11 microcontroller",
    "Motorola MC68HC08 microcontroller",
    "Motorola MC68HC05 microcontroller",
    "Silicon Graphics SVx",
    "STMicroelectronics ST19 8 bit mc",
    "Digital VAX",
    "Axis Communications 32-bit emb.proc",
    "Infineon Technologies 32-bit emb.proc",
    "Element 14 64-bit DSP Processor",
    "LSI Logic 16-bit DSP Processor",
    "Donald Knuth's educational 64-bit",
    "Harvard University machine-independent object files",
    "SiTera Prism",
    "Atmel AVR 8-bit microcontroller",
    "Fujitsu FR30",
    "Mitsubishi D10V",
    "Mitsubishi D30V",
    "NEC v850",
    "Mitsubishi M32R",
    "Matsushita MN10300",
    "Matsushita MN10200",
    "picoJava",
    "OpenRISC 32-bit embedded processor",
    "ARC International ARCompact",
    "Tensilica Xtensa Architecture",
    "Alphamosaic VideoCore",
    "Thompson Multimedia General Purpose Proc",
    "National Semi. 32000",
    "Tenor Network TPC",
    "Trebia SNP 1000",
    "STMicroelectronics ST200",
    "Ubicom IP2xxx",
    "MAX processor",
    "National Semi. CompactRISC",
    "Fujitsu F2MC16",
    "Texas Instruments msp430",
    "Analog Devices Blackfin DSP",
    "Seiko Epson S1C33 family",
    "Sharp embedded microprocessor",
    "Arca RISC",
    "PKU-Unity & MPRC Peking Uni. mc series",
    "eXcess configurable cpu",
    "Icera Semi. Deep Execution Processor",
    "Altera Nios II",
    "National Semi. CompactRISC CRX",
    "Motorola XGATE",
    "Infineon C16x/XC16x",
    "Renesas M16C",
    "Microchip Technology dsPIC30F",
    "Freescale Communication Engine RISC",
    "Renesas M32C",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "Altium TSK3000",
    "Freescale RS08",
    "Analog Devices SHARC family",
    " Cyan Technology eCOG2",
    "Sunplus S+core7 RISC",
    "New Japan Radio (NJR) 24-bit DSP",
    "Broadcom VideoCore III",
    "RISC for Lattice FPGA",
    "Seiko Epson C17",
    "Texas Instruments TMS320C6000 DSP",
    "Texas Instruments TMS320C2000 DSP",
    "Texas Instruments TMS320C55x DSP",
    "Texas Instruments App. Specific RISC",
    "Texas Instruments Prog. Realtime Unit",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "STMicroelectronics 64bit VLIW DSP",
    "Cypress M8C",
    "Renesas R32C",
    "NXP Semi. TriMedia",
    "QUALCOMM DSP6",
    "Intel 8051 and variants",
    "STMicroelectronics STxP7x",
    "Andes Tech. compact code emb. RISC",
    "Cyan Technology eCOG1X",
    "Dallas Semi. MAXQ30 mc",
    "New Japan Radio (NJR) 16-bit DSP",
    "M2000 Reconfigurable RISC",
    "Cray NV2 vector architecture",
    "Renesas RX",
    "Imagination Tech. META",
    "MCST Elbrus",
    "Cyan Technology eCOG16",
    "National Semi. CompactRISC CR16",
    "Freescale Extended Time Processing Unit",
    "Infineon Tech. SLE9X",
    "Intel L10M",
    "Intel K10M",
    "",
    "ARM AARCH64",
    "",
    "Amtel 32-bit microprocessor",
    "STMicroelectronics STM8",
    "Tileta TILE64",
    "Tilera TILEPro",
    "Xilinx MicroBlaze",
    "NVIDIA CUDA",
    "Tilera TILE-Gx",
    "CloudShield",
    "KIPO-KAIST Core-A 1st gen",
    "KIPO-KAIST Core-A 2nd gen",
    "Synopsys ARCompact V2",
    "Open8 RISC",
    "Renesas RL78",
    "Broadcom VideoCore V",
    "Renesas 78KOR",
    "Freescale 56800EX DSC",
    "Beyond BA1",
    "Beyond BA2",
    "XMOS xCORE",
    "Microchip 8-bit PIC(r)",
    "",
    "",
    "",
    "",
    "",
    "KM211 KM32",
    "KM211 KMX32",
    "KM211 KMX16",
    "KM211 KMX8",
    "KM211 KVARC",
    "Paneve CDP",
    "Cognitive Smart Memory Processor",
    "Bluechip CoolEngine",
    "Nanoradio Optimized RISC",
    "CSR Kalimba",
    "Zilog Z80",
    "Controls and Data Services VISIUMcore",
    "FTDI Chip FT32",
    "Moxie processor",
    "AMD GPU",
};

const char s_flags[S_FLAGS_LEN] = {'W', 'A', 'X', ' ', 'M', 'S', 'I', 'L', 'O', 'G', 'T', 'C', 'o', 'p', 'E', 'x'};

const char p_flags[P_FLAGS_LEN][4] = {"", "E", "W", "W E", "R", "R E", "RW", "RWE"};

const char d_flags[D_FLAGS_LEN][17] = {
    "(NULL)",
    "(NEEDED)",
    "(PLTRELSZ)",
    "(PLTGOT)",
    "(HASH)",
    "(STRTAB)",
    "(SYMTAB)",
    "(RELA)",
    "(RELASZ)",
    "(RELAENT)",
    "(STRSZ)",
    "(SYMENT)",
    "(INIT)",
    "(FINI)",
    "(SONAME)",
    "(RPATH)",
    "(SYMBOLIC)",
    "(REL)",
    "(RELSZ)",
    "(RELENT)",
    "(PLTREL)",
    "(DEBUG)",
    "(TEXTREL)",
    "(JMPREL)",
    "(BIND_NOW)",
    "(INIT_ARRAY)",
    "(FINI_ARRAY)",
    "(INIT_ARRAYSZ)",
    "(FINI_ARRAYSZ)",
    "(RUNPATH)",
    "(FLAGS)",
    "(ENCODING)",
    "(PREINIT_ARRAY)",
    "(PREINIT_ARRAYSZ)",
    "(SYMTAB_SHNDX)",
    "(NUM)"};

const char *get_ehdr_class(unsigned char id)
{
    switch (id)
    {
    case ELFCLASS64:
        return "ELF64";
    case ELFCLASS32:
        return "ELF32";
    case ELFCLASSNONE:
        return "Invalid class";
    default:
        return "Unknown class";
    }
}

const char *get_ehdr_data(unsigned char id)
{
    switch (id)
    {
    case ELFDATA2LSB:
        return "2's complement, little endian";
    case ELFDATA2MSB:
        return "2's complement, big endian";
    case ELFDATANONE:
        return "Invalid class";
    default:
        return "Unknown Data";
    }
}

const char *get_ehdr_osabi(unsigned char id)
{
    switch (id)
    {
    case ELFOSABI_NONE:
        return "UNIX - System V";
    case ELFOSABI_HPUX:
        return "HP-UX";
    case ELFOSABI_NETBSD:
        return "NetBSD";
    case ELFOSABI_GNU:
        return "Object uses GNU ELF extensions";
    case ELFOSABI_SOLARIS:
        return "Sun Solaris";
    case ELFOSABI_AIX:
        return "IBM AIX";
    case ELFOSABI_IRIX:
        return "SGI Irix";
    case ELFOSABI_FREEBSD:
        return "FreeBSD";
    case ELFOSABI_TRU64:
        return "Compaq TRU64 UNIX";
    case ELFOSABI_MODESTO:
        return "Novell Modesto";
    case ELFOSABI_OPENBSD:
        return "OpenBSD";
    case ELFOSABI_ARM_AEABI:
        return "ARM EABI";
    case ELFOSABI_ARM:
        return "ARM";
    case ELFOSABI_STANDALONE:
        return "Standalone (embedded) application";
    default:
        return "Unknown OS/ABI";
    }
}

const char *get_ehdr_type(Elf64_Half type)
{
    switch (type)
    {
    case ET_DYN:
        return "DYN (Shared Object File)";
    case ET_EXEC:
        return "EXEC (Executable File)";
    case ET_REL:
        return "REF (Relocatable File)";
    case ET_NONE:
        return "No file type";
    case ET_CORE:
        return "(CORE)";
    case ET_NUM:
        return "Number of defined types";
    case ET_LOOS:
        return "OS-specific range start";
    case ET_HIOS:
        return "OS-specific range end";
    case ET_LOPROC:
        return "Processor-specific range start";
    case ET_HIPROC:
        return "Processor-specific range end";
    default:
        return "Unknown file type";
    }
}

const char *get_shdr_type(Elf64_Word type)
{
    switch (type) //Section type
    {
    case SHT_NULL:
        return "NULL";
    case SHT_PROGBITS:
        return "PROGBITS";
    case SHT_SYMTAB:
        return "SYMTAB";
    case SHT_STRTAB:
        return "STRTAB";
    case SHT_RELA:
        return "RELA";
    case SHT_HASH:
        return "HASH";
    case SHT_DYNAMIC:
        return "DYNAMIC";
    case SHT_NOTE:
        return "NOTE";
    case SHT_NOBITS:
        return "NOBITS";
    case SHT_REL:
        return "REL";
    case SHT_SHLIB:
        return "SHLIB";
    case SHT_DYNSYM:
        return "DYNSYM";
    case SHT_INIT_ARRAY:
        return "INIT_ARRAY";
    case SHT_FINI_ARRAY:
        return "FINI_ARRAY ";
    case SHT_LOPROC:
        return "LOPROC ";
    case SHT_HIPROC:
        return "HIPROC ";
    case SHT_LOUSER:
        return "SHT_LOUSER ";
    case SHT_HIUSER:
        return "HIUSER ";
    case SHT_GNU_HASH:
        return "GNU_HASH ";
    case SHT_GNU_versym:
        return "GNU_versym ";
    case SHT_GNU_verneed:
        return "GNU_verneed ";
    default:
        return "Unknown Type";
    }
}

const char *get_phdr_type(Elf64_Word type)
{
    switch (type)
    {
    case PT_NULL:
        return "NULL";
    case PT_LOAD:
        return "LOAD";
    case PT_DYNAMIC:
        return "DYNAMIC";
    case PT_INTERP:
        return "INTERP";
    case PT_NOTE:
        return "NOTE";
    case PT_SHLIB:
        return "SHLIB";
    case PT_PHDR:
        return "PHDR";
    case 0x6474e550:
        return "GNU_EH_FRAME";
    case 0x6474e551:
        return "GNU_STACK";
    case 0x6474e552:
        return "GNU_RELRO";
    case 0x70000000:
        return "PT_LOPROC";
    case 0x7fffffff:
        return "PT_HIPROC";
    default:
        return "Unkown Type";
    }
}

const char *get_dyn_type(Elf64_Dyn dyn, Filedata filedata)
{
    static char str[50];
    char *str_buff;
    switch (dyn.d_tag)
    {
    case DT_NULL:
        sprintf(str, "%-16s 0x%x", "(NULL)", dyn.d_un.d_val);
        return str;
    case DT_NEEDED:
        sprintf(str, "%-16s Shared library: [%s]", "(NEEDED)", &filedata.dynstrtab[dyn.d_un.d_val]);
        return str;
    case DT_PLTRELSZ:
        sprintf(str, "%-16s %u (bytes)", "(PLTRELSZ)", dyn.d_un.d_val);
        return str;
    case DT_PLTGOT:
        sprintf(str, "%-16s 0x%x", "(PLTGOT)", dyn.d_un.d_val);
        return str;
    case DT_HASH:
        sprintf(str, "%-16s 0x%x", "(HASH)", dyn.d_un.d_ptr);
        return str;
    case DT_STRTAB:
        sprintf(str, "%-16s 0x%x", "(STRTAB)", dyn.d_un.d_ptr);
        return str;
    case DT_SYMTAB:
        sprintf(str, "%-16s 0x%x", "(SYMTAB)", dyn.d_un.d_ptr);
        return str;
    case DT_RELA:
        sprintf(str, "%-16s 0x%x", "(RELA)", dyn.d_un.d_ptr);
        return str;
    case DT_RELASZ:
        sprintf(str, "%-16s %u (bytes)", "(RELASZ)", dyn.d_un.d_val);
        return str;
    case DT_RELAENT:
        sprintf(str, "%-16s %u (bytes)", "(RELAENT)", dyn.d_un.d_val);
        return str;
    case DT_STRSZ:
        sprintf(str, "%-16s %u (bytes)", "(STRSZ)", dyn.d_un.d_val);
        return str;
    case DT_SYMENT:
        sprintf(str, "%-16s %u (bytes)", "(SYMENT)", dyn.d_un.d_val);
        return str;
    case DT_INIT:
        sprintf(str, "%-16s 0x%x", "(INIT)", dyn.d_un.d_ptr);
        return str;
    case DT_FINI:
        sprintf(str, "%-16s 0x%x", "(FINI)", dyn.d_un.d_ptr);
        return str;
    case DT_SONAME:
        sprintf(str, "%-16s Shared library: [%s]", "(SONAME)", &filedata.dynstrtab[dyn.d_un.d_val]);
        return str;
    case DT_RPATH:
        sprintf(str, "%-16s 0x%x", "(RPATH)", dyn.d_un.d_val);
        return str;
    case DT_SYMBOLIC:
        sprintf(str, "%-16s 0x%x", "(SYMBOLIC)", dyn.d_un.d_val);
        return str;
    case DT_REL:
        sprintf(str, "%-16s 0x%x", "(REL)", dyn.d_un.d_ptr);
        return str;
    case DT_RELSZ:
        sprintf(str, "%-16s %u (bytes)", "(RELSZ)", dyn.d_un.d_val);
        return str;
    case DT_RELENT:
        sprintf(str, "%-16s %u (bytes)", "(RELENT)", dyn.d_un.d_val);
        return str;
    case DT_PLTREL:
        sprintf(str, "%-16s %s", "(PLTREL)", "RELA");
        return str;
    case DT_DEBUG:
        sprintf(str, "%-16s 0x%x", "(DEBUG)", dyn.d_un.d_val);
        return str;
    case DT_TEXTREL:
        sprintf(str, "%-16s 0x%x", "(TEXTREL)", dyn.d_un.d_val);
        return str;
    case DT_JMPREL:
        sprintf(str, "%-16s 0x%x", "(JMPREL)", dyn.d_un.d_ptr);
        return str;
    case DT_BIND_NOW:
        sprintf(str, "%-16s 0x%x", "(BIND_NOW)", dyn.d_un.d_val);
        return str;
    case DT_INIT_ARRAY:
        sprintf(str, "%-16s 0x%x", "(INIT_ARRAY)", dyn.d_un.d_val);
        return str;
    case DT_FINI_ARRAY:
        sprintf(str, "%-16s 0x%x", "(FINI_ARRAY)", dyn.d_un.d_val);
        return str;
    case DT_INIT_ARRAYSZ:
        sprintf(str, "%-16s %u (bytes)", "(INIT_ARRAYSZ)", dyn.d_un.d_val);
        return str;
    case DT_FINI_ARRAYSZ:
        sprintf(str, "%-16s %u (bytes)", "(FINI_ARRAYSZ)", dyn.d_un.d_val);
        return str;
    case DT_RUNPATH:
        sprintf(str, "%-16s 0x%x", "(RUNPATH)", dyn.d_un.d_val);
        return str;
    case DT_FLAGS:
        switch (dyn.d_un.d_val)
        {
        case DF_ORIGIN:
            str_buff = (char *)("Flag: ORIGIN");
            break;
        case DF_SYMBOLIC:
            str_buff = (char *)("Flag: SYMBOLIC");
            break;
        case DF_TEXTREL:
            str_buff = (char *)("Flag: TEXTREL");
            break;
        case DF_BIND_NOW:
            str_buff = (char *)("Flag: BIND_NOW");
            break;
        case DF_STATIC_TLS:
            str_buff = (char *)("Flag: STATIC_TLS");
            break;
        }
        sprintf(str, "%-16s %s", "(FLAGS)", str_buff);
        return str;
    case DT_ENCODING:
        sprintf(str, "%-16s 0x%x", "(ENCODING)", dyn.d_un.d_val);
        return str;
    case DT_PREINIT_ARRAYSZ:
        sprintf(str, "%-16s %u (bytes)", "(PREINIT_ARRAYSZ)", dyn.d_un.d_val);
        return str;
    case DT_SYMTAB_SHNDX:
        sprintf(str, "%-16s 0x%x", "(SYMTAB_SHNDX)", dyn.d_un.d_ptr);
        return str;
    case DT_NUM:
        sprintf(str, "%-16s %u", "(NUM)", dyn.d_un.d_val);
        return str;
    case DT_LOOS:
        sprintf(str, "%-16s 0x%x", "(LOOS)", dyn.d_un.d_val);
        return str;
    case DT_HIOS:
        sprintf(str, "%-16s 0x%x", "(HIOS)", dyn.d_un.d_val);
        return str;
    case DT_LOPROC:
        sprintf(str, "%-16s 0x%x", "(LOPROC)", dyn.d_un.d_val);
        return str;
    case DT_HIPROC:
        sprintf(str, "%-16s 0x%x", "(HIPROC)", dyn.d_un.d_val);
        return str;
    case DT_PROCNUM:
        sprintf(str, "%-16s %u", "(PROCNUM)", dyn.d_un.d_val);
        return str;

    case DT_VALRNGLO:
        sprintf(str, "%-16s 0x%x", "(VALRNGLO)", dyn.d_un.d_val);
        return str;
    case DT_GNU_PRELINKED:
        sprintf(str, "%-16s 0x%x", "(GNU_PRELINKED)", dyn.d_un.d_val);
        return str;
    case DT_GNU_CONFLICTSZ:
        sprintf(str, "%-16s %u (bytes)", "(GNU_CONFLICTSZ)", dyn.d_un.d_val);
        return str;
    case DT_GNU_LIBLISTSZ:
        sprintf(str, "%-16s %u (bytes)", "(GNU_LIBLISTSZ)", dyn.d_un.d_val);
        return str;
    case DT_CHECKSUM:
        sprintf(str, "%-16s 0x%x", "(CHECKSUM)", dyn.d_un.d_val);
        return str;
    case DT_PLTPADSZ:
        sprintf(str, "%-16s %u (bytes)", "(PLTPADSZ)", dyn.d_un.d_val);
        return str;
    case DT_MOVEENT:
        sprintf(str, "%-16s 0x%x", "(MOVEENT)", dyn.d_un.d_val);
        return str;
    case DT_MOVESZ:
        sprintf(str, "%-16s 0x%x", "(MOVESZ)", dyn.d_un.d_val);
        return str;
    case DT_FEATURE_1:
        switch (dyn.d_un.d_val)
        {
        case DTF_1_PARINIT:
            str_buff = (char *)("Flag: PARINIT");
            break;
        case DTF_1_CONFEXP:
            str_buff = (char *)("Flag: CONFEXP");
            break;
        }
        sprintf(str, "%-16s %s", "(FEATURE_1)", str_buff);
        return str;
    case DT_POSFLAG_1:
        switch (dyn.d_un.d_val)
        {
        case DF_P1_LAZYLOAD:
            str_buff = (char *)("Flag: LAZYLOAD");
            break;
        case DF_P1_GROUPPERM:
            str_buff = (char *)("Flag: GROUPPERM");
            break;
        }
        sprintf(str, "%-16s %s", "(POSFLAG_1)", str_buff);
        return str;

    case DT_SYMINSZ:
        sprintf(str, "%-16s %u (bytes)", "(SYMINSZ)", dyn.d_un.d_val);
        return str;
    case DT_SYMINENT:
        sprintf(str, "%-16s 0x%x", "(SYMINENT)", dyn.d_un.d_val);
        return str;

    case DT_ADDRRNGLO:
        sprintf(str, "%-16s 0x%x", "(ADDRRNGLO)", dyn.d_un.d_val);
        return str;
    case DT_GNU_HASH:
        sprintf(str, "%-16s 0x%x", "(GNU_HASH)", dyn.d_un.d_val);
        return str;
    case DT_TLSDESC_PLT:
        sprintf(str, "%-16s 0x%x", "(TLSDESC_PLT)", dyn.d_un.d_val);
        return str;
        return "(TLSDESC_PLT)";
    case DT_TLSDESC_GOT:
        sprintf(str, "%-16s 0x%x", "(TLSDESC_GOT)", dyn.d_un.d_val);
        return str;
    case DT_GNU_CONFLICT:
        sprintf(str, "%-16s 0x%x", "(GNU_CONFLICT)", dyn.d_un.d_val);
        return str;
    case DT_GNU_LIBLIST:
        sprintf(str, "%-16s 0x%x", "(GNU_LIBLIST)", dyn.d_un.d_val);
        return str;
    case DT_CONFIG:
        sprintf(str, "%-16s 0x%x", "(CONFIG)", dyn.d_un.d_val);
        return str;
    case DT_DEPAUDIT:
        sprintf(str, "%-16s 0x%x", "(DEPAUDIT)", dyn.d_un.d_val);
        return str;
    case DT_AUDIT:
        sprintf(str, "%-16s 0x%x", "(AUDIT)", dyn.d_un.d_val);
        return str;
    case DT_PLTPAD:
        sprintf(str, "%-16s 0x%x", "(PLTPAD)", dyn.d_un.d_val);
        return str;
    case DT_MOVETAB:
        sprintf(str, "%-16s 0x%x", "(MOVETAB)", dyn.d_un.d_val);
        return str;
    case DT_SYMINFO:
        sprintf(str, "%-16s 0x%x", "(SYMINFO)", dyn.d_un.d_val);
        return str;

    case DT_VERSYM:
        sprintf(str, "%-16s 0x%x", "(VERSYM)", dyn.d_un.d_val);
        return str;
    case DT_RELACOUNT:
        sprintf(str, "%-16s %u", "(RELACOUNT)", dyn.d_un.d_val);
        return str;
    case DT_RELCOUNT:
        sprintf(str, "%-16s 0x%x", "(RELCOUNT)", dyn.d_un.d_val);
        return str;

    case DT_FLAGS_1:
        switch (dyn.d_un.d_val)
        {
        case DF_1_NOW:
            str_buff = (char *)("Flag: NOW");
            break;
        case DF_1_GLOBAL:
            str_buff = (char *)("Flag: GLOBAL");
            break;
        case DF_1_GROUP:
            str_buff = (char *)("Flag: GROUP");
            break;
        case DF_1_NODELETE:
            str_buff = (char *)("Flag: NODELETE");
            break;
        case DF_1_LOADFLTR:
            str_buff = (char *)("Flag: LOADFLTR");
            break;
        case DF_1_INITFIRST:
            str_buff = (char *)("Flag: INITFIRST");
            break;
        case DF_1_NOOPEN:
            str_buff = (char *)("Flag: NOOPEN");
            break;
        case DF_1_ORIGIN:
            str_buff = (char *)("Flag: ORIGIN");
            break;
        case DF_1_DIRECT:
            str_buff = (char *)("Flag: DIRECT");
            break;
        case DF_1_TRANS:
            str_buff = (char *)("Flag: TRANS");
            break;
        case DF_1_INTERPOSE:
            str_buff = (char *)("Flag: INTERPOSE");
            break;
        case DF_1_NODEFLIB:
            str_buff = (char *)("Flag: NODEFLIB");
            break;
        case DF_1_NODUMP:
            str_buff = (char *)("Flag: NODUMP");
            break;
        case DF_1_CONFALT:
            str_buff = (char *)("Flag: CONFALT");
            break;
        case DF_1_ENDFILTEE:
            str_buff = (char *)("Flag: ENDFILTEE");
            break;
        case DF_1_DISPRELDNE:
            str_buff = (char *)("Flag: DISPRELDNE");
            break;
        case DF_1_DISPRELPND:
            str_buff = (char *)("Flag: DISPRELPND");
            break;
        case DF_1_NODIRECT:
            str_buff = (char *)("Flag: NODIRECT");
            break;
        case DF_1_IGNMULDEF:
            str_buff = (char *)("Flag: IGNMULDEF");
            break;
        case DF_1_NOKSYMS:
            str_buff = (char *)("Flag: NOKSYMS");
            break;
        case DF_1_NOHDR:
            str_buff = (char *)("Flag: NOHDR");
            break;
        case DF_1_EDITED:
            str_buff = (char *)("Flag: EDITED");
            break;
        case DF_1_NORELOC:
            str_buff = (char *)("Flag: NORELOC");
            break;
        case DF_1_SYMINTPOSE:
            str_buff = (char *)("Flag: SYMINTPOSE");
            break;
        case DF_1_GLOBAUDIT:
            str_buff = (char *)("Flag: GLOBAUDIT");
            break;
        case DF_1_SINGLETON:
            str_buff = (char *)("Flag: SINGLETON");
            break;
        case DF_1_STUB:
            str_buff = (char *)("Flag: STUB");
            break;
        case DF_1_PIE:
            str_buff = (char *)("Flag: PIE");
            break;
        }
        sprintf(str, "%-16s %s", "(FLAGS_1)", str_buff);
        return str;
    case DT_VERDEF:
        sprintf(str, "%-16s 0x%x", "(VERDEF)", dyn.d_un.d_ptr);
        return str;
    case DT_VERDEFNUM:
        sprintf(str, "%-16s %u", "(VERDEFNUM)", dyn.d_un.d_val);
        return str;
    case DT_VERNEED:
        sprintf(str, "%-16s 0x%x", "(VERNEED)", dyn.d_un.d_ptr);
        return str;
    case DT_VERNEEDNUM:
        sprintf(str, "%-16s %u", "(VERNEEDNUM)", dyn.d_un.d_val);
        return str;

    case DT_AUXILIARY:
        sprintf(str, "%-16s 0x%x", "(AUXILIARY)", dyn.d_un.d_val);
        return str;

    default:
        return "Unkown Tag";
    }
}

/**
 * @description: Init filedata
 * @param {Filedata} filedata
 * @return {*}
 */
void Filedata_Init(Filedata *filedata)
{
    int i;
    int flag = 1;
    filedata->dynsec.dyn = NULL;
    filedata->dynsec.dyn_index = 0;
    filedata->dynsec.dyn_num = 0;

    filedata->dynstrtab = NULL;

    filedata->ehdr = (Elf64_Ehdr *)filedata->mem;
    filedata->shdr = (Elf64_Shdr *)&filedata->mem[filedata->ehdr->e_shoff];
    filedata->phdr = (Elf64_Phdr *)&filedata->mem[filedata->ehdr->e_phoff];
    filedata->shstrtab = filedata->ehdr->e_shnum > 0 ? &filedata->mem[filedata->shdr[filedata->ehdr->e_shstrndx].sh_offset] : NULL;
    for (i = 0; i < filedata->ehdr->e_shnum; i++)
    {
        if (flag && !strcmp(&filedata->shstrtab[filedata->shdr[i].sh_name], ".dynstr"))
        {
            filedata->dynstrtab = &filedata->mem[filedata->shdr[i].sh_offset];
            flag = 0;
            continue;
        }
        if (!flag && filedata->shdr[i].sh_type == SHT_DYNAMIC)
        {
            filedata->dynsec.dyn_index = i;
            break;
        }
    }
    if (filedata->dynsec.dyn_index)
    {
        filedata->dynsec.dyn = (Elf64_Dyn *)&filedata->mem[filedata->shdr[filedata->dynsec.dyn_index].sh_offset];
        i = 0;
        while (filedata->dynsec.dyn[i++].d_tag != 0)
            ;
        filedata->dynsec.dyn_num = i;
    }
}
/**
 * @description: Init struct elf
 * @param {Elf_64_Parse} epar
 * @return {*}
 */
int ELF_Init(Elf_64_Parse *epar, char **argv, uint8_t *mem)
{
    //命令参数
    epar->argv = argv;
    //获取指针
    epar->filedata.mem = mem;
    //ELF魔数校验
    if (epar->filedata.mem[0] != 0x7f && strcmp(&epar->filedata.mem[1], "ELF"))
    {
        fprintf(stderr, "%s is not an ELF file\n", epar->argv[2]);
        return 1;
    }
    //判断elf文件为32位还是64位
    epar->ostype = epar->filedata.mem[4] == 1 ? 32 : 64;
    //补充filedata
    epar->filedata_init = Filedata_Init;
    epar->filedata_init(&epar->filedata);
    return 0;
}
/**
 * @description: Analysis ELF header(64)
 * @param {uint8_t} *mem
 * @return {*}
 */
void elf_header_64_parse(Filedata filedata)
{
    //Print ELF_Header Info
    puts("ELF Header:");
    //ehdr->e_ident: Magic(7f 'E' 'L' F') EI_CLASS EI_DATA EI_VERSION
    printf("  Magic:   ");
    for (int i = 0; i < EI_NIDENT; ++i)
        printf("%02x ", filedata.ehdr->e_ident[i]);
    //Class: 32 or 64 bit
    printf("\n  %-35s%s\n", "Class: ", get_ehdr_class(filedata.ehdr->e_ident[EI_CLASS]));
    //Data: Encoding Format
    printf("  %-35s%s\n", "Data: ", get_ehdr_data(filedata.ehdr->e_ident[EI_DATA]));
    //Version: only the EV_CURRENT
    printf("  %-35s%d(current)\n", "Version: ", filedata.ehdr->e_ident[EI_VERSION]);
    //OS/ABI: default 00
    printf("  %-35s%s\n", "OS/ABI: ", get_ehdr_osabi(filedata.ehdr->e_ident[EI_OSABI]));
    //ABI Version: default 00
    printf("  %-35s%d\n", "ABI Version: ", filedata.ehdr->e_ident[EI_ABIVERSION]);
    //Type: ELF File Type
    printf("  %-35s%s\n", "Type:", get_ehdr_type(filedata.ehdr->e_type));
    //Machine: Architecture for which the file is oriented
    printf("  %-35s", "Machine: ");
    if (filedata.ehdr->e_machine < MACHINE_LEN)
        printf("%s\n", machine[filedata.ehdr->e_machine]);
    else
        printf("\n");
    //Version: ELF File Version
    printf("  %-35s0x%x\n", "Version: ", filedata.ehdr->e_version);
    //Entry point address & offset of program header table & offset of ection header table
    printf("  %-35s0x%x\n", "Entry point address: ", filedata.ehdr->e_entry);
    printf("  %-35s%u (bytes into file)\n", "Start of program headers: ", filedata.ehdr->e_phoff);
    printf("  %-35s%u (bytes into file)\n", "Start of section headers: ", filedata.ehdr->e_shoff);
    //Processor-specific flags
    printf("  %-35s0x%x\n", "Flags: ", filedata.ehdr->e_flags);
    //Both size and number of ELF_Header, Program_Header and Section_Header
    printf("  %-35s%u (bytes)\n", "Size of this header: ", filedata.ehdr->e_ehsize);
    printf("  %-35s%u (bytes)\n", "Size of program headers: ", filedata.ehdr->e_phentsize);
    printf("  %-35s%u\n", "Number of program headers: ", filedata.ehdr->e_phnum);
    printf("  %-35s%u (bytes)\n", "Size of section headers: ", filedata.ehdr->e_shentsize);
    printf("  %-35s%u\n", "Number of section headers: ", filedata.ehdr->e_shnum);
    //Section name string table
    printf("  %-35s%u\n", "Section header string table index: ", filedata.ehdr->e_shstrndx);
}
/**
 * @description: Analysis section header(64)
 * @param {uint8_t} *mem
 * @return {*}
 */
void section_header_64_parse(Filedata filedata)
{
    int i, j, k;                   //Loop variable
    char strflags[5];              //Save section attribute
    Elf64_Xword flags_temp = 0x00; //sh_flag buff array
    if (filedata.ehdr->e_shnum)    //Section header is not empty?
    {
        printf("There are %d section headers, starting at offset 0x%04x:\n\n", filedata.ehdr->e_shnum, filedata.ehdr->e_shoff); //num and offset of section header
        puts("Section Headers:");
        //Print meter head
        printf("  %4s %-18s %-13s %-16s %-8s %-16s %-8s %-5s %-4s %-4s %-5s\n", "[Nr]", "Name", "Type", "Address", "Offset", "Size", "EntSize", "Flags", "Link", "Info", "Align");
        //Print every section info in order
        for (i = 0; i < filedata.ehdr->e_shnum; i++)
        {
            printf("  [%2d] %-18s ", i, &filedata.shstrtab[filedata.shdr[i].sh_name]); //Serial number and Indexes of section
            printf("%-13s ", get_shdr_type(filedata.shdr[i].sh_type));                 //Section type
            printf("%016x ", filedata.shdr[i].sh_addr);                                //Virtual address of current section in execution
            printf("%08x ", filedata.shdr[i].sh_offset);                               //Offset of current section  in ELF_File
            printf("%016x ", filedata.shdr[i].sh_size);                                //Size of current section
            printf("%08x ", filedata.shdr[i].sh_entsize);                              //Entry size if section holds table
            flags_temp = filedata.shdr[i].sh_flags;                                    //Current section flags
            for (j = 0, k = 0; j < 12; j++)                                            //local the '1' of sh_flags and search corresponding attribute from s_flag[]
            {
                if (flags_temp & 0x01)
                    strflags[k++] = s_flags[j];
                flags_temp = flags_temp >> 1;
            }
            if (filedata.shdr[i].sh_flags & SHF_MASKOS)
                strflags[k++] = s_flags[12];
            if (filedata.shdr[i].sh_flags & SHF_MASKPROC)
                strflags[k++] = s_flags[13];
            if (filedata.shdr[i].sh_flags & SHF_EXCLUDE)
                strflags[k++] = s_flags[14];
            strflags[k] = '\0';
            printf("%5s ", strflags);
            printf("%4u ", filedata.shdr[i].sh_link);        //Link to another section
            printf("%4u ", filedata.shdr[i].sh_info);        //Additional section information
            printf("%5u \n", filedata.shdr[i].sh_addralign); //Section alignment
        }
        //Print Key to Flags
        printf("Key to Flags:\n");
        printf("  W(write), A(alloc), X(execute), M(merge), S(strings), I(info),\n");
        printf("  L(link order), O(extra OS processing required), G(group), T(TLS),\n");
        printf("  C(compressed), x(unknown), o(OS specific), E(exclude),p(processor specific)\n");
    }
    else
        printf("\nThere are no section headers in this file.\n");
}
/**
 * @description: Analysis program header(64)
 * @param {uint8_t} *mem
 * @return {*}
 */
void program_header_64_parse(Filedata filedata)
{
    int i;                                                       //Loop variable
    char *interp;                                                //Save INTERP info
    uint8_t formal_flag = SHF_WRITE | SHF_ALLOC | SHF_EXECINSTR; //按段分类时, 用于筛选section
    if (filedata.ehdr->e_phnum)                                  //Program header is not empty?
    {
        printf("\nElf file type is %s\n", get_ehdr_type(filedata.ehdr->e_type));
        printf("Entry point 0x%x\n", filedata.ehdr->e_entry); //Program header entey poin address
        //Number and offfset of program header
        printf("There are %d program headers, starting at offset %u:\n\n", filedata.ehdr->e_phnum, filedata.ehdr->e_phoff);
        puts("Program Headers:");
        //Print meter head
        printf("  %-13s %-18s %-18s %-18s %-18s %-18s %-5s %-5s\n", "Type", "Offset", "VirtAddr", "PhysAddr", "FileSiz", "MemSiz", "Flags", "Align");
        //Print every section info in order
        for (i = 0; i < filedata.ehdr->e_phnum; ++i)
        {
            printf("  %-13s ", get_phdr_type(filedata.phdr[i].p_type)); //Segment type
            printf("0x%016x ", filedata.phdr[i].p_offset);              //Segment file offset
            printf("0x%016x ", filedata.phdr[i].p_vaddr);               //Segment virtual address
            printf("0x%016x ", filedata.phdr[i].p_paddr);               //Segment physical address
            printf("0x%016x ", filedata.phdr[i].p_filesz);              //Segment size in file
            printf("0x%016x ", filedata.phdr[i].p_memsz);               //Segment size in memory
            if (filedata.phdr[i].p_flags < P_FLAGS_LEN)
                printf("%-5s ", p_flags[filedata.phdr[i].p_flags]); //Segment flags(search table)
            else
                printf("%-5s ", "");                    //search table failed, not print
            printf("0x%x\n", filedata.phdr[i].p_align); //Segment alignment
            //Print info of the INTERP(interp)
            filedata.phdr[i].p_type == PT_INTERP ? printf("      [Requesting program interpreter: %s]\n", interp = strdup((char *)&filedata.mem[filedata.phdr[i].p_offset])) : printf("");
        }
        //Print segment info
        printf("\n Section to Segment mapping:\n");
        printf("  %-7s %-11s\n", "Segment", "Sections...");
        for (int i = 0; i < filedata.ehdr->e_phnum; i++)
        {
            printf("   %02d     ", i);
            for (int j = 0; j < filedata.ehdr->e_shnum; j++)
            {
                Elf64_Off temp = filedata.shdr[j].sh_offset + filedata.shdr[j].sh_size;
                if ((filedata.shdr[j].sh_flags & formal_flag) && ((filedata.shdr[j].sh_offset >= filedata.phdr[i].p_offset && filedata.shdr[j].sh_offset + filedata.shdr[j].sh_size <= filedata.phdr[i].p_offset + filedata.phdr[i].p_memsz) ||
                                                                  (temp > filedata.phdr[i].p_offset && temp <= filedata.phdr[i].p_offset + filedata.phdr[i].p_memsz)))
                {
                    printf("%s ", &filedata.shstrtab[filedata.shdr[j].sh_name]);
                }
            }
            printf("\r\n");
        }
    }
    else
        printf("\nThere are no program headers in this file.\n");
}
/**
 * @description:  Analysis dynamic section
 * @param {Filedata} filedata
 * @return {*}
 */
void dynamic_section_64_parse(Filedata filedata)
{
    int i;
    if (filedata.dynsec.dyn_num)
    {
        printf("Dynamic section at offset 0x%x contains %d entries:\n", filedata.shdr[filedata.dynsec.dyn_index].sh_offset, filedata.dynsec.dyn_num);
        printf("  %-18s %-16s %s\n", "Tag", "Type", "Name/Value");
        for (i = 0; i < filedata.dynsec.dyn_num; i++)
        {
            printf("  0x%016x %s", filedata.dynsec.dyn[i].d_tag, get_dyn_type(filedata.dynsec.dyn[i], filedata));
            printf("\n");
        }
    }
    else
        printf("\nThere is no dynamic section in this file.\n");
}
/**
 * @description: Analysis ELF file(64) according the argv
 * @param {Elf_64_Parse} epar
 * @return {*}
 */
void elf_file_64_print(Elf_64_Parse epar)
{
    //Assign values according to parameters(-h -S -l)
    epar.elf_file_64_parse = strcmp(epar.argv[1], ELF_header) ? (strcmp(epar.argv[1], Section_header) ? (strcmp(epar.argv[1], Program_header) ? (strcmp(epar.argv[1], Dynamic_Section) ? NULL : dynamic_section_64_parse) : program_header_64_parse) : section_header_64_parse)
                                                              : elf_header_64_parse;
    //chect parameters
    if (epar.elf_file_64_parse != NULL)
        epar.elf_file_64_parse(epar.filedata); //Analysis ELF file
    else
        printf("argc error(-h/S/l/d)\n");
}
