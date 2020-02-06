|[Table of Contents](/00-Table-of-Contents.md)|
|---|

---

# Double Pointers \(and more\)

---

We just went over pointers, so we know that a pointer points to a location in memory and is used to store addresses of variables. But... what happens when you assign a pointer to a pointer? How do you access the value for the second pointer? Well, that's where double pointers come in.

```cpp
int **ptr;    // This is how you declare a double pointer
```

### Example:

```cpp
#include <stdio.h>

int main() {
    int var = 100;

    // pointer... will assign to var's address
    int *ptr;

    // This ill be the double pointer... that points to ptr
    int **dblPtr;

    // Store address of var into ptr
    ptr = &var;

    // Store address of ptr into dblPtr
    dblPtr = &ptr;

    printf("Value of var %d\n", var);
    printf("Value of var using ptr %d\n", *ptr);
    printf("Value of var using double pointer %d\n", **dblPtr);

    return 0;
}
```

### Breakdown

* First we set **var = 100**
* Let's assume **var's memory address is 0x20000000**
* Then we set ptr to **0x20000000** \(aks var's address\)
* \*ptr is now equal to 100
* Let's assume **&ptr is 0x300000000**
* We then set **dblPtr = &ptr \(0x300000000\)**
* By using two \(\*\) we can access a pointer to a pointer's value. 
* The first \* accesses dblPtr's addresses value... so **\*dblPtr == &ptr**
* The second\* accesses that addresses value... so **\*\*dblPtr == \*ptr**

### It's really that simple.

---

|[Next Topic](/12_IO_part_2/Objectives.md)|
|---|
