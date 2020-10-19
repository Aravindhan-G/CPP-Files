#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    ofstream finput("read.txt");
    string input;
    cout<<"Please enter the text and use'.' to end input:";
    getline(cin,input,'.');
    finput<<input;
    finput.close();
    ifstream fread("read.txt");
    ifstream freadd("read.txt");
    int count=0;
    char read;
    while(!fread.eof())
    {
        fread>>read;
        count+=1;
    }
    ofstream fwrite("write.txt");
    for(int i=1; i<=count; i++)
    {
        freadd.seekg(-i,ios::end);
        freadd>>read;
        cout<<read;
        fwrite<<read;
    }


}
