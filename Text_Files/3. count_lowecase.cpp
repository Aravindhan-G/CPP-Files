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
    ifstream fread("boot.txt");
    int count_lwrcse=0;
    char read;
    while(!fread.eof())
    {
        fread>>read;
        if(read>='a'&&read<='z')
            count_lwrcse+=1;
    }
    cout<<"The total no.of lower case alphabets found are:"<<count_lwrcse<<endl;
}
