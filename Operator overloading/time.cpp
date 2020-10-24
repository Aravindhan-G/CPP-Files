#include<iostream>
using namespace std;
class Time
{
    int hrs,mint,sec;
public:
    Time(int hrs=0,int mint=0,int sec=0): hrs{hrs},mint{mint},sec{sec} {}
    Time operator + (const Time & rhs)
    {
        Time t;
        t.hrs=hrs+rhs.hrs;
        t.mint=mint+rhs.mint;
        t.sec=sec+rhs.sec;
        return t;
    }
    Time operator - (const Time & rhs)
    {
        Time t;
        t.hrs=hrs-rhs.hrs;
        t.mint=mint-rhs.mint;
        t.sec=sec-rhs.sec;
        return t;
    }
    bool operator > (const Time & rhs)
    {
        if(hrs>rhs.hrs&&mint>=rhs.mint&&sec>=rhs.sec)
            return true;
        else
            return false;
    }
    bool operator < (const Time & rhs)
    {
        if(hrs<rhs.hrs&&mint<=rhs.mint&&sec<=rhs.sec)
            return true;
        else
            return false;
    }
   Time operator = (const Time&rhs)
    {
        this->hrs=rhs.hrs;
        this->mint=rhs.mint;
        this->sec=rhs.sec;
        return *this;
    }
    Time operator += (const Time& rhs)
    {
        this->hrs=this->hrs+rhs.hrs;
        this->mint=this->mint+rhs.mint;
        this->sec=this->sec+rhs.sec;
    }
     Time operator -= (const Time& rhs)
    {
        this->hrs=this->hrs-rhs.hrs;
        this->mint=this->mint-rhs.mint;
        this->sec=this->sec-rhs.sec;
    }
    void print()
    {
        cout<<"Hours:Minute:Seconds = "<<hrs<<':'<<mint<<':'<<sec<<endl;
    }


};
int main()
{

    Time t(11,12,23);
    Time t1(1,12,12);
    cout<<"Arithmetic Operations: + -"<<endl;
    Time t2=t+t1;
    t2.print();
    Time t4=t2-t;
    t4.print();
    cout<<"Relation Operations : < >"<<endl;
    if(t4>t1)
        cout<<"Greater = Yes "<<endl;
    else
        cout<<"Greater = No " <<endl;
    if(t1<t)
        cout<<"Lesser = Yes " <<endl;
    else
        cout<<"Lesser = No " <<endl;
    cout<<"Assignment Operation: = "<<endl;
    Time t3=t2;
    t3.print();
    cout<<"Compound Assignment operation: += -="<<endl;
    t4+=t2;
    t4.print();
    t4-=t2;
    t4.print();
}
