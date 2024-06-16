//For testing pointers and dynamic allocation.
#include <stdlib.h>
#include <stdio.h>


//In this file we only test the standard c code.
/*For four types of ADT:
Code: self-explanatpry
Global:not needed here
Stack:the main function and variables
Heap:pointers inside
*/

int main () {
	//EX.1 malloc 
	int a; //a is stored inside stack
	int *p; //ibid
	//Hint: to assign address to pointers we use p=2; 
	//but to set the specific value in the address *p must be applied for deference
	p = (int *)malloc(sizeof(int));
	*p = 10; 
	printf("EX.1 malloc\nHere we can see the essence of pointers.\n");
	printf("The pointer *p stores the hexadecimal address: %p\nwhose decimal integer form is: %d\nin which the dereferenced value is:%d", p, p, *p);
	
	//EX.2 free
	free(p);
	printf("\n\nEX.2 free\nAfter the free operation the results are changed into:\n");
	printf("The pointer *p stores the hexadecimal address: %p\nwhose decimal integer form is: %d\nin which the dereferenced value is:%d", p, p, *p);
	
	//let's see if this is an array
	//EX.3 array-style assignment 
	p = (int*)malloc(5 * sizeof(int));
	printf("\n\nEX.3 array-style assignment\nThe data for 20-Byte pointer is:\n");
	printf("The pointer *p stores the hexadecimal address: %p\nwhose decimal integer form is: %d\nin which the dereferenced value is:%d\n", p, p, *p);
	printf("Let's see the garbage data before our assignment.\n");
	for (int i = 0; i < 5; i ++) {
		printf("Address: %p, Value: %d\n", (p + i), *(p + i)); 
	}
	printf("Clean this chunk with a for loop.\n");
	for (int i = 0; i < 5; i ++) {
		*(p + i) = 10 * (i + 1);
		printf("Address: %p, Value: %d\n", (p + i), *(p + i)); //The brackets here serve as a symbol of element.
	}
	
	//EX.4 calloc and relloc
	//It's normal if you find yourself acquainted with calloc, because it's the same as malloc, except for the initialisation.
	printf("EX.4 calloc and relloc\n");
	int n = 5;
	printf("The calloc function returns a contiguous block.\n");
	p = (int *)calloc(n, sizeof (int)); //Notice that the multiplication sign is replaced by comma in calloc.
	printf("p is: %p, *p is: %d\n", p, *p); //to check that p points to the first unit of the block
	//Change the value of the first unit from default 0 to preset 99.
	p [0] = 99; //Asterisk is not needed.
	for (int i = 0; i < n; i ++) {
		printf("Address: %p, Value: %d\n", (p + i), * (p + i)); //Brackets mustn't be ignored, or it will be executed as addition.
		printf("!!!!!Address: %d, Value: %d\n", p + i, * p + i); //By default, p + i = add i to the value of the first element, which is p[0] or *(p + 0)
		// %d gives the decimal form of hexadecimal address.
	}

}

/*Below shows the running results:
EX.1 malloc 
Here we can see the essence of pointers.
The pointer *p stores the hexadecimal address: 0000000000BD1400
whose decimal integer form is: 12391424
in which the dereferenced value is:10

Summary: 
Pointer is a special integer type to store the decimal form of hexadecimal-defined addressess.
int *p;  -----> define an integer p which represents the decimal address.
(int*)malloc(4)  -----> ask for an extra 4-byte space. the 4 can be replaced by multiplication.


EX.2 free
Here we can see the essence of pointers.
The pointer *p stores the hexadecimal address: 00000000009D1400
whose decimal integer form is: 10294272
in which the dereferenced value is:10
After the free operation the results are changed into:
The pointer *p stores the hexadecimal address: 00000000009D1400
whose decimal integer form is: 10294272
in which the dereferenced value is:10318752

Summary:
1) Every time the malloc is run, the OS allocates a different address.
2) Free ¡Ùdestroy. 

EX.3 array-style assignment 
The data for 20-Byte pointer is:
The pointer *p stores the hexadecimal address: 0000000000BD1400
whose decimal integer form is: 12391424
in which the dereferenced value is:12415904
Let's see the garbage data before our assignment.
Address: 0000000000BD1400, Value: 12415904
Address: 0000000000BD1404, Value: 0
Address: 0000000000BD1408, Value: 12386640
Address: 0000000000BD140C, Value: 0
Address: 0000000000BD1410, Value: 1347436876
Clean this chunk with a for loop.
Address: 0000000000BD1400, Value: 10
Address: 0000000000BD1404, Value: 20
Address: 0000000000BD1408, Value: 30
Address: 0000000000BD140C, Value: 40
Address: 0000000000BD1410, Value: 50

Summary:
1) Constrained to only integers, *p is redefined as a larger chunk whose fist address is still the same as befire.
2) Using brackets and addition, we can reach any units in the block in O(1) time.
3) The multiplication in malloc means the number of units wanted in the chunk.
Simply put, malloc is to expand your business building by renting the nearby buildings.
However, the cleaning work is left to you as well. It's hard to imagine what the previous guy left you with.
*(p + 1) = 10 -----> give the value 10 to the second location
p [1] = 10 -----> ibid


EX.4 calloc and relloc
The calloc function returns a contiguous block.
p is: 00000000009D1420, *p is: 0
Address: 00000000009D1420, Value: 99
!!!!!Address: 10294304, Value: 99
Address: 00000000009D1424, Value: 0
!!!!!Address: 10294308, Value: 100
Address: 00000000009D1428, Value: 0
!!!!!Address: 10294312, Value: 101
Address: 00000000009D142C, Value: 0
!!!!!Address: 10294316, Value: 102
Address: 00000000009D1430, Value: 0
!!!!!Address: 10294320, Value: 103

Summary:
malloc = create new space uninitialized
calloc = create new space initialized
p = (int*)calloc(5, 4) -----> allocate 5 units of space, each of which takes up 4 bytes.



*/

