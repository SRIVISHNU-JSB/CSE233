// finding area of circle using friend function

#include<iostream>
using namespace std;

class area{
	int r;
	float pi;
	public:
	void getdata(){
		cout<<"enter radius: ";
		cin>>r;
	}
	friend void aoc(area);
};
void aoc(area obj){
	obj.pi = 3.14;
	float ans;
	ans = obj.pi * obj.r * obj.r;
	cout<<"area  = "<<ans;
}

main(){
	area ob;
	ob.getdata();
	aoc(ob);
}
