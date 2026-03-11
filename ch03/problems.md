
3.1.

| Operand        | Value |
|----------------|-------|
| %rax           | 0x100 |
| 0x104          | 0xAB  |
| $0x108         | 0x108 |
| (%rad)         | 0xFF  |
| 4(%rax)        | 0xAB  |
| 9(%rax,%rdx)   | 0x11  |
| 260(%rcx,%rdx) | 0x13  |
| 0xFC(,%rcx,4)  | 0xFF  |
| (%rax,%rdx,4)  | 0x11  |

3.2.

a. l
b. w
c. b
d. b
e. q
f. w

3.3.

a. This empirically does not generate an error when assembling.
b. Source %rax is 64 bits but mov was 32.
c. Both soruce and dest can not be memory addresses.
d. %sl is not a register name.
e. You can't mov into a immediate value.
f. Dest %rdx is 64 bits and soruce was 32 bits but mov was 16.
g. Source %si is 16 bits but the mov was 8.

3.4.

```
movq (%rdi), %rax
movq %rax, (%rsi)
```

a. char 8 -> int 32

```
movsbl (%rdi), %eax
movl %eax, (%rsi)
```

b. char 8 -> unsigned 32

```
movsbl (%rdi), %eax
movl %eax, (%rsi)
```

c. unsigned char 8 -> long 64

```
movzbl (%rdi), %eax
movq %rax, (%rsi)
```

d. int 32 -> char 8

```
movb (%dil), %al
movb %al, (%rsi)
```

e. unsigned 32 -> unsigned char 8

```
movl (%rdi), %eax
movb %al, (%rsi)
```

f. char 8 -> short 16

```
movsbw (%rdi), %ax
movw %ax, (%rsi)
```

3.5.

```c
void decode(long *xp, long *yp, long *zp) {
  long tmp_a = *xp;
  long tmp_b = *yp;
  long tmp_c = *zp;

  *yp = tmp_a;
  *zp = tmp_b;
  *xp = tmp_c;
}
```

3.6.

%rbx = p
%rdx = q

a. 9+q
b. q+p
c. 3p+q
d. 8p+2
e. 3q+14
f. 7q+p+6

3.7. `10*y+z+x*y`

3.8.

| Instruction             | Destination | Value |
|-------------------------|-------------|-------|
| addq %rcx, (%rax)       | 0x100       | 0x100 |
| subq %rdx,8(%rax)       | 0x108       | 0xa8  |
| imulq $16,(%rax,%rdx,8) | 0x118       | 0x110 |
| incq 16(%rax)           | 0x110       | 0x14  |
| decq %rcx               | %rcx        | 0x0   |
| subq %rdx,%rax          | %rax        | 0xfd  |


3.9.

```
salq $4, %rax
sarq %cl, %rax
```

3.10.

```c
short arith3(short x, short y, short z) {
  short p1 = y | z;
  short p2 = p1 >> 9;
  short p3 = ~p2;
  short p4 = y - p3;
  return p4;
}
```

3.11.

A. It sets %rcx value to 0.
B. movq $0, %rcx
C. 3, 7, and 4

```
       7: 48 31 c9                     	xorq	%rcx, %rcx
      11: 48 c7 c1 00 00 00 00         	movq	$0x0, %rcx
      1f: 48 83 e1 00                  	andq	$0x0, %rcx
```

3.12.

```
uremdiv:
  movq %rdx, %r8
  movq %rdi, %rax
  movl $0, %edx
  divq %rsi
  movq %rax, (%r8)
  movq %rdx, (%rcx)
  ret
```

3.13.

A.

data_t = int
COMP   = <

B.

data_t = short
COMP   = >=

C.

data_t = unsigned char, char (if it is unsigned by default by the implementation)
COMP   = <=

D.

data_t = long (signed or unsgined), void *
COMP   = !=

3.14.

A.

~(SF ^ OF)
~(SF ^ 0)
~SF

data_t = long
TEST   = >=

B.

data_t = short (signed or unsigned)
TEST   = ==

C.

data_t = unsigned char
TEST   = >, !=

D.

data_t = int
TEST   = <=

3.15.

A. The instruction past the callq instruction (0x4003fe).
B. The instruction -12 bytes from the start of the next instruction (0x400425).
C. ja (0x400543), pop (0x400545)
D. The instruction -141 byttes from the start of the nextd instruction (0x400560).
