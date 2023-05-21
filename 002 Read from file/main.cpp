//reads from file

#include <string>
#include <fstream>
#include <iostream>

using namespace std;
int main(){
	string apple;
	fstream file;
	file.open("sample.txt",ios::in);
	
	//goes by line, but if I use file.get(), goes by character
	while(file.good()){
		//.good() returns boolean false if eof
		file>>apple;
		cout<<apple<<"\n";
	}
	

}