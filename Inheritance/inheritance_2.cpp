#include<iostream>
#include<conio.h>
using namespace std;

class Person	{
	protected:
	char name[30],address[50],ph_no[15];
};

class Employee : protected Person	{
	protected:
	char e_no[10],e_name[30];
};

class Manager : private Employee	{
	char designation[20], department[25];
	int basic_salary;
	public:
	void get_data()	{
		cout<<"\n\nEnter Manager Name : ";
		scanf(" %[^\n]s",e_name);
		cout<<"\nEnter Manager ID   : ";
		scanf(" %[^\n]s",e_no);
		cout<<"\nEnter Designation  : ";
		scanf(" %[^\n]s",designation);
		cout<<"\nEnter Department   : ";
		scanf(" %[^\n]s",department);
		cout<<"\nEnter your Salary  : ";
		cin>>basic_salary;
	}
	int get_sal()	{
		return basic_salary;
	}
	void disp_data()	{
		cout<<"\nManager Name : "<<e_name<<"\nManager ID   : "<<e_no<<"\nDesignation  : "<<designation<<"\nDepartment   : "<<department<<"\nSalary       : "<<basic_salary<<"\n";
	}
};

main()	{
	int n,i,max=0;
	char opt;
	cout<<"\nEnter no.of Managers : ";
	cin>>n;
	Manager mg[n];
	do	{
		system("cls");
		cout<<"\n\n1.Enter Data\n2.Display data\n3.Exit\n\nEnter your option : ";
		opt=getche();
		switch(opt)	{
			case '1':
				for(i=0;i<n;i++)	{
					cout<<"\n\nMANAGER - "<<i+1<<" :-";
					mg[i].get_data();
				}
				break;
			case '2':
				cout<<"\n\n\nDETAILS :-\n";
				for(i=0;i<n;i++)	{
					cout<<"\nMANAGER - "<<i+1<<" :-\n";
					mg[i].disp_data();
					if(mg[i].get_sal()>mg[max].get_sal()) max =i;
				}
				cout<<"\n\n\nHIGHEST PAID MANAGER :-\n\n";
				mg[max].disp_data();
				break;
			case '3':
				cout<<"\n\nGoodBye ! Have a nice Day !\n";
				exit(0);
			default:
				cout<<"\nEnter a valid option !\n";
		}
		cout<<"\nPress Any key to Continue....";
		opt=getche();
	}while(opt!='3');
}
