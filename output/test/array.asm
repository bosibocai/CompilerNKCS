%include "io/asm_io.inc"
section .text
global main

main:
enter 52,0
push ebx
push ecx
mov [ebp-4],dword 2
mov edx,[ebp-4]
mov [ebp-8],edx
mov ebx,[ebp-4]
mov edx,ebp
sub edx,8
mov [edx],ebx
mov ebx,[ebp-8]
mov [ebp-4],ebx
mov ebx,[ebp-4]
mov edx,[ebp-8]
mov [edx],ebx
mov ebx,[ebp-8]
mov ebx,[ebx]
mov [ebp-4],ebx
mov eax,[ebp-4]
call print_int_i
pop ecx
pop ebx
leave
ret
