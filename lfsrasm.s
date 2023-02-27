.global _lfsr32A

_lfsr32A:
push %ebp
movl %esp, %ebp

movl    8(%ebp),%ebx  #move seed to register file

cmpl    $0,%ebx        #check if seed is zero
jne     setSeed

#do calculations use %eax and %ebx as temporary variables
calculate:
movl    (0x12000), %ecx   #load seed from memory
movl    %ecx, %eax
shll    $24,  %eax      #get 25th bit
shrl    $31,  %eax

movl    %ecx, %ebx
shll    $25,  %ebx      #get 26th bit
shrl    $31,  %ebx

xorl    %ebx, %eax

movl    %ecx, %ebx
shll    $29,  %ebx      #get 30th bit
shrl    $31,  %ebx

xorl    %ebx, %eax

movl    %ecx, %ebx
shll    $31,  %ebx      #get 32th bit
shrl    $31,  %ebx

xorl    %ebx, %eax
shll    $31,  %eax
shrl    $1,   %ecx

orl    %ecx, %eax
movl   %eax, (0x12000)
jmp return

setSeed:
movl    %ebx, (0x12000)    # previous value = seed
jmp calculate

return:
movl    %ebp,%esp
popl    %ebp
ret
