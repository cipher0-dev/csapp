
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

3.16.

A.

```c
void cond(short a, short *p) {
  if (!a)
    goto done;
  if (a <= *p)
    goto done;
  *p = a;
done:
  return;
}
```

B.

The if condition has two conditions anded together so there are two conditions
to check.

3.17.

A.

```c
long gotodiff_se(long x, long y) {
  long result;
  if (x < y)
    goto true;
  ge_cnt++;
  result = x - y;
  return result;
x_lt_y:
  lt_cnt++;
  result = y - x;
  return result;
}
```

B. Maybe for performance to allow the normal path the be predicted more often by
   having the less frequent codition be the jump.

3.18.

a. z + y - x
b. z > 5
c. y > 2
d. x / z
e.  x / y
f. z < 3
g. z / y

3.19.

45 = (25 + x)/2
90 = 25 + x
x = 90 - 25 = 65

A. 40 cycles
B. 65 cycles

3.20.

A. /

B.

```asm
# short arith(short x)
# x in %rdi
arith:
  leaq   15(%rdi), %rbx # rbx =  x+15
  testq  %rdi, %rdi     # sets flags based on x
  cmovns %rdi, %rbx     # if (x>=0) rbx = x
  sarq   $4, %rbx       # rbx /= 16, not sure why this isn't rax if it is returned
  ret
```

3.21.

```c
short test(short x, short y) {
  short val = y + 12;
  if (x < 0) {
    if (x < y)
      val = x * y;
    else
      val = x | y;
  } else if (y >= 10)
    val = x / y;
  return val;
}
```

```asm
# short test(short x, short y)
# x in %rdi, y in %rsi
test:
  leaq 12(%rsi), %rbx  # val = y + 12

  testq %rdi, %rdi     # test x & x
  jge .L2              # if (x >= 0) goto .L2

  movq   %rdi, %rbx    # val = x
  imulq  %rsi, %rbx    # val *= y
  movq   %rdi, %rdx    # val2 = x
  orq    %rsi, %rdx    # val2 |= y
  cmpq   %rsi, %rdi    # comp x - y
  cmovge %rdx, %rbx    # if (x >= y) val = val2
  ret

.L2:
  idivq  %rsi, %rdi    # x = x / y
  cmpq   $10, %rsi     # comp y - 10
  cmovge %rdi, %rbx    # if (y >= 10) val = x
  ret
```

3.22.

A. Yea, it overflowed.
B. It does not overflow.

3.23.

A.

x = rdi and rbx
y = rcx
n = rdx

B. p is initialized once and never assigned to again, therefore it is an alias
   to its inital value (x).

C.

```asm
# short dw_loop(short x)
# x initially in %rdi
dw_loop:
  movq  %rdi, %rbx         # copy x
  movq  %rdi, %rcx         # y = x
  idivq $9, %rcx           # y /= 9
  leaq  (,%rdi,4), %rdx    # n = x*4
.L2:
  leaq  5(%rbx,%rcx), %rcx # y += x + 5, how is this correct?
  subq  $1, %rdx           # n -= 1 ?? shouldn't this be 2?
  testq %rdx, %rdx         # test n
  jg    .L2                # if (n > 0) goto .L2
  rep; ret
```

3.24.

```c
short loop_while(short a, short b) {
  short result = 0;
  while (a > b) {
    result = result + b*a;
    a = a - 1;
  }
  return result;
}
```

3.25.

```c
long loop_while2(long a, long b) {
  long result = b;
  while (b > 0) {
    result = result * a;
    b = b - a;
  }
  return result;
}
```

3.26.

A. jump-to-middle
B.

```c
short test_one(unsigned short x) {
  short val = 1;
  while (x) {
    val ^= x;
    x >>= 1;
  }
  return val & 0;
}
```

C. It returns 0. The book is on crack talking about it computing parity.

3.27.

```c
void fibonacci(int n) {
  int a = 0;
  int b = 1;
  int tmp = 0;

  if (n <= 0)
    goto done;

loop:
  printf("%d\n", a);
  tmp = a;
  a = b;
  b += tmp;
  n--;
  if (n > 0)
    goto loop;

done:
  return;
}
```

3.28.

A.

```c
short test_two(unsigned short x) {
  short val = 0;
  short i;
  for (i = 1, val = 65; i; ++i) {
    val *= 2;
    val |= !!x;
    x >> 1;
  }
  return val;
}
```

```asm
# short test_two(unsigned short x)
# x in %rdi
test_two:
  movl $1, %edx    # i = 1
  movl $65, %eax   # val = 65
.L10:
  movq %rdi, %rcx  # tmp = x
  andl $1, %ecx    # tmp = !!tmp
  addq %rax, %rax  # val *= 2
  orq %rcx, %rax   # val |= tmp
  shrq %rdi        # x >>= 1
  addq $1, %rdx    # i += 1
  jne .L10         # if (i) goto .L10
  rep; ret         # return val
```

B. The initial loop can be assumed to always be true.
C. I have no clue. Note: I think the book used the wrong asm for this or
   something. Given the amount of mistakes in the book I don't exactly trust their
   ASM here.

3.29.

A. We need to make sure that the increment of i always happens, even with the
   continue. We wouldn't be able to just jump to the start of the loop.
B. I would just inline the increment before the goto to the top of the loop
   body but you could also just goto end where end is where the increment is at
   the end of the loop body.

3.30.

A. -2, -1, 0, 1, 3, 4, 6
B. 1/3, -1/6

3.31.

```c
void switcher(long a, long b, long c, long *dest) {
  long val;
  switch (a) {
  case 5: /* Case A */
    c = 15^a;
    /* Fall through */
  case 0: /* Case B */
    val = 112+c;
    break;
  case 2: /* Case C */
  case 7: /* Case D */
    val = (c+a)*4;
    break;
  case 4: /* Case E */
    val = val;
    break;
  default:
    val = a;
  }
  *dest = val;
}
```

0 .L3 case b
1 .L2 default
2 .L5 case c/d
3 .L2 default
4 .L6 case e
5 .L7 case a
6 .L2 default
7 .L5 case c/d

Note: The books answers assume registers that don't align with the problem
statement.

3.32.

|         Instruction            |               State values (at beginning)                          |
| Label | PC       | Instruction | %rdi | %rsi | %rax | %rsp           | *%rsp    | Description       |
|-------|----------|-------------|------|------|------|----------------|----------|-------------------|
| M1    | 0x400560 | callq       | 10   | -    | -    | 0x7fffffffe820 | -        | Call first(10)    |
| F1    | 0x400548 | lea         | 10   | -    | -    | 0x7fffffffe818 | 0x400565 | x+1               |
| F2    | 0x40054c | sub         | 10   | 11   | -    | 0x7fffffffe818 | 0x400565 | x-1               |
| F3    | 0x400550 | callq       |  9   | 11   | -    | 0x7fffffffe818 | 0x400565 | Call last(x-1,x+1 |
| L1    | 0x400540 | mov         |  9   | 11   | -    | 0x7fffffffe810 | 0x400555 | u                 |
| L2    | 0x400543 | imul        |  9   | 11   |  9   | 0x7fffffffe810 | 0x400555 | u*v               |
| L3    | 0x400547 | retq        |  9   | 11   | 99   | 0x7fffffffe810 | 0x400555 | return            |
| F4    | 0x400555 | repz retq   |  9   | 11   | 99   | 0x7fffffffe818 | 0x400565 | return            |
| M2    | 0x400565 | mov         |  9   | 11   | 99   | 0x7fffffffe820 | -        | resume            |

3.33.

edi a
sil b
rdx u
rcx v

a int
b short
u long *
v char *

3.34.

A. a0-a5
B. a6, a7
C. There weren't enough to store them all.

3.35.

A. It stores the first arg, x.
B.

```c
long rfun(unsigned long x) {
  if (!x)
    return 0;
  unsigned long nx = x >> 2;
  long rv = rfun(nx);
  return x + rv;
}
```

```asm
rfun:
  pushq %rbx         # save off rbx
  movq  %rdi, %rbx   # put first arg into rbx
  movl  $0, %eax     # put 0 into ret
  testq %rdi, %rdi   # test first arg
  je    .L2          # if it is zero goto .L2
  shrq  $2, %rdi     # div first arg by 4 or shift right
  call  rfun         # call rfun
  addq  %rbx, %rax   # add result to original first arg value
.L2:
  popq  %rbx         # restore rbx
  ret
```

3.36.

| Array | Element size | Total size | Start address | Element i |
|-------|--------------|------------|---------------|-----------|
| P     | 4            | 20         | xp            | P + i * 4 |
| Q     | 2            | 4          | xq            | Q + i * 2 |
| R     | 8            | 72         | xr            | R + i * 8 |
| S     | 8            | 80         | xs            | S + i * 8 |
| T     | 8            | 16         | xt            | T + i * 8 |

3.37.

%rdx = (short *)P
%rcx = (long)i

| Expression   | Type    | Value            | Assembly code               |
|--------------|---------|------------------|-----------------------------|
| P[1]         | short   | *(P + 2)         | movw 2(%rdx),%ax            |
| P + 3 + i    | short * | P + 6 + i*2      | leaq 6(P,%rcx,2),%rax       |
| P[i * 6 - 5] | short   | *(P + i*12 - 10) | movw -10(%rdx,%rcx,12),%ax  |
| P[2]         | short   | *(P + 4)         | movw 4(%rdx),%ax            |
| &P[i + 2]    | short * | P + i*2 + 4      | leaq 4(%rdx,%rcx,2),%rax    |

3.38.

```c
#define M 5
#define N 7
```

```asm
leaq 0(,%rdi,8), %rdx      # tmp1  = i*8
subq %rdi, %rdx            # tmp1 -= i
addq %rsi, %rdx            # tmp1 += j
leaq (%rsi,%rsi,4), %rax   # tmp2 = j*5
addq %rax, %rdi            # tmp3 = tmp2 + i
movq Q(,%rdi,8), %rax      # ret  = *(Q + (tmp3*8)) -> Q + ((j*5+i)*8)
addq P(,%rdx,8), %rax      # ret += *(P + (tmp1*8)) -> P + ((i*7+j)*8)
```

for P
row size = N*8
P[i][j] = P + i*N*8 + j

for Q
row size = M*8
Q[j][i] = P + j*M*8 + i

3.39. Skip
3.40. Skip

3.41.

A. (assuming no alignment padding)

p: 0
s.x: 8
s.y: 10
next: 12

B. 20
C.

```asm
st_init:
movl 8(%rdi), %eax  # ...
movl %eax, 10(%rdi) # *(st+10) = *(st+8)
leaq 10(%rdi), %rax # ...
movq %rax, (%rdi)   # st->p = (st+10)
movq %rdi, 12(%rdi) # st->next = st
ret
```

```c
void st_init(struct test *st) {
    st->s.y = st->s.x;
    st->p = &st->s.y;
    st->next = st;
}
```

3.42.

A.

```asm
test:
  movl $1, %eax       # ret = 1
  jmp .L2             # goto .L2
.L3:
  imulq (%rdi), %rax  # ret *= ptr->v
  movq 2(%rdi), %rdi  #
.L2:
  testq %rdi, %rdi    # if (ptr != NULL)
  jne .L3             #   goto .L3
  rep; ret
```

```c
short test(struct ACE *ptr) {
  short ret = 1;
  while (ptr != NULL) {
    ret *= ptr->v;
    ptr = ptr->p;
  }
  return ret;
}
```

B. This is a linked list, and test just multiplies all the elements of the list
   together.

3.43. Skip

3.44.

P1:
  size/offset:
    i: 2/0
    c: 4/4
    j: 8/8
    d: 8/16
  total size: 24
  alginment: 8
P2:
  size/offset (alignment):
    i: 8/0 (4)
    c: 8/8 (1)
    s: 8/16 (2)
    j: 8/24 (8)
  total size: 32
  alginment: 8
P3:
  size/offset (alignment):
    w: 16/0 (8)
    c: 16/16 (8)
  total size: 32
  alginment: 8
P4:
  size/offset (alignment):
    w: 16/0 (1)
    c: 16/16 (8)
  total size: 32
  alginment: 8
P5:
  size/offset (alignment):
    a: 64/0 (8)
    t: 24/64 (8)
  total size: 88
  alginment: 8

3.45.

A.

```c
// size/offset/alignment
struct {
  int    *a; // 8/0/8
  float  b;  // 4/8/4
  char   c;  // 1/12/1
  short  d;  // 2/14/2
  long   e;  // 8/16/8
  double f;  // 8/24/8
  int    g;  // 4/32/4
  char   *h; // 8/40/8
} rec;
```

0123456789abcdef0123456789abcdef0123456789abcdef
|.......|...|x|.|.......|.......|...xxxx|.......

B. 48

C. 42 (although in reality the size will be padded with another 6 bytes to make
anything following it 8 byte aligned)

```c
// size/offset/alignment
struct {
  int    *a; // 8/0/8
  long   e;  // 8/8/8
  double f;  // 8/16/8
  char   *h; // 8/24/8
  float  b;  // 4/32/4
  int    g;  // 4/36/4
  short  d;  // 2/40/2
  char   c;  // 1/42/1
} rec;
```

0123456789abcdef0123456789abcdef0123456789abcdef
|.......|.......|.......|.......|...|...|.|

3.46.

A.

| 00 00 00 00 00 40 00 76 | Return address
| 01 23 45 67 89 ab cd ef | %rbx of caller
| ?? ?? ?? ?? ?? ?? ?? ?? | result
| .. .. .. .. ?? ?? ?? ?? | buf with 4 bytes of padding, %rsp points to lsb

B.

| ?? ?? ?? ?? ?? 40 00 34 | Return address
| 33 32 31 30 39 38 37 36 | %rbx of caller
| 35 34 33 32 31 30 39 38 | result
| 37 36 35 34 33 32 31 30 | buf with 4 bytes of padding, %rsp points to lsb

C. 0x400034
D. %rbx because it was saved on the stack
E. The buffer is way too small for a practical application. malloc should
   account for the null byte beign written and handle errors. strcpy does not
   enforce an length, and while it will be the length of the string, it is
   better to use strncpy.

3.47. Skip

3.48.

A.

buf: 0
v: 24
canary: none

buf: 16
v: 8
canary: 40

B. Putting the buffer closer to the canary after the locals prevents ascending
   writes from overwriting the local values.

3.49. Skip
