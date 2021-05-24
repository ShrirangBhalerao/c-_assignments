#include<iostream>
using namespace std;
int main()
{
int *p,*q,*add,*sub,*mul,*div;
p=new int(25);
q=new int(25);
*add=*p+*q;
*sub=*p-*q;
*mul=*p * *q;
*div=*p / *q;
cout<<"Addition =  "<<*add;
cout<<"Subtraction =  "<<*sub;
cout<<"Multiplication =  "<<*mul;
cout<<"Division =  "<<*div;


} 
