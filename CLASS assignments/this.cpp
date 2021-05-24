#include<iostream>
using namespace std;

class student
{
private:
int value;
public:
student();
void display(int value);
};


student::student()
{
value=20;
}

void student::display(int value)
{
this->value=value;
cout<<"ANS 1 = "<<this->value;
cout<<"ANS = "<<value;
}

int main()
{
student s;
s.display(10);
}


