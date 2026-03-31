
5.1. Both *xp and *yp will be zero.
5.2.

Version 1: n < 2.45161
Version 2: 2.45161 < n < 7.63636
Version 3: 7.63636 < n

5.3.

| Code | min | max | incr | square |
|------|-----|-----|------|--------|
| A.   |   1 |  91 |  90  |   90   |
| B.   |  91 |   1 |  90  |   90   |
| C.   |   1 |   1 |  90  |   90   |

5.4.

A. xmm0 is explicity set to the value in dest on the second version
B. Yes, because it is writen out to memory at the end of every iteration
C. Because the register state gets written out to memory at the end of every
   iteration, the two stay in sync, and the appropriate vaule is read later by
   indexing against data.

5.5. Skip
5.6. Skip
5.7. Skip
5.8. Skip

5.9.

```
void merge(long src1[], long src2[], long dest[], long n) {
  long i1 = 0;
  long i2 = 0;
  long id = 0;
  while (i1 < n && i2 < n) {
    long x = src1[i1];
    long y = src2[i2];
    bool cond = x < y;

    dest[id++] = cond ? x : y;
    i1 += cond;
    i2 += 1-cond;
  }
  while (i1 < n)
    dest[id++] = src1[i1++];
  while (i2 < n)
    dest[id++] = src2[i2++];
}
```

5.10. Skip
5.11. Skip
5.12. Skip
