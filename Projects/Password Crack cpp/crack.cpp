#include "methods.h"
#include "pass.h"
#include "stopwatch.h"
#include <iostream>
#include <vector>
#include <string>


using namespace std;

//password will start as ""

int main(){
	string command;
	cout<<"Command?"<<endl;
	cin>>command;
	cout<<endl<<endl;
	string program;
	cout<<"Program?"<<endl;
	cin>>program;
	cout<<endl<<endl;
	cout<<"Cracking..."<<endl;
	stopwatch time = stopwatch();
	time.start();
	vector<string> strings = {"0","1","2","3","4","5","6","7","8","9","a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t",
	"u","v","w","x","y","z","A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
	password apple = password(strings);
	while(exec("echo "+apple.update()+"|"+"java pw"/*command+" "+program*/).find(" correct") == string::npos){
		cout<<apple.update()<<endl;
		apple.up();
	}
	time.stop();
	cout<<"The password is: "+apple.update()<<endl;
	cout<<"Took "<<time.getDurSec()<<" seconds!"<<endl;
	system("pause");
	return 0;
}



