#include<iostream>
#include<string.h>
using namespace std;

class personalr
{
protected:

	char name[30];
	int age;
public:
	void getdata();
	void virtual display()=0;
};

void  personalr::getdata()
{
	cout<<"\nENTER NAME OF EMPLOYEE- ";
	cin>>name;
	cout<<"\nENTER AGE OF EMPLOYEE- ";
	cin>>age;
}

class acadamic
{
protected:

	char degree1[20];
	int pass1;
	char degree2[20];
	int pass2;
public:
	void getdata();
	void virtual display()=0;
};

void  acadamic::getdata()
{
	cout<<"\nENTER DEGREE OF GRADUATION - ";
	cin>>degree1;
	cout<<"\nENTER YEAR OF PASSING- ";
	cin>>pass1;
	cout<<"\nENTER DEGREE OF POST GRADUATION (IF ANY) - ";
	cin>>degree2;
	cout<<"\nENTER YEAR OF PASSING- ";
	cin>>pass2;
	
	
}

class professional:public acadamic,public personalr
{
protected:
	char post[20];
	int empid;
	char company[20];
public:
	void getdata();
	void display();
};

void professional::getdata()
{	
	personalr::getdata();
	acadamic::getdata();
	cout<<"\nENTER THE COMPANY TO WHICH EMPLOYEE IS ASSOCIATED- ";
	cin>>company;
	cout<<"\nENTER EMPLOYEE ID- ";
	cin>>empid;
	cout<<"\nENTER DESIGNATION OF THE EMPLOYEE- ";
	cin>>post;
	
	
}
void professional::display()
{
	cout<<"\n\n\t\t\t\tBIO-DATA";
	cout<<"\n\n\tPERSONAL DETAILS\n ";				     
	cout<<"*******************************************************************************";
	cout<<"\n\nNAME :               "<<name;;
	cout<<"\n\nAGE  :               "<<age;
	cout<<"\n\n\tACADAMIC DETAILS\n ";
	cout<<"*******************************************************************************";
	cout<<"\n\nDEGREE-1 :           "<<degree1;
	cout<<"\n\nYEAR OF PASSING :    "<<pass1;
	cout<<"\n\nDEGREE-2 :           "<<degree2;
	cout<<"\n\nYEAR OF PASSING :    "<<pass2;
	cout<<"\n\n\tPROFESSIONAL DETAILS\n ";
	cout<<"*******************************************************************************";
	cout<<"\n\nASSOCIATION :        "<<company;
	cout<<"\n\nEMPLOYEE-ID :        "<<empid;
	cout<<"\n\nDESIGNATION :        "<<post;
	cout<<"\n\n***************************************************************************";
}

int main()
{
	professional p;


	p.getdata();
	p.display();
}
