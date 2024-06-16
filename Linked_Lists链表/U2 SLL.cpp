#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct node {
	int info;
	struct node *link;
};

struct node* globalp; 
//The pointers cannot be passed automatically due to the temporal status in the OS.
//We thus designed a global pointer to showcase the true being.

struct node* def_value (struct node *head, int end, int max) { 
	printf("-------Defalt setting function called.-------\n");
	//Using either the inherited name max or redefined label x can work.
	head = (struct node*)malloc(sizeof(struct node));
	
	printf("We have created a singly linked list starting with the head pointer pointing to %p (Dec: %d)\nwhile the address of this pointer itself is %p (Dec: %d).", head, head, &head, &head);
	//Step 1. Create a mathematical sequence.
	//Step 2. Copy the sequence elements to the SLL.
	struct node *p = head;
	printf("\n\nUsing a while loop to randomly generate a sequence whose elements will be distributed to the SLL.\n");
	//Traverse the SLL.
	int c = 1;
	srand(time(0)); // seed the random number generator
	while (c <= end) {
		p -> info = rand() % max;
		if (c == end) 
			p -> link = NULL;
		else
			p -> link = (struct node*)malloc(sizeof(struct node));
		printf("Node No.%d\n    Address: %p (Dec: %d),\n    Information: %d,\n    Pointer for the next node: %p (Dec: %d)\n", c, p, p, p -> info, p -> link, p -> link);
		c ++;
		p = p -> link;
	}
	//printf("%p\n", head);//Nothing wrong
	globalp = head;
	return head;
}

//The display and count functions are embedded inside other functions like insertion & deletion.
struct node * display (struct node * in) {
	printf("-------Display function called.-------\n");
	//Case 1: Nothing in the list.
	if (in == NULL) {
		printf("This linked list is empty.\n");
		return NULL; //Directly cease the function
	}

	//Case 2: Lots of items to be explored.
	struct node *p;
	int c = 1;
	p = in;
	printf("Traverse the list:\n");
	while (p != NULL) {
		printf("Node No.%d\n    Address: %p (Dec: %d),\n    Information: %d,\n    Pointer for the next node: %p (Dec: %d)\n", c, p, p, p -> info, p -> link, p -> link);
		p = p -> link;
		c ++;
	}
	return in;	
}

//Only count the number of nodes. No need to display the elements.
int count (struct node *head) {
	printf("-------Count function called.-------\n");
	struct node *p;
	int c = 0;
	p = head;
	while (p != NULL) {
		p = p -> link;
		c ++;
	}
	printf ("The number of elements is %d.\n", c);
	return c;
}

//Below are formal functions
void search (struct node *head, int data) {
	struct node *p = head;
	int pos = 1;
	while (p != NULL) {
		if (p -> info == data) {
			printf("Item %d found at position %d\n", data, pos);
			return;
		}
		p = p -> link;
		pos ++;
	}
	printf("Item %d not found in list\n", data);
}

struct node * insert_at_beg (struct node *head, int data) {
	printf("\nInsert at the beginning of the list a value of %d.\n", data);
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp -> info = data;
	temp -> link = globalp;
	globalp = temp;
	display(globalp);
	count(globalp);
	return head;
}

struct node * insert_at_end (struct node *head, int data) {
	printf("\nInsert at the end of the list a value of %d.\n", data);
	struct node *p, *temp;
	
	//create the node
	temp = (struct node*)malloc(sizeof(struct node));
	temp -> info = data;
	temp -> link = NULL;
	
	//traverse the existing list and add the node
	head = globalp;
	p = head;
	if (p) {
		while (p -> link != NULL)
			p = p -> link;
		p -> link = temp;
	}
	else
		head = temp;
	display(head);
	count(head);
	return head;	
}

struct node * insert_after_given_node (struct node *head, int loc, int data) {
	printf("\nInsert after node #%d a value of %d.\n", loc, data);
	int length = count(globalp);
	//traverse the list until we find the one we need.
	if (loc > length || loc <= 0) {
		printf("Location is invalid.\n");
		return head;
	}
		
	struct node *p = globalp, *temp;
	int i = 1;
	while (p != NULL)  {
		if (i == loc) {
			temp = (struct node*)malloc(sizeof(struct node));
			temp -> info = data;
			temp -> link = p -> link;
			p ->link = temp;
			display(globalp);
			count(globalp);
			return head;
		} 
		p = p-> link;
		i ++;
	}
}


struct node *del (struct node * head, int loc) {
	printf("Try to remove the #%d node from the list.\n", loc);

	//Nothing to delete
	head = globalp;
	if (head == NULL) {
		printf("List is empty.\n");
		return head;
	}	
	int x = count(head);
	if (loc > x || loc <= 0) {
		printf("Invalid position!\n");
		return head;
	}
	//when deleting the first node
	if (loc == 1) {
		globalp = head -> link;
		display(globalp);
		count(globalp);
		return head;
	}
	
	//when deleting the later nodes
	struct node *p = head, *q;
	//find the previous node
	for (int i = 1; i < loc; i ++) { //taking the first node into account. start from 0.
		q = p;//q will be the fourth if we have 5 nodes.
		p = p -> link; //p will be the 5th if we have 5 nodes.
	}
	//read the to-be-deleted node
	q -> link = p -> link;
	free (p);
	display(globalp);
	count(globalp);
	return head;
}


int main () {
	int length = 5, max = 1000;
	
	//1.Create a singly linked list of length 5.
	printf("-------Singly Linked List-------\n");
	struct node *head;
	
	//2.Give value to each of these elements and show the traversing process. Calculate the length.
	def_value (head, length, max);
	//The display function is embedded inside other functions like insertion & deletion.
	//To make display work, you must use a global pointer to store the list. Local pointer cannot be passed to the second function.
	//display(globalp);
	//count(globalp);
	
	//3.Insert at the beginning and end and at the 3rd place. Try both inserting after and before an element.
	printf("\n-------Insertion-------\n");
	insert_at_beg(head, 666);
	insert_at_end(head, 999);
	insert_after_given_node(head, 3, 12345);
	
	//4.Delete the first, last and 3rd element.
	printf("\n-------Deletion-------\n");
	del(head, 1);
	del(head, count(globalp));
	del(head, 3);
	printf("\nCongratulations! All functions are operating well.\nAfter these deletion steps we are back to the very primitive status.");
	
}




