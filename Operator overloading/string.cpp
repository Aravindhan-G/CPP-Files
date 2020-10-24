#include<iostream>
#include<cstring>
using namespace std;
class String
{
    char s1[40];
public:
    String(){strcpy(s1,"NULL");}
    String(char cpy[40])
    {
        strcpy(s1,cpy);
    }
    String operator + (String &rhs)
    {
        String temp;
        strcpy(temp.s1,s1);
        strcpy(temp.s1,rhs.s1);
        return temp;

    }
    bool operator <= (String &rhs)
    {
        if(strlen(s1)<=strlen(rhs.s1))
            return true;
        else
            return false;
    }
    bool operator >= (String &rhs)
    {
        if(strlen(s1)>=strlen(rhs.s1))
            return true;
        else
            return false;
    }
    bool operator == (String &rhs)
    {
        if(strcmp(s1,rhs.s1)==0)
            return true;
        else
            return false;
    }
    void print()
    {
        cout<<"The String is : "<<s1<<endl;
    }
};
int main()
{
    char get[40];
    cout<<"Enter String 1 and use '\\n' to terminate :";
    cin.getline(get,40,'\n');
    String s(get);
    s.print();
    cout<<"Enter String 2 and use '\\n' to terminate :";
    cin.getline(get,40,'\n');
    String s1(get);
    s1.print();
    cout<<"String Concatenation : "<<endl;
    String s2=s+s1;
    s.print();
    s1.print();
    s2.print();
    cout<<"String Check : <= >= == "<<endl;
    if(s<=s1)
        cout<<"\nThe first String is less than or equal to second string"<<endl;
    else
        cout<<"\nCheck condition for <= FAILS...string 1 is greater than string 2"<<endl;
    if(s2>=s1)
        cout<<"\nThe concatenated String is greater than or equal to second string"<<endl;
    else
        cout<<"\nCheck condition for >= FAILS...concatenated is less than compared string "<<endl;
    if(s==s1)
        cout<<"\nBoth strings are equal"<<endl;
    else
        cout<<"\nBoth strings are different"<<endl;
    }






