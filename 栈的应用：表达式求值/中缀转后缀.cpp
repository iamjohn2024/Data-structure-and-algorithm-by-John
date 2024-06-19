/*
Credit:
https://www.programming9.com/programs/c-programs/230-c-program-to-convert-infix-to-postfix
Tutorial:
https://gate.appliedroots.com/lecture/6/data-structures-and-algorithms/255/infix-to-postfix/5/stacks-and-stack-operations
*/


#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h> //activating: printf 
#include <ctype.h> //activating: isalnum
//More about this library function is available on:
//https://www.programiz.com/c-programming/library-function/ctype.h/isalnum
#include <stdlib.h>
#include <string.h>

char stack[100];
int top = -1;

void push(char x) //push = add into
{
	stack[++top] = x; //add the current character to the stack
}


//Below is not defining any variables.
//No typedef nor struct
//It is simply returning a value without demanding any inputs
char pop()
{
	if (top == -1)
		return -1;
	else
		return stack[top--]; 
	printf("|pop incalled. top = %d|", top);
	//one bug is that, the top is never really cleared and replaced by NULL character...
}


int priority(char x)
{
	//Following the BODMAS tradition
	switch (x)
	{
	case '(':
		return 0;
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	default:
		return 0;
	}
}


int main()
{
	//pass the expression entered by the user to RAM
	char exp[20];
	char *e, x;
	printf("Enter the expression :: ");
	scanf("%s", exp);
	printf("\n");
	e = exp;

	//stack operation : parenthesize the whole expression 
	//and rewrite in postfix
	while (*e != '\0')
	{
		//case 1: numbers, i.e. operands ->keep
		if (isalnum(*e))
			printf("%c", *e);

		//case 2: brackets -> stack push or pop
		else if (*e == '(')
			push(*e);
		else if (*e == ')')
		{
			while ((x = pop()) != '(')
				printf("%c", x);
		}

		//case 3: operators -> re
		else
		{
			//compare:
			//1.the priority of the top of the stack
			//2.the current character we are reading in the expression
			while (priority(stack[top]) >= priority(*e))
				printf("%c", pop());
			push(*e);
		}

		//enable the loop to continue
		e++;// 1 charcter = 1 byte = 8 bits
	}

	while (top != -1)
	{
		printf("<top = %d>", top);
		printf("%c", pop());
	}
	printf("\n\n top = %d", top);

	system("pause");
	return 0;
}
