#include <stdio.h>
#include <stdlib.h>

int MaxSize = 10;

typedef struct{
	int data [10];
	int length;
}SqList;

void IniList (SqList &L) {
	for (int i = 0; i < MaxSize; i ++)
		L.data [i] = 0;
	L.length = 0;
}

void CheckVal (SqList &L) {
	for (int i = 0; i < L.length; i ++)
		printf("data [%d] = %d\n", i, L.data [i]);
}

int main () {
	SqList L;
	CheckVal (L);
	IniList (L);
	CheckVal (L);
}
