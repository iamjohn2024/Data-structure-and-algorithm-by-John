//记住：先写数据结构，再封装系统。不要一上来就想UI这种有的没的问题 
#include <stdlib.h>
#include <stdio.h>

//把学生信息这种结构性变量嵌套到现有的链表结构里
//链表本身不用动！

struct student 
{
	char name[20];
	int age;
	int num;//代表学号 
};

struct singleList 
{
	//int data; //用来建链表 
	struct student data;//注意，后面链表封装的函数，涉及data的全得改 
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
struct singleList* createNode (struct student data)
{
	struct singleList* newNode =  (struct singleList*)malloc(sizeof(struct singleList));
	newNode -> data = data;
	newNode -> next = NULL;
	return newNode;
}

//特别提示：课上讲的头插法和业内的有些不同，头结点没有数据，以示区别。所以，插入数据要在头结点的后面，当成第一个节点。头结点本身的数据不动 
void insertNodeByHead (struct singleList *headNode, struct student data)
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
	printf("姓名\t年龄\t学号\n");
	while (pMove)
	{
		printf("%s\t%d\t%d\n", pMove -> data.name, pMove -> data.age, pMove -> data.num); //注意改成student之后，这个要改啊！ 
		//发现没有！人家写的很简单！真的不用你拿自然语言解释半天！直接打印结果！ 
		pMove = pMove -> next;
	}
	printf("\n");
}

//管理系统：增删改查

//菜单 
void printMenu()
{
	printf("------------------------------\n");
	printf("\t\t0.退出信息\n");
	printf("\t\t1.录入信息\n");
	printf("\t\t2.显示信息\n");
	printf("------------------------------\n");
	
}

//按键 
struct singleList* list = createList();//放这里，就相当于放主程序了 

//在系统设计阶段，链表的生成就不是在主程序完成的了，而是在用户交互界面，分类讨论，需要生成新结点再说
void keyDown ()
{
	int choice = 0;
	scanf("%d", &choice); //把识别的字符改成整数传给choice，然后分类讨论 
	struct student tempData;
	
	switch (choice)
	{
		case 0:
			printf("正常退出！\n");
			system("pause");
			break;
		case 1:
			printf("请输入学生姓名，年龄，学号：\n");
			scanf("%s%d%d", tempData.name, &tempData.age, &tempData.num); //注意后两个必须转类型，否则报错
			insertNodeByHead(list, tempData); //不用想什么循环结构了，整个结构体变量student直接当成int传到链表的新结点里面，多省事！ 
			break;
		case 2:
			printList(list);
			break;
	}
}


int main () 
{
	while(1)
	{
		printMenu();
		keyDown();//这一句才是真的主程序 
		system("pause"); //stdlib.h，后两句是惯用伎俩
		system("cls");
	}

	system ("pause");
	return 0;
}


