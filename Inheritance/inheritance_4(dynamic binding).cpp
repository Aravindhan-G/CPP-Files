#include<iostream>
using namespace std;
class shape
{
    protected:
    double d1,d2;
    public:
    virtual void get_data()
    {
    }
    virtual void display_area()
    {
    }
};
class triangle:public shape
{
public:
    void get_data()
    {
        cout<<"\n Enter breadth : ";
        cin>>d1;
        cout<<"\n Enter height : ";
        cin>>d2;
    }
    void display_area()
    {
        cout<<"\n Area of Triangle is : "<<0.5*d1*d2;
    }
};
class rectangle:public shape
{
    public:
    void get_data()
    {
        cout<<"\n Enter breadth : ";
        cin>>d1;
        cout<<"\n Enter length : ";
        cin>>d2;
    }
    void display_area()
    {
        cout<<"\n Area of Rectangle is : "<<d1*d2;
    }
};
class circle:public shape
{
public:
    void get_data()
    {
        cout<<"\n Enter radius : ";
        cin>>d1;
    }
     void display_area()
    {
        cout<<"\n Area of Rectangle is : "<<d1*d1;
    }
};
int main()
{
    shape *sh;
    int switchh;
    cout<<"\n Area Calculation.\n\t 1.Triangle\n\t 2.Rectangle\n\t 3.Circle.\n\t\t Enter your choice : ";
    cin>>switchh;
    switch(switchh)
    {
        case 1: sh=new triangle();
                sh->get_data();
                sh->display_area();
                break;
        case 2:sh=new rectangle();
                sh->get_data();
                sh->display_area();
                break;
        case 3: sh=new circle();
                sh->get_data();
                sh->display_area();
                break;

    }
}
