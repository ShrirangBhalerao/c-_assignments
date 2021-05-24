#include<iostream>
using namespace std;

class number
{
private:
int x;
static int cnt;
public:
void getdata(int y);
static void accept();
void display();
};

int number::cnt=0;
void number:: getdata(int y)
{
x=y;
cnt++;
}

void number::accept()
{
cnt++;
//x=1;
}

void number::display()
{
cout<<"\nx= "<<x;
cout<<"\ncnt= "<<cnt;
}

int main()
{
int p;
number n;
cout<<"Enter any number  ";
cin>>p;
number::accept();
n.getdata(p);
n.accept();
n.display();
n.getdata(25);
n.accept();
n.display();
}



