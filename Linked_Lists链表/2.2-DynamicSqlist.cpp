//��̬���䣬һ��ʼ�͸�˳���������鶨������󳤶�maxsize
//��̬���䣬��ָ������������ڽṹ����

#include <stdlib.h> //malloc��free
#include <stdio.h>  //printf

#define InitSize 10 //˳���Ĭ�ϵ���󳤶� 

typedef struct {
	int * data; //data�����ָʾ��̬���������ָ�� 
	int MaxSize; //˳����������� 
	int length; //˳���ĵ�ǰ���� 
}SeqList;  //��ɣ����嶯̬����˳���

//��̬������ͷ��ڴ�ռ�
// C	malloc free
// C++	new delete

void InitList(SeqList &L) {
	//��malloc����һƬ�����Ĵ洢�ռ� 
	L.data = (int *)malloc(InitSize * sizeof(int));
	L.length = 0;
	L.MaxSize = InitSize;
}

void IncreaseSize (SeqList &L, int len) {
	int *p = L.data;
	L.data = (int *)malloc((L.MaxSize + len) * sizeof(int));
	for (int i = 0; i <L.length; i++) {
		//printf("%d\n", L.data[i]);
		L.data[i] = p [i]; //�����ݸ��Ƶ��µ����� 
	}
	L.MaxSize = L.MaxSize + len; //˳�����󳤶�����len 
	free(p); //�ͷ�ԭ�����ڴ�ռ� 
}

int main () {
	SeqList L;
	InitList (L);
	printf("%d", L.data);
	//�����ǲ���Ԫ��
	IncreaseSize (L, 5);
	return 0; 
}
