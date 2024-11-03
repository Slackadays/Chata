addi t0, a0, 0

addi t1, zero, 7
addi t2, t0, 0

loop:
    mul t0, t0, t2
    addi t1, t1, -1
    bnez t1, loop

ret
