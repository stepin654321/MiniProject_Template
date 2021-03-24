# Outline

## Install valgrind
* If valgrind is not installed, install thru package manager
  ```
  sudo apt install valgrind
  ```

## Simple Usage
  ```
  gcc example1.c -o ex1.out
  valgrind ./ex1.out

  gcc example3.c -o ex3.out -g
  valgrind ./ex3.out
  ```

## Memory Leaks & Heap Analysis
* Memory leak
* Read/write after free
* Read/write beyond heap block size
* Mismatch between malloc/new, free/delete
* Modified/Invalid base address to free
* Double free problem
* Direct vs Indirect memory leaks

  

