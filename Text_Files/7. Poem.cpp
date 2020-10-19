#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>
using namespace std;
class poem
{
    int lines_s,lines_m,no_of_words,lowercase,uppercase,no_of_lines,avg_size;
    char ch,word[20],line[80];
    public:
        void lines_start()
        {
            ifstream fin;
            fin.open("poem.txt");
            if(!fin)
            {
                cout<<"ERROR";
                exit(5);
            }
            else
            {
               lines_s=0;
               lines_m=0;
               while(!fin.eof())
               {
                  fin.getline(line,80);
                  if(line[0]=='S' || line[0]=='s')
                  lines_s++;
                  if(line[0]=='M' || line[0]=='m')
                  lines_m++;

               }
               cout<<"\nThe no of lines starting with s/S is"<<lines_s;
               cout<<"\nThe no of lines starting with m/M is"<<lines_m;
            }
          fin.close();
       }
       void words_count()
        {
            ifstream fin;
            fin.open("poem.txt");
            if(!fin)
            {
                cout<<"ERROR";
                exit(5);
            }
            else
            {
            no_of_words=0;
            while(!fin.eof())
            {
                fin>>word;
                no_of_words++;
            }
            fin.close();
            cout<<"\nThe no of words is"<<no_of_words-1;
            }
        }
       void letter_case()
        {
           ifstream fin;
		   fin.open("poem.txt");
		   if(!fin)
            {
                cout<<"ERROR";
                exit(5);
            }
            else
           {
		    lowercase=0;
		    uppercase=0;
			while(!fin.eof())
                {
				  fin>>ch;
				  {
				      if(ch==NULL)
                        exit(5);
                      else
                       {
                        if(ch>='a' && ch<='z')
                        lowercase++;
                        if(ch>='A' && ch<='Z')
                        uppercase++;
                        }
				  }
                }
                fin.close();
			    cout<<"The no.of Lower Case alphabets are"<<lowercase<<endl;
			    cout<<"The no.of Upper Case alphabets are"<<uppercase<<endl;
            }
           }
       void lines_count()
        {
            ifstream fin;
            fin.open("poem.txt");
            if(!fin)
            {
                cout<<"ERROR";
                exit(5);
            }
            else
            {
               no_of_lines=0;
               while(!fin.eof())
               {
                  fin.getline(line,80,'\n');
                  no_of_lines++;
               }
               cout<<"\nThe no of lines is "<<no_of_lines-1;
            }
          fin.close();
       }
       void avg_word_size()
        {
            ifstream fin;
            fin.open("poem.txt");
            if(!fin)
            {
                cout<<"ERROR";
                exit(5);
            }
            else
            {
                int sum=0;
                while(!fin.eof())
                {
                    fin>>word;
                    if(word==NULL)
                        exit(5);
                    else
                    {
                    sum+=strlen(word);
                    }
                }
                fin.close();
                cout<<"\nThe average word size"<<sum/no_of_words<<endl;

             }
        }
        void display_words()
        {
            ifstream fin;
            fin.open("poem.txt");
            if(!fin)
            {
                cout<<"ERROR";
                exit(5);
            }
            else
            {
            no_of_words=0;
            while(!fin.eof())
            {
                fin>>word;
                cout<<"\nThe word is :"<<word<<"\tThe size is :"<<strlen(word);
            }
            fin.close();

            }
        }
};
int main()
{

    poem p;
    ofstream fwrite;
    fwrite.open("poem.txt");
    char ch[200];
    cout<<"Enter the contents of file. Use enter key for each line Press Tab to terminate:"<<endl;
    cin.getline(ch,200,'\t');
    fwrite<<ch<<endl;
    fwrite.close();
    int choice;
    char option='y';
    cout<<"\nEnter:\n1)\tTo print the number of lines starting with s and m\n2)\tTo print the number of words\n3)\tTo print the number of lowercase and uppercase letters\n4)\tTo print the number of lines\n5)\tTo print the average word length\n6)\tTo print every word and its length\n7)\tTo Exit"<<endl;
    while(option=='y'||option=='Y')
    {
        cin>>choice;
    switch(choice)
    {
    case 1:
        {
            p.lines_start();
            break;
        }
    case 2:
        {
            p.words_count();
            break;
        }
    case 3:
        {
            p.letter_case();
            break;
        }
    case 4:
        {
            p.lines_count();
            break;
        }
    case 5:
        {
            p.words_count();
            p.avg_word_size();
            break;
        }
    case 6:
        {
            p.display_words();
            break;
        }
    case 7:
        {
            exit(5);
        }
    default:
        {
            cout<<"\Wrong choice!!Enter choice between 1 and 7 only!!";
            exit(5);
        }
    }
    cout<<"Do you want to continue again?press y to continue";
    cin>>option;
    }
    return 0;
}
