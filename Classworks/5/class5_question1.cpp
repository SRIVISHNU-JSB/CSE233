#include <iostream>

using namespace std;

class university
{
//private:
	int regNumber;
	static int totalAdmission;
	
public:
	void admission()
	{
		cout<<"Enter the registration number of student: ";
		cin>>regNumber;
		totalAdmission++;
		cout<<"Total number of admissions are: "<<totalAdmission<<endl;
	}
	
};
int university::totalAdmission;

int main()
{
	university s1,s2,s3,s4,s5;
	s1.admission();
	s2.admission();
	s3.admission();
	s4.admission();
	s5.admission();
}
