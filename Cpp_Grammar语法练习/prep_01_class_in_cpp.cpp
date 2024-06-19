/*
Tutorial from:
https://www.w3schools.com/cpp/cpp_classes.asp

class = attribute + method = static member + dynamic member
object = variable + function
e.g.
car : attribute = color, weight, price;
	function = drive
*/

#include <cstdio>
#include <cstdlib>
#include <string>

using namespace std; 
//N.B. string cannot be a/c unless one of the following is used:
//1. using namespace std + include string
//2. include string + std::string STRINGNAME
//ref:
//https://stackoverflow.com/questions/5527665/why-am-i-getting-string-does-not-name-a-type-error

class MyClass { // term class followed by object name
	public: //access specifier: can be used with MyClass.value
		int x;
		string myString;
	private://compiling failed due to myclass.value quote
		int y;
};

int main () {
	MyClass newname;
	newname.x = 1;
	//newname.y = 2; //cannot be compiled
	newname.myString = "Show the world my ambitions.";
	printf("int x = %d\n", newname.x);
	printf("myString = %s", newname.myString);
	system("pause");
	return 0;
}


