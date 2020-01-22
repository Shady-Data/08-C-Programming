#include <stdio.h>
#include <ctype.h>

int this_that(void)
{
    int this = 9;
    printf("%d : %ld\n", this, sizeof(this));
    int that = 0;
    printf("%d : %ld\n", that, sizeof(that));
    int * int_ptr;
    int_ptr = &this;
    printf("%ls : %ld\n", int_ptr, sizeof(int_ptr));
    printf("%p : %ld\n", int_ptr, sizeof(int_ptr));
    printf("* of %d : %ld\n", *int_ptr, sizeof(int_ptr));
    // that = int_ptr;
    // printf("%d\n", that);
    that = *int_ptr;
    printf("%d : %ld\n", that, sizeof(that));
    *int_ptr = 1;
    printf("%d : %ld\n", this, sizeof(this));

    return 0;
}

int illustrate_pointers(void)
{
     int   count = 10, x;
     int   *int_pointer;

     int_pointer = &count;
     x = *int_pointer;

     printf ("count = %i, x = %i\n", count, x);

     return 0;
}

int demonestrate_ptrs_1( void )
{
   int a; // a is an integer
   int *aPtr; // aPtr is a pointer to an integer

   a = 7;
   aPtr = &a; // set aPtr to the address of a

   printf( "The address of a is %p"
           "\nThe value of aPtr is %p", &a, aPtr );

   printf( "\n\nThe value of a is %d"   
           "\nThe value of *aPtr is %d", a, *aPtr );

   printf( "\n\nShowing that * and & are complements of "
           "each other\n&*aPtr = %p"   
           "\n*&aPtr = %p\n", &*aPtr, *&aPtr );
}

// calculate and return cube of integer argument                 
int cubeByValue( int n )                                            
{                                                                   
   return n * n * n; // cube local variable n and return result
} // end function cubeByValue

int cube_val_main( void )
{
   int number = 5; // initialize number

   printf( "The original value of number is %d", number );
   
   // pass number by value to cubeByValue
   number = cubeByValue( number );

   printf( "\nThe new value of number is %d\n", number );
} // end cube_val_main

// calculate cube of *nPtr; actually modifies number in main
void cubeByReference( int *nPtr )                              
{                                                              
   *nPtr = *nPtr * *nPtr * *nPtr; // cube *nPtr            
} // end function cubeByReference

int cube_ref_main( void )
{
   int number = 5; // initialize number

   printf( "The original value of number is %d", number );
 
   // pass address of number to cubeByReference
   cubeByReference( &number );

   printf( "\nThe new value of number is %d\n", number );
} // end cube_ref_main

// convert string to uppercase letters
void convertToUppercase( char *sPtr )
{
   while ( *sPtr != '\0' ) { // current character is not '\0' 
      *sPtr = toupper( *sPtr ); // convert to uppercase
      ++sPtr; // make sPtr point to the next character
   } // end while
} // end function convertToUppercase

int str2upper_main( void )
{
   char string[] = "cHaRaCters and $32.98"; // initialize char array

   printf( "The string before conversion is: %s", string );
   convertToUppercase( string );
   printf( "\nThe string after conversion is: %s\n", string ); 
} // end str2upper_main

// sPtr cannot modify the character to which it points,
// i.e., sPtr is a "read-only" pointer
void printCharacters( const char *sPtr )
{
   // loop through entire string                            
   for ( ; *sPtr != '\0'; ++sPtr ) { // no initialization   
      printf( "%c", *sPtr );                                   
   } // end for                                             
} // end function printCharacters

int print_chars_main( void )
{
   // initialize char array
   char string[] = "print characters of a string"; 

   puts( "The string is:" );
   printCharacters( string );
   puts( "" );
} // end main
/*
* // xPtr cannot be used to modify the 
* // value of the variable to which it points
* void f( const int *xPtr )
* {
*    *xPtr = 100; // error: cannot modify a const object
* } // end function f
* 
* int fail_main( void )
* {
*    int y; // define y
* 
*    f( &y ); // f attempts illegal modification
* } // end fail_main
*
* ----- Attempted Compile Result -----
* pointer_stuff.c: In function ‘f’:
* pointer_stuff.c:135:10: error: assignment of read-only location ‘*xPtr’
*   135 |    *xPtr = 100; // error: cannot modify a const object
*       |   
*/

/*
* int const_main_1( void )
* {
*    int x; // define x
*    int y; // define y
* 
*    // ptr is a constant pointer to an integer that can be modified     
*    // through ptr, but ptr always points to the same memory location
*    int * const ptr = &x;                                               
* 
*    *ptr = 7; // allowed: *ptr is not const
*    ptr = &y; // error: ptr is const; cannot assign new address
* } // end const_main_1
* 
* ----- Attempted Compile Result -----
* pointer_stuff.c: In function ‘const_main_1’:
* pointer_stuff.c:162:8: error: assignment of read-only variable ‘ptr’
*   162 |    ptr = &y; // error: ptr is const; cannot assign new address
*       |  
*/

/*
int const_main_2( void )
{
   int x = 5; // initialize x
   int y; // define y

   // ptr is a constant pointer to a constant integer. ptr always 
   // points to the same location; the integer at that location
   // cannot be modified
   const int *const ptr = &x; // initialization is OK
                                 
   printf( "%d\n", *ptr );
   *ptr = 7; // error: *ptr is const; cannot assign new value 
   ptr = &y; // error: ptr is const; cannot assign new address
} // end const_main_2

pointer_stuff.c: In function ‘const_main_2’:
pointer_stuff.c:184:9: error: assignment of read-only location ‘*ptr’
  184 |    *ptr = 7; // error: *ptr is const; cannot assign new value
      |         ^
pointer_stuff.c:185:8: error: assignment of read-only variable ‘ptr’
  185 |    ptr = &y; // error: ptr is const; cannot assign new address
      |  
*/

#define SIZE 20

// return size of ptr
size_t getSize( float *ptr )
{
   return sizeof( ptr );
} // end function getSize

int array_pointer_main( void )
{
   float array[ SIZE ]; // create array

   printf( "The number of bytes in the array is %lu"            
           "\nThe number of bytes returned by getSize is %lu\n",
           sizeof( array ), getSize( array ) );                
} // end array_pointer_main

int sizeof_main( void )
{ 
   char c;           
   short s;         
   int i;       
   long l;         
   long long ll;         
   float f;        
   double d;         
   long double ld;   
   int array[ 20 ]; // create array of 20 int elements
   int *ptr = array; // create pointer to array

   printf( "     sizeof c = %lu\tsizeof(char)  = %lu"   
           "\n     sizeof s = %lu\tsizeof(short) = %lu"   
           "\n     sizeof i = %lu\tsizeof(int) = %lu"   
           "\n     sizeof l = %lu\tsizeof(long) = %lu"   
           "\n    sizeof ll = %lu\tsizeof(long long) = %lu"   
           "\n     sizeof f = %lu\tsizeof(float) = %lu"   
           "\n     sizeof d = %lu\tsizeof(double) = %lu"   
           "\n    sizeof ld = %lu\tsizeof(long double) = %lu"   
           "\n sizeof array = %lu"   
           "\n   sizeof ptr = %lu\n",    
          sizeof c, sizeof( char ), sizeof s, sizeof( short ), sizeof i,
          sizeof( int ), sizeof l, sizeof( long ), sizeof ll,           
          sizeof( long long ), sizeof f, sizeof( float ), sizeof d,     
          sizeof( double ), sizeof ld, sizeof( long double ),           
          sizeof array, sizeof ptr );                                   
} // end main

#define ARRAY_SIZE 4

int ptr_array_main( void )
{
   int b[] = { 10, 20, 30, 40 }; // create and initialize array b
   int *bPtr = b; // create bPtr and point it to array b
   size_t i; // counter
   size_t offset; // counter

   // output array b using array subscript notation
   puts( "Array b printed with:\nArray subscript notation" );

   // loop through array b
   for ( i = 0; i < ARRAY_SIZE; ++i ) {
      printf( "b[ %lu ] = %d\n", i, b[ i ] );
   } // end for

   // output array b using array name and pointer/offset notation
   puts( "\nPointer/offset notation where\n"
         "the pointer is the array name" );

   // loop through array b
   for ( offset = 0; offset < ARRAY_SIZE; ++offset ) {
      printf( "*( b + %lu ) = %d\n", offset, *( b + offset ) );  
   } // end for

   // output array b using bPtr and array subscript notation
   puts( "\nPointer subscript notation" );

   // loop through array b
   for ( i = 0; i < ARRAY_SIZE; ++i ) {
      printf( "bPtr[ %lu ] = %d\n", i, bPtr[ i ] );
   } // end for

   // output array b using bPtr and pointer/offset notation
   puts( "\nPointer/offset notation" );

   // loop through array b
   for ( offset = 0; offset < ARRAY_SIZE; ++offset ) {
      printf( "*( bPtr + %lu ) = %d\n", offset, *( bPtr + offset ) );   
   } // end for
} // end ptr_array_main

#undef SIZE
#define SIZE 10

// copy s2 to s1 using array notation
void copy1( char * const s1, const char * const s2 )
{
   size_t i; // counter

   // loop through strings
   for ( i = 0; ( s1[ i ] = s2[ i ] ) != '\0'; ++i ) {
      ; // do nothing in body                      
   } // end for                                    
} // end function copy1

// copy s2 to s1 using pointer notation
void copy2( char *s1, const char *s2 )
{
   // loop through strings
   for ( ; ( *s1 = *s2 ) != '\0'; ++s1, ++s2 ) {
      ; // do nothing in body                
   } // end for                              
} // end function copy2

int copy_main( void )
{
   char string1[ SIZE ]; // create array string1
   char *string2 = "Hello"; // create a pointer to a string
   char string3[ SIZE ]; // create array string3
   char string4[] = "Good Bye"; // create a pointer to a string

   copy1( string1, string2 );
   printf( "string1 = %s\n", string1 );

   copy2( string3, string4 );
   printf( "string3 = %s\n", string3 );
} // end copy_main

int main(void)
{
    // this_that();
    // illustrate_pointers();
    // demonestrate_ptrs_1();
    // cube_val_main();
    // cube_ref_main();
    // str2upper_main();
    // print_chars_main();
    // fail_main();
    // const_main_1();
    // const_main_2();
    // array_pointer_main();
    // sizeof_main();
    // ptr_array_main();
    copy_main();

    return 0;
}