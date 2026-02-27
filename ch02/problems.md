
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
