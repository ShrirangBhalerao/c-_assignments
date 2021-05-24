#include<iostream>
#include<string.h>
using namespace std;

class number
{
private:
char *s;
char c[10];
public:
void getdata();
void display();
};

void number::getdata()
{
int a=0;
cout<<"ENTER NAME  ";
cin>>c;

a=strlen(c);
cout<<a<<"\n\n";
s=new char[a+1];
strcpy(s,c);

}

void number::display()
{
cout<<"s= "<<s;
cout<<"l= "<<strlen(s);
delete s;
}

int main()
{
number n;
n.getdata();
n.display();
}
