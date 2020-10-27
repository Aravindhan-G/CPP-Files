#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;
class Phone
{
    char name[20],street[10],city[10],code[10],phnum[11];
    int door_num;
public:
    Phone()
    {
       strcpy(code,"DEL");
    }
       void getdata()
       {
           cout<<"\n Enter name : ";
           cin>>name;
           cout<<"\n Enter phnum : ";
           cin>>phnum;
           cout<<"\n\t\t Provide information for your address !! ";
           cout<<"\n Enter door num : ";
           cin>>door_num;
           cout<<"\n Enter street name : ";
           cin>>street;
           cout<<"\n Enter city : ";
           cin>>city;
           cout<<"\n Enter code : ";
           cin>>code;
       }
       void display()
       {
           cout<<"\n Name : ";
           cout<<name;
           cout<<"\n Phnum : ";
           cout<<phnum;
           cout<<"\n Door num : ";
           cout<<door_num;
           cout<<"\n Street name : ";
           cout<<street;
           cout<<"\n City : ";
           cout<<city;
           cout<<"\n Code : ";
           cout<<code;
       }
       friend void Transfer();
};
void Transfer()
{
    fstream f("PHONE.DAT",ios::binary|ios::in|ios::out);
    Phone ph;
    fstream cp("PHONEBACK.DAT",ios::binary|ios::in|ios::out|ios::trunc);
    while(f.read((char *)&ph,sizeof(Phone)))
    {
        if(strcmp(ph.code,"DEL")==0)
            cp.write((char *)&ph,sizeof(Phone));
    }
        cp.close();
        f.close();
}

int main()
{
    fstream of("PHONE.DAT",ios::binary|ios::in|ios::out|ios::trunc);
    int i;
    char choice='y';
    while(choice=='y'||choice=='Y')
    {
        Phone ph;
        ph.getdata();
        of.write((char *)&ph,sizeof(Phone));
        cout<<"\n Check Your Information !! ";
        ph.display();
        cout<<"\n Do you want to continue?(Y/N)";
        cin>>choice;
    }
    Phone ph;
    of.close();
    Transfer();
    cout<<"\n\t\t Data in Backup File ";
    fstream off("PHONEBACK.DAT",ios::binary|ios::in|ios::out);
    while(off.read((char *)&ph,sizeof(Phone)))
        ph.display();
    return 0;
}
