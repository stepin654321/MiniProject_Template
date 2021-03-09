# Software Setup on Linux OS for C Programming
## IDE
* [Visula Studio Code](https://code.visualstudio.com/docs/cpp/config-linux) for compiling and debuggin the code.
* Compiling and running without IDE
```
    sudo apt-get update
    sudo apt-get upgrade
    sudo apt-get install build-essential
```
* Compiling and running
```
    gcc filename.c -o outputname.out
    ./outputname.out
```

### Build tools
* Make for automating the build
```
    sudo apt-get install cmake
```

### Code Analysis
* [cppcheck](http://cppcheck.sourceforge.net/) for Static Analysis
* Valgrind for Heap analysis. Check usage [here](http://cs.ecs.baylor.edu/~donahoo/tools/valgrind/)
```
    sudo apt-get install valgrind
```
* [Memory Sanitization](https://lemire.me/blog/2016/04/20/no-more-leaks-with-sanitize-flags-in-gcc-and-clang/) using gcc and -fsanitize option

### Source code Management
* [git](https://git-scm.com/downloads)

### Test Framework
* [Unit test](http://www.throwtheswitch.org/unity)

### Documentation
* [Doxygen](https://www.doxygen.nl/download.html)
