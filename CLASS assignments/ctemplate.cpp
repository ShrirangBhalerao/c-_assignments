#include<iostream>
using namespace std;

template<class t>
class scc
{
	t a,b;
public:
	void getdata();
	void display();
};

template<class t>
void scc<t>::getdata()
{
	cout<<"\n\nENTER TWO NUMBERS ";
	cin>>a>>b;
}
template<class t>
void scc<t>::display()
{
	cout<<"\n\na= "<<a<<"b= "<<b;
}


int main()
{
	scc <int>c;
	scc <float>s;
	c.getdata();
	c.display();

	s.getdata();
	s.display();
}
