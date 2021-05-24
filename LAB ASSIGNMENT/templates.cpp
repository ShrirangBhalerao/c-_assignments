#include<iostream>
using namespace std;

template<class T>                 //class template declaration
class matrix
{
private:
	T a[3][3];
	T b[3][3];
	int size1,size2,size3,size4;
public:
	void getsize();
	void getdata();
	void display();
	void add();
	void sub();
	void mul();
	void transpose();
	void saddle();
};


template<class T>
void matrix<T>::getsize()              
{
	cout<<"\n\tENTER DIMENSIONS OF MATRIX 1  ";
	cin>>size1>>size2;
	cout<<"\n\tENTER DIMENSIONS OF MATRIX 2  ";
	cin>>size3>>size4;
}

template<class T>
void matrix<T>::getdata()                  //function to input matrix
{
	int i,j;
	cout<<"\n\nEnter the elements of matrix 1-      ";
	for(i=0;i<size1;i++)
	{
		for(j=0;j<size2;j++)
		{
			cin>>a[i][j];
		}
	}
	cout<<"\n\nEnter the elements of matrix 2-       ";
	for(i=0;i<size3;i++)
	{
		for(j=0;j<size4;j++)
		{
			cin>>b[i][j];
		}
	}
}


template<class T>
void matrix<T>::display()             //display function
{
	int i,j;
	cout<<"\n\n\t matrix 1 \n\n";
	for(i=0;i<size1;i++)
	{
		cout<<"\t";
		for(j=0;j<size2;j++)
		{
			cout<<a[i][j]<<"\t";
		}
		cout<<"\n";
	}
	cout<<"\n\n\t matrix 2\n\n ";
	for(i=0;i<size3;i++)
	{  
		cout<<"\t";
		for(j=0;j<size4;j++)
		{
			cout<<b[i][j]<<"\t";
		}
		cout<<"\n";
	}
}


template<class T>
void  matrix<T>::add()                           //Addition of matrix
{
	T c[size1][size2];
	int i,j;
	if(size1!=size3||size2!=size4)
		cout<<"\n\tADDITION NOT POSSIBLE ";
	else
	{
		cout<<"\n\n\tADDITION OF MATRICES- \n\n";
		for(i=0;i<size1;i++)
		{
			for(j=0;j<size2;j++)
			{
				c[i][j]=a[i][j]+b[i][j];
			}
		}
		for(i=0;i<size1;i++)
		{
			cout<<"\t";
			for(j=0;j<size2;j++)
			{
				cout<<c[i][j]<<"\t";
			}
			cout<<"\n";
		}
	}
}


template<class T>
void  matrix<T>::sub()                         //Subtraction of matrix
{
	T d[size1][size2];
	int i,j;
	if(size1!=size3||size2!=size4)
		cout<<"\n\tSUBTRACTION NOT POSSIBLE ";
	else
	{
		cout<<"\n\n\tSUBTRACTION OF MATRICES- \n\n";
		for(i=0;i<size1;i++)
		{
			for(j=0;j<size2;j++)
			{
				d[i][j]=a[i][j]-b[i][j];
			}
		}
		for(i=0;i<size1;i++)
		{
			cout<<"\t";
			for(j=0;j<size2;j++)
			{
				cout<<d[i][j]<<"\t";
			}
			cout<<"\n";
		}
	}
}


template<class T>
void matrix<T>::mul()                     //Multiplication of matrix
{
	int i,j,k;
	T c[size1][size2];
	if(size1!=size3||size2!=size4)
		cout<<"\n\tMULTIPLICATION NOT POSSIBLE ";
	else
	{
		for(i=0;i<size1;i++)
		{
			for(j=0;j<size2;j++)
			{
				c[i][j]=0;
				for(k=0;k<size1;k++)
				{
			          c[i][j]=c[i][j]+(a[i][k]*b[k][j]);
				}
			}
		}
		cout<<"\n\n\tMULTIPLICATION OF MATRICES - \n\n";
		for(i=0;i<size1;i++)
		{
			cout<<"\t";
			for(j=0;j<size2;j++)
			{
				cout<<c[i][j]<<"\t";
			}
			cout<<"\n";
		}
	}
}


template<class T>
void matrix<T>::transpose()         //transpose of matrix
{
	int i,j;
	if(size1!=size3||size2!=size4)
		cout<<"\n\tTRANSPOSE NOT POSSIBLE ";
	else
	{
		cout<<"\n\n\tTRANSPOSE OF MATRIX 1\n\n ";
		for(i=0;i<size1;i++)
		{
			cout<<"\t";
			for(j=0;j<size2;j++)
			{
				cout<<a[j][i]<<"\t";
			}	
			cout<<"\n";
		}
		cout<<"\n\n\tTRANSPOSE OF MATRIX 2\n\n ";
		for(i=0;i<size3;i++)
		{
			cout<<"\t";
			for(j=0;j<size4;j++)
			{
				cout<<b[j][i]<<"\t";
			}	
			cout<<"\n";
		}
	}
}


template<class T>
void matrix<T>::saddle()              //saddle-point of matrix
{
 	T r,t;
	int p,q,k,s,z=0;
	for(p=0;p<size1;p++)
	{
		r=a[p][0];
		for(q=0;q<size2;q++)
		{
			if(r>=a[p][q])
			{
				r=a[p][q];
				s=q;
			}
		}
		t=a[0][s];
		for(k=0;k<size1;k++)
		{
			if(t<=a[k][s])
			{	
				t=a[k][s];
				z=k;	
			}
		}
		if(r==t)
		{
			cout<<"\n\tSADDLE POINT OF MATRIX  IS "<<t;
			cout<<"\n\tPOSITION OF MATRIX IS a["<<z+1<<"]["<<s+1<<"]";
			break;
			cout<<"\n";
		}	
	}
	if(r!=t)	
	{
		cout<<"\n\tSADDLE POINT ABSENT ";
	}
	for(p=0;p<size3;p++)
	{
		r=b[p][0];
		for(q=0;q<size4;q++)
		{
			if(r>=b[p][q])
			{
				r=b[p][q];
				s=q;
			}
		}
		t=a[0][s];
		for(k=0;k<size3;k++)
		{
			if(t<=b[k][s])
			{	
				t=b[k][s];
				z=k;	
			}
		}
		if(r==t)
		{
			cout<<"\n\n\tSADDLE POINT OF MATRIX  IS "<<t;
			cout<<"\n\tPOSITION OF MATRIX IS b["<<z+1<<"]["<<s+1<<"]";
			break;
			cout<<"\n";
		}	
	}
	if(r!=t)	
	{
		cout<<"\n\tSADDLE POINT ABSENT ";
	}
}

int main()                   //main function
{
	int i,j,k;
	while(1)
	{
		cout<<"\n\n\tData Types";
		cout<<"\n\n1.Int";
		cout<<"\n\n2.Float";

		cout<<"\n\n\tEnter Data Type  ";
		cin>>i;
		if(i==1)
		{
			matrix<int> m;
			m.getsize();
			m.getdata();	
			while(1)
			{
				m.display();
				cout<<"\n\n\tList Of Operation";
				cout<<"\n\n1.Addition";
				cout<<"\n\n2.Subtraction";
				cout<<"\n\n3.Multiplication";
				cout<<"\n\n4.Transpose";
				cout<<"\n\n5.Saddle Point";
				cout<<"\n\nEnter Your choice  ";
				cin>>j;
				switch(j)
				{
					case 1: m.add();
					break;
					case 2: m.sub();
					break;
					case 3: m.mul();
					break;
					case 4: m.transpose();
					break;
					case 5: m.saddle();
					break;
				}
				cout<<"\n\n\tContinue Data-Type ? (1/0)   ";
				cin>>k;
				if(k==0)
					break;
			}
		}
		else
		{
			matrix<float> m;
			m.getsize();
			m.getdata();
			while(1)
			{
				m.display();
				cout<<"\n\n\tList Of Operation";
				cout<<"\n\n1.Addition";
				cout<<"\n\n2.Subtraction";
				cout<<"\n\n3.Multiplication";
				cout<<"\n\n4.Transpose";
				cout<<"\n\n5.Saddle Point";
				cout<<"\n\n\tEnter Your choice  ";
				cin>>j;
				switch(j)
				{
					case 1: m.add();
					break;
					case 2: m.sub();
					break;
					case 3: m.mul();
					break;
					case 4: m.transpose();
					break;
					case 5: m.saddle();
					break;
				}
				cout<<"\n\n\tContinue Data-Type ? (1/0)  ";
				cin>>k;
				if(k==0)
					break;
			}
		}
		cout<<"\n\nContinue ? (1/0)  ";
		cin>>k;
		if(k==0)
			break;
	}
	cout<<"\n\t\t\t\tTHANK-YOU!!!";
}










