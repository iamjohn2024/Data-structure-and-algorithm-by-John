//补充第二个：
//pointer自己有没有地址？pointer自己占多大空间？

#include <stdlib.h>
#include <stdio.h>

int main () 
{
	
	int* p = (int*)malloc(1 * sizeof (int));
	*p = 999;
	printf("The address %p denoted by p contains the value %d.\n", p, *p);
	//printf("The address %p denoted as p contains the value %d.\n", p, p);// address=value, for a pointer p.
	printf("However, the address of the pointer p itself is %d when its own value is %d.\n", &p, *(&p));
	printf("The result for the pointer remains the same regardless of whether we choose p directly, or *(&p) to find the value.\n");
	
	int x = 666;
	int *y = &x;
	printf("x = %d, address: %p\ny = %d, hex = %p, address: %p\n", x, &x, y, y, &y);
	return 0;
}

/*
The address 00000000000003E7 denoted by p contains the value 999.
However, the address of the pointer p itself is 00000000009D1400 when its own value is 10294272.
The result for the pointer remains the same regardless of whether we choose p directly, or *(&p) to find the value.
*/
