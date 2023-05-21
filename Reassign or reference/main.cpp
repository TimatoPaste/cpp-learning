#include <string>
#include <iostream>

using namespace std;
int main(){
	int banana = 10;
	int apple = 20;
	//passes by value
	apple = banana;
	banana = 50;
	cout<<apple;
	
	//passes by reference
	int grape = 100;
	int* juice = &(grape+1);
	grape = 200;
	cout<<*juice;
	
	
	return 0;
}