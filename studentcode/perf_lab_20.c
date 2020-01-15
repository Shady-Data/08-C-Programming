/* 
* 
*  name: Robert Chunn
*  date: 14 Jan 2020
*  project: Performance Lab 20
*
*  URL: https://github.com/CyberTrainingUSAF/08-C-Programming/blob/master/08_Functions/performance_labs/lab8A/Lab20.md
*
*/

#include <stdio.h>
#include <string.h>             // provides strlen()
#define ERR_NULL_POINTER -1		// Error:  Pointer passed was NULL
#define ERR_NONE_FOUND 0		// Error:  Didn't find any newlines

int replace_character(char * string, const char findThisChar, const char replaceItWithThis); // prototype function for declaration

int main(void)
{
    // input Arrays to test the replace_character function
    char beforeArray1[] = "This is to check that I is replaced with A\n"; // expected 1 replacement
    char beforeArray2[] = "This is to check that A is replaced with I\n"; // expected 1 replacement
    char beforeArray3[] = "This is to check that u is replaced with v\n"; // expected 1 replacement
    char beforeArray4[] = "This is to check that 1 is replaced with 0\n"; // expected 1 replacement
    char beforeArray5[] = "This is to check that a is replaced with  \n"; // expected 3 replacements
    char * beforeArray6 = NULL; // NULL Pointer
    char * beforeArrays[] = {beforeArray1, beforeArray2, beforeArray3, beforeArray4, beforeArray5, beforeArray6}; // array containing pointer to the other arrays

    // output Arrays to verify the replacement
    char afterArray1[] = "This is to check that A is replaced with A\n";
    char afterArray2[] = "This is to check that I is replaced with I\n";
    char afterArray3[] = "This is to check that v is replaced with v\n";
    char afterArray4[] = "This is to check that 0 is replaced with 0\n";
    char afterArray5[] = "This is to check th t   is repl ced with  \n";
    char * afterArray6 = NULL; // NULL Pointer
    char * afterArrays[] = {afterArray1, afterArray2, afterArray3, afterArray4, afterArray5, afterArray6}; // array containing pointer to the other arrays

    // array for result comparison
    int expectedResults[6] = {1, 1, 1, 1, 3, ERR_NULL_POINTER};

    int i = 0; // iterating variable
    int tempResults = 0; // temporary variable to store function result for comparison

    // test cases
    for (i = 0; i < sizeof(beforeArrays)/sizeof(*beforeArrays); i++)
    {
        // Tests header
        printf("\tTEST #%d\n", i + 1);
        printf("--------------------\n");

        switch (i)
        {
            case (0):
                tempResults = replace_character(beforeArrays[i], 'I', 'A');
                break;
            case (1):
                tempResults = replace_character(beforeArrays[i], 'A', 'I');
                break;
            case (2):
                tempResults = replace_character(beforeArrays[i], 'u', 'v');
                break;
            case (3):
                tempResults = replace_character(beforeArrays[i], '1', '0');
                break;
            case (4):
                tempResults = replace_character(beforeArrays[i], 'a', ' ');
                break;
            case (5):
                tempResults = replace_character(beforeArrays[i], 'A', '\n');
                break;
            default:
                printf("Outside of expected cases.");
                break;
        }

        printf("Returned Results: ");
        if (expectedResults[i] == tempResults)
        {
            printf("\tPASS\n");
        }
        else
        {
            printf("\tFAIL\n");
        }
        
        printf("Comparison Results:\t%d", tempResults);
        if (beforeArrays[i])
        {
            /* Temporarily stores the retun value of strcmp() */
			tempResults = strcmp(beforeArrays[i], afterArrays[i]);
			if (!tempResults) // strcmp() returns 0 if the two strings match
			{
				printf("\tPASS\n"); // 0
			}
			else
			{
				printf("\tFAIL\n"); // 1
			}
		}
		else
		{
			printf("\tNo string present.\n"); // strcmp() doesn't like NULL pointers.  No comparison necessary.
		}
    }

    return 0;
}

int replace_character(char * string, const char findThisChar, const char replaceItWithThis)
{
	int count = 0; // Number of newlines removed
	if (string)
	{
		/* LOCAL VARIABLE DECLARATION */
		size_t length = 0;
		int i = 0;

		/* FUNCTION ALGORITHM */
		length = strlen(string);			// Calculate length of input buffer
		for (i = 0; i < length; i++)		// Iterates through entire buffer
		{
			if (*string == findThisChar)		// Checks the char at the pointer position to see if is matches findThisChar
			{
				*string = replaceItWithThis;	// Changes the character at the current pointer location to replaceItwithThis
				count++;						// Increment the number of characters replaced
			}
			string++;							// Increments to the next element in the string
		}
	}
	else
	{
		return ERR_NULL_POINTER;				// otherwise string is a NULL pointer
	}

	/* DYNAMIC RETURN VALUES */
	if (count)
	{
		return count;                           // if the count is not 0, return it
	}
	else
	{
		return ERR_NONE_FOUND;					// Because the function found no characters to replace
	}
}