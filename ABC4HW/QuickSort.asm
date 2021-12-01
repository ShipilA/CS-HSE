global QuickSort
QuickSort:
section .text
push rbp
mov rbp, rsp
sub rsp, 40
    mov DWORD PTR [rbp-12], 0
    mov eax, DWORD PTR [rbp+12]
    dec eax
    mov DWORD PTR [rbp-16], eax
    mov eax, DWORD PTR [rbp+12]
    sar eax
    lea edx, [0+eax*4]
    mov eax, DWORD PTR [rbp+8]
    add eax, edx
    mov eax, DWORD PTR [eax]
    mov DWORD PTR [rbp-20], eax
    L2:
    mov eax, DWORD PTR [rbp-12]
    lea edx, [0+eax*4]
    mov eax, DWORD PTR [rbp+8]
    add eax, edx
    mov eax, DWORD PTR [eax]
    sub rsp, 4
    push eax
    call Function
    add rsp, 8
    fstp QWORD PTR [rbp-32]
    sub rsp, 4
    push DWORD PTR [rbp-20]
    call Function
    add rsp, 8
    fld QWORD PTR NUMS
    faddp st(1), st
    fld QWORD PTR [rbp-32]
    fxch st(1)
    fucompp
    fnstsw ax
    test ah, 69
    sete al
    test al, al
    je L6
    inc DWORD PTR [ebp-12]
    jmp L2
    L6:
    mov eax, DWORD PTR [rbp-16]
    lea edx, [0+eax*4]
    mov eax, DWORD PTR [rbp+8]
    add eax, edx
    mov eax, DWORD PTR [eax]
    sub rsp, 4
    push eax
    call Function
    add rsp, 8
    fstp QWORD PTR [rbp-32]
    sub rsp, 4
    push DWORD PTR [rbp-20]
    call Function
    add rsp, 8
    fld QWORD PTR NUMS
    faddp st(1), st
    fld QWORD PTR [rbp-32]
    fxch st(1)
    fucompp
    fnstsw ax
    test ah, 69
    sete al
    test al, al
    je L8
    dec DWORD PTR [rbp-16]
    jmp L6
    L8:
    mov eax, DWORD PTR [rbp-12]
    cmp eax, DWORD PTR [rbp-16]
    jg L9
    mov eax, DWORD PTR [rbp-12]
    lea edx, [0+eax*4]
    mov eax, DWORD PTR [rbp+8]
    add eax, edx
    mov eax, DWORD PTR [eax]
    mov DWORD PTR [rbp-24], eax
    mov eax, DWORD PTR [rbp-12]
    lea edx, [0+eax*4]
    mov eax, DWORD PTR [rbp+8]
    add edx, eax
    mov eax, DWORD PTR [rbp-16]
    lea ecx, [0+eax*4]
    mov eax, DWORD PTR [rbp+8]
    add eax, ecx
    mov eax, DWORD PTR [eax]
    mov DWORD PTR [edx], eax
    mov eax, DWORD PTR [rbp-16]
    lea edx, [0+eax*4]
    mov eax, DWORD PTR [rbp+8]
    add edx, eax
    mov eax, DWORD PTR [rbp-24]
    mov DWORD PTR [edx], eax
    inc DWORD PTR [rbp-12]
    dec DWORD PTR [rbp-16]
    L9:
    mov eax, DWORD PTR [rbp-12]
    cmp eax, DWORD PTR [rbp-16]
    jg L10
    jmp L2
    L10:
    cmp DWORD PTR [rbp-16], 0
    jle L11
    sub rsp, 8
    push DWORD PTR [rbp-16]
    push DWORD PTR [rbp+8]
    call QuickSort
    add rsp, 16
    NUMS:
    .long   2547550652
    .long   1016910514
    L11:
    mov eax, DWORD PTR [rbp+12]
    cmp eax, DWORD PTR [rbp-12]
    jle L13
    mov eax, DWORD PTR [rbp+12]
    sub eax, DWORD PTR [rbp-12]
    mov edx, DWORD PTR [rbp-12]
    lea ecx, [0+edx*4]
    mov edx, DWORD PTR [rbp+8]
    add edx, ecx
    sub rsp, 8
    push eax
    push edx
    call QuickSort
    add rsp, 16
    L13:
    nop
    leave
    ret
