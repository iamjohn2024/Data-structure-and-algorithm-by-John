//���Ƕ�2.3�ڵĲ��䣺
//ǰ�涼��typedef struct{}shunxubiao;
//��������û��typedefҲ����
//��������ʵ�飬����һ��

//������typedef
#include <stdlib.h>
#include <stdio.h>

#define maxsize 10 //����û�зֺ� 

/*
typedef struct {
	int shuzu [maxsize];
	int length;
}shunxubiao;
*/

//������û��typedef
struct shunxubiao { //���������ʱ�򣬱������struct���� 
	int shuzu [maxsize];
	int length;
};
//��Ҫ�����ǣ�����Ĵ��벻֪��shunxubiao��ɶ�� 
typedef struct shunxubiao shunxubiao; //����ԭ�������֣���Ҫ�ĳ�sxb 
//��ʾ��struct�����������Լ������Ľṹ���ͣ����Ǹ������Ĵʡ���й̶����䡣 

//�ؼ�����ֻ֤����������������Ϊû��ֱ�Ӵ�ṹ�����ķ����� 

void see (shunxubiao &L) {
	for (int i = 0; i < L.length; i ++)
		printf ("i = %d, value = %d\n", i, L.shuzu [i]);
}

void givevalue (shunxubiao &L) {
	L.length = maxsize;
	for (int i = 0; i < L.length; i ++)
		L.shuzu [i] = (i + 1) * (i + 1);
	see (L);
}

/*��typedef�������Ĵ��붼�ܺ�д 
void see (shunxubiao &L) {
	for (int i = 0; i < L.length; i ++)
		printf ("i = %d, value = %d\n", i, L.shuzu [i]);
}

void givevalue (shunxubiao &L) {
	L.length = maxsize;
	for (int i = 0; i < L.length; i ++)
		L.shuzu [i] = (i + 1) * (i + 1);
	
}
*/

int main () {
	//EX1. typedef = rename
	printf("EX1. typedef = rename\n");
	printf("First let's see how typedef works.\n");
	typedef int zhengshu;
	typedef int* zhengshuzhizhen;	//the renaming can be written both inside and outside the main function.
	zhengshu i;
	zhengshuzhizhen j;
	i = 1;
	j = (int *)malloc(1*sizeof(int));
	*j = 2;
	printf("zhengshu i = %d\n", i);
	printf("zhengshuzhizhen j = %p\n", j); //typedef is applicable for both integer and pointer
	
	//EX.2 Point to a structure
	printf("\nEX.2 Point to a structure\n");
	printf("We ought to acknowledge that, the pointer could also point to a structural variable.\n");
	//����֪ʶ�㣺����������shunxubiao��Lֻ��һ��label���ѣ���shunxubiao��һ���������ӡ� sizeof�Ƕ���������shunxubiao������ 
	shunxubiao* ptr =  (shunxubiao*)malloc(1*sizeof(shunxubiao));
	printf("The ptr variable points to a newly created space for the whole wierd structure shunxubiao.\nIts location is %p.\n", ptr);
	int x = sizeof(shunxubiao); //44B
	printf("Creating one such strange structure costs %d bytes.", x);
	
	//EX.3 Define a sequential list directly with struct
	printf("\n\nEX.3 Define a sequential list directly with struct\n");
	shunxubiao L;
	givevalue (L);
	
	
	return 0;
} 
 
