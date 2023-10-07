#include <stdio.h> 

// Inline function in C 
// inline int foo() 
// { 
// 	return 2; 
// } 
/*  ERROR 
    undefined reference to `foo'
    collect2: error: ld returned 1 exit status

    - This is one of the side effect of GCC the way it handle inline function. 
    - When compiled, GCC performs inline substitution as the part of optimisation
*/

static inline int foo() // Using static keyword forces the compiler to consider this inline function in the linker
{ 
	return 2; 
} 

// Driver code 
int main() 
{ 

	int ret; 

	// inline function call 
	ret = foo(); 

	printf("Output is: %d\n", ret); 
	return 0; 
} 
