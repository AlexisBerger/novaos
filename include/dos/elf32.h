#ifndef ELF32_H
#define ELF32_H

#include <exec/types.h>

    typedef	_u32	Elf32_Addr;
    typedef	_u16	Elf32_Half;
    typedef	_u32	Elf32_Off;
    typedef	_32	Elf32_Sword;
    typedef	_u32	Elf32_Word;

#define	EI_NIDENT	16

typedef struct {
    _u8		e_ident[EI_NIDENT];
    Elf32_Half	e_type;
    Elf32_Half	e_machine;
    Elf32_Word	e_version;
    Elf32_Addr	e_entry;
    Elf32_Off	e_phoff;
    Elf32_Off	e_shoff;
    Elf32_Word	e_flags;
    Elf32_Half	e_ehsize;
    Elf32_Half	e_phentsize;
    Elf32_Half	e_phnum;
    Elf32_Half	e_shentsize;
    Elf32_Half	e_shnum;
    Elf32_Half	e_shstrndx;
} Elf32_Ehdr;

typedef	struct {
    Elf32_Word	st_name;
    Elf32_Addr	st_value;
    Elf32_Word	st_size;
    _u8		st_info;
    _u8		st_other;
    Elf32_Half	st_shndx;
} Elf32_Sym;

typedef struct {
    Elf32_Word	sh_name;
    Elf32_Word	sh_type;
    Elf32_Word	sh_flags;
    Elf32_Addr	sh_addr;
    Elf32_Off	sh_offset;
    Elf32_Word	sh_size;
    Elf32_Word	sh_link;
    Elf32_Word	sh_info;
    Elf32_Word	sh_addralign;
    Elf32_Word	sh_entsize;
} Elf32_Shdr;

typedef struct {
    Elf32_Word	p_type;
    Elf32_Off	p_offset;
    Elf32_Addr	p_vaddr;
    Elf32_Addr	p_paddr;
    Elf32_Word	p_filesz;
    Elf32_Word	p_memsz;
    Elf32_Word	p_flags;
    Elf32_Word	p_align;
} Elf32_Phdr;

#define	SHF_WRITE	0x01
#define	SHF_ALLOC	0x02
#define	SHF_EXECINSTR	0x04
#define SHF_MASKPROC	0xf0000000    

#define	SHT_LOPROC	0x70000000
#define	SHT_HIPROC	0x7fffffff
#define	SHT_LOUSER	0x80000000
#define	SHT_HIUSER	0xffffffff

#endif

    