#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
int main()
{
    ofstream finput("boot.txt");
    string input;
    cout<<"Please enter the text and use'.' to end input:";
    getline(cin,input,'.');
    finput<<input;
    finput.close();
    int count_this=0;
    int count_these=0;
    char get[100];
    ifstream fread("boot.txt");
    while(!fread.eof())
    {
        fread>>get;
        if(strcmp(get,"this")==0)
        {
            count_this++;
        }
        if(strcmp(get,"these")==0)
        {
            count_these++;
        }

    }
    fread.close();
    cout<<"No of this in the paragraph is:"<<count_this<<endl;
    cout<<"No of these in the paragraph is:"<<count_these<<endl;
    return 0;
}
