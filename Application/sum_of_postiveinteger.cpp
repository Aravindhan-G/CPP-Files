#include<iostream>
#include<fstream>
#include <bits/stdc++.h>
#include<cmath>
using namespace std;
int main()
{
    ifstream file("sample.txt");
    int sum=0,temp=0;
    string str;
    while(file>>str)
    {
    for(int ind=0;str[ind]!='\0';ind++)
    {
        if(isdigit(str[ind]))
         temp=(temp*10)+(str[ind]-'0');
        else{
        sum+=temp;
        temp=0;}
    }
    }
    sum+=temp;
    cout<<"\n sum is :"<<sum;



    }

