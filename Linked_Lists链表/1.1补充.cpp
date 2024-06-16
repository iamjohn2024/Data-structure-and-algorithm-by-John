//The role of ampersand which passes the address and real variable is fully explored.
//On 18 Apr 2023. By Hegel.

#include <stdio.h>

// Without the ampersand before variable name, 
// the function executes with another variable that has the same label,
// returning the result to its own variable,
// leaving the original variable unchanged. 

//EXE 3
void change (int &v){ // Note what happens when x is changed into v?
	//Summary: it doesn't matter whether the functioned variable is labelled x or v.
	//The thing is, they are different variables seperated by different memory addresses.
	printf("Inside the function the variable v is equal to %d.\n", v);
	printf("The address of v is %p.\n", &v);
	//EXE 4
	v = 1024;
	printf("The function resets the variable v as %d.\n", v);
	printf("The address of v is %p.\n", &v);
}

int main (){
	//EXE 1
	int x = 1; // original state
	printf("Before execution the variable x is equal to %d.\n", x);
	printf("The address of x is %p.\n", &x); // %p and &x in printf work.
	//EXE 2
	change(x); // call the outside function
	//EXE 5
	printf("After execution the variable x is equal to %d.\n", x);
	printf("The address of x is %p.\n", &x);
}

/*Below is the result of execution without ampersand:
Before execution the variable x is equal to 1.
The address of x is 000000000062FE4C.
Inside the function the variable v is equal to 1.
The address of v is 000000000062FE20.
The function resets the variable v as 1024.
The address of v is 000000000062FE20.
After execution the variable x is equal to 1.
The address of x is 000000000062FE4C.
*/
/*After adding the ampersand, we are operating directly on the real variable.
Before execution the variable x is equal to 1.
The address of x is 000000000062FE4C.
Inside the function the variable v is equal to 1.
The address of v is 000000000062FE4C.
The function resets the variable v as 1024.
The address of v is 000000000062FE4C.
After execution the variable x is equal to 1024.
The address of x is 000000000062FE4C.*/
