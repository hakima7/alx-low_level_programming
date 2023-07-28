global main
extern printf
    format db 'Hello, Holberton', 10, 0 ; Include ASCII 10 for new line

main:
    mov edi, format
    xor eax, eax
    call printf
    mov eax, 0
    ret
