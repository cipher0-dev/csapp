
2.1.

A. 0x25b9d2 -> bin

   2    5    b    9    d    2
0010 0101 1011 1001 1101 0010

0  0 0000
1  1 0001
2  2 0010
3  3 0011
4  4 0100
5  5 0101
6  6 0110
7  7 0111
8  8 1000
9  9 1001
a 10 1010
b 11 1011
c 12 1100
d 13 1101
e 14 1110
f 15 1111

B. 1010111001001001 -> hex

1010 1110 0100 1001
   a    e    4    9

C. 0xa8b3d -> bin

   a    8    b    3    d
1010 1000 1011 0011 1101

D. 1100100010110110010110 -> hex

0011 0010 0010 1101 1001 0110
   3    2    2    d    9    6

2.2.

|  n |  2^n (dec) | 2^n (hex) |
|----|------------|-----------|
|  5 |         32 |      0x20 |
| 23 | *8,388,608 |  0x800000 |
| 15 |     32,768 |    0x8000 |
| 13 |      8,192 |    0x2000 |
| 12 |      4,096 |    0x1000 |
|  6 |         64 |      0x40 |
|  8 |        256 |     0x100 |

* = I only calculated approx in my head, relied on python for exact result

2.3.

| Dec |    Binary |  Hex |
|-----|-----------|------|
|   0 | 0000 0000 | 0x00 |
| 158 | 1001 1110 | 0x9e |
|  76 | 0100 1100 | 0x4c |
| 145 | 1001 0001 | 0x91 |
| 174 | 1010 1110 | 0xae |
|  60 | 0011 1100 | 0x3c |
| 241 | 1111 0001 | 0xf1 |
| 117 | 0111 0101 | 0x75 |
| 189 | 1011 1101 | 0xbd |
| 245 | 1111 0101 | 0xf5 |

2.4.

A.
   1
 605c
+   5
 6061

B.

 605c
-  20
 603c

C.

 605c
+  20
 607c

D.
   e1a
 60..
-605c
   9e

2.5.

12 34 56 78

A. little: 78
   big: 12
B. little: 78 56
   big: 12 34
C. little: 78 56 34
   big: 12 34 56

2.6.

  int 2607352   -> 0x0027C8F8
float 3510593.0 -> 0x4a1f23e0

A.
  0b00000000001001111100100011111000
    0b01001010000111110010001111100000
B. 21
C. The first 8 bits of the float, probably because these are use for exponent.
   Also the last two bits but only because there aren't enough bits in the int.

* conversion to binary was done in python just to save time

2.7. 6d 6e 6f 70 71 72

2.8.()

|  Op |   Result  |
|-----|-----------|
|   a | 0100 1110 |
|   b | 1110 0001 |
|  ~a | 1011 0001 |
|  ~b | 0001 1110 |
| a&b | 0100 0000 |
| a|b | 1110 1111 |
| a^b | 1010 1111 |

2.9.

A.

| R | G | B |  Color  | ~Color  |
|---|---|---|---------|---------|
| 0 | 0 | 0 | Black   | White   |
| 0 | 0 | 1 | Blue    | Yellow  |
| 0 | 1 | 0 | Green   | Magenta |
| 0 | 1 | 1 | Cyan    | Red     |
| 1 | 0 | 0 | Red     | Cyan    |
| 1 | 0 | 1 | Magenta | Green   |
| 1 | 1 | 0 | Yellow  | Blue    |
| 1 | 1 | 1 | White   | Black   |

B.

Blue | Green = Cyan
Yellow & Cyan = Green
Red ^ Magenta = Blue

2.10.

| Step | *x |  *y |
|------|----|-----|
| Init |  a |  b  |
|   1  |  a | a^b |
|   2  |  b | a^b |
|   3  |  b |  a  |

2.11.

A. k*
B. Because each operation is mutating the same memory address. So when you
   assign to *y on Step 1, you are actually mutating both *y and *x. The same
   applies to the other steps.
C. Remove the `=` from the `first <= last` loop condition.

* I kinda got this one wrong initially because I was thinking about the wth
  element (counting from 1) vs the ith index (counting from 0).

2.12.

A. `x & 0xFF`
B. `x ^ ~0xFF`
C. `x | 0xFF`

2.13.

`bis` is like `x | m`:

```
  0 1 m
0 0 1
1 1 1
x
```

`bic` is like `x & ~m`:

```
  0 1 m
0 0 0
1 1 0
x
```

```
  0 1 m
0 0 1
1 1 0
x
```

A. bis(x, y)
B. bis(bic(x, y), bic(y, x))

* I struggled a bit on B since I forgot the property x ^ y = (x & ~y) | (y & ~x)

2.14.

a = 0x55 (0b0101_0101)
b = 0x46 (0b0100_0110)

| Expression | Value |
|------------|-------|
|   a  &  b  |  0x44 |
|   a  |  b  |  0x57 |
|  ~a  | ~b  |  0xbb |
|   a  & !b  |  0x00 |
|   a &&  b  |  0x01 |
|   a ||  b  |  0x01 |
|  !a || !b  |  0x00 |
|   a && ~b  |  0x01 |

2.15.

operators:

```
~
&
|
^

!
&&
||
```

| x | y | x == y | x ^ y | ~(x ^ y) |
|---|---|--------|-------|----------|
| 0 | 0 |    1   |   0   |     1    |
| 0 | 1 |    0   |   1   |     0    |
| 1 | 0 |    0   |   1   |     0    |
| 1 | 1 |    1   |   0   |     1    |

|  x |  y | x == y | ~(x ^ y) | x ^ y | !(x ^ y) |
|----|----|--------|----------|-------|----------|
| 00 | 00 |   01   |    11    |   00  |    01    |
| 00 | 01 |   00   |    10    |   01  |    00    |
| 00 | 10 |   00   |    01    |   10  |    00    |
| 00 | 11 |   00   |    00    |   11  |    00    |
| 01 | 00 |   00   |    10    |   01  |    00    |
| 01 | 01 |   01   |    11    |   00  |    01    |
| 01 | 10 |   00   |    00    |   11  |    00    |
| 01 | 11 |   00   |    01    |   10  |    00    |
| 10 | 00 |   00   |    01    |   10  |    00    |
| 10 | 01 |   00   |    00    |   11  |    00    |
| 10 | 10 |   01   |    11    |   00  |    01    |
| 10 | 11 |   00   |    10    |   01  |    00    |
| 11 | 00 |   00   |    00    |   11  |    00    |
| 11 | 01 |   00   |    01    |   10  |    00    |
| 11 | 10 |   00   |    10    |   01  |    00    |
| 11 | 11 |   01   |    11    |   00  |    01    |

`!(x ^ y)`

2.16.

|         a        |        a<<2      |   logical a>>3   |  arithmetic a>>3 |
|  hex |    bin    |  hex |    bin    |  hex |    bin    |  hex |    bin    |
|------|-----------|------|-----------|------|-----------|------|-----------|
| 0xd4 | 1101 0100 | 0x50 | 0101 0000 | 0x1a | 0001 1010 | 0xfa | 1111 1010 |
| 0x64 | 0110 0100 | 0x90 | 1001 0000 | 0x0c | 0000 1100 | 0x0c | 0000 1100 |
| 0x72 | 0111 0010 | 0xc8 | 1100 1000 | 0x0e | 0000 1110 | 0x0e | 0000 1110 |
| 0x44 | 0100 0100 | 0x10 | 0001 0000 | 0x08 | 0000 1000 | 0x08 | 0000 1000 |

A2.17.

| Hex |  Bin | B2U4(x) | B2T4(x) |
| ----|------|---------|---------|
| 0xa | 1010 |    10   |    -6   |
| 0x1 | 0001 |     1   |     1   |
| 0xb | 1011 |    11   |    -5   |
| 0x2 | 0010 |     2   |     2   |
| 0x7 | 0111 |     7   |     7   |
| 0xc | 1100 |    12   |    -4   |

2.18.

A. 0x2e0 -> 0010 1110 0000 -> 32+64+128+512 = 736
B. -0x58 -> 0000 0101 1000 -> 8+16+64 = -88
C.  0x28 -> 0000 0010 1000 -> 8+32 = 40
D. -0x30 -> 0000 0011 0000 -> 16+32 = -48
E.  0x78 -> 0000 0111 1000 -> 8+16+32+64 = 120
F.  0x88 -> 0000 1000 1000 -> 8+128 = 136
G. 0x1f8 -> 0001 1111 1000 -> 8+16+32+64+128+256 = 504
H.  0xc0 -> 0000 1100 0000 -> 64+128 = 192
I. -0x48 -> 0000 0100 1000 -> 8+64 = -72

2.19.

|  x |  Bin  | T2U4(x) |
|----|-------|---------|
| -1 |  1111 |    15   |
| -5 |  1011 |    11   |
| -6 |  1010 |    10   |
| -4 |  1100 |    12   |
|  1 |  0001 |     1   |
|  8 | 01000 |     8   |

2.20.

Basically any non-negative value is the same in both representations, and then
with negative values you look at the bit position of the sign bit, and instead
of subtracting that from the value of the rest of the bits, you would add it.
Since the value has already subtracted that term, you add twice the value hence
2^w vs 2^(w-1).

2.21.

|            Expression          |   Type   | Evaluation |
|--------------------------------|----------|------------|
| -2147483647-1  ==  2147483648u | unsigned |      1     |
| -2147483647-1   <  2147483647  |   signed |      1     |
| -2147483647-1u  <  2147483647  | unsigned |      0     |
| -2147483647-1   < -2147483647  |   signed |      1     |
| -2147483647-1u  < -2147483647  | unsigned |      1     |

2.22.

A.   1100 =       -8+4 = -4
B.  11100 =    -16+8+4 = -4
C. 111100 = -32+16+8+4 = -4

2.23.

A.

|      w     |   fun1(w)  |   fun2(w)  |
|------------|------------|------------|
| 0x00000076 | 0x00000076 | 0x00000076 |
| 0x87654321 | 0x00000021 | 0x00000021 |
| 0x000000c9 | 0x000000c9 | 0xffffffc9 |
| 0xedcba987 | 0x00000087 | 0xffffff87 |

B. `fun1` reads the least significant byte of the word. `fun2` is interpreting
   the word as a signed value and reading the least significant byte.

2.24.

|     Hex    |  Unsigned  | Two's Complement |
| Og | Trunc | Og | Trunc |   Og   |  Trunc  |
|----|-------|----|-------|--------|---------|
|  1 |   1   |  1 |   1   |    1   |    1    |
|  3 |   3   |  3 |   3   |    3   |    3    |
|  5 |   5   |  5 |   5   |    5   |    5    |
|  C |   4   | 12 |   4   |   -4   |    4    |
|  E |   6   | 14 |   6   |   -2   |    6    |

2.25.

When length = 0, in the for loop condition we subract 1 from it, causing it to
underflow up to UMax. i will then be less than that value reading adding parts
of memory to the result that it shouldn't. The simple fix is to do `i < length`
vs `i <= length-1`.

2.26.

A. When t is longer than s.
B. If len(t) > len(s), then you have a negative value which will underflow the
   unsigned size_t, making it positive.
C. `return strlen(s) > strlen(t);`

2.27.

```c
int uadd_ok(unsigned x, unsigned y) {
  return x + y >= x;
}
```

2.28.

|     x     |    -x     |
| hex | dec | dec | hex |
|-----|-----|-----|-----|
|  1  |   1 |  15 |  f  |
|  4  |   4 |  12 |  c  |
|  7  |   7 |   9 |  9  |
|  a  |  10 |   6 |  6  |
|  e  |  14 |   2 |  2  |
