#include<iostream>
using namespace std;

class Book	{
	char name[50],author[30];
	int id;
	public:
	void get_details();
	void display();
};
class Library	{
	static int book_count;
	public:
	friend void Book::get_details();
};

void Book::get_details()	{
	cout<<"\nEnter Book Name : ";
	gets(name);
	cout<<"\nEnter Book Author : ";
	gets(author);
	id = ++Library::book_count;
}
void Book::display()	{
	cout<<"\nBook Name   : "<<name<<"\nBook Author : "<<author<<"\nBook ID     : "<<id<<endl;
}

int Library::book_count=0;

int main()	{
	Book b1,b2;
	
	b1.get_details();
	b1.display();
	
	b2.get_details();
	b2.display();
	
	return 0;
}
