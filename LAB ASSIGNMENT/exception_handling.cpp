#include<iostream>
using namespace std;

class num
{
private:
	double num1,num2,result;
public:
	void getdata();
	void divide();
};

void num::getdata()                       //FUNCTION TO INPUT NUMBERS
{
	cout<<"\n\nENTER THE NUMBERS  ";
	cin>>num1>>num2;
}

void num::divide()                    //FUNCTION TO DIVIDE NUMBERS
{
	try
	{
		if(num2!=0)
		{
			result=num1/num2;
			cout<<"\n\tDIVISION OF TWO NUMBERS -  "<<result;
		}
		else
		{
			throw result;
		}
	}
	catch(...)
	{
		cout<<"\n\n\tDIVISION NOT POSSIBLE";
	}
}


int main()
{
	num n1;
	int a;
	while(1)
	{
		n1.getdata();
		n1.divide();
		cout<<"\n\n\tCONTINUE (1/0) ";
		cin>>a;
		if(a==0)
			break;
	}			
	return 0;
}

