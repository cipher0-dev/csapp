
9.1.

| Number of virtual address bits (n) | Number of virtual addresses (N) | Largest possible virtual address |
|------------------------------------|---------------------------------|----------------------------------|
| 4                                  | 2^4 = 16                        | 2^4 - 1 = 15                     |
| 14                                 | 2^14 = 16 K                     | 2^14 - 1 = 16 K - 1              |
| 24                                 | 2^24 = 16 M                     | 2^24 - 1 = 16 M - 1              |
| 46                                 | 2^46 = 64 T                     | 2^46 - 1 = 64 T - 1              |
| 54                                 | 2^54 = 16 P                     | 2^54 - 1 = 16 P - 1              |

9.2.

| n  | P = 2^p | # of PTEs |
|----|---------|-----------|
| 12 | 1 K     | 4         |
| 16 | 16 K    | 4         |
| 24 | 2 M     | 8         |
| 36 | 1 G     | 64        |

# of PTEs = 2^(n - p)

 1 K = 2^p, p = 10, n - p = 12 - 10 = 2
16 K = 2^p, p = 14, n - p = 16 - 14 = 2
 2 M = 2^p, p = 21, n - p = 24 - 21 = 3
 1 G = 2^p, p = 30, n - p = 36 - 30 = 6

9.3.

| P     | VPN bits | VPO bits | PPN bits | PPO bits |
|-------|----------|----------|----------|----------|
| 1 KB  | 54       | 10       | 22       | 10       |
| 2 KB  | 53       | 11       | 21       | 11       |
| 4 KB  | 52       | 12       | 20       | 12       |
| 16 KB | 50       | 14       | 18       | 14       |

virtual address space bits: 64
physical address space bits: 32

VPO bits = PPO bits = p (where P = 2^p) = log2(P)
VPN = 64-VPO
PPN = 64-PPO

9.4.

A. 00 0011 1101 0111
B.

| Parameter   | Value |
|-------------|-------|
| VPN         |  0x0f |
| TLB index   |  0x3  |
| TLB tag     |  0x03 |
| TLB hit?    |   Y   |
| Page fault? |   N   |
| PPN         |  0x0d |

C. 0011 0101 0111
D.

| Parameter           | Value |
|---------------------|-------|
| Byte offset         |  0x3  |
| Cache index         |  0x5  |
| Cache tag           |  0x0d |
| Cache hit?          |   Y   |
| Cache byte returned |  0x1d |

*Parse Addr*

VADDR: 0x3d7
VADDR bits = 14
VPO bits = 6
VPN bits = 8

[VPN]    [VPO]
00001111 010111

VPO/PPO = 0x17
VPN = 0x0f

*Parse TLB*

[TLBT] [TLBI]
000011 11

TLBI = 0x3
TLBT = 0x03

*TLB Lookup*

TLB hit
TLB entry
  tag: 0x03
  PPN: 0x0D
  valid: 1

*Construct PADDR*

[PPN]  [PPO]
001101 010111

PPN = 0x0d
PPO = 0x17
PADDR = 0x357

*Parse PADDR for L1*

block bits = 2
set bits = 4
tag bits = 12-4-2 - 6

[tag]  [set] [block]
001101 0101  11

*Check L1*

cache hit
tag present and valid
value: 0x1d
