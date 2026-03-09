.text
.globl _start

_start:
  movb $0xF, (%ebx)
  movl %rax, (%rsp)
  movw (%rax),4(%rsp)
  movb %al,%sl
  movq %rax,$0x123
  movl %eax,%rdx
  movb %si, 8(%rbp)
