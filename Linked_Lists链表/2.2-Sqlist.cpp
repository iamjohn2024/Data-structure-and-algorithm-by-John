// The reason why Mandarin comments are added to the codes is,
// in 408 examinations the reviewers usually evaluate your algo with the help of comments.
// So they are located exactly to the right places:)


#include <stdio.h> 
#include <iostream>
#include <stdlib.h>
using namespace std;

#define MaxSize 10  //定义最大长度 

//第一步：创建顺序表 
typedef struct{
	long shuzu [MaxSize]; //用静态数组存放数据 
	//Hint: In the Chinese textbooks, professors like to boast by 
	//using ElemType instead of feasible characters in cpp.
	//Replacing ElemType by either int or long will help you out :)
	int length; //顺序表当前长度 
}shunxubiao; //定义ADT为顺序表sequence list 
//实质是定义一个结构变量，其中核心的是数组shuzu，也就是书上的data；
//辅助的是长度length和maxsize。
//书上用的是SqList，我故意改成拼音，并不影响……因为全是中国人自己编的 
 

//ADT的三个知识点：创建，查找，插入

//函数：初始化顺序表 
void InitList(shunxubiao &L){ //函数是对整个顺序表进行操作的 
	for (int i=0; i<MaxSize; i++)
		L.shuzu[i] = 0; //但只有顺序表里的数组有数可以改 
	L.length = 0; //将顺序表初始长度设置成0 
}

//下面这个是王道说的健壮的代码 
bool ListInsert (shunxubiao &L, int i, int e) { //i和e是用户在主程序自己设置的 
	//有两种不宜操作的情形：
	//1.在自然语言第1个数前插入，或者最后一个数隔一个之后插入。无法实现首尾相接 
	bool a = true;
	if (i<1 ||i>L.length +1) 
		printf("\nfalse type 1\n");
		a = false;
	//2.严格一点，不要动态分配，设定内存数量有限，无法插入 
	if (L.length >= MaxSize)
		printf("\nfalse type 2\n");
		a = false;
	for (int j = L.length; j >= i; j --)
		L.shuzu [j] = L.shuzu [j-1]; //左边整体完成一次右移运算
	L.shuzu [i - 1] = e;
	L.length ++;
	printf("The bool value is %d\n", a); //提示；书上这里有个bug，即使有问题，也不影响扩列+右移 
	return a;	//这里的输出布尔a是我自己定的， 目的是看下Return的到底是啥 
}

void CheckVal (shunxubiao &L) {
	for (int i = 0; i < L.length; i ++)
		printf("shuzu [%d] = %d\n", i, L.shuzu [i]);
}

/*其实有两种写法，下面这个是最简单的  
void ListInsert (shunxubiao &L, int i, int e) {
	//在L的i处插入元素e
	for (int j = L.length; j >= i; j--)  //将第i个之后的元素后移 
	//补充下为什么是>=i:每一步都是把自然语言的第j个元素做一次后移操作。从length开始，往前，原来第i个也需要这样操作一次。 
		L.shuzu [j] = L.shuzu [j-1];
	L.shuzu [i-1] = e;
	L.length ++;
}
*/

//先写简单版本的代码 
void ListDelete (shunxubiao &L, int i) {
	//最初的算法： 
	//第一步：舍去不要的第i个数
	//第二步：从第i+1个元素开始，左移 
	//王道的算法： 
	//将被删的赋值给一个新变量（包含在参数里），然后前移
	//总结：这段代码就是写着玩的，有个巨大的bug：实际上最后的一个元素没办法去掉，只是length变量-1了，但是数组的长度还是那么长
	//L.shuzu [i] = 0;
	//反应过来了，其实根本不需要考虑这个被放弃的数，直接左移就行
	for (int j = i; j <= L.length; j ++)  //自然语言序号，所以加等号 
		L.shuzu [j - 1] = L.shuzu [j];
	L.length --;
	//改length是为了方便主程序后面的函数调用循环模块 
	 
}

void LocateElem (shunxubiao &L, int x) {
	//the inputted x represents the element we want to search and find.
	bool a = false;
	for (int i = 1; i <= L.length; i ++) {//自然语言序号，要加等号 
		if (L.shuzu [i - 1] == x) {
			a = true;
			printf("\nThe location of the number %d is %d in the sequential list.", x, i);
		}
	}
	if (a == false)
		printf("\nNot found.");
}

 
//主程序的函数已在上面定义 
int main (){
	//1.创建顺序表
	shunxubiao L; 
	//不妨在这里看下，如果不初始化，顺序表长什么样 
	printf("The sequential list looks like this at the very beginning:\n%s\nIts address is:%p", L, L);
	//When delivering the address with %p, it's not necessary to set & before the variable.
	InitList (L); //初始化顺序表
	//Notice that cout doesn't work for our customized type.
	//cout<<L<<endl;
	//But printf works in both giving us the list and its address.
	//初始化后的结果，我们也看一下： 
	printf("\nAfter initialisation it looks like this:\n%s\nIts address is:%p\n", L, L);
	
	//2.接下来插入元素
	printf("Create a real sequential list of length 5.\nAssign the default values.\n");
	L.length = 10; //初始化很坑，把长度改成0了，所以所有操作都相当于没执行。 
	for (int i = 0; i < L.length; i ++) 
		L.shuzu [i] = i + 1;
	CheckVal (L);
	printf("Insert the value 999 before the 1st position.");
	ListInsert (L, 1, 999);
	CheckVal (L); 
	//从打出来的数据可以看出一个问题：最大长度10，但是可以从s[0]到s[10]打出来11个数！为何可以改长度？ 
	
	//3.删除元素 
	printf("Remove the value 5 from the 6th position denoted as shuuzu[5].\n");
	ListDelete (L, 6); 
	//我的想法：先去掉。把后面的依次往前。参数就是要删的第i个，还有对谁操作
	 //实验预期成果：a0,,,a9共10个数，一开始是1,2,...10
	 //在表头插入999后，共11个
	 //我们现在删掉第6个a5，应该是4后面直接跟6
	CheckVal (L);
	
	//4.查找
	LocateElem (L, 7); //上一步已经删掉了第6个数5，如果返回下标应该是6，返回自然语言的序数就是7 
	//优化代码，把主程序重复出现的CheckVal函数嵌入新函数里面 
	
	
	//5.排序 
	
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

