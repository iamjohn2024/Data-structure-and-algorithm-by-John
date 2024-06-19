
#include <stdlib.h>
#include <stdio.h>

struct singleList 
{
	int data;
	struct singleList *next;
};

//创建一个表，本质上就是把第一个节点写出来 
struct singleList* createList () 
{
	struct singleList* headNode =  (struct singleList*)malloc(sizeof(struct singleList));
	headNode -> next = NULL; //初始化后，只有一个结点，不指向下一个结点。 
	//易错提示：动态分配内存，用的是指针变量，所以必须用-> 
	return headNode;
}

//专门写个函数用来创建新的结点
struct singleList* createNode (int data)
{
	struct singleList* newNode =  (struct singleList*)malloc(sizeof(struct singleList));
	newNode -> data = data;
	newNode -> next = NULL;
	return newNode;
}

//特别提示：课上讲的头插法和业内的有些不同，头结点没有数据，以示区别。所以，插入数据要在头结点的后面，当成第一个节点。头结点本身的数据不动 
void insertNodeByHead (struct singleList *headNode, int data)
{
	struct singleList* newNode =  createNode(data);
	//易错提示：这里容易自以为是直接动态分配，倒也没问题，就是会忘掉……还有数据……不然你都不知道为啥有个 
	newNode -> next = headNode -> next;
	headNode -> next = newNode;
}

void printList (struct singleList *headNode)
{
	//因为第一个结点没有数据，所以必须从第二个节点开始打印。标明位置的临时指针最开始就要指向有意义的这个第二个结点
	struct singleList* pMove = headNode -> next;
	while (pMove)
	{
		printf("%d -> ", pMove -> data); //发现没有！人家写的很简单！真的不用你拿自然语言解释半天！直接打印结果！ 
		pMove = pMove -> next;
	}
	printf("\n");
}

int main () 
{
	struct singleList* list = createList();

	insertNodeByHead (list, 1);
	insertNodeByHead (list, 2);
	insertNodeByHead (list, 3);
	printList(list); //因为用的是头插法，新数据放在最前面，最先打出来。FILO，像stack一样 
	

	system ("pause");
	return 0;
}



/*
//结构体变量有两种生成方法
	//一种是普通结构体变量
	struct singleList Node000 = {1, NULL};
	//第二种是指针
	//2.1是把地址分配给指针变量 
	int iNum = 1;
	int *pNum = &iNum;
	int sum = *pNum;
	printf("%d\n", sum);
	//2.2是动态申请内存分配 
	int *p = (int*)malloc(sizeof(int));
	*p = 3;
	printf("%d\n", *p);
*/

/*
//写一个很简单的链表
	//节点之间本来是没有任何关系的
	struct singleList Node1 = {1, NULL};//普通结构体变量 
	struct singleList Node2 = {2, NULL};//普通结构体变量 
	struct singleList Node3 = {3, NULL};//普通结构体变量 
	Node1.next = &Node2;
	Node2.next = &Node3;//修改从node1开始的后继结点指针 
*/


