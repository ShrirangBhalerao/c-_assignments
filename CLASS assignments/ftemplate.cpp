#include<iostream>
using namespace std;

template<class a>a add(a v,a b)
{
a c;
c=v+b;
cout<<"\n\nsum = "<<c;
}

int main()
{
add(10,20);
add(15.3,67.09);
add(10.4444,23.5);
return 0;
}


