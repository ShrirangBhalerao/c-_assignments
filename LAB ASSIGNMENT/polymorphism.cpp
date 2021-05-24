#include<iostream>
using namespace std;

class shape                          //function to input dimensions of figure
{
protected:
	double s1,s2;
public:
void input()
{
	cout<<"\nENTER THE DIMENSIONS OF FIGURE (in cms)";
	cin>>s1>>s2;
	while(s1<=0||s2<=0)
	{
		cout<<"INVALID DIMENSIONS ENTER AGAIN";
		cin>>s1>>s2;
	}
}
virtual double compute_area()=0;               //pure virtual function
};


class rectangle:public shape
{
public:
double compute_area()                         //AREA OF RECTANGLE 
{
	return (s1*s2);
}
};


class triangle:public shape
{
public:
double compute_area()                       //AREA OF TRIANGLE
{
	return  (0.5*s1*s2);
}
};


int main()
{
	int a,b;
	shape *s;
	rectangle r;
	triangle t;
	while(1)
	{
		cout<<"\n\n1.AREA OF RECTANGLE ";
		cout<<"\n\n2.AREA OF TRIANGLE ";
		cout<<"\n\n\tENTER YOUR CHOICE ";
		cin>>a;

		switch(a)
		{
			case 1:
				s=&r;
				s->input();
				cout<<"\n\n\tAREA OF RECTANGLE IS "<<s->compute_area()<<" cm^2";
			break;
			case 2: 
				s=&t;
				s->input();
				cout<<"\n\n\tAREA OF TRIANGLE IS  "<<s->compute_area()<<" cm^2";
			break;
			default: cout<<"INVALID OPTION ";
			break;
		}
		cout<<"\n\n\tCONTINUE ?(1/0)";
		cin>>b;
		if(b==0)
			break;
	}
}

