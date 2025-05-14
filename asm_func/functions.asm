section .data
    c0_6    dq 0.6
    c3      dq 3.0
    c2      dq 2.0

section .text

global f1
f1:
    push ebp
    mov  ebp, esp
    fld  qword [ebp+8]
    fld  qword [c0_6]
    fmulp st1, st0
    fld  qword [c3]
    faddp st1, st0
    pop  ebp
    ret

global f2
f2:
    push ebp
    mov  ebp, esp
    fld  qword [ebp+8]
    fld  qword [c2]
    fsubp st1, st0
    fld  st0
    fld  st0
    fmulp st1, st0
    fmulp st1, st0
    fld1
    fsubp st1, st0
    leave
    ret

global f3
f3:
    push ebp
    mov  ebp, esp
    fld  qword [c3]
    fld  qword [ebp+8]
    fdivp st1, st0
    leave
    ret
