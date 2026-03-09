.text
.globl _start

_start:
  mov $15, %rcx
  xorq %rcx, %rcx

  mov $15, %rcx
  movq $0, %rcx

  mov $15, %rcx
  andq $0, %rcx

  mov $60, %rax    # exit syscall
  xor %rdi, %rdi   # status = 0
  syscall
