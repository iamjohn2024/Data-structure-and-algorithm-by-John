
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct node { //to show that every structural variable is a node. the pointer leading us to the first of such is used to store the list.
	int data;
	struct node *prev, *next; //may change the order stored in the memory
};

struct node *globalp;

int list_gen (struct node *head, int length, int max) {
	printf("�������ɵ�˫��������Ϊ��\n");
	srand (time (0));
	int value [max];
	for (int i = 0; i < length; i ++) {
		value [i] = rand () % max;		
		printf("%d\n", value [i]);
	}//finish creating the list

	//�������ɵ�һ���ڵ� 
	head -> prev = NULL;
	if (length == 1) {
		head -> data = value [0];
		head -> next = NULL;
		return 0;
	}
 
	//����Ϊ�����ڵ� 
	struct node* p = head;
	int i = 1;
	while (p -> next != NULL) {
		if (i == length - 1) {
			p -> next = NULL;
			p -> data = value [i];
			return 0;
		}
		p -> next = (struct node*)malloc(sizeof(struct node));
		p -> next -> prev = p;
		p -> data = value [i];
		p = p ->next;
		i ++;
	}
	globalp = head;
	
}



void insert_at_beg (struct node* head, int starter) {
	
}


void traverse (struct node* head) {
	int i = 1;
	struct node *p = head;
	printf("Node #%d\n\tPrevious Address: %p (Dec: %d)\n\tCurrent Address: %p (Dec: %d),\n\tData: %d\n\tNext Address: %p (Dec: %d)\n", i, p -> prev, p -> prev, p, p, p -> data, p -> next, p -> next);
}

int search (struct node* head) {
	
}

void insert_at_end (struct node* head) {
	
}

void insert_after (struct node* head) {
	
}

void del (struct node* head) {
	
}

int main () {
	//1.Create a DLL. Make it a list of length 5. Randomly generate numbers for each element.
	printf("----------����˫����----------\n");
	struct node * head = (struct node*)malloc(sizeof(struct node));	
	printf("˫�����ͷ����ַΪ%p (Dec: %d)\nָ��������ָ������%p (Dec: %d)\n", head, head, &head, &head);
	int length = 5, max = 1000;
	printf("˫����ĳ���Ϊ%d\n", length);
	printf("\n");
	list_gen (head, length, max);
	
	

	//�������˫���� 
	printf("\n���ɵ�˫����Ϊ��\n");
	traverse (globalp);
	//2.Traverse the DLL. Search for the given value.
	
	//3.Insert at the beginning & end and after the element with value 25.
	
	//insert_at_beg (head, starter);
	//4.Delete elements.
	
}


