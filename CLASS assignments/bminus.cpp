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
	friend Complex operator-(Complex,Complex);  //USING FRIEND FUNCTION.....
	void display();
};

Complex  operator-(Complex z,Complex t)
{
	Complex r;
	r.x=t.x-z.x;
	r.y=t.y-z.y;
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
	c3=c1-c;
	cout<<"\tSUBTRACTION OF TWO COMPLEX NUMBERS- ";
	c3.display();
	cout<<"\n\n";
}



