#include<iostream>
using namespace std;

class value
{
private:
int x,y;
public:
value();
value(int);
value(int ,int);
void display();
};

value::value()
{
x=0,y=0;
}

value::value(int a)
{
x=a;
}

value::value(int a,int b)
{
x=a;
y=b;
}

void value::display()
{
cout<<"\nx = "<<x;
cout<<"\ny = "<<y;
cout<<"\n\n";
}

int main()
{
value v;
v.display();
value v1(25);
v1.display();
value v2(10,20);
v2.display();

}




