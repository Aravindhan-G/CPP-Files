#include<iostream>
using namespace std;
class Salesperson;
class Mobile
{
char code[10],name[12],model[20];
    int amount;
public:
    void getdata();
    void display(int i)
    {
        cout<<"\n "<<i+1<<".Model Name = "<<name<<" "<<model<<"\n Amount = "<<amount;
    }
    friend class Salesperson;
};
class Salesperson
{
private:
    int sold,id,amount;
    char name[20];
    static int s_sold,s_amount;
public:
    friend class Mobile;
    static void search(int idd,Salesperson s[] , int n,Mobile obj[],int m)
    {
    for(int i=0;i<n;i++)
    {
        if(idd==s[i].id)
            {
                for(int i=0;i<m;i++)
                    obj[i].display(i);
                s[i].sales();
            }
        else
            continue;
    }
    }
    Salesperson()
    {
        sold=0;
        amount=0;
    }
    void salesid()
    {
        cout<<"\n Enter your id : ";
        cin>>id;
        cout<<"\n Enter your name :";
        cin>>name;
    }
    void sales();
   void disp(int i)
   {
    cout<<"\n"<<i+1<<" Id = "<<id<<"\n Name = "<<name<<"\n Products Sold = "<<sold<<"\n Sales = Rs:"<<amount;
   }
   static  void s_display();
   static void s_sales(int amt)
   {
       s_sold+=1;
       s_amount+=amt;
   }

};
void Salesperson::s_display()
{
    cout<<"\n Total Products Sold = "<<s_sold<<"\n Income = "<<s_amount;
}
void Salesperson::sales()
{
    int amt;
    cout<<"\n Enter the product price : ";
    cin>>amt;
    amount=amount+amt;
    sold++;
     s_sales(amt);
}

void Mobile::getdata()
{
    cout<<"\n Enter mobile code :";
    cin>>code;
    cout<<"\n Enter brand name :";
    cin>>name;
    cout<<"\n Enter model name :";
    cin>>model;
    cout<<"\n Enter amount :";
    cin>>amount;
}

int Salesperson::s_sold=0;
int Salesperson::s_amount=0;

int main()
{
    int n,m;
    cout<<"\n Enter the total no of m products : ";
    cin>>m;
    cout<<"\n\t\t Enter Product Details !! ";
    Mobile obj[m];
    for(int i=0;i<m;i++)
        obj[i].getdata();
    cout<<"\n\t\t Sales Id !!";
    cout<<"\n Enter total number of sales rep : ";
    cin>>n;
    Salesperson *s;
    s=new Salesperson [n];
    for(int i=0;i<n;i++)
        s[i].salesid();
    char choice='y';
    cout<<"\n\t\t Sales !! ";
    while(choice=='y'||choice=='Y')
    {
        int id;
        cout<<"\n Enter id : ";
        cin>>id;
        Salesperson::search(id,s,n,obj,m);
        cout<<"\n Would you like to continue sales?(y/n)";
        cin>>choice;
    }
    cout<<"\n\t\t Report !!";
    for(int i=0;i<n;i++)
        {
            s[i].disp(i);
        }
        Salesperson::s_display();
}



