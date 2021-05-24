                                                                              //ROLL NO-8068

                               //TITLE- WEATHER REPORT 


#include<iostream> 
using namespace std;
class weatherreport
{
	private:
	float dateofmonth[32],hightemp[32],lowtemp[32],ammount_rain[32],ammount_snow[32];
	public:
		weatherreport();              //default constructor.......
		void getdata(int v,int x);
		weatherreport(weatherreport &x);    //copy constructor.......
		void display(int x,int v);                     //display function.......
		void averagehightemp(int v);
		void averagelowtemp(int v);
		void averageammount_rain(int v);
		void averageammount_snow(int v);
};


void weatherreport::getdata(int v,int x)
{
	int p;
	for(p=1;p<=v;p++)
	{
		cout<<"\t\tDATE- "<<p<<"-"<<x<<"-"<<"2018"<<"\n";
		cout<<"\nHIGH TEMP -";
		cin>>hightemp[p];
		cout<<"\nLOW TEMP - ";
		cin>>lowtemp[p];
		cout<<"\nAMMOUNT_RAIN - ";
		cin>>ammount_rain[p];
		cout<<"\nAMMOUNT_SNOW - ";
		cin>>ammount_snow[p];
		cout<<"\n";
	}
}


void weatherreport::display(int x,int v)             //display function.......
{ 
	int p; 
	cout<<"\t\t\tWEATHER REPORT ";
	cout<<"\n\n";
	cout<<"\tDate"<<"\t\t"<<"H.Temp"<<"\t\t"<<"L.Temp"<<"\t\t"<<"Rainfall"<<"\t"<<"Snowfall";
	cout<<"\n\n";
	for(p=1;p<=v;p++)
	{
  cout<<"\t"<<p<<"-"<<x<<"-"<<"18"<<"\t\t"<<hightemp[p]<<"\t\t"<<lowtemp[p]<<"\t\t"<<ammount_rain[p]<<"\t \t"<<ammount_snow[p];
		cout<<"\n";
	}
}


weatherreport::weatherreport()               //default constructor.......
{
	int p;
	for(p=1;p<=31;p++)
	{	
		dateofmonth[p]=0;
		hightemp[p]=0;
		lowtemp[p]=0;
		ammount_rain[p]=0;
		ammount_snow[p]=0;
	}
}


weatherreport::weatherreport(weatherreport &x)           //copy constructor.......
{
	int p;
	for(p=1;p<=31;p++)
	{		
		hightemp[p]=x.hightemp[p];
		lowtemp[p]=x.lowtemp[p];
		ammount_rain[p]=x.ammount_rain[p];
		ammount_snow[p]=x.ammount_snow[p];	
	}
}


void weatherreport::averagehightemp(int v)
{
	int p,sum=0;
	float average;
	for(p=1;p<=v;p++)
	{
		sum=sum+hightemp[p];
	}
	average=sum/v;       //average high temperature....
	cout<<"\tAVERAGE HEIGH TEMPERATURE- "<<average<<"oC";
	cout<<"\n";
}


void weatherreport:: averagelowtemp(int v)
{
	int p,sum=0;
	float average;
	for(p=1;p<=v;p++)
	{
		sum=sum+lowtemp[p];
	}
	average=sum/v;          //average  low temperature....
	cout<<"\tAVERAGE LOW TEMPERATURE- "<<average<<"oC";
	cout<<"\n";
}


void weatherreport:: averageammount_rain(int v)
{
	int p,sum=0;
	float average;
	for(p=1;p<=v;p++)
	{
		sum=sum+ammount_rain[p];
	}
	average=sum/v;            //average ammount of rainfall....
	cout<<"\tAVERAGE AMMOUNT OF RAINFALL- "<<average<<"mm";
	cout<<"\n";
}
  
    
void weatherreport:: averageammount_snow(int v)       
{
	int p,sum=0;
	float average;
	for(p=1;p<=v;p++)
	{
		sum=sum+ammount_snow[p];
	}
	average=sum/v;                 //average ammount of snow....
	cout<<"\tAVERAGE AMMOUNT OF SN0W- "<<average <<"inch";
	cout<<"\n";
}


int main()                   //main function.......
{
	int ch,a,v,x;
	cout<<"\n1.JANUARY ";
	cout<<"\n2.FEBRUARY ";
	cout<<"\n3.MARCH ";
	cout<<"\n4.APRIL ";
	cout<<"\n5.MAY ";
	cout<<"\n6.JUNE ";
	cout<<"\n7.JULY ";
	cout<<"\n8.AUGUST ";
	cout<<"\n9.SEPTEMBER ";
	cout<<"\n10.OCTOBER";
	cout<<"\n11.NOVEMBER ";
	cout<<"\n12.DECEMBER";
	cout<<"\n";
	cout<<"\n ENTER THE MONTH OF WHICH YOU WANT ENTER WEATHER REPORT ";
	cin>>x;
	cout<<"\n";
	switch(x)                 //switch case for selection of month......
	{
		case 1:v=01;
		break;
		case 2:v=28;
		break;
		case 3: v=31;
		break;
		case 4: v=30;
		break;
		case 5: v=31;
		break;
		case 6: v=30;
		break;
		case 7: v=31;
		break;
		case 8: v=31;
		break;
		case 9: v=30;
		break;
		case 10: v=31;
		break;
		case 11: v=30;
		break;
		case 12: v=31;
		break;
	}
	weatherreport w;
	w.getdata(v,x);
	weatherreport w1(w);
	do
	{
		cout<<"\nLIST OF FUNCTIONS";
		cout<<"\n";
		cout<<"\n1. MONTHLY WEATHER REPORT";
		cout<<"\n2. AVERAGE HIGH TEMPERATURE";
		cout<<"\n3. AVERAGE LOW TEMPERATURE";
		cout<<"\n4. AVERAGE RAIN ";
		cout<<"\n5. AVERAGE SNOW";
		cout<<"\n6. COPY OF MONTHLY WEATHER REPORT";
		cout<<"\n";
		cout<<"\nENTER YOUR CHOICE  ";
		cin>>ch;
		cout<<"\n";
		switch(ch)                 //switch case for selection of operation......
		{
			case 1: w.display(x,v);
			break;
			case 2: w.averagehightemp(v);
			break;
			case 3: w.averagelowtemp(v);
			break;
			case 4: w.averageammount_rain(v);
			break;
			case 5: w.averageammount_snow(v);
			break;
			case 6: w1.display(x,v);
		}
		cout<<"\nWOULD YOU LIKE TO PERFORM ANY OTHER OPERATION (1/0) ";
		cin>>a;
		cout<<"\n";
	}while(a==1);
	cout<<"\t\t\tTHANK-YOU!!";
	cout<<"\n";
	return 0;
}
                                //END OF PROGRAM


