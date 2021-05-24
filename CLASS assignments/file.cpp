#include<iostream>
#include<fstream>
using namespace std;

int main()
{
int rollno;
char name[20];
ofstream fout("shrirang");
cout<<"Enter roll no  ";
cin>>rollno;
//fout<<"Roll no - ";
fout<<rollno;
cout<<"Enter name  ";
cin>>name;
//fout<<"\nName - ";
fout<<name;
fout.close();
ifstream fin("shrirang");
fin>>rollno;
cout<<"\nroll no - "<<rollno;
fin>>name;
cout<<"\nname-  "<<name;
fin.close();
}
