#include<iostream>
using namespace std;
class fool;
class FriendDemo
{
    protected:
    char name[30];
    public:
        friend class fool;

};
class fool
{
 int id;
 public:
     static void friendfun(FriendDemo f,fool f2[],int n)
     {
    cout<<"\n Enter Your Name : ";
    cin>>f.name;
    cout<<"\n Hi "<<f.name<<" this program is a friend function demonstration."<<endl;
    for(int i=0;i<n;i++)
        cin>>f2[i].id;
}
};


int main()
{
    FriendDemo f;
    fool f2[5];
    fool::friendfun(f,f2,5);
    return 0;
}
