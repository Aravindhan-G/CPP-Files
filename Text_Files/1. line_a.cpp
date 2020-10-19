#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    ofstream fnme;
    fnme.open("line_A.txt");
    char input[200];
    cout<<"Enter the text and use '.' to end a line and use'!'terminate the input:";
    cin.getline(input,200,'!');
    fnme<<input<<endl;
    fnme.close();
    ifstream fread("line_A.txt");
    int count=0;
    string read;
    while(!fread.eof())
    {
        fread>>read;
        if(read=='A'||read=='a')
        {
            count+=1;
            while(read!='.')
            {
                cout<<read;
                fread>>read;
            }
            cout<<endl;
        }
        else
        {
            while(read!='.')
                fread>>read;
        }
    }
     cout<<"The Number of lines starting with a are:"<<count<<endl;
        fread.close();
    return 0;
}
