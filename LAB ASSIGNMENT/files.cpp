#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;

static int q=100;

class student                                           
{
private:
	char name[20];
	int m1,m2,m3;
	float average;
public:
	int rollno;
	void getdata(int);
	void display();
	void modify(int);
};

void student::getdata(int w)                  //function to receive data from user
{
	cout<<"\nENTER DETAILS OF STUDENT";
	rollno=q+(10*w+w);
	cout<<"\n\n\tROLLNO -  ";
	cout<<rollno;
	cout<<"\n\n\tNAME -  ";
	cin>>name;
	cout<<"\nENTER MARKS SCORED BY STUDENT\n";
	cout<<"\n\tM1- ";
	cin>>m1;
	while(m1<=0)
	{
		cout<<"\nENTER MARKS AGAIN";
		cout<<"\n\tM1- ";
		cin>>m1;
	}
	cout<<"\n\tM2- ";
	cin>>m2;
	while(m2<=0)
	{
		cout<<"\nENTER MARKS AGAIN";
		cout<<"\n\tM2- ";
		cin>>m2;
	}
	cout<<"\n\tM3- ";
	cin>>m3;
	while(m3<=0)
	{
		cout<<"\nENTER MARKS AGAIN";
		cout<<"\n\tM3- ";
		cin>>m3;
	}
	average=(m1+m2+m3)/3;
	cout<<"\n********************************************\n";
}

void student::display()                         //function to display data
{
	cout<<"\n\nROLL NO - "<<rollno;
	cout<<"\n\nNAME -  "<<name;
	cout<<"\n\nMARKS SCORED\n";
	cout<<"\n\tM1- "<<m1<<"/100";
	cout<<"\n\n\tM2- "<<m2<<"/100";
	cout<<"\n\n\tM3- "<<m3<<"/100";
	cout<<"\n\nAVERAGE MARKS- "<<average<<"%";
	cout<<"\n\n********************************************\n";
}

void student::modify(int z)                     //function to modify data
{
	int a;
	cout<<"\nMARKS SCORED IN  ";
	cout<<"\n\n\t1.M1"<<"\n\n\t2.M2"<<"\n\n\t3.M3\n\n\t";
	cin>>a;
	switch(a)
	{
		case 1:
			cout<<"\n\n\tM1- ";
			cin>>m1; 
		break;
		case 2:
			cout<<"\n\n\tM2- ";
			cin>>m2; 
		break;
		case 3:
			cout<<"\n\n\tM3- ";
			cin>>m3; 
		break;
	}
	average=(m1+m2+m3)/3;
}


int main()
{
	int a,b=0,c,d,e,f=0,j=0, v=0;
	student s[20];
	ifstream fin,din;
	ofstream fout,dout;
	fout.open("STUDENTS.DAT",ios::binary|ios::out|ios::in);
	fout.close();
	do
	{
		cout<<"\n\nLIST OF OPERATIONS\n";
		cout<<"\n\t1.CREATE";
		cout<<"\n\t2.DISPLAY";
		cout<<"\n\t3.ADD";
		cout<<"\n\t4.DELETE";
		cout<<"\n\t5.MODIFY";
		cout<<"\n\t6.EXIT";
		cout<<"\n\nENTER YOUR CHOICE  ";
		cin>>a;
		switch(a)
		{
			case 1 : 
				f++;
				cout<<"\n\nENTER NUMBER OF STUDENTS ";
				cin>>b;
				fout.open("STUDENTS.DAT",ios::out);
				for(c=0;c<b;c++)
				{
					s[c].getdata(c);
					fout.write((char*)&s[c],sizeof(s[c]));
					
					//data written into file
				}
				fout.close();
			break;
			case 2:
				if(f==0)
					cout<<"\n\tFILE EMPTY";
				else
				{
					f++;
					fin.open("STUDENTS.DAT",ios::in);
					for(c=0;c<b;c++)
					{
						fin.read((char*)&s[c],sizeof(s[c]));
						
						//data read from file
						
						s[c].display();
					}
					fin.close();
				}
			break;
			case 3:
					if(f==0)
						cout<<"\n\tFILE NOT CREATED";
					else
					{
						f++;
						fout.open("STUDENTS.DAT",ios::app);
						s[b].getdata(b);
						fout.write((char*)&s[c],sizeof(s[c]));
						b=b+1;
						fout.close();
					}
			break;	
			case 4:
				
				if(f==0)
					cout<<"\n\tFILE EMPTY";
				else
				{	
					f--;
				      fin.open("STUDENTS.DAT",ios::in);				
					dout.open("temp.dat",ios::out);
					cout<<"\n\nENTER THE ROLLNO TO BE DELETED ";
					cin>>d;
					for(c=0;c<b;c++)
					{
						fin.read((char*)&s[c],sizeof(s[c]));
						if(d==s[c].rollno)
						{	
							v++;
							cout<<"\n\tCONTAINTS DELETED\n ";
						}
						else
							dout.write((char*)&s[c],sizeof(s[c]));
					}
					if(v==0)
						cout<<"\n\tDATA DOES NOT EXSIST\n";		
					b=b-1;
					q++;
					fin.close();
					dout.close();
					remove("STUDENTS.DAT");
					rename("temp.dat","STUDENTS.DAT");
				}	
			break;
			case 5:
				fin.seekg(0);
				if(f==0)
					cout<<"\n\tFILE EMPTY";
				else
				{
				f++;
				cout<<"\n\nENTER THE ROLLNO WHOSE DETAILS ARE TO BE MODIFIED ";
				cin>>e;
				for(c=0;c<b;c++)
				{
					fin.read((char*)&s[c],sizeof(s[c]));
					if(e==s[c].rollno)
					{	
						j++;
						s[c].modify(e);
						cout<<"\n\tCONTAINTS MODIFIED!!\n";
						dout.write((char*)&s[c],sizeof(s[c]));
					}
					else
						dout.write((char*)&s[c],sizeof(s[c]));
				}
				if(j==0)
					cout<<"\n\tDATA DOES NOT EXSIST\n";
				fin.close();
				dout.close();
				remove("STUDENTS.DAT");
				rename("temp.dat","STUDENTS.DAT");
				}
			break;
		}	
	}while(a!=6);
}

