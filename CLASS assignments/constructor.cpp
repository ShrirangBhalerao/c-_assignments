#include<iostream>
using namespace std;

class number
{
private:
int num1,num2,num3;
public:
number();                    //default constructor
number(int ,int);           //parameterized constructor
number(number &a);          //copy constructor  
/*~number()
{
cout<<"\nDESTRUCTOR CALLED";
}*/
                    //destructor
void display();                
};

number::number()
{
num1=num2=num3=0;
}

number::number(int x,int y)
{
num1=x;
num2=y;
}

number::number(number &a)
{
num1=a.num1;
num2=a.num2;
num3=a.num1;

}


void number::display()
{
cout<<"\nnum1= "<<num1;
cout<<"\nnum2= "<<num2;
cout<<"\nnum3= "<<num3;
cout<<"\n";
}

int main()
{
number n;
cout<<"\nDEFAULT CONSTRUCTOR ";
n.display();
number n2(1,2);
number n1(n2);
cout<<"\nPARAMETRIZED CONSTRUCTOR ";
n2.display();
cout<<"\nCOPY CONSTRUCTOR ";
n1.display();
}


