    .file "Exp2.S"
    .intel_syntax noprefix

    .text

    .global Exp2
Exp2:
    minss       xmm0, upper_exp
    maxss       xmm0, lower_exp

    # ipart = rax = int(x)
    movaps      xmm1, xmm0
    cvttss2si   rax, xmm1
    cvtsi2ss    xmm1, rax

    # fpart = xmm2 = x - ipart
    movaps      xmm2, xmm0
    subss       xmm2, xmm1

    # expipart = xmm3
    add         rax, 127
    shl         rax, 23
    movq        xmm3, rax

    # expfpart = xmm4
    movss       xmm4, c3
    mulss       xmm4, xmm2
    addss       xmm4, c2
    mulss       xmm4, xmm2
    addss       xmm4, c1
    mulss       xmm4, xmm2
    addss       xmm4, c0

    # final result
    mulss       xmm3, xmm4
    movaps      xmm0, xmm3
    ret

upper_exp:
    .float 128.0
lower_exp:
    .float -126.99999
c0:
    .float 1.0
c1:
    .float 0.695833540494823811697
c2:
    .float 0.226067155427249155588
c3:
    .float 0.0780245226406372992967

    .att_syntax noprefix
