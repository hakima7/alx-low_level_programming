#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void check_elf(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_abi(unsigned char *e_ident);
void print_type(unsigned int e_type, unsigned char *e_ident);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_elf(int elf);

/**
 * check_elf - checks if a file is an ELF file
 * @e_ident: A pointer to an array containing the ELF magic numbers
 *
 * Description: if the file is not an ELF file - exit code 98
 */
void check_elf(unsigned char *e_ident)
{
	int index;

	for (index = 0; index < 4; index++)
	{
		if (e_ident[index] != 127 &&
		    e_ident[index] != 'E' &&
		    e_ident[index] != 'L' &&
		    e_ident[index] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * print_magic - prints the magic numbers of an ELF magic numbers
 * @e_ident: A pointer to an array containing the ELF magic numbers
 *
 * Description: Magic numbers are separated by spaces
 */
void print_magic(unsigned char *e_ident)
{
	int index;

	printf(" Magic: ");

	for (index = 0; index < EI_NIDENT; index++)
	{
		printf("%02x", e_ident[index]);

		if (index++ == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * print_class - prints the class of an ELF header
 * @e_ident: A pointer to an array containing the ELF class
 */
void print_class(unsigned char *e_ident)
{
	printf(" class: ");

	switch (e_ident[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * print_data - prints the data of an ELF header
 * @e_ident: A pointer to an array containing the ELF class
 */
void print_data(unsigned char *e_ident)
{
	printf(" data: ");

	switch (e_ident[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case  ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * print_version - prints the version of an ELF header
 * @e_ident: A pointer to an array containing the ELF version
 */
void print_version(unsigned char *e_ident)
{
	printf("version: %d",
			e_ident[EI_VERSION]);

	switch (e_ident[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}

/**
 * print_osabi - prints the OS\ABI of an ELF header
 * @e_ident: A pointer to an array containing the ELF version
 */
void print_osabi(unsigned char *e_ident)
{
	printf(" OS\\ABI: ");

	switch (e_ident[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX 6 System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - SOlaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown:%x>\n", e_ident[EI_OSABI]);
	}
}

/**
 * print_abi - prints the ABI versio of an ELF header
 * @e_ident: A pointer to an array containing the ELF ABI version
 *
 * Description:
 * This function prints the ABI version of an ELF header.
 *
 * Parameters:
 * @e_ident: A pointer to an array containing the ELF ABI version.
 * It is used to determine the ABI version of the ELF header.
 */
void print_abi(unsigned char *e_ident)
{
	printf(" ABI version: %d\n",
			e_ident[EI_ABIVERSION]);
}

/**
 * print_type - print the type of an elef header
 * @e_type: the ELF type
 * @e_type: A pointer to an array containing the ELF class
 * @e_ident: A pointer to an array containing the ELF ABI version
 *
 * Description:
 * This function prints the type of an ELF header based on the provided
 * ELF type value and the class of the ELF header.
 *
 * Parameters:
 * @e_type: The ELF type value. It determines the type of the ELF file.
 * @e_ident: A pointer to an array containing the ELF class information.
 *           It is used to determine the class of the ELF header.
 */
void print_type(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;
	printf(" type: ");

	switch (e_type)
	{
	case ET_NONE:
		printf("No file type\n");
		break;
	case ET_REL:
		printf("Relocatable file\n");
		break;
	case ET_EXEC:
		printf("Executable file\n");
		break;
	case ET_DYN:
		printf("Shared object file\n");
		break;
	case ET_CORE:
		printf("Core file\n");
		break;
	default:
		printf("< unknown: %x>\n", e_type);
		break;
	}
}

/**
 * print_entry - prints the entry point of an ELF header
 * @e_entry: the address of the ELF entry point
 * @e_ident: A pointer to an array containing the ELF class
 *
 * Description:
 * This function prints the entry point address of an ELF header based
 * on the provided entry point value and the class of the ELF header.
 *
 * Parameters:
 * @e_entry: The entry point address. It determines the starting point
 *           of execution for the ELF file.
 * @e_ident: A pointer to an array containing the ELF class information.
 *           It is used to determine the class of the ELF header.
 */
void print_entry(unsigned long int e_entry, unsigned char *e_ident)
{
	printf(" Entry point address: ");

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) &  0xFF00FF00) |
			((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}
	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);

	else
		printf("%#lx\n", e_entry);
}

/**
 * close_elf - closes an ELF file
 * @elf: the file descriptor of the elf file
 *
 * Description:
 * This function closes an open ELF file based on the provided file
 * descriptor. If the file cannot be closed, the function exits with
 * exit code 98.
 *
 * Parameters:
 * @elf: The file descriptor of the ELF file. It represents the opened file.
 */
void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
				"Error: can't close fd %d\n", elf);
		exit(98);
	}
}

/**
 * main - Displays the information contained in the
 * ELF header at the start of an ELF file
 * @argc: the number of arguments supplied to the program
 * @argv: An array of pointers to the arguments
 *
 * Return: 0 on success
 *
 * Description: This function reads an ELF file and prints information
 * about its header. If the file is not an ELF file or an error occurs,
 * the function exits with exit code 98.
 */
int main(int __attribute__((__unused__))argc, char *argv[])
{
	Elf64_Ehdr *header;
	int o, r;

	o = open(argv[1], O_RDONLY);
	if (o == -1)
	{
		dprintf(STDERR_FILENO, "Error: can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_elf(o);
		dprintf(STDERR_FILENO, "Error: can't read file %s\n", argv[1]);
		exit(98);
	}
	r = read(o, header, sizeof(Elf64_Ehdr));
	if (r == -1)
	{
		free(header);
		close_elf(o);
		dprintf(STDERR_FILENO, "Error: '%s': no such file\n", argv[1]);
		exit(98);
	}

	check_elf(header->e_ident);
	printf("ELF Header:\n");
	print_magic(header->e_ident);
	print_class(header->e_ident);
	print_data(header->e_ident);
	print_version(header->e_ident);
	print_abi(header->e_ident);
	print_type(header->e_type, header->e_ident);
	print_entry(header->e_entry, header->e_ident);

	free(header);
	close_elf(o);
	return (0);
}
