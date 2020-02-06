|[Table of Contents](/00-Table-of-Contents.md)|
|---|

---

## GNU C Compiler

### GCC (Linux)      MinGW (Windows)

***Cygwin GCC:*** Cygwin is a Unix-like environment and command-line interface for Microsoft Windows. Cygwin is huge and includes most of the Unix tools and utilities. It also included the commonly-used Bash shell.

***MinGW:*** MinGW (Minimalist GNU for Windows) is a port of the GNU Compiler Collection (GCC) and GNU Binutils for use in Windows. It also included MSYS (Minimal System), which is basically a Bourne shell (bash).

***MinGW-W64:*** a fork of MinGW that supports both 32-bit and 64-bit windows.


### Help
You can get the help manual via the --help option. For example;

```
$ gcc --help
```

### Man Pages
You can read the GCC manual pages (or man pages) via the man utility:

```
$ man gcc
// or
$ man g++
// Press space key for next page, or 'q' to quit.
```

Reading man pages under CMD or Bash shell can be difficult. You could generate a text file via:

```
$ man gcc | col -b > gcc.txt
```

The col utility is needed to strip the backspace. (For Cygwin, it is available in "Utils", "util-linux" package.)

Alternatively, you could look for an online man pages, e.g., http://linux.die.net/man/1/gcc.


### Compiling simple programs

Say you have a file hello.c as follows:

```c
#include <stdio.h>

void main ()
{
    printf("hello");
}
```

You can compile and run it from the unix prompt as follows:

```
gcc hello.c
```

The default output executable is called "a.exe" (Windows) or "a.out" (Unixes and Mac OS X).

 You can run it by typing:

```
./a.out
```

a.out is the default name for an executable. Use the "-o" option to change the name:

```
// (Windows) In CMD shell
> gcc -o hello.exe hello.c

  // Compiles and links the source file hello.c into an executable: hello.exe
  // Execute hello.exe under CMD shell
> hello  

// (Unixes / Mac OS X) In Bash shell
$ gcc -o hello hello.c
$ ./hello
```

### Include Directories

Sometimes the header files that you write are not in the same directory as the .c file that *#include's* it. E.g. you have a structure in a file "foo.h" that resides in: /homes/me/include. If I want to include that file in hello.c I can do the following:

- add the following to hello.c

```c
 #include < foo.h >
```

- compile it with the -I option:

```
gcc -o hello hello.c -I/homes/me/include
```

This basically tells gcc to look for *#include's* in /homes/me/include in addition to other directories you specify with -I.

Try listing the default include-paths in your system used by the "GNU C Preprocessor" via "cpp -v":

```
> cpp -v
......
#include "..." search starts here:
#include <...> search starts here:
 /usr/lib/gcc/x86_64-pc-cygwin/6.4.0/include
 /usr/include
 /usr/lib/gcc/x86_64-pc-cygwin/6.4.0/../../../../lib/../include/w32api
```

### Other options

***Warnings:*** -Wall turns on most warnings. man gcc for more options.  
***Debugging:*** if you intend to use the debugger (gdb), also use the -g option.  
***Optimizations:*** -O or -O2  

### Compiling multiple files

***Basic idea:*** compile each .c file into a .o file, then compile the .o files (along with any libraries) into an executable. One of these .c files obviously has to define the main function, or else the linker will gag.

E.g. Suppose we have main.c, foo.c and bar.c and want to create an executable fubar, and suppose further that we need the math library:

```
gcc -c foo.c
gcc -c main.c
gcc -c bar.c
gcc -o fubar foo.o main.o bar.o -lm
```

The first three commands generate foo.o, main.o and bar.o respectively. The last line links them together along with the math library.

### Libraries

Specify library paths with the -L option. e.g. -L/usr/lib tells gcc to look for libraries in /usr/lib. As with includes, you can add as many -L's as necessary. Specify which libraries to link with -l.

Try running the compilation in verbose mode (-v) to study the library-paths (-L) and libraries (-l) used in your system:

```
> gcc -v -o hello.exe hello.c
......
-L/usr/lib/gcc/x86_64-pc-cygwin/6.4.0
-L/usr/x86_64-pc-cygwin/lib
-L/usr/lib
-L/lib
-lgcc_s     // libgcc_s.a
-lgcc       // libgcc.a
-lcygwin    // libcygwin.a
-ladvapi32  // libadvapi32.a
-lshell32   // libshell32.a
-luser32    // libuser32.a
-lkernel32  // libkernel32.a
```

### C++
All the same rules apply to compiling C++ programs except we use ***g++*** instead of ***gcc***:

```
// (Windows) In CMD shell
> g++ -o hello.exe hello.c

  // Compiles and links the source file hello.c into an executable: hello.exe
  // Execute hello.exe under CMD shell
> hello  

// (Unixes / Mac OS X) In Bash shell
$ g++ -o hello hello.c
$ ./hello
```


---

|[Next Topic](/01_Introduction/05_cmake.md)|
|---|

