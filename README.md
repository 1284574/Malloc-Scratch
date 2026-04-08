# Malloc-Scratch
Implemented a Malloc-inspired memory allocator using Unix system calls brk and sbrk to manage Heap memory. References to Daniel Hirsch

📌 Overview

This project demonstrates a basic custom memory allocator in C by implementing simplified versions of:

malloc() → own_malloc
free() → own_free_all

Instead of using the standard C library, this implementation directly interacts with the operating system using:

sbrk() — to extend the heap
brk() — to shrink/reset the heap

This project is designed to help understand low-level memory management and how dynamic allocation works under the hood in Unix-like systems.

🛠️ Compilation & Run
gcc -o custom_malloc main.c
./custom_malloc
