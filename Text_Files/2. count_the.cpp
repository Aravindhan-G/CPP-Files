#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
int main()
{
    ofstream finput("story.txt");
    string input;
    cout<<"Please enter the text and use'.' to end input:";
    getline(cin,input,'.');
    finput<<input;
    finput.close();
    char check[]="the";
    int count_the=0;
    ifstream fread("story.txt");
    char read,read_1[3];
    while(!fread.eof())
    {
        fread>>read;
        if(read=='t')
        {
            int ind=0;
            while(ind<3)
            {
                read_1[ind]=read;
                fread>>read;
                ind+=1;
            }
            int temp=0;
            for(int i=0;i<3;i++)
            {
                if(check[i]==read_1[i])
                    temp+=1;
            }
            if(temp==3)
                count_the+=1;
        }
    }
    cout<<"Total no of the in the story is:"<<count_the<<endl;
    fread.close();

}
