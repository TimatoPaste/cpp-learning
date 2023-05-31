#include <string>

using namespace std;
class Student{
	public:
		string fName;
		string lName;
		double pGrade;
		string lGrade;
		
	public:
		Student(string fNameIn,string lNameIn,double pGradeIn){
			fName = fNameIn;
			lName = lNameIn;
			pGrade = pGradeIn;
		}
		
		Student(string fNameIn,string lNameIn,string lGradeIn){
			fName = fNameIn;
			lName = lNameIn;
			lGrade = lGradeIn;
		}
};