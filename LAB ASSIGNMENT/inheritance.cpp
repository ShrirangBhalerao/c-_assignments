#include<iostream>
#include<string.h>
using namespace std;

class personald                           //BASE CLASS-PERSONAL DETAILS
{
protected:
	 int rollno;
	 static int id;
	char name[30];
	int day;
	char bloodgrp[2];
	int month;
	int year;
public:
	void getdata();
	void display();
};

int personald::id=100;
class physic                              //BASE CLASS-PHYSICAL DETAILS
{
protected:
	int ht;
	int wt;
public:
	void getdata();
	void display();
};


class policy                             //BASE CLASS-POLICY DETAILS
{
protected:
	char pl[10];
	char address[30];
public:
	void getdata();
	void display();
};


class contact:public personald,public physic,public policy
{                                                          //DERIEVED CLASS-CONTACT DETAILS
protected:
	char number[10];
	int dl;
public:
	void getdata();
	void display();
	int search(contact c[],int s);
	int add(contact c[],int s);
	void master(contact c[],int s);
	void edit(contact c[],int s);
};


void personald::getdata()
{
	rollno=0+id;
	cout<<"\n";
	cout<<"\n\tROLL NO "<<rollno;
	id++;
	cout<<"\nENTER NAME  ";
	cin>>name;
	cout<<"ENTER BIRTH-DATE (DD/MM/YY) ";
	cin>>day>>month>>year;
	cout<<"ENTER BLOOD GROUP  ";
	cin>>bloodgrp;
}


void personald::display()
{
	cout<<"\n";
	cout<<"\n\n\tROLL NO- "<<rollno;
	cout<<"\n\n\tNAME-"<<name;
	cout<<"\n\n\tBIRTH-DATE-  "<<day<<"-"<<month<<"-"<<year;
	cout<<"\n\n\tBLOOD GROUP- "<<bloodgrp;
}


void physic::getdata()
{
	cout<<"ENTER HEIGHT  ";
	cin>>ht;
	cout<<"ENTER WEIGHT ";
	cin>>wt;
}


void physic::display()
{
	cout<<"\n\n\tHEIGHT- "<<ht;
	cout<<"\n\n\tWEIGHT- "<<wt;
}


void policy::getdata()
{
	cout<<"ENTER POLICY NUMBER  ";
	cin>>pl;
	if(pl[0]<65)
	{
	cout<<"INVALID POLICY NUMBER ,ENTER AGAIN";
	cin>>pl;
	}
	cout<<"ENTER ADDRESS ";
	cin>>address;
}


void policy::display()
{
	cout<<"\n\n\tPOLICY NUMBER- "<<pl;
	cout<<"\n\n\tADDRESS- "<<address;
}


void contact::getdata()
{
	int a;
	personald::getdata();
	physic::getdata();
	policy::getdata();
	cout<<"ENTER MOBILE NUMBER ";
	cin>>number;
	while(strlen(number)!=10)
	{
		cout<<"\n\tINVALID NUMBER,ENTER AGAIN ";
		cin>>number;
		cout<<"\n";
		if(strlen(number)==10)
		break;
	}
	cout<<"ENTER DRIVING LISCENSE NUMBER ";
	cin>>dl;
	cout<<"\n";
}


void contact::display()
{
	personald::display();
	physic::display();
	policy::display(); 
	cout<<"\n\n\tMOBILE NUMBER- "<<number;
	cout<<"\n\n\tDRIVING LISCENSE- "<<dl;
}


int contact::search(contact c[],int s)
{
	int a,b,d;
	cout<<"\n\tENTER ROLL NO ";
	cin>>d;
	for(a=0;a<s;a++)
	{
		b=0;
		if(c[a].rollno==d)
		{
			b=1;
			return a;
			cout<<a;
			break;
		}
	}
	if(b==0)
	{
		cout<<"\n\tDATA NOT FOUND ";
		return 1000;
	}
}


int contact::add(contact c[],int s)
{
	s++;
	c[s-1].getdata();
	return s;
}
	
void contact::master(contact c[],int s)
{
	int i;
	cout<<"\n";
	cout<<"ROLL-NO\t\t"<<"NAME"<<"\t\tB-DATE"<<"\t\tB-GRP"<<"\tHT"<<"\tWT"<<"\tPOLICY NO\t"<<"ADDRESS\t"<<"\tM-NO"<<"\t\tD.LISCENCE NO";
	cout<<"\n\n";
	for(i=0;i<s;i++)
	{
		cout<<c[i].rollno<<"\t\t"<<c[i].name<<"\t"<<c[i].day<<"-"<<c[i].month<<"-"<<c[i].year<<"\t"<<c[i].bloodgrp<<"\t"<<c[i].ht<<"\t"<<c[i].wt<<"\t"<<c[i].pl<<"\t\t"<<c[i].address<<"\t\t"<<c[i].number<<"\t"<<c[i].dl;
		
	cout<<"\n\n";
	}
}

void contact::edit(contact c[],int s)
{
contact z;
int i,j;
i=z.search(c,s);

cout<<"\n\nWHICH DETAILS WOULD U LIKE TO UPDATE ";
cout<<"\n\t1.BIRTH DATE ";
cout<<"\n\t2.ADDRESS ";
cout<<"\n\t3.MOBILE NUMBER ";
cout<<"\n\t4.POLICY NO ";
cout<<"\n\nENTER YOUR CHOICE ";
cin>>j;
switch(j)
{
case 1:{
cout<<"\nENTER NEW BIRTH DATE  ";
cin>>c[i].day;
cin>>c[i].month>>c[i].year;
cout<<"\n\tBIRTH DATE UPDATED ";
}
break;

case 2:{
cout<<"\nENTER NEW ADDRESS  ";
cin>>c[i].address;
cout<<"\n\tADDRESS  UPDATED ";
}
break;

case 3:{
cout<<"\nENTER NEW MOBILE NUMBER  ";
cin>>c[i].number;
while(strlen(c[i].number)!=10)
	{
		cout<<"\n\tINVALID NUMBER,ENTER AGAIN ";
		cin>>number;
		cout<<"\n";
		if(strlen(number)==10)
		break;
	}
cout<<"\n\tMOBILE NUMBER  UPDATED ";
}
break;

case 4:
{
cout<<"\nENTER NEW POLICY NUMBER  ";
cin>>c[i].pl;
if(c[i].pl[0]<65)
	{
	cout<<"INVALID POLICY NUMBER ,ENTER AGAIN";
	cin>>pl;
	}
cout<<"\n\tPOLICY NUMBER UPDATED ";
}
break;
}
}
int main()
{
	int s,d,ch,ch1,y,x,i,j;
	cout<<"\tENTER NO OF STUDENTS- ";
	cin>>s;
	contact c[s],p;
	personald v[2];
	policy o[s] ;
	physic w[s];
	for(d=0;d<s;d++)
	{
		c[d].getdata();
	}
	do
	{
		cout<<"\tLIST OF OPERATIONS ";
		cout<<"\n\n1.BUILT A MASTER TABLE";
		cout<<"\n2.DISPLAY";
		cout<<"\n3.DELETE AN ENTRY";
		cout<<"\n4.INSERT A NEW ENTRY";
		cout<<"\n5.SEARCH FOR A RECORD";
		cout<<"\n6.UPDATE A RECORD";
		cout<<"\n\n\tENTER YOUR CHOICE  ";
		cin>>ch;
		switch(ch)
		{
			case 1:{
					p.master(c,s);
				}
			break;
			case 2:
			{	
				for(d=0;d<s;d++)
				{
					c[d].display();
				}
			}
			break; 
			case 4:
			{
				s=p.add(c,s);
			}
			break;
			case 3:
			{
				x=p.search(c,s);	
				for(i=x;i<s;i++)
				{
					c[i]=c[i+1];
				}
				s--;
				cout<<"\t\nDETAILS DELETED";
			}
			break;
			case 5:
			{
				y=p.search(c,s);
				if(y!=1000)
				c[y].display();
			}
			break;
			case 6: p.edit(c,s);
			break;
			default: cout<<"\n\nINVALID OPTION ";
			break;
		}	
		cout<<"\n\n\tWOULD U LIKE TO CONTINUE ";
		cin>>ch1;
		cout<<"\n";
	}while(ch1==1);
	cout<<"\n\t\t\tTHANK-YOU!!\n";
	return 0;
}














