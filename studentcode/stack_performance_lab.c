/*
# Performance Lab 1

## (Reversing the Words of a Sentence) Write a program that inputs a line of text and uses a stack to print the line reversed.
*/
#include <stdio.h>
#include <string.h>

#define MAXSIZE 255

int isempty(char * stack, char * stack_top_ptr)
{
    if (stack_top_ptr == NULL /* &&  stack_top_ptr == stack*/){
        return 1;
    }
    else {
        return 0;
    }
}

int isfull(char * stack, char * stack_top_ptr)
{
    if ((stack + MAXSIZE) == stack_top_ptr){
        return 1;
    }
    else{
        return 0;
    }
}

void push(char * stack, char ** stack_top_ptr, char item)
{
    if(!isfull(stack, *stack_top_ptr)){
        **stack_top_ptr = item;
        (*stack_top_ptr)++;
    }
}

char peek(char * stack_top_ptr){
    return *stack_top_ptr;
}

char pop(char * stack, char ** stack_top_ptr)
{
    if (!isempty(stack, *stack_top_ptr)){
        char value = **stack_top_ptr;
        if (*stack_top_ptr == stack){
            (*stack_top_ptr) = NULL;
        }
        else{
            (*stack_top_ptr)--;
        }
        return value;
    }
}

void string_reverse(char * string)
{
    char stack[MAXSIZE] = {0};
    char * top_ptr = stack;

    for (int i = 0; i < strlen(string); string++){
        push(stack, &top_ptr, *string);
    }

    // printf("%c", peek(top_ptr));

    printf("The reversed string is:\n");
    while (!isempty(stack, top_ptr)){
        printf("%c", pop(stack, &top_ptr));
    }
    printf("\n");
}


/*
## (Palindrome Tester) Write a program that uses a stack to determine whether a string is a palindrome
(i.e., the string is spelled identically backward and forward). 
The program should ignore spaces and punctuation.
*/

int isPalindrome(char * string)
{
    char stack[MAXSIZE] = {0}; // declare and zeroize a char array, as a stack, of max size
    char * top_ptr = stack; // declare and initialize a char pointer to the start of the stack

    for (int i = 0; i < strlen(string); string++){ // for i is 0, while i is less than the calculated length starting at the string pointer, incrementing the string pointer for each iteration
        if (*string != ' ' && *string != ',' && *string != '.' && *string != ';' && *string != ':' && *string != '[' && *string != ']' && *string != '/' && *string != '\\' && *string != '!'
             && *string != '@' && *string != '#' && *string != '$' && *string != '%' && *string != '^' && *string != '&' && *string != '*' && *string != '(' && *string != ')' && *string != '?'
             && *string != '<' && *string != '>' && *string != '\n' && *string != '\t' && *string != '\0' && *string != '\000'){ // if the value of the referenced pointer is not a special character or whitespace char 
            push(stack, &top_ptr, *string); // push the value at the current string reference onto the stack
        } // end if
    } // end for
    char * reverse_ptr = stack; // declare and initialize a pointer to the base of the stack
    top_ptr--; // set the top pointer to be one less to not test on the NULL terminating char
    while (reverse_ptr != top_ptr && reverse_ptr != top_ptr +1){ // while the reverse pointer is not equal to the top pointer, or top pointer + 1
        if (*reverse_ptr != pop(stack, &top_ptr)){ // if the value at reverse pointer is not equal to the popped value from the top of the stack
            return 0; // return 0
        } // end if
        reverse_ptr++; // increment the reverse_ptr reference for each loop
        // top_ptr--;
    } // end while
    return 1; // if the previous return was not hit, return 1
}

int main(void)
{
    char string2check1[] = "not a palindrome";
    char string2check2[] = "racecar";
    char string2check3[] = "race car";
    char * strings[3] = {string2check1, string2check2, string2check3};

    for (int i = 0; i < 3; i++){
        if  (isPalindrome(strings[i])){
            printf("\"%s\" is a palindrome.\n", strings[i]);
        }
        else {
            printf("\"%s\" is not a palindrome.\n", strings[i]);
        }
    }

    for (int i = 0; i < 3; i++){
        string_reverse(strings[i]);
    }

    return 0;
}