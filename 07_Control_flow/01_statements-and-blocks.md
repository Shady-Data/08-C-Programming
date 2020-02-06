|[Table of Contents](/00-Table-of-Contents.md)|
|---|

---

# Statements and Blocks

A statement is an expression followed by a semicolon.
    
```c
    [expression]; //example of a statement
    
    i = 0;  // assignment expression
    
```

A block consists of a group of statements that are made into a single statement.

**Blocks may also contain declarations (variables)**

```c
    {...};   //block example
    
    {
    
    int i = 0;//declaration statement part of a block
    
    i++;  //single statement part of a block
    
    i *= 2;   //single statement part of a block
    
    if (i >4)//single statement part of a block
    
    { ... }//a nested block of statements within a block
    
    }
    
```

---

|[Next Topic](/07_Control_flow/02_conditional-statements.md)|
|---|
