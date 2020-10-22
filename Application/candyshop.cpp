#include<iostream>
#include<cstdlib>
using namespace std;
class Machine
    {
        int candies_sold,chips_sold,gum_sold,cookies_sold;
        long int total_sales,cur_sale;
        int candies_cost,chips_cost,gum_cost,cookies_cost;
    public:
        Machine()
        {
            candies_sold=0;
            chips_sold=0;
            gum_sold=0;
            cookies_sold=0;
            total_sales=0;
            cur_sale=0;
        }
        Machine(int c1,int c2,int c3,int c4)
        {
            candies_sold=0;
            chips_sold=0;
            gum_sold=0;
            cookies_sold=0;
            total_sales=0;
            cur_sale=0;
            candies_cost=c1;
            chips_cost=c2;
            gum_cost=c3;
            cookies_cost=c4;
        }
        void products_sold();
        void make_order();
        void confirm_order();
        void final_review();
        void display_order();

    };
void Machine::products_sold()
{
    cout<<"\n \t\t\t\t WELCOME TO CANDY MACHINE";
    cout<<"\n\n The various products sold by machine are:\n\t 1. Candies = Rs."<<candies_cost<<"\n\t 2.Chips = Rs."<<chips_cost<<"\n\t 3.Gums = Rs."<<gum_cost<<"\n\t 4.Cookies = Rs."<<cookies_cost;
    system("pause");
}
void Machine::display_order()
{
    cout<<"\n Product  \t\t Items          \t\t Cost";
    cout<<"\n 1.Candies \t\t"<<candies_sold<<"\t\t"<<candies_sold*candies_cost;
    cout<<"\n 2.Chips \t\t"<<chips_sold<<"\t\t"<<chips_sold*chips_cost;
    cout<<"\n 3.Gum      \t\t"<<gum_sold<<"\t\t"<<gum_sold*gum_cost;
    cout<<"\n 4.Cookies \t\t"<<cookies_sold<<"\t\t"<<cookies_sold*cookies_cost;
    cur_sale=(candies_sold*candies_cost)+(chips_sold*chips_cost)+(gum_sold*gum_cost)+(cookies_sold*cookies_cost);
    cout<<"\n\t\t\t\t Total cost ="<< cur_sale;
    total_sales+=cur_sale;
    system("pause");
}
void Machine::make_order()
{
    cout<<"\n\n Enter the no of candies required:";
    cin>>candies_sold;
    cout<<"\n\n Enter the no of chips required:";
    cin>>chips_sold;
    cout<<"\n\n Enter the no of gums required:";
    cin>>gum_sold;
    cout<<"\n\n Enter the no of cookies required:";
    cin>>cookies_sold;
    system("pause");
    display_order();


}
void Machine::confirm_order()
{
    cout<<"\n 1.Place order \n 2.Edit order \n 3.Cancel order \n\t Enter your choice?";
    int choice;
    cin>>choice;
    switch(choice)
    {
    case 1:{
        int temp,balance;
        cout<<"Please Enter the amount to be paid to pay :";
        cin>>temp;
        balance=temp-cur_sale;
        cout<<"\n PAYMENT DONE!!!";
        cout<<"\n PAID = "<<temp;
        cout<<"\n BALANCE = "<<balance;
        break;
        }
    case 2:
        {
           make_order();
           int temp,balance;
        cout<<"Please Enter the amount to be paid to pay :";
        cin>>temp;
        balance=temp-cur_sale;
        cout<<"\n PAYMENT DONE!!!";
        cout<<"\n PAID = "<<temp;
        cout<<"\n BALANCE = "<<balance;
        break;

        break;

        }
    case 3:
        {
          candies_sold=0;
            chips_sold=0;
            gum_sold=0;
            cookies_sold=0;
            total_sales=0;
            cur_sale=0;
          display_order();

          break;
        }
}
}


void Machine::final_review()
{
    cout<<"\n Total sales = "<<total_sales;
}
 int main()
 {
     int c1,c2,c3,c4;
     Machine m(10,20,30,40);
     char temp='y';
     while(temp=='y'||temp=='Y')
     {

        m.products_sold();
       m.make_order();
       m.confirm_order();

       cout<<"\n Do you wish to continue(y/n)?";
       cin>>temp;
     }
m.final_review();
return 0;

 }







