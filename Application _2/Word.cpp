#include<iostream>
#include<cstring>
using namespace std;
class Word
{
    char s1[20];
public:
    Word()
    {
        strcpy(s1,"NULL");
    }
    Word(char cpy[20])
    {
        strcpy(s1,cpy);
    }
     bool operator <= (Word &rhs)
    {
        if(strlen(s1)<=strlen(rhs.s1))
            return true;
        else
            return false;
    }
    bool operator >= (Word &rhs)
    {
        if(strlen(s1)>=strlen(rhs.s1))
            return true;
        else
            return false;
    }
    bool operator == (Word &rhs)
    {
        if(strcmp(s1,rhs.s1)==0)
            return true;
        else
            return false;
    }
        bool operator != (Word &rhs)
    {
        if(strcmp(s1,rhs.s1)!=0)
            return true;
        else
            return false;
    }
    bool operator < (Word &rhs)
    {
        if(strlen(s1)<strlen(rhs.s1))
            return true;
        else
            return false;
    }
    bool operator > (Word &rhs)
    {
        if(strlen(s1)>strlen(rhs.s1))
            return true;
        else
            return false;
    }
};
int main()
{
    Word w1("Aravind");
    Word w2("Gobi");
    if(w1>w2)
        cout<<"\n > -- True";
    else
        cout<<"\n > -- False";
     if(w1<w2)
        cout<<"\n < -- True";
    else
        cout<<"\n < -- False";
     if(w1>=w2)
        cout<<"\n >= -- True";
    else
        cout<<"\n >= -- False";
     if(w1<=w2)
        cout<<"\n <= -- True";
    else
        cout<<"\n <= -- False";
     if(w1==w2)
        cout<<"\n == -- True";
    else
        cout<<"\n == -- False";
     if(w1!=w2)
        cout<<"\n != -- True";
    else
        cout<<"\n != -- False";
    return 0;
}
