//tests pointers to pass by reference

#include <string>
#include <iostream>
#include <fstream>

using namespace std;
int main(){
	
	/*
	If something takes a pointer type like funtion(int* a), can either put in a pointer, or the address
	of a normal type like if int b = 10, we write function(&b). But if int* b = [address], we write function(b)
	
	
	1. a::b is only used if b is a member of the class/namespace b; a::b
	gets the member b of class a
	
	2. a.b is only used if b is a member of the object a; a.b gets member
	b from object a
	
	3. a -> b is shorthand for (*a).b, (dereferencing a pointer [getting value], then getting
	member of the object it points to)
	
	*/
	
	//quick note: namespace stores variables and functions, but no object whereas classes can be instantiated as objects
	
	//make sure to cast because quotes default to character
	// -> is the same as using . when calling functions or parts of structure
	//&variableName will return the address of the variable's data
	string apple = "banana";
	
	//type* = &thing; makes a pointer that points to the address of thing
	string* banana = &apple;
	
	//*pointerName dereferences gets value at address that is being pointed to
	cout<<*banana<<endl;
	//reassigns value
	apple = string("hi");
	cout<<apple;



	return 0;
}