//��ס����д���ݽṹ���ٷ�װϵͳ����Ҫһ��������UI�����е�û������ 
#include <stdlib.h>
#include <stdio.h>

//��ѧ����Ϣ���ֽṹ�Ա���Ƕ�׵����е�����ṹ��
//�������ö���

struct student 
{
	char name[20];
	int age;
	int num;//����ѧ�� 
};

struct singleList 
{
	//int data; //���������� 
	struct student data;//ע�⣬���������װ�ĺ������漰data��ȫ�ø� 
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
struct singleList* createNode (struct student data)
{
	struct singleList* newNode =  (struct singleList*)malloc(sizeof(struct singleList));
	newNode -> data = data;
	newNode -> next = NULL;
	return newNode;
}

//�ر���ʾ�����Ͻ���ͷ�巨��ҵ�ڵ���Щ��ͬ��ͷ���û�����ݣ���ʾ�������ԣ���������Ҫ��ͷ���ĺ��棬���ɵ�һ���ڵ㡣ͷ��㱾������ݲ��� 
void insertNodeByHead (struct singleList *headNode, struct student data)
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
	printf("����\t����\tѧ��\n");
	while (pMove)
	{
		printf("%s\t%d\t%d\n", pMove -> data.name, pMove -> data.age, pMove -> data.num); //ע��ĳ�student֮�����Ҫ�İ��� 
		//����û�У��˼�д�ĺܼ򵥣���Ĳ���������Ȼ���Խ��Ͱ��죡ֱ�Ӵ�ӡ����� 
		pMove = pMove -> next;
	}
	printf("\n");
}

//����ϵͳ����ɾ�Ĳ�

//�˵� 
void printMenu()
{
	printf("------------------------------\n");
	printf("\t\t0.�˳���Ϣ\n");
	printf("\t\t1.¼����Ϣ\n");
	printf("\t\t2.��ʾ��Ϣ\n");
	printf("------------------------------\n");
	
}

//���� 
struct singleList* list = createList();//��������൱�ڷ��������� 

//��ϵͳ��ƽ׶Σ���������ɾͲ�������������ɵ��ˣ��������û��������棬�������ۣ���Ҫ�����½����˵
void keyDown ()
{
	int choice = 0;
	scanf("%d", &choice); //��ʶ����ַ��ĳ���������choice��Ȼ��������� 
	struct student tempData;
	
	switch (choice)
	{
		case 0:
			printf("�����˳���\n");
			system("pause");
			break;
		case 1:
			printf("������ѧ�����������䣬ѧ�ţ�\n");
			scanf("%s%d%d", tempData.name, &tempData.age, &tempData.num); //ע�����������ת���ͣ����򱨴�
			insertNodeByHead(list, tempData); //������ʲôѭ���ṹ�ˣ������ṹ�����studentֱ�ӵ���int����������½�����棬��ʡ�£� 
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
		keyDown();//��һ�������������� 
		system("pause"); //stdlib.h���������ǹ��ü���
		system("cls");
	}

	system ("pause");
	return 0;
}


