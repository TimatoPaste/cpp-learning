#include <string>

//initialize all values after creating the object because you cannot declare without initializing if there is a constructor
//if no constructor, can declare, then initialize attributes after

/*
can do this
class Student{
	public:
		std::string fName;
		std::string lName;
		double pGrade;
		std::string lGrade;
};
*/

//or this, public by default, struct is technically just classes without 

struct Student{
	std::string fName;
	std::string lName;
	double pGrade;
	
	Student(){
		fName = "EMPTY";
		lName = "EMPTY";
		pGrade = -1;
	}
};