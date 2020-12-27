%include "io/asm_io.inc"
section .text
global main

mov [ebp+0],dword 0
label5:
cmp [ebp+0],dword 5
jl label0
jmp label1
label0:
mov [ebp+0],dword 0
label4:
cmp [ebp+0],dword 5
jl label2
jmp label3
label2:
mov ebx,[ebp+0]
add ebx,[ebp+0]
xor edx,edx
mov eax,dword 10
mov ecx,dword 4
div ecx
mov ecx,eax
xor edx,edx
mov eax,dword 3
mov eax,[ebp+0]
mul eax
mov eax,eax
add ebx,ecx
mov [ebp+0],ebx
xor ebx,ebx
mov ebx,dword[ebp+0]
add ebx,dword 1
mov [ebp+0],ebx
jmp label4
label3:
xor ebx,ebx
mov ebx,dword[ebp+0]
add ebx,dword 1
mov [ebp+0],ebx
jmp label5
label1:
