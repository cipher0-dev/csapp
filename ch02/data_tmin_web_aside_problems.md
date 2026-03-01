
1.

```c
int dtmin32 = -2147483648;
int dpos32a = (dtmin32 > 0);
int htmin32 = 0x80000000;
int hpos32a = (htmin32 > 0);
```

- For the hex literal, it is taken as an unsigned int, then converted into a signed int.
- For the decimal literal:
  - on 64 bit machines, all values fit well within the ranges for long (8 bytes).
  - on 32 bit machines:
    - compiled under C99, a long long value is used which fits all values.
    - compiled under C90, an unsigned value is used, but because it is assigned
      to an int the numerically large positive bit pattern is interpreted as a
      negative value again.

2. Yes, hex is always unsigned, it then converts the bit pattern to a signed int
   and subtracts 1 to get the lowest value. We never exceed 32 bits so it safely
   fits into a 32 bit int.

3. A.

```c
1L << sizeof(long)<<3 - 1
1L << 4<<3 - 1             // sizeof(long) has the highest precedence
1L << 4<<2                 // - has the next highest precedence
16<<2
64
```

B.

```c
1L << sizeof(long)<<3 - 1
1L << 8<<3 - 1
1L << 8<<2
256<<2
1024
```

C.

```c
1L << (sizeof(long)<<3) - 1
1L << (8<<3) - 1
1L << 64 - 1
1L << 63
LONG_MIN
```

4.

| Word Size | C Version | -9223372036854775808 | 0x8000000000000000 |
|-----------|-----------|----------------------|--------------------|
|     32    |    C90    |      undefined       |     undefined      |
|     32    |    C99    |      undefined       | unsigned long long |
|     64    |    C90    |    unsigned long     |   unsigned long    |
|     64    |    C99    |      undefined       |   unsigned long    |
