#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

class emp
{
public:
    int empid;
    char name[30];
    char designation[30];
    int salary;
public:
    void getdata(int s);
    void display();
};


void emp::getdata(int s)
{
    cout<<"\n\n ENTER THE DETAILS OF EMPLOYEE\n ";
    empid=(100*(s+1))+(5*s);
    cout<<"\nEMPLOYEE ID :  ";
    cout<<empid;
    cout<<"\n\n\tNAME :  ";
    cin>>name;
    cout<<"\n\tDESIGNATION :  ";
    cin>>designation;
    cout<<"\n\tSALARY :  ";
    cin>>salary;
    while(salary<10000)
    {
    	cout<<"\n\t\tENTER SALARY AGAIN  ";
    	cin>>salary;
    }	
}


void emp::display()
{
    cout<<"\n\nEMPLOYEE ID   :  "<<empid;
    cout<<"\n\n\tNAME        :  "<<name;
    cout<<"\n\n\tDESIGNATION :  "<<designation;
    cout<<"\n\n\tSALARY      :  "<<salary;
    cout<<"\n";
}


int main()
{
	int b;
	cout<<"\n\nENTER THE NUMBER OF EMPLOYEES  ";
	cin>>b;
	emp a[b],r;
	
	fstream f;
	f.open("Employee.dat",ios::binary|ios::out);
	for(int s=0;s<b;s++)
	{
		a[s].getdata(s);
		f.write((char *)&a[s],sizeof(a[s]));
	}
	cout<<"\n**************************************\n";
	f.close();
	f.open("Employee.dat", ios::in);
	f.seekg(0);
	cout<<"\nDETAILS OF EMPLOYEES ARE -:";
	for(int s=0;s<b;s++)
	{
		f.read((char *)&a[s],sizeof(a[s]));
		a[s].display();
	}			
	cout<<"\n\n**************************************";
	f.close();
	return 0;
}

