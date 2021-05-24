		                                                               //ROLL NO-8068
																				
          //TITLE-OPERATIONS ON COMPLEX NUMBERS USING OPERATOR OVERLOADING


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
	friend Complex operator+(Complex,Complex);  //OPERATOR OVERLOADING 
	friend Complex operator-(Complex,Complex);  //USING FRIEND FUNCTION.....
	Complex operator*(Complex);
	Complex operator/ (Complex);
	void display();
};


Complex  operator+(Complex z,Complex t)
{
	Complex r;
	r.x=t.x+z.x;
	r.y=t.y+z.y;
	return r;
}


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


Complex Complex::operator *(Complex z)
{
	Complex r;
	r.x=(z.x*x)-(z.y*y);
	r.y=(x*z.y)+(z.x*y);
	return r;
}


Complex Complex::operator /(Complex z)
{
	Complex r;
	r.x=((z.x*x)+(z.y*y))/(z.x*z.x+z.y*z.y);
	r.y=((x*z.y)-(z.x*y))/(z.x*z.x+z.y*z.y);
	return r;
}


int main()
{
	Complex c2,c3,c4,c5;                  //invokes default constructor.........
	int i,j,k,l,ch,m=0;
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
	do
	{
		cout<<"\nLIST OF OPERATIONS";
		cout<<"\n";
		cout<<"\n1.ADDITION OF COMPLEX NUMBER";
		cout<<"\n2.SUBTRACTION OF COMPLEX NUMBER";
		cout<<"\n3.MULTIPLICATION OF COMPLEX NUMBER";
		cout<<"\n4.DIVISION OF COMPLEX NUMBER";
		cout<<"\n\nENTER YOUR CHOICE ";
		cin>>ch;
		cout<<"\n";
		switch(ch)
		{
			case 1:{
					c2=c+c1;
					cout<<"\tADDITION OF 2 COMPLEX NUMBERS-";
					c2.display();
					cout<<"\n\n";
				}
			break;

			case 2:{
					c3=c1-c;
					cout<<"\tSUBTRACTION OF TWO COMPLEX NUMBERS- ";
					c3.display();
					cout<<"\n\n";	
				}
			break;

			case 3:{
					cout<<"\tMULTIPLICATION OF 2 COMPLEX NUMBERS-  ";
					c4=c*c1;
					c4.display();
					cout<<"\n\n";
				}
			break;

			case 4:{
					cout<<"\tDIVISION OF 2 COMPLEX NUMBERS- ";
					c5=c/c1;
					c5.display();
					cout<<"\n\n";
				}
			break;

			default:cout<<"\tINVALID OPTION";
			break;
		}
	cout<<"WOULD U LIKE TO PERFORM ANY OTHER OPERATION (1/0) ";
	cin>>m;
	cout<<"\n";
	}while(m==1);
	cout<<"\t\t\tTHANK-YOU!!";
	cout<<"\n";
	return 0;
}




