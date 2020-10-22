#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;
class Contacts_book
{
    char ph_num[11];
    char name[30];
public:
    void create();
    int check(int );
    void edit();
    void display();
};
void Contacts_book::create()
{
    cout<<"\n Enter Name : ";
    cin>>name;
    cout<<"\n Phone Number : ";
    cin>>ph_num;
}
int Contacts_book::check(int choice)
{
    Contacts_book s;
    fstream file("MyContacts.DAT",ios::binary | ios::out | ios::in);
    if(choice!=1)
    {
        cout<<"\n 1.Enter Phone Number to find Contact.\n 2.Enter Name to find Mobile Number.\n\t Your Preference to check?";
        cin>>choice;
    }
    switch(choice)
    {
    case 1:
        {
            char ph[11];
            cout<<"\n Enter the mobile number : ";
            cin>>ph;
            while(file.read((char *)&s,sizeof(Contacts_book)))
            {
                if(strcmp(s.ph_num,ph)== 0)
                   {
                       cout<<"\n Contact Found !!\n Name = "<<s.name;
                       return 1 ;
                   }
            }
            cout<<"\n Contact Not Found :( ";
            return 0;
            break;
        }
    case 2:
        {
            char nme[30];
            cout<<"\n Enter the Name : ";
            cin>>nme;
            while(file.read((char *)&s,sizeof(Contacts_book)))
            {
                if(strcmp(s.name,nme)==0)
                   {
                       cout<<"\n Contact Found !!\n Phone Number = "<<s.ph_num;
                       return 1;
                   }
            }
            cout<<"\n Contact Not Found :( ";
            return 0;
            break;
        }
    }
    file.close();
}
void Contacts_book::edit()
{
    Contacts_book s;
    if(check(1))
    {
        fstream file("MyContacts.DAT",ios::binary | ios::in |ios::out);
        char ph[11],ph1[11];
        cout<<"\n Please Enter Your Old Mobile Number Again : ";
        cin>>ph;
        cout<<"\n Enter The New Mobile Number To Be Updated : ";
        cin>>ph1;
        while(file.read((char *)&s,sizeof(Contacts_book)))
        {
            if(strcmp(s.ph_num,ph)==0)
            {
                strcpy(s.ph_num,ph1);
                cout<<"\n Phone Number Update!!\n\t Name = "<<s.name<<"\n\t Phone Number = "<<s.ph_num;
                file.write((char *)&s,sizeof(Contacts_book));
                break;
            }
        }
        file.close();
    }
    else
    {
        cout<<"\n There is Nothing To Be Edited !!";
    }
    }

void Contacts_book::display()
{
    Contacts_book disp;
    fstream file("MyContacts.DAT",ios::binary | ios::in | ios::out);
    while(file.read((char *)&disp,sizeof(Contacts_book)))
    {
        cout<<"\n Name = "<<disp.name;
        cout<<"\n Phone Number = "<<disp.ph_num;
    }
    file.close();
}

int main()
{
    Contacts_book neew;
    int choice=0;
    while(choice!=5)
    {
    cout<<"\n 1.Create Contact\n 2.Check contact\n 3.Edit contact\n 4.Display Contacts\n 5.Quit\n \t Your Choice?";
    cin>>choice;
    switch(choice)
    {
    case 1:
        {
           neew.create();
           fstream file("MyContacts.DAT",ios::binary |ios::in | ios::out |ios::app);
        if(!file.is_open())
        {
            cout<<endl<<"Error opening";
        }
        file.write((char *)&neew,sizeof(Contacts_book));
        file.close();
           break;
        }
    case 2:
        {
            neew.check(0);
            break;
        }
    case 3:
        {
            neew.edit();
            break;
        }
    case 4:
        {
            neew.display();
            break;
        }
    }
}
cout<<"\n\tBye BYE";
}
