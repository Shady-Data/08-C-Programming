#include <stdio.h>

void print_str(char * string)
{
    while (*string != '\n' && *string != '\0')
    {
        printf("%c", (char)*string++);
    }
    printf("\n");
}

int main(void)
{
    //Example code will be executed per line and displayed in memory//
    int someList[] = { 0xFEEDFACE, 0xC001C0DE, 0xCAFEF00D, 0xFACEB00C };
    for (int i = 0; i < sizeof(someList)/sizeof(someList[0]); i++){
        printf("someList[%d] : 0x%x @ %p\n", i, someList[i], &someList[i]);
    }
    someList[0] = 0x8BADF00D;		// Normal
    int * someList_ptr = &someList[1];	// By pointer referenc...
    printf("\nsomeList_ptr = %p\n", someList_ptr);
    * someList_ptr = 0xC0DEDEAD;		// ...and then dereferencing it
    * (someList + 2) = 0x1BADD00D;		// Array name pointer math…
    someList_ptr += 2;			// ...AKA Address arithmetic
    printf("someList_ptr = %p\n\n", someList_ptr);
    * someList_ptr = 0xDEADBEEF;		// Dereference a pointer
    for (int i = 0; i < sizeof(someList)/sizeof(someList[0]); i++){
        printf("someList[%d] : 0x%x @ %p\n", i, someList[i], &someList);
    }
    
    char my_string[] = "This may be interesting";

    print_str(my_string);


    return 0;
}