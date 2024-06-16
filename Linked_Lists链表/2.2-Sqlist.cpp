// The reason why Mandarin comments are added to the codes is,
// in 408 examinations the reviewers usually evaluate your algo with the help of comments.
// So they are located exactly to the right places:)


#include <stdio.h> 
#include <iostream>
#include <stdlib.h>
using namespace std;

#define MaxSize 10  //������󳤶� 

//��һ��������˳��� 
typedef struct{
	long shuzu [MaxSize]; //�þ�̬���������� 
	//Hint: In the Chinese textbooks, professors like to boast by 
	//using ElemType instead of feasible characters in cpp.
	//Replacing ElemType by either int or long will help you out :)
	int length; //˳���ǰ���� 
}shunxubiao; //����ADTΪ˳���sequence list 
//ʵ���Ƕ���һ���ṹ���������к��ĵ�������shuzu��Ҳ�������ϵ�data��
//�������ǳ���length��maxsize��
//�����õ���SqList���ҹ���ĳ�ƴ��������Ӱ�졭����Ϊȫ���й����Լ���� 
 

//ADT������֪ʶ�㣺���������ң�����

//��������ʼ��˳��� 
void InitList(shunxubiao &L){ //�����Ƕ�����˳�����в����� 
	for (int i=0; i<MaxSize; i++)
		L.shuzu[i] = 0; //��ֻ��˳�����������������Ը� 
	L.length = 0; //��˳����ʼ�������ó�0 
}

//�������������˵�Ľ�׳�Ĵ��� 
bool ListInsert (shunxubiao &L, int i, int e) { //i��e���û����������Լ����õ� 
	//�����ֲ��˲��������Σ�
	//1.����Ȼ���Ե�1����ǰ���룬�������һ������һ��֮����롣�޷�ʵ����β��� 
	bool a = true;
	if (i<1 ||i>L.length +1) 
		printf("\nfalse type 1\n");
		a = false;
	//2.�ϸ�һ�㣬��Ҫ��̬���䣬�趨�ڴ��������ޣ��޷����� 
	if (L.length >= MaxSize)
		printf("\nfalse type 2\n");
		a = false;
	for (int j = L.length; j >= i; j --)
		L.shuzu [j] = L.shuzu [j-1]; //����������һ����������
	L.shuzu [i - 1] = e;
	L.length ++;
	printf("The bool value is %d\n", a); //��ʾ�����������и�bug����ʹ�����⣬Ҳ��Ӱ������+���� 
	return a;	//������������a�����Լ����ģ� Ŀ���ǿ���Return�ĵ�����ɶ 
}

void CheckVal (shunxubiao &L) {
	for (int i = 0; i < L.length; i ++)
		printf("shuzu [%d] = %d\n", i, L.shuzu [i]);
}

/*��ʵ������д���������������򵥵�  
void ListInsert (shunxubiao &L, int i, int e) {
	//��L��i������Ԫ��e
	for (int j = L.length; j >= i; j--)  //����i��֮���Ԫ�غ��� 
	//������Ϊʲô��>=i:ÿһ�����ǰ���Ȼ���Եĵ�j��Ԫ����һ�κ��Ʋ�������length��ʼ����ǰ��ԭ����i��Ҳ��Ҫ��������һ�Ρ� 
		L.shuzu [j] = L.shuzu [j-1];
	L.shuzu [i-1] = e;
	L.length ++;
}
*/

//��д�򵥰汾�Ĵ��� 
void ListDelete (shunxubiao &L, int i) {
	//������㷨�� 
	//��һ������ȥ��Ҫ�ĵ�i����
	//�ڶ������ӵ�i+1��Ԫ�ؿ�ʼ������ 
	//�������㷨�� 
	//����ɾ�ĸ�ֵ��һ���±����������ڲ������Ȼ��ǰ��
	//�ܽ᣺��δ������д����ģ��и��޴��bug��ʵ��������һ��Ԫ��û�취ȥ����ֻ��length����-1�ˣ���������ĳ��Ȼ�����ô��
	//L.shuzu [i] = 0;
	//��Ӧ�����ˣ���ʵ��������Ҫ�������������������ֱ�����ƾ���
	for (int j = i; j <= L.length; j ++)  //��Ȼ������ţ����ԼӵȺ� 
		L.shuzu [j - 1] = L.shuzu [j];
	L.length --;
	//��length��Ϊ�˷������������ĺ�������ѭ��ģ�� 
	 
}

void LocateElem (shunxubiao &L, int x) {
	//the inputted x represents the element we want to search and find.
	bool a = false;
	for (int i = 1; i <= L.length; i ++) {//��Ȼ������ţ�Ҫ�ӵȺ� 
		if (L.shuzu [i - 1] == x) {
			a = true;
			printf("\nThe location of the number %d is %d in the sequential list.", x, i);
		}
	}
	if (a == false)
		printf("\nNot found.");
}

 
//������ĺ����������涨�� 
int main (){
	//1.����˳���
	shunxubiao L; 
	//���������￴�£��������ʼ����˳���ʲô�� 
	printf("The sequential list looks like this at the very beginning:\n%s\nIts address is:%p", L, L);
	//When delivering the address with %p, it's not necessary to set & before the variable.
	InitList (L); //��ʼ��˳���
	//Notice that cout doesn't work for our customized type.
	//cout<<L<<endl;
	//But printf works in both giving us the list and its address.
	//��ʼ����Ľ��������Ҳ��һ�£� 
	printf("\nAfter initialisation it looks like this:\n%s\nIts address is:%p\n", L, L);
	
	//2.����������Ԫ��
	printf("Create a real sequential list of length 5.\nAssign the default values.\n");
	L.length = 10; //��ʼ���ܿӣ��ѳ��ȸĳ�0�ˣ��������в������൱��ûִ�С� 
	for (int i = 0; i < L.length; i ++) 
		L.shuzu [i] = i + 1;
	CheckVal (L);
	printf("Insert the value 999 before the 1st position.");
	ListInsert (L, 1, 999);
	CheckVal (L); 
	//�Ӵ���������ݿ��Կ���һ�����⣺��󳤶�10�����ǿ��Դ�s[0]��s[10]�����11������Ϊ�ο��Ըĳ��ȣ� 
	
	//3.ɾ��Ԫ�� 
	printf("Remove the value 5 from the 6th position denoted as shuuzu[5].\n");
	ListDelete (L, 6); 
	//�ҵ��뷨����ȥ�����Ѻ����������ǰ����������Ҫɾ�ĵ�i�������ж�˭����
	 //ʵ��Ԥ�ڳɹ���a0,,,a9��10������һ��ʼ��1,2,...10
	 //�ڱ�ͷ����999�󣬹�11��
	 //��������ɾ����6��a5��Ӧ����4����ֱ�Ӹ�6
	CheckVal (L);
	
	//4.����
	LocateElem (L, 7); //��һ���Ѿ�ɾ���˵�6����5����������±�Ӧ����6��������Ȼ���Ե���������7 
	//�Ż����룬���������ظ����ֵ�CheckVal����Ƕ���º������� 
	
	
	//5.���� 
	
	return 0; 
}


/*The result of initialisation is very surprising:
The sequential list looks like this at the very beginning:

Its address is:00000000006FFDC0
After initialisation it looks like this:

Its address is:00000000006FFDF0
1.Something exists in the empty new array/list.
2.The memory location is changed!

*/

/*Let's see the result of this whole series of codes.
The sequential list looks like this at the very beginning:

Its address is:00000000006FFDC0
After initialisation it looks like this:

Its address is:00000000006FFDF0
Create a real sequential list of length 5.
Assign the default values.
shuzu [0] = 1
shuzu [1] = 2
shuzu [2] = 3
shuzu [3] = 4
shuzu [4] = 5
shuzu [5] = 6
shuzu [6] = 7
shuzu [7] = 8
shuzu [8] = 9
shuzu [9] = 10
Insert the value 999 before the 1st position.
false type 2
The bool value is 0
shuzu [0] = 999
shuzu [1] = 1
shuzu [2] = 2
shuzu [3] = 3
shuzu [4] = 4
shuzu [5] = 5
shuzu [6] = 6
shuzu [7] = 7
shuzu [8] = 8
shuzu [9] = 9
shuzu [10] = 11
Remove the value 5 from the 6th position denoted as shuuzu[5].
shuzu [0] = 999
shuzu [1] = 1
shuzu [2] = 2
shuzu [3] = 3
shuzu [4] = 4
shuzu [5] = 6
shuzu [6] = 7
shuzu [7] = 8
shuzu [8] = 9

The location of the number 7 is 7 in the sequential list.

*/

