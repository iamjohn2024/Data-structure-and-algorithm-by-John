
#include <stdlib.h>
#include <stdio.h>

struct singleList 
{
	int data;
	struct singleList *next;
};

//����һ���������Ͼ��ǰѵ�һ���ڵ�д���� 
struct singleList* createList () 
{
	struct singleList* headNode =  (struct singleList*)malloc(sizeof(struct singleList));
	headNode -> next = NULL; //��ʼ����ֻ��һ����㣬��ָ����һ����㡣 
	//�״���ʾ����̬�����ڴ棬�õ���ָ����������Ա�����-> 
	return headNode;
}

//ר��д���������������µĽ��
struct singleList* createNode (int data)
{
	struct singleList* newNode =  (struct singleList*)malloc(sizeof(struct singleList));
	newNode -> data = data;
	newNode -> next = NULL;
	return newNode;
}

//�ر���ʾ�����Ͻ���ͷ�巨��ҵ�ڵ���Щ��ͬ��ͷ���û�����ݣ���ʾ�������ԣ���������Ҫ��ͷ���ĺ��棬���ɵ�һ���ڵ㡣ͷ��㱾������ݲ��� 
void insertNodeByHead (struct singleList *headNode, int data)
{
	struct singleList* newNode =  createNode(data);
	//�״���ʾ��������������Ϊ��ֱ�Ӷ�̬���䣬��Ҳû���⣬���ǻ����������������ݡ�����Ȼ�㶼��֪��Ϊɶ�и� 
	newNode -> next = headNode -> next;
	headNode -> next = newNode;
}

void printList (struct singleList *headNode)
{
	//��Ϊ��һ�����û�����ݣ����Ա���ӵڶ����ڵ㿪ʼ��ӡ������λ�õ���ʱָ���ʼ��Ҫָ�������������ڶ������
	struct singleList* pMove = headNode -> next;
	while (pMove)
	{
		printf("%d -> ", pMove -> data); //����û�У��˼�д�ĺܼ򵥣���Ĳ���������Ȼ���Խ��Ͱ��죡ֱ�Ӵ�ӡ����� 
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
	printList(list); //��Ϊ�õ���ͷ�巨�������ݷ�����ǰ�棬���ȴ������FILO����stackһ�� 
	

	system ("pause");
	return 0;
}



/*
//�ṹ��������������ɷ���
	//һ������ͨ�ṹ�����
	struct singleList Node000 = {1, NULL};
	//�ڶ�����ָ��
	//2.1�ǰѵ�ַ�����ָ����� 
	int iNum = 1;
	int *pNum = &iNum;
	int sum = *pNum;
	printf("%d\n", sum);
	//2.2�Ƕ�̬�����ڴ���� 
	int *p = (int*)malloc(sizeof(int));
	*p = 3;
	printf("%d\n", *p);
*/

/*
//дһ���ܼ򵥵�����
	//�ڵ�֮�䱾����û���κι�ϵ��
	struct singleList Node1 = {1, NULL};//��ͨ�ṹ����� 
	struct singleList Node2 = {2, NULL};//��ͨ�ṹ����� 
	struct singleList Node3 = {3, NULL};//��ͨ�ṹ����� 
	Node1.next = &Node2;
	Node2.next = &Node3;//�޸Ĵ�node1��ʼ�ĺ�̽��ָ�� 
*/


