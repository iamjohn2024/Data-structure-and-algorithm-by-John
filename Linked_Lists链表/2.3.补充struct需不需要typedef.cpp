//这是对2.3节的补充：
//前面都是typedef struct{}shunxubiao;
//但是这里没有typedef也可以
//所以做下实验，调试一下

//先试下typedef
#include <stdlib.h>
#include <stdio.h>

#define maxsize 10 //后面没有分号 

/*
typedef struct {
	int shuzu [maxsize];
	int length;
}shunxubiao;
*/

//现在是没有typedef
struct shunxubiao { //定义变量的时候，必须跟在struct后面 
	int shuzu [maxsize];
	int length;
};
//主要问题是，后面的代码不知道shunxubiao是啥。 
typedef struct shunxubiao shunxubiao; //留下原来的名字，不要改成sxb 
//提示：struct后面必须搭配自己创建的结构类型，才是个完整的词。这叫固定搭配。 

//关键：验证只能用数组来看，因为没有直接打结构变量的方法。 

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

/*有typedef，函数的代码都很好写 
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
	//澄清知识点：数据类型是shunxubiao，L只是一个label而已，是shunxubiao的一个具体例子。 sizeof是对数据类型shunxubiao操作的 
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
 
