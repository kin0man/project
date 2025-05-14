section .note.GNU-stack noalloc noexec nowrite progbits  ; Добавлено для совместимости
section .data
    const3     dd 3.0
    const4     dd 4.0
    const8     dd 8.0
    ln2        dq 0.69314718056

section .text
global f1
global f2
global f3
global df1
global df2
global df3

f1:;  1 + 4 / (x^2 + 1)
    push ebp
    mov ebp, esp
    sub esp, 24
    
    finit
    fld qword [ebp + 8]
    fld qword [ebp + 8]
    fmulp
    fld1
    faddp
    fld dword [const4]
    fdivrp
    fld1
    faddp
    
    leave
    ret

f2: ;x^3
    push ebp
    mov ebp, esp
    sub esp, 24
    
    finit
    fld qword [ebp + 8]
    fld qword [ebp + 8]
    fmulp
    fld qword [ebp + 8]
    fmulp
    
    leave
    ret

f3:;2^(-x)
    push ebp
    mov ebp, esp
    sub esp, 24
    
    finit
    fld qword[ebp + 8]
    fchs
    fld1
    fld
    fprem ;остаток от деления
    fstp
    f2xm1 ;2^y - 1
    fld1
    fadd ;2^y
    fld 
    fld1
    fscale 
    fstp
    fmul
    
    leave
    ret

df1: ;-(8 * x)/((x^2 + 1) * (x^2 + 1))
    push ebp
    mov ebp, esp
    sub esp, 24

    finit
    fld qword [ebp + 8]
    fld qword [ebp + 8]
    fmulp
    fld1
    faddp ; 1 + x^2
    fst dword[ebp - 12]
    fld dword[ebp - 12]
    fmulp                  ; (1 + x^2) ^ 2
    fld dword[const8]
    fld qword[ebp + 8]
    fmulp
    fdivrp                 ; 6 / (2 * x + 2) ^ 2
    fchs                   ; - 6 / (2 * x + 2) ^ 2

    leave
    ret

df2: ;3x^2
    push ebp
    mov ebp, esp
    sub esp, 24

    finit
    fld qword [ebp + 8]
    fld qword [ebp + 8]
    fmulp
    fld dword[const3]
    fmulp

    leave
    ret

df3: ; -(ln2)/(2^x)
    push ebp
    mov ebp, esp
    sub esp, 24

    finit
    fld qword[ebp + 8]
    fchs
    fld1
    fld
    fprem ;остаток от деления
    fstp
    f2xm1 ;2^y - 1
    fld1
    fadd ;2^y
    fld 
    fld1
    fscale 
    fstp
    fmul
    fld qword [ln2]
    fmulp
    fchs

    leave
    ret