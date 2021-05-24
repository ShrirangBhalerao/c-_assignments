#include<iostream>
using namespace std;
inline int cube(int c)
{
return(c*c*c);
}

int main()
{
int a,p;
cout<<"ENTER THE VALUE OF  A"<<"\n";
cin>>a;
p=cube(a);
cout<< "THE CUBE  IS "<<p;
return 0;
}

