#include<iostream>
using namespace std;
class Complex
{
	private:
		float x,y;
	public:
		Complex()                            //DEFAULT CONSTRUCTOR.........
		{
			x=0,y=0;
		}
		Complex(int real ,int img )        //PARAMETERIZED CONSTRUCTOR......
		{
			x=real;
			y=img;
		}
	
	Complex operator/(Complex);
	void display();
};

Complex Complex::operator /(Complex z)
{
	Complex r;
	r.x=((z.x*x)+(z.y*y))/(z.x*z.x+z.y*z.y);
	r.y=((x*z.y)-(z.x*y))/(z.x*z.x+z.y*z.y);
	return r;
}


void Complex::display()                       //DISPLAY FUNCTION.........
{
	cout<<"\t"<<x<<"+"<<"("<<y<<")"<<"i";
}


int main()
{
	Complex c2,c3;                  //invokes default constructor.........
	int i,j,k,l;
	cout<<"ENTER REAL AND IMAGINARY PART OF COMPLEX NUMBER  ";
	cin>>i>>j;
	cout<<"\n";
	Complex c(i,j);
	cout<<"ENTER REAL AND IMAGINARY PART OF COMPLEX NUMBER  ";
	cin>>k>>l;
	Complex c1(k,l);
	cout<<"\n";
	cout<<"FIRST COMPLEX NUMBER- ";
	c.display();
	cout<<"\n";
	cout<<"SECOND COMPLEX NUMBER-";
	c1.display();
	cout<<"\n";		
	cout<<"\tDIVISION OF 2 COMPLEX NUMBERS-  ";
	c3=c/c1;
	c3.display();
	cout<<"\n\n";
}
			



