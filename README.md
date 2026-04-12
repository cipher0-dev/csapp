
# Computer Systems: A Programmer's Perspective

### Randal E. Bryant and David R. O'Hallaron

This repo tracks my work on Carnegie Mellon
[15-213 Introduction to Computer Systems][course] coursework including reading
the textbook [CS:AAP3e][book], [lab exercises][labs], and
[video lectures][lectures].

## Chapters

- [x] Preface
- [x] Chapter 01 - A Tour of Computer Systems
  - [x] 1.1 Information Is Bits + Context
  - [x] 1.2 Programs Are Translated by Other Programs into Different Forms
  - [x] 1.3 It Pays to Understand How Compilation Systems Work
  - [x] 1.4 Processors Read and Interpret Instructions Stored in Memory
  - [x] 1.5 Caches Matter
  - [x] 1.6 Storage Devices Form a Hierarchy
  - [x] 1.7 The Operating System Manages the Hardware
  - [x] 1.8 Systems Communicate with Other Systems Using Networks
  - [x] 1.9 Important Themes
  - [x] 1.10 Summary
- [x] Chapter 02 - Representing and Manipulating Information
  - [x] 2.1 Information Storage
  - [x] 2.2 Integer Representations
  - [x] 2.3 Integer Arithmetic
  - [x] 2.4 Floating Point
  - [x] 2.5 Summary
- [x] Chapter 03 - Machine-Level Representation of Programs
  - [x] 3.1 A Historical Perspective
  - [x] 3.2 Program Encodings
  - [x] 3.3 Data Formats
  - [x] 3.4 Accessing Information
  - [x] 3.5 Arithmetic and Logical Operations
  - [x] 3.6 Control
  - [x] 3.7 Procedures
  - [x] 3.8 Array Allocation and Access
  - [x] 3.9 Heterogeneous Data Structures
  - [x] 3.10 Combining Control and Data in Machine-Level Programs
  - [x] 3.11 Floating-Point Code
  - [x] 3.12 Summary
- [ ] ~Chapter 04 - Processor Architecture~ - _Skip_ Not relavent to my learning objectives
- [x] Chapter 05 - Optimizing Program Performance
  - [x] 5.1 Capabilities and Limitations of Optimizing Compilers
  - [x] 5.2 Expressing Program Performance
  - [x] 5.3 Program Example
  - [x] 5.4 Eliminating Loop Inefficiencies
  - [x] 5.5 Reducing Procedure Calls
  - [x] 5.6 Eliminating Unneeded Memory References
  - [x] 5.7 Understanding Modern Processors
    - [x] 5.7.1 Overall Operation
    - [x] 5.7.2 Functional Unit Performance
    - [x] 5.7.3 An Abstract Model of Processor Operation
  - [x] 5.8 Loop Unrolling
  - [x] 5.9 Enhancing Parallelism
    - [x] 5.9.1 Multiple Accumulators
    - [x] 5.9.2 Reassociation Transformation
  - [x] 5.10 Summary of Results for Optimizing Combining Code
  - [x] 5.11 Some Limiting Factors
    - [x] 5.11.1 Register Spilling
    - [x] 5.11.2 Branch Prediction and Misprediction Penalties
  - [x] 5.12 Understanding Memory Performance
    - [x] 5.12.1 Load PerformanceS
    - [x] 5.12.2 Store Performance
  - [x] 5.13 Life in the Real World: Performance Improvement Techniques
  - [x] 5.14 Identifying and Eliminating Performance Bottlenecks
    - [x] 5.14.1 Program Profiling
    - [x] 5.14.2 Using a Profiler to Guide Optimization
  - [x] 5.15 Summary
- [x] Chapter 06 - The Memory Hierarchy
  - [x] 6.1 Storage Technologies
    - [x] 6.1.1 Random Access Memory
    - [x] 6.1.2 Disk Storage
    - [x] 6.1.3 Solid State Disks
    - [x] 6.1.4 Storage Technology Trends
  - [x] 6.2 Locality
    - [x] 6.2.1 Locality of References to Program Data
    - [x] 6.2.2 Locality of Instruction Fetches
    - [x] 6.2.3 Summary of Locality
  - [x] 6.3 The Memory Hierarchy
    - [x] 6.3.1 Caching in the Memory Hierarchy
    - [x] 6.3.2 Summary of Memory Hierarchy Concepts
  - [x] 6.4 Cache Memories
    - [x] 6.4.1 Generic Cache Memory Organization
    - [x] 6.4.2 Direct-Mapped Caches
    - [x] 6.4.3 Set Associative Caches
    - [x] 6.4.4 Fully Associative Caches
    - [x] 6.4.5 Issues with Writes
    - [x] 6.4.6 Anatomy of a Real Cache Hierarchy
    - [x] 6.4.7 Performance Impact of Cache Parameters
  - [x] 6.5 Writing Cache-Friendly Code
  - [x] 6.6 Putting It Together: The Impact of Caches on Program Performance
    - [x] 6.6.1 The Memory Mountain
    - [x] 6.6.2 Rearranging Loops to Increase Spatial Locality
    - [x] 6.6.3 Exploiting Locality in Your Programs
  - [x] 6.7 Summary
- [x] Chapter 07 - Linking
  - [x] 7.1 Compiler Drivers
  - [x] 7.2 Static Linking
  - [x] 7.3 Object Files
  - [x] 7.4 Relocatable Object Files
  - [x] 7.5 Symbols and Symbol Tables
  - [x] 7.6 Symbol Resolution
    - [x] 7.6.1 How Linkers Resolve Duplicate Symbol Names
    - [x] 7.6.2 Linking with Static Libraries
    - [x] 7.6.3 How Linkers Use Static Libraries to Resolve References
  - [x] 7.7 Relocation
    - [x] 7.7.1 Relocation Entries
    - [x] 7.7.2 Relocating Symbol References
  - [x] 7.8 Executable Object Files
  - [x] 7.9 Loading Executable Object Files
  - [x] 7.10 Dynamic Linking with Shared Libraries
  - [x] 7.11 Loading and Linking Shared Libraries from Applications
  - [x] 7.12 Position-Independent Code (PIC)
  - [x] 7.13 Library Interpositioning
    - [x] 7.13.1 Compile-Time Interpositioning
    - [x] 7.13.2 Link-Time Interpositioning
    - [x] 7.13.3 Run-Time Interpositioning
  - [x] 7.14 Tools for Manipulating Object Files
  - [x] 7.15 Summary
- [x] Chapter 08 - Exceptional Control Flow
  - [x] 8.1 Exceptions
    - [x] 8.1.1 Exception Handling
    - [x] 8.1.2 Classes of Exceptions
    - [x] 8.1.3 Exceptions in Linux/x86-64 Systems
  - [x] 8.2 Processes
    - [x] 8.2.1 Logical Control Flow
    - [x] 8.2.2 Concurrent Flows
    - [x] 8.2.3 Private Address Space
    - [x] 8.2.4 User and Kernel Modes
    - [x] 8.2.5 Context Switches
  - [x] 8.3 System Call Error Handling
  - [x] 8.4 Process Control
    - [x] 8.4.1 Obtaining Process IDs
    - [x] 8.4.2 Creating and Terminating Processes
    - [x] 8.4.3 Reaping Child Processes
    - [x] 8.4.4 Putting Processes to Sleep
    - [x] 8.4.5 Loading and Running Programs
    - [x] 8.4.6 Using fork and execve to Run Programs
  - [ ] ~8.5 Signals~ - _Skip_ TLPI covered this in depth
  - [x] 8.6 Nonlocal Jumps
  - [x] 8.7 Tools for Manipulating Processes
  - [x] 8.8 Summary
- [x] Chapter 09 - Virtual Memory
  - [x] 9.1 Physical and Virtual Addressing
  - [x] 9.2 Address Spaces
  - [x] 9.3 VM as a Tool for Caching
    - [x] 9.3.1 DRAM Cache Organization
    - [x] 9.3.2 Page Tables
    - [x] 9.3.3 Page Hits
    - [x] 9.3.4 Page Faults
    - [x] 9.3.5 Allocating Pages
    - [x] 9.3.6 Locality to the Rescue Again
  - [x] 9.4 VM as a Tool for Memory Management
  - [x] 9.5 VM as a Tool for Memory Protection
  - [x] 9.6 Address Translation
    - [x] 9.6.1 Integrating Caches and VM
    - [x] 9.6.2 Speeding Up Address Translation with a TLB
    - [x] 9.6.3 Multi-Level Page Tables
    - [x] 9.6.4 Putting It Together: End-to-End Address Translation
  - [x] 9.7 Case Study: The Intel Core i7/Linux Memory System
    - [x] 9.7.1 Core i7 Address Translation
    - [x] 9.7.2 Linux Virtual Memory System
  - [x] 9.8 Memory Mapping
    - [x] 9.8.1 Shared Objects Revisited
    - [x] 9.8.2 The fork Function Revisited
    - [x] 9.8.3 The execve Function Revisited
    - [x] 9.8.4 User-Level Memory Mapping with the mmap Function
  - [x] 9.9 Dynamic Memory Allocation
    - [x] 9.9.1 The malloc and free Functions
    - [x] 9.9.2 Why Dynamic Memory Allocation?
    - [x] 9.9.3 Allocator Requirements and Goals
    - [x] 9.9.4 Fragmentation
    - [x] 9.9.5 Implementation Issues
    - [x] 9.9.6 Implicit Free Lists
    - [x] 9.9.7 Placing Allocated Blocks
    - [x] 9.9.8 Splitting Free Blocks
    - [x] 9.9.9 Getting Additional Heap Memory
    - [x] 9.9.10 Coalescing Free Blocks
    - [x] 9.9.11 Coalescing with Boundary Tags
    - [x] 9.9.12 Putting It Together: Implementing a Simple Allocator
    - [x] 9.9.13 Explicit Free Lists
    - [x] 9.9.14 Segregated Free Lists
  - [x] 9.10 Garbage Collection
    - [x] 9.10.1 Garbage Collector Basics
    - [x] 9.10.2 Mark&Sweep Garbage Collectors
    - [x] 9.10.3 Conservative Mark&Sweep for C Programs
  - [x] 9.11 Common Memory-Related Bugs in C Programs
    - [x] 9.11.1 Dereferencing Bad Pointers
    - [x] 9.11.2 Reading Uninitialized Memory
    - [x] 9.11.3 Allowing Stack Buffer Overflows
    - [x] 9.11.4 Assuming That Pointers and the Objects They Point to Are the Same Size
    - [x] 9.11.5 Making Off-by-One Errors
    - [x] 9.11.6 Referencing a Pointer Instead of the Object It Points To
    - [x] 9.11.7 Misunderstanding Pointer Arithmetic
    - [x] 9.11.8 Referencing Nonexistent Variables
    - [x] 9.11.9 Referencing Data in Free Heap Blocks
    - [x] 9.11.10 Introducing Memory Leaks
  - [x] 9.12 Summary
- [ ] ~Chapter 10 - System-Level I/O~ - _Skip_ TLPI covered this in depth
- [ ] ~Chapter 11 - Network Programming~ - _Skip_ TLPI covered this in depth,
      and I have a lot of experience already
- [ ] ~Chapter 12 - Concurrent Programming~ - _Skip_ I have a lot of experience
      already and have a book scheduled later this year that will go into more
      depth than this

## Web Asides

- Chapter 02:
  - [x] DATA:TMIN
  - [x] DATA:BOOL
  - [ ] ~DATA:TNEG~ - _Skip_
- Chapter 03:
  - [x] ASM:I32 - Read but didn't do the practice problems
  - [ ] ASM:EASM - _Skip_
- Chapter 04:
  - [ ] ~ARCH:VLOG~ — _Skip_ Not relavent to my learning objectives
  - [ ] ~ARCH:HCL~ — _Skip_ Not relavent to my learning objectives
- Chapter 05:
  - [x] OPT:SIMD - Read but didn't do the practice problems
- Chapter 06:
  - [ ] MEM:BLOCKING - _Skip_

## Labs

[Labs Repo][labs-repo]

- [x] Data
- [x] Bomb
- [x] Attack
- [x] Cache
- [ ] Malloc - _Skip_ Covered in K&R C
- [ ] Shell - _Skip_ Covered in TLPI
- [ ] Proxy - _Skip_ Covered in TLPI and I have a lot of experience already

## Lectures

- [x] Lecture 01: Course Overview
- [x] Lecture 02: Bits, Bytes, and Integers
- [x] Lecture 03: Bits, Bytes, and Integers (cont.)
- [x] Lecture 04: Floating Point
- [x] Lecture 05: Machine-Level Programming I: Basics
- [x] Lecture 06: Machine-Level Programming II: Control
- [x] Lecture 07: Machine-Level Programming III: Procedures
- [x] Lecture 08: Machine-Level Programming IV: Data
- [x] Lecture 09: Machine-Level Programming V: Advanced Topics
- [x] Lecture 10: Program Optimization
- [x] Lecture 11: The Memory Hierarchy
- [x] Lecture 12: Cache Memories
- [x] Lecture 13: Linking
- [x] Lecture 14: Exceptional Control Flow: Exceptions and Processes
- [x] Lecture 15: Exceptional Control Flow: Signals and Nonlocal Jumps
- [x] Lecture 16: System Level I/O
- [x] Lecture 17: Virtual Memory: Concepts
- [x] Lecture 18: Virtual Memory: Systems
- [x] Lecture 19: Dynamic Memory Allocation: Basic Concepts
- [x] Lecture 20: Dynamic Memory Allocation: Advanced Concepts
- [x] Lecture 21: Network Programming: Part I
- [x] Lecture 22: Network Programming: Part II
- [x] Lecture 23: Concurrent Programming
- [x] Lecture 24: Synchronization: Basics
- [x] Lecture 25: Synchronization: Advanced
- [x] Lecture 26: Thread-Level Parallelism
- [x] Lecture 27: Future of Computing
- [x] Recitation 03: Datalab and Data Representations
- [x] Recitation 04: Bomb Lab
- [x] Recitation 05: Attack Lab and Stacks
- [x] Recitation 06: C Review
- [x] Recitation 07: Cache Lab and Blocking
- [x] Recitation 08: Exam Review
- [x] Recitation 09: Shell Lab, Processes, and Signals, and I/O
- [ ] Recitation 10: Virtual Memory - _Skip_
- [ ] Recitation 11: Malloc Lab - _Skip_
- [ ] Recitation 12: Debugging Malloc Lab - _Skip_
- [ ] Recitation 13: Proxy Lab - _Skip_
- [ ] Recitation 14: Synchronization - _Skip_
- [ ] Recitation 15: Exam review - _Skip_

[course]: https://www.cs.cmu.edu/~213/
[book]: https://csapp.cs.cmu.edu/
[labs]: https://csapp.cs.cmu.edu/3e/labs.html
[labs-repo]: https://github.com/bmadone/csapp-labs
[lectures]: https://scs.hosted.panopto.com/Panopto/Pages/Sessions/List.aspx#folderID=%22b96d90ae-9871-4fae-91e2-b1627b43e25e%22
