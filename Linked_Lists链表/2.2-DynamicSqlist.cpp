//静态分配，一开始就给顺序表里的数组定好了最大长度maxsize
//动态分配，用指针让数组独立于结构变量

#include <stdlib.h> //malloc和free
#include <stdio.h>  //printf

#define InitSize 10 //顺序表默认的最大长度 

typedef struct {
	int * data; //data变成了指示动态分配数组的指针 
	int MaxSize; //顺序表的最大容量 
	int length; //顺序表的当前长度 
}SeqList;  //完成：定义动态分配顺序表

//动态申请和释放内存空间
// C	malloc free
// C++	new delete

void InitList(SeqList &L) {
	//用malloc申请一片连续的存储空间 
	L.data = (int *)malloc(InitSize * sizeof(int));
	L.length = 0;
	L.MaxSize = InitSize;
}

void IncreaseSize (SeqList &L, int len) {
	int *p = L.data;
	L.data = (int *)malloc((L.MaxSize + len) * sizeof(int));
	for (int i = 0; i <L.length; i++) {
		//printf("%d\n", L.data[i]);
		L.data[i] = p [i]; //将数据复制到新的区域 
	}
	L.MaxSize = L.MaxSize + len; //顺序表最大长度增加len 
	free(p); //释放原来的内存空间 
}

int main () {
	SeqList L;
	InitList (L);
	printf("%d", L.data);
	//这里是插入元素
	IncreaseSize (L, 5);
	return 0; 
}
