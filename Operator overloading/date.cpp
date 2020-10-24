#include<iostream>
#include<cmath>
using namespace std;
class Date
{
    int dd,mm,yy;
public:
    Date(int dd=0,int mm=0,int yy=0):dd{dd},mm{mm},yy{yy} {}
    int operator >> (int &date)
    {
        if(mm%2!=0||mm==8&&date>31)
        {
            if(date>=365)
            {
                int temp=date-((date/365)*365);
                dd+=round(date/365)+round(temp/12)+1;
                while(temp>31)
                {
                    mm+=temp/31;
                    temp/=31;
                }
                 while(dd>31)
                {
                    mm+=dd/31;
                    dd%=31;
                }
                while(mm>12)
                {
                    yy+=mm/12;
                    mm%=12;
                }
                while(date>=365)
                {
                    yy+=round(date/365);
                    date=date/365;
                }
                return 0;
            }
            dd+=(date-round(date/31)*31)+1;
             while(dd>31)
                {
                    mm+=dd/31;
                    dd%=31;
                }
            while(date>31)
           {
               mm+=date/31;
                date/=31;
           }
           while(mm>12)
                {
                    yy+=mm/12;
                    mm%=12;
                }
                return 0;
            return 0;
        }
       if(mm%2==0&&mm!=8&&date>30)
        {
           if(date>=365)
            {
                int temp=date-((date/365)*365);
                dd+=round(date/365)+round(temp/12)+3;
                while(temp>30)
                {
                    mm+=temp/30;
                    temp/=30;
                }
                 while(dd>30)
                {
                    mm+=dd/30;
                    dd%=30;
                }
                while(mm>12)
                {
                    yy+=mm/12;
                    mm%=12;
                }
                 while(date>=365)
                {
                    yy+=round(date/365);
                    date=date/365;
                }


                return 0;
            }
            dd+=(date-round(date/30)*30)+3;
            while(dd>30)
                {
                    mm+=dd/30;
                    dd%=30;
                }
            while(date>30)
           {
               mm+=date/30;
                date/=30;
           }
           while(mm>12)
                {
                    yy+=mm/12;
                    mm%=12;
                }
                return 0;

            return 0;
        }
        if(date>=28&&mm==02&&yy%4!=0)
        {
            if(date>=365)
            {
                int temp=date-((date/365)*365);
                dd+=round(date/365)+round(temp/12)+1;
                 while(dd>28)
                {
                    mm+=dd/28;
                    dd%=29;
                }
                while(temp>28)
                {
                    mm+=temp/28;
                    temp/=28;
                }
                 while(date>=365)
                {
                    yy+=date/365;
                    date/=365;
                }
                return 0;
            }
            dd+=(date-round(date/28)*28)+1;
            while(dd>28)
                {
                    mm+=dd/28;
                    dd%=28;
                }
            while(date>28)
           {
                mm+=date/28;
                date/=28;
           }

           return 0;
        }
        if(date>=29&&mm==02&&yy%4==0)
        {
            if(date>=366)
            {
                int temp=date-((date/365)*365);
                dd+=round(date/365)+round(temp/12)+1;
                while(dd>29)
                {
                    mm+=dd/29;
                    dd%=29;
                }
                while(temp>29)
                {
                    mm+=temp/29;
                    temp/=29;
                }
                 while(date>=366)
                {
                    yy+=date/366;
                    date/=366;
                }
                return 0;
            }
             dd+=(date-round(date/29)*29)+1;
           while(dd>29)
                {
                    mm+=dd/29;
                    dd%=29;
                }
            while(date>29)
           {
                mm+=date/29;
                date/=29;
           }

           return 0;
        }
    }
    void print()
    {
        cout<<"Date:Month:Year = "<<dd<<':'<<mm<<':'<<yy<<endl;
    }
};

int main()
{
    int movedate,dd,mm,yy;
    cout<<"\n Enter date in dd mm yyyy format : ";
    cin>>dd>>mm>>yy;
    Date d(dd,mm,yy);
    cout<<"\nEnter No of Days to be moved : ";
    cin>>movedate;
    if(movedate>0)
    {
        d>>movedate;
        d.print();
    }

    return 0;
}
