.globl myRiscvFunc
.globl exponent
.globl exponentFloat
.globl cycles

myRiscvFunc:

addi t0, a0, 0

addi t1, zero, 7
addi t2, t0, 0
#c.mv t2, t0

loop:
    mul t0, t0, t2
    addi t1, t1, -1
    bnez t1, loop

addi a0, t0, 0
ret

exponent:

lw a0, (a0)
addi t1, a1, 0
addi t2, a0, 0
addi t1, t1, -1

loop2:
    mul a0, a0, t2
    addi t1, t1, -1
    bnez t1, loop2

ret

exponentFloat:

fmv.s.x ft9, zero
fadd.s ft0, fa0, ft9
addi t0, a0, 0
fadd.s ft2, fa0, ft9
addi t0, t0, -1

loop3:
    fmul.s ft0, ft0, ft2
    addi t0, t0, -1
    bnez t0, loop3

fadd.s fa0, ft0, ft9
ret

cycles:

add a0, zero, zero
rdinstret a0
ret