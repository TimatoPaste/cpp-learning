//imports header with class and instantiates objects

#include <iostream>//imports cout, cin, endl, etc
#include "ye.h"//imports another file with class and method definitions, kind of like packages in java
using namespace std;
	int main(){
		apple haha(2);//new instance of class object, calls constructor
		cout<<haha.getHaha()<<endl;//using accessor method from a class
		hello();//using "inherited" method from ye.h
		cout<<endl;
		system("echo hi");//commands in cmd
		cout<<hi<<endl;
		system("pause");
		return 0;
	}

