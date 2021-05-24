#include<iostream>
using namespace std;

class student
{
private:
int x,y;
public:
 void accept();
friend void display(student t);
};

void student ::accept()
{
cout<<"Enter the numbers ";
cin>>x>>y;
}

void display(student t)
{
cout<<"x= "<<t.x;
cout<<"y= "<<t.y;
}

int main()
{
student s;
s.accept();
display(s);
return 0;
}
