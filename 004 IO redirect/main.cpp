//notepad++ shortcuts to know:
//ctrl+l deletes current line
//ctrl+alt+shift+enter makes line below current

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int main(){
	//fstream is read + write
	//ifstream is just read
	//ofstream is just write
	fstream file;
	//gets output stream from file
	file.open("sample.txt",ios::out);
	string line;
	
	//terminal input and output streams - pointer variable that points to the streams
	
	//save buffer values
	
	/*rdbuf() returns pointer to the buffer of the stream for reading. If you add a stream in the parameters, 
	it will redirect the object's stream to the inputted stream*/
	streambuf* cInBuf = cin.ios::rdbuf();
	streambuf* cOutBuf = cout.ios::rdbuf();
	
	streambuf* fileBuf = file.ios::rdbuf();
	
	//set cout buffer to file
	cout.std::ios::rdbuf(fileBuf);
	
	cout<<"test thing please"<<endl;
	
	//set cout buffer back
	cout.ios::rdbuf(cOutBuf);
	
	cout<<"ran";
	
	
	file.close();
	return 0;
}