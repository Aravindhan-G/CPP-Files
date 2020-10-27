#include<iostream>
using namespace std;
class publication
{
protected:
    char title[20];
    int price;
    void getdata()
    {
        cout<<"\n Enter title : ";
        cin>>title;
        cout<<"\n Enter Cost : ";
        cin>>price;
    }
    void display()
    {
        cout<<"\n Title -> "<<title<<"\n Cost -> "<<price;
    }
};
class book:private publication
{
    int pageCount;
public:
    void getBook()
    {
        cout<<"\n Book!! ";
        getdata();
        cout<<"\n Enter total no of pages : ";
        cin>>pageCount;
    }
    void dispBook()
    {
        cout<<"\n Books !!! ";
        display();
        cout<<"\n Total Pages -> "<<pageCount;
    }
    void nPagebook(int n)
    {
        if(pageCount>n)
        {
            dispBook();
        }
    }
};
class tape:private publication
{
    int minuteCount;
public:
    void getTape()
    {
        cout<<"\n Tape!! ";
        getdata();
        cout<<"\n Enter total minutes : ";
        cin>>minuteCount;
    }
    void dispTape()
    {
        cout<<"\n Tape !!! ";
        display();
        cout<<"\n Total minutes -> "<<minuteCount;
    }
    void nminuteTape(int n)
    {
        if(minuteCount>n)
        {
            dispTape();
        }
    }
};

int main()
{
    int i,n,count,choice;
    char check='y';
    cout<<"\n Enter over all count : ";
    cin>>i;
    book b[i];
    tape t[i];
    for(count=0;count<i;b[count].getBook(),count++);
    for(count=0;count<i;t[count].getTape(),count++);
    while(check=='y'||check=='Y')
    {
        cout<<"\n 1.Display All Books.\n 2.Display book with >n pages.\n 3.Display All Tapes.\n 4.Display tapes with >n minutes.\n\t\tEnter your choice ? ";
        cin>>choice;
        switch(choice)
        {
            case 1: for(count=0;count<i;b[count].dispBook(),count++);break;
            case 2: cout<<"\n Enter the particular number of page : ";cin>>n;
                        for(count=0;count<i;b[count].nPagebook(n),count++);break;
            case 3: for(count=0;count<i;t[count].dispTape(),count++);break;
            case 4 :cout<<"\n Enter the particular number of minute : ";cin>>n;
                        for(count=0;count<i;t[count].nminuteTape(n),count++);break;
        }
        cout<<"\n\t\t Do you want to Continue :(y||n) ";
        cin>>check;
    }
}
