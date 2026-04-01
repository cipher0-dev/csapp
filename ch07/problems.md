
7.1.

| Symbol | .symtab entry? | Symbol type | Module where defined | Section |
|--------|----------------|-------------|----------------------|---------|
| buf    |      Yes       |   external  |          m.o         |  .data  |
| bufp0  |      Yes       |    global   |        swap.o        |  .data  |
| bufp1  |      Yes       |    global   |        swap.o        |  COMMON |
| swap   |      Yes       |    global   |        swap.o        |  .text  |
| temp   |       No       |      -      |           -          |    -    |

7.2.

A. a. main.1
   b. main.1

B. a. error
   b. error

C. a. x.2
   b. x.2

7.3.

A. gcc p.o -lx
B. gcc p.o -lx -ly
C. gcc p.o -lx -ly -lx

7.4.

A. 0x4004df
B. 0x5

7.5.

0x9      <- og offset of call instruction
0xa      <- og offset of swap ref inside instruction
0x4004d0 <- new base of .text
0x4004da <- new offset of swap ref
0x4004e8 <- new location of swap

0x4004e8 - 0x4004da - 4

value of pc ref: 0xa
