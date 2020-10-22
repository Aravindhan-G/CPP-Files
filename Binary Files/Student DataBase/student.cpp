#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;
class STUDENT
{
    char S_Admno[10];
    char S_Name[30];
    int Percentage;
public:
    void EnterData()
    {
        cout<<"Enter your Admission Number :";
        cin>>S_Admno;
        cout<<"Enter Student Name :";
        cin>>S_Name;
        cout<<"Enter the Marks Percentage :";
        cin>>Percentage;
    }
    void DisplayData()
    {
        cout<<"Admission Number = "<<S_Admno<<endl<<"Name = "<<S_Name<<endl<<"Percentage = "<<Percentage<<endl;
    }
    static void readfile()
    {
        STUDENT s;
        int count=0;
        fstream fread("STUDENT.DAT",ios::binary | ios::in |ios::out);
        while(fread.read((char*)&s,sizeof(STUDENT)))
        {
            count++;
            s.DisplayData();
        }
        cout<<"\nNo of records found in the file are = "<<count;
        fread.close();
    }
        static void Perc_check()
    {
        STUDENT ob;
        fstream fil("STUDENT.DAT",ios::binary | ios::in |ios::out);
        while(fil.read((char*)&ob,sizeof(STUDENT)))
        {
            int chk=ob.ReturnPercentage();
            if(chk)
                ob.DisplayData();
        }
        fil.close();

    }

    int ReturnPercentage()
    {
        if(Percentage >= 75)
            return 1;
        else
            return 0;
    }
};





int main()
{
    fstream file("STUDENT.DAT",ios::binary |ios::out |ios::in |ios::trunc);
    int num;
    cout<<"Enter total number of students :";
    cin>>num;
    STUDENT obj[num];
    for(int i=0;i<num;i++)
    {
        obj[i].EnterData();
        file.write((char *)&obj[i],sizeof(STUDENT));
    }
    file.close();
    cout<<"\n \t\t\t\t   Display of all records"<<endl;
    STUDENT::readfile();
    cout<<"\n \t\t\t\t   Display of record with 75% or more"<<endl;
    STUDENT::Perc_check();
    return 0;
}
