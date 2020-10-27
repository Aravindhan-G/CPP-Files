#include<iostream>
using namespace std;

// Hierarchial Inheritance....
class Furniture	{
	char color[20];
	int wid,hei;
	public:
	void get_data()	{
		cout<<"\nEnter Color : ";
		scanf(" %[^\n]s",color);
		cout<<"\nEnter Height and Width (in cms.): ";
		cin>>hei>>wid;
	}
	void disp_data()	{
		cout<<"\nColor            : "<<color<<"\nHeight and Width : "<<hei<<"\t"<<wid<<"\n";
	}
};

class Chair	: public Furniture	{
	int legs;
	public:
	void get_data()	{
		Furniture::get_data();
		cout<<"\nEnter no.of Legs : ";
		cin>>legs;
	}
	void disp_data()	{
		Furniture::disp_data();
		cout<<"No.of Legs       : "<<legs<<"\n";
	}
};

class BookShelf	: public Furniture {
	int shelves;
	public:
	void get_data()	{
		Furniture::get_data();
		cout<<"\nEnter no.of Shelves : ";
		cin>>shelves;
	}
	void disp_data()	{
		Furniture::disp_data();
		cout<<"No.of Shelves    : "<<shelves<<"\n";
	}
};

class Cot : public Furniture	{
	int legs;
	public:
	void get_data()	{
		Furniture::get_data();
		cout<<"\nEnter no.of Legs : ";
		cin>>legs;
	}
	void disp_data()	{
		Furniture::disp_data();
		cout<<"No.of Legs       : "<<legs<<"\n";
	}
};

main()	{
	Chair ch;
	BookShelf b;
	Cot co;
	
	cout<<"\nCHAIR :-\n";
	ch.get_data();
	cout<<"\nBOOK_SHELF :-\n";
	b.get_data();
	cout<<"\nCOT :-\n";
	co.get_data();
	
	cout<<"\n\nDETAILS :\n";
	cout<<"\nCHAIR :-\n";
	ch.disp_data();
	cout<<"\nBOOK_SHELF :-\n";
	b.disp_data();
	cout<<"\nCOT :-\n";
	co.disp_data();
}
