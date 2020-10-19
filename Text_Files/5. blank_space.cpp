#include<iostream>
#include<fstream>
using namespace std;
int main()
{

    ofstream fput("blank_space_2.txt");
    ifstream fread("blanl_space+1.txt");
    char read,readd=fread.get();
    while(!fread.eof())
    {
        fput.put(readd);
        read=fread.get();
        if(read==32&&readd==32)
        {
               readd=read;
                read=fread.get();

        }


            readd=read;
        }

    fput.close();
    fread.close();
    }

