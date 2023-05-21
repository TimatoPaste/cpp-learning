#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int main(){
	fstream apple;
	// .open(String fileName, mode)
	//will create new file if the file does not exist yet
	apple.open("sample.txt",ios::app);
	
	for(int a = 0;a<100;a++){
		//when appending strings, use +, but when printing numbers and strings
		//connect them with more <<
		apple<<"nope"<<a<<endl;
	}
	apple.close();
	return 0;
}