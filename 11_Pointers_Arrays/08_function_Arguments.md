|[Table of Contents](/00-Table-of-Contents.md)|
|---|

---

## Function Arguments

## Introduction

* Generally speaking, functions take input (arguments) and provdes output (return Value)
* Arguments may take the form of **value** or **reference** depending on how they are 'passed' to the function
* **Pass by Value** - functions receive a copy in memory or the actual parameter's value (which is a local scope)
* **Pass by Reference** - Advanced functions can access and modify memory space

### Comments
Really, this section should be titled “Pointers as function arguments”.  
A good analogy for the difference between “pass by value” and “pass by reference” is sharing a web page with someone.

**Pass by Value** – I print the web page out for you.  Your copy is your own and local to you.  Any modifications you make to the page will not affect the original web page.  Also, you will not see any changes that are made to the web page after your copy was printed.  If you shred that paper, your merely destroying your personal copy of the web page.  The original still exists.

**Pass by Reference** – I give you the URL of the web page.  You now know how to find the information on your own.  You’ll also see changes that are made to the original.  Any changes you make to that web page will be seen by everyone else who follows that URL.  If you delete the URL, you’re merely destroying the reference to that page, not the page itself.

---

![](/assets/Functional_Arg1.png)

* What happens if the original changes?
* Does this always represent the original?
* If you destroy the printout (pass by value) or the URL (pass by reference) Does the original still exsist?
* Are changes reflected on the original for either the Pass by Value or Pass by Reference?

### Pass by Value

```
/////// PASS BY VALUE EXAMPLE ///////   //// PASS BY VALUE OUTPUT ////
void swap_em(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
    return;
}
int main(void)
{
    int x = 9; int y = 0;
    printf("x = %d\ny = %d\n", x, y);
    swap_em(x, y);
    printf("x = %d\ny = %\n", x, y);
    [...]
}
```

**Note** - This code is stub code.  The function swap_em() is stand-alone but main() is missing some other things.  There are other basic style errors (e.g., no comments, two statements on one line) that were included in an attempt to display the necessary code at an appropriate pitch.
Discuss these slides with the student.
* Invite the students to speculate as to the output of this code.
* Show the students the output
* Discuss the output
Focus the discussion to topics such as scope.

---

### Pass by Reference

```
/////// PASS BY REFERENCE EXAMPLE ///////   //// PASS BY REFERENCE OUTPUT ////
void swap_em(int *a, int *b)
{
    int temp = *a;                           x = 9
    *a = *b;                                 y = 0
    *b = temp;                               x = 0
    return;                                  y = 9
}
int main(void)
{
    int x = 9; int y = 0;
    printf("x = %d\ny = %d\n", x, y);
    swap_em(&x, &y);
    printf("x = %d\ny = %\n", x, y);
    [...]
}
```

---

|[Next Topic](/11_Pointers_Arrays/09_Pointer_Arrays.md)|
|---|
