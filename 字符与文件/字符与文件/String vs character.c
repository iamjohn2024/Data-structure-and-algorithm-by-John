#define _CRT_SECURE_NO_WARNINGS 1

#if 0
The purpose of this file is to remind myself
of the basics in string and charcter operations
so that the problems in file processing can be settled.
#endif

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void charLengthTutorial()
{
	//string = {characters}
	//John in double quote is a string.
	//Each of the letters is a character.
	//the length of character = the number of used elements in the char [] array - 1
	//the extra \0 is called a NULL character, 
	//which is used for telling the OS this line ends here.
	printf("We are going to define a char [] array containing the name JOHN.\n");
	printf("Without the NULL terminator,\nthe array of a size exactly equal to the length of the string\nwill be printed abnormally.\n");
	char c1[4]; //this is a constant pointer
	c1[0] = 'J';
	c1[1] = 'O';
	c1[2] = 'H';
	c1[3] = 'N';
	printf("It looks like this:\n%s\nBe careful that Dev C++ handles this well while VS presents weird results.\n", c1);

	printf("After adding the NULL terminator,\nthe array of a size one character longer than the length of the string\nwill be printed normally.\n");
	char c2[5]; //this is a constant pointer
	c2[0] = 'J';
	c2[1] = 'O';
	c2[2] = 'H';
	c2[3] = 'N';
	c2[4] = '\0';
	printf("It looks like this:\n%s\n", c2);
	int len = strlen(c2);
	printf("The length of the second array in characters is: %d.\n", len);
	printf("\n");
}

void iniChar()
{
	char c[] = { 'J', 'O', 'H', 'N', '\0' };
	char c1[] = "JOHN"; 
	//must be >= 5 or 0
	printf("Using an array of characters to define a string: %s\n", c);
	printf("Using a string to initialize the array: %s\n", c1);
	printf("Size in bytes = %d\n", sizeof(c));
	printf("Length = %d\n", strlen(c));
	printf("\n");
}

void pointerTutorial()
{
	printf("\nThere's no need to use * to seek the address in char arrays.\n");
	char c1[6] = "Hello"; //c1 = a constant pointer
	char *c2; //c2 = a variable pointer

	c2 = c1; //It does work...
	//For more: check lessons on: 1.Project: snake game 2.Project: stack prefix
	printf("%c\n", c2[1]); //e
	c2[0] = 'A';
	printf("%s\n", c2);
	c2 = c1 + 1; //don't use *c, it needn't to be dereferenced
	printf("%c\n", c2[1]); //l

	printf("\n");
}

void print(char *ch)
//Customized function to substitute printf
//Experiment the traversing process 
{
	int i = 0;
	while (ch[i] != '\0')
	//Two ways to write the address/ordinal number:
	// *(c+i) = c [i] from i = 0
	//char c1[]; char *c2; c2 = c1;
	//is valid, as the pointer points to the head of the character array 
	//like the head node in linked list
	{
		printf("%c", *(ch + i)); //only %c works here. %s is illegal.
		ch++;
	}

	printf("\n");
}


int main()
{
	charLengthTutorial();
	iniChar();
	pointerTutorial();

	char ch[20] = "Hello!";
	print(ch);

	system("pause");
	return 0;
}

