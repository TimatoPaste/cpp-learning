//files that end in .h are like files that create a class that defines functions that are imported by other cpp files for use
//import using #include 
#include <iostream>

class apple{
	private:
		int haha;
	public:
		
		apple(int hi){
			haha = hi;
		}
		int getHaha(){
			return haha;
		}
};
void hello(){
	std::cout << "hello";
}