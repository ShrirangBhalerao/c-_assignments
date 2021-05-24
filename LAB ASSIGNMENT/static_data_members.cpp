#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;


class Book
{
private:
	int b_id;
	static int st;               //STATIC DATA MEMBERS
	static int ut;
	char title[30];
	char n_author[30];
	char n_publisher[30];
	int price;
	int b_stock;
public:
	void getdata(int );
	int search(Book b1[],int a);
	void display();
	int add(Book b1[],int a);
	void purchase(Book b1[],int a);
	void record(Book b1[],int a);
	void update(Book b1[],int a);
};

int Book::st=0;              //INITIALIZATION OF STATIC DATA MEMBERS
int Book::ut=0;


void  Book::getdata(int i) 
{
	int x;
	b_id=i+100;
	cout<<"\nBook id = "<<b_id; 
	cout<<"\n\nEnter the title of book ";
	cin>>title;
	cout<<"\nEnter the Author's name ";
	cin>>n_author;
	
	cout<<"\nEnter the Publisher's name ";
	cin>>n_publisher;
	
	cout<<"\nEnter the stock of the book ";
	cin>>b_stock;
	cout<<"\nEnter the price of the book ";
	cin>>price;
		
}


void Book:: display()              //DISPLAY FUNCTION
{
	cout<<"\n\tBOOK ID-"<<b_id;
	cout<<"\n\n\tTITLE - "<<title;
	cout<<"\n\n\tAUTHOR - "<<n_author;
	cout<<"\n\n\tPUBLIHER- "<<n_publisher;
	cout<<"\n\n\tPRICE- "<<price;
	cout<<"\n\n\tSTOCK- "<<b_stock;
	cout<<"\n";
}


int  Book::search(Book b1[],int a)              //SEARCH A BOOK
{
	int x,b=0;
	char *s;
	s=new char[20];
	cout<<"\nENTER THE NAME OF BOOK  ";
	cin>>s;
	cout<<"\n";
	for(x=0;x<a;x++)
	{
		if(strcmp(b1[x].title,s)==0)
		{
			b1[x].display();
			b=1;
			return x;
			break;
		}
	}
	if(b==0)
	{
		cout<<"\n\tBOOK NOT FOUND";
		return 1000;
	}	
}


int Book::add(Book b1[],int a)            //ADD AN ENTRY
{
	b1[a].getdata(a);
	a++;
	return a;
}


void Book::purchase(Book b1[],int a)     //FUNCTION TO PURCHASE A BOOK
{
	int x,z,bill=0;
	char v='y';
	char q;
	do
	{
		cout<<"\n\tLIST OF BOOKS \n";
		cout<<"\nBOOK ID"<<"\t\t"<<"TITLE"<<"\t\t  "<<"PRICE";
		cout<<"\n\n";
		for(x=0;x<a;x++)
		{
			cout<<b1[x].b_id<<"\t    "<<b1[x].title<<"\t\t "<<b1[x].price;
			cout<<"\n";
		}
		if(q!='y')
		{
			cout<<"\n\nWOULD U LIKE TO PURCHASE ANY OF THESE BOOKS (y/n) \n ";
			cin>>v;
		}
		if(v=='y')
		{
			cout<<"\nENTER BOOK ID  ";
			cin>>z;
			for(x=0;x<a;x++)
			{
				if(b1[x].b_id==z)
				{
					cout<<"\n"<<b1[x].title<<"  PURCHASED\n";
					cout<<"\n\tSUCCESSFUL TRANSCATION";
					st++;
					b1[x].b_stock--;
					bill=bill+b1[x].price;
				}
			}			
		}
		if(v=='y')
		{	
			cout<<"\n\tWOULD U LIKE TO PURCHASE ANY OTHER BOOK (y/n)  ";
			cin>>q;
			cout<<"\n";
		}
	}while(q=='y');
	if(v!='y')
	{
		cout<<"\n\tUNSUCCESSFUL TRANSACTION\n";
		ut++;
	}
	if(bill!=0)
		cout<<"\n\tBILL = Rs."<<bill;
}


void Book::record(Book b1[],int a)    //RECORD OF TRANSACTIONS
{
	cout<<"\n\tSUCCESSFUL TRANSACTIONS-"<<b1[a].st;
	cout<<"\n\tUNUCCESSFUL TRANSACTIONS- "<<b1[a].ut;
	cout<<"\n";
}


void Book::update(Book b1[],int a)             //UPDATION OF DATA
{
	Book c;
	int ch,n;
	char g='y';
	do
	{
		n=c.search(b1,a);
		cout<<"\n1.STOCK ";
		cout<<"\n2.PRICE";
		cout<<"\n3.PUBLISHER";
		cout<<"\n\tWHAT WOULD U LIKE TO UPDATE ";
		cin>>ch;
		switch(ch)
		{
			case 1:{
					cout<<"\nENTER NEW STOCK  ";
					cin>>b1[n].b_stock; 
					cout<<"\n\tSTOCK UPDATED ";
				}
			break;
			case 2:{
					cout<<"\nENTER NEW PRICE  ";
					cin>>b1[n].price;
					cout<<"\n\tPRICE UPDATED ";
				}
			break;
			case 3:{
					cout<<"\nENTER NEW PUBLISHER'S NAME  ";
					cin>>b1[n].n_publisher;
					cout<<"\n\tPUBLISHER'S NAME UPDATED ";
				}
			break;
		}
		cout<<"\n\tWOULD U LIKE TO UPDATE ANY BOOK (y/n)";
		cin>>g;
	}while(g=='y');
}


int main()               //MAIN FUNCTION
{
	int a,i,j,d,ch,n,o;
	char s='y';
	
	cout<<"\nENTER THE COLLECTION OF LIBRARY ";
	cin>>a;
	if(a<=0)
	{
		cout<<"\n\tNO BOOKS AVAILABLE";
		exit (0);
	}
	else
	{
		Book b1[a],v;
		for(i=0;i<a;i++)
		{
			b1[i].getdata(i);
		}
		do
		{
			cout<<"\n\tLIST OF OPERATIONS";
			cout<<"\n\n1.ADD A NEW BOOK";
			cout<<"\n\n2.UPDATE";
			cout<<"\n\n3.SEARCH A BOOK";
			cout<<"\n\n4.PURCHASE A BOOK";
			cout<<"\n\n5.RECORD";
			cout<<"\n\n\tENTER YOUR OPTION ";
			cin>>ch;
			switch(ch)
			{
				case 1:a=v.add(b1,a);
				break;
				case 2:v.update(b1,a);
				break;
				case 3:n=v.search(b1,a);
				break;
				case 4:v.purchase(b1,a);
				break;
				case 5:v.record(b1,a);
				break;
			}
			cout<<"\n\tWOULD YOU LIKE TO CONTINUE (y/n) ";
			cin>>s;
			cout<<"\n";
		}while(s=='y');
		cout<<"\n\t\t\tTHANK-YOU!!";
		
	}
	
}





