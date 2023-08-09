#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>
#include <string.h>
#include <errno.h>

void error_exit(const char *message) {
    dprintf(STDERR_FILENO, "%s\n", message);
    exit(98);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        error_exit("Usage: elf_header elf_filename");
    }

    const char *elf_filename = argv[1];
    int fd = open(elf_filename, O_RDONLY);
    if (fd == -1) {
        error_exit("Error: Can't open ELF file");
    }

    Elf32_Ehdr ehdr;
    ssize_t bytes_read = read(fd, &ehdr, sizeof(Elf32_Ehdr));
    if (bytes_read != sizeof(Elf32_Ehdr)) {
        close(fd);
        error_exit("Error: Can't read ELF header");
    }

    if (memcmp(ehdr.e_ident, ELFMAG, SELFMAG) != 0) {
        close(fd);
        error_exit("Error: Not an ELF file");
    }

    printf("ELF Header:\n");
    printf("  Magic:   ");
    for (int i = 0; i < SELFMAG; i++) {
        printf("%02x%c", ehdr.e_ident[i], i == SELFMAG - 1 ? '\n' : ' ');
    }
    printf("  Class:                             ");
    switch (ehdr.e_ident[EI_CLASS]) {
        case ELFCLASS32:
            printf("ELF32\n");
            break;
        case ELFCLASS64:
            printf("ELF64\n");
            break;
        default:
            printf("Unknown\n");
    }
    printf("  Data:                              ");
    switch (ehdr.e_ident[EI_DATA]) {
        case ELFDATA2LSB:
            printf("2's complement, little endian\n");
            break;
        case ELFDATA2MSB:
            printf("2's complement, big endian\n");
            break;
        default:
            printf("Unknown\n");
    }
    printf("  Version:                           %d (current)\n", ehdr.e_version);
    printf("  OS/ABI:                            ");
    switch (ehdr.e_ident[EI_OSABI]) {
        case ELFOSABI_SYSV:
            printf("UNIX - System V\n");
            break;
        case ELFOSABI_NETBSD:
            printf("UNIX - NetBSD\n");
            break;
        // Add more cases for other OS/ABI values
        default:
            printf("<unknown: %d>\n", ehdr.e_ident[EI_OSABI]);
    }
    printf("  ABI Version:                       %d\n", ehdr.e_ident[EI_ABIVERSION]);
    printf("  Type:                              ");
    switch (ehdr.e_type) {
        case ET_EXEC:
            printf("EXEC (Executable file)\n");
            break;
        case ET_DYN:
            printf("DYN (Shared object file)\n");
            break;
        // Add more cases for other types
        default:
            printf("Unknown\n");
    }
    printf("  Entry point address:               0x%x\n", ehdr.e_entry);

    close(fd);
    return 0;
}
