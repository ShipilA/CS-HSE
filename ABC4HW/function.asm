extern BIRD
extern BEAST
extern FISH

global Function
Function:
section .text
push rbp
mov rbp, rsp
    mov ebx, [rdi]
    mov eax, 0
    mov ecx, 255
    mov edx, 0
    L1:
    add eax, [rdi + 8 + edx]
    add edx, 8
    loop L1

    div ebx
    cvtsi2sd xmm0, eax

leave
ret