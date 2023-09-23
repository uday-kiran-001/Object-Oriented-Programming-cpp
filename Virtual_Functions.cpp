#include<iostream>
#include<string>
#include<vector>

#define MAX 5

using namespace std;

class Student{
    protected:
        string name;
        string Roll_num;
    public:
        virtual void Display()=0;
        bool Check_Roll_num(string s)
        {
            if(s==Roll_num){return true;}
            else{return false;}
        }
};


class Pg_Student:virtual public Student{
    protected:
        string course1;
        string course2;
        string course3;
    public:
        void Display()
        {
            cout<<"Course - 1    : "<<course1<<endl;
            cout<<"Course - 2    : "<<course2<<endl;
            cout<<"Course - 3    : "<<course3<<endl;
        }
};


class Research_Student:virtual public Student{
    protected:
        string course_1;
        string Research_area;
    public:
        void Display()
        {
            cout<<"Course - 1    : "<<course_1<<endl;
            cout<<"Research Area : "<<Research_area<<endl;
            
        }
};


class T_A:public Pg_Student, public Research_Student{
    string course;
    string role;
    public:
        void Set(string n,string rn,string c,string r,string c1,string c2,string c3)
        {
            name=n;
            Roll_num=rn;
            course=c;
            role=r;
            course1=c1;
            course2=c2;
            course3=c3;
        }
        void Set(string n,string rn,string c,string r,string c1,string R_a)
        {
            name=n;
            Roll_num=rn;
            course=c;
            role=r;
            course_1=c1;
            Research_area=R_a;
        }
        void Display()
        {
            cout<<"Name          : "<<name<<endl;
            cout<<"Roll Number   : "<<Roll_num<<endl;
            cout<<"Course        : "<<course<<endl;
            cout<<"Role          : "<<role<<endl;
            if(role=="Pg Student")
            {
                Pg_Student::Display();
            }else{
                Research_Student::Display();
            }
        }
};






int main()
{
    int count=0,flag=0,tag=0;
    int t=1,k,l;
    string name,Roll_num,course1,course2,course3,course_1,course;
    string Research_area,role;
    T_A arr[MAX];
    
    while(t)
    {
        cout<<"\n1. SET DETAILS                           - ENTER 1\n";
        cout<<"2. DISPLAY                               - ENTER 2\n";
        cout<<"3. EXIT                                  - ENTER 3\n";
        cin>>k;
        switch(k)
        {
            case 1:{
                cout<<"Enter the Name: ";                   cin>>name;
                cout<<"Enter the Roll Number: ";            cin>>Roll_num;
                for(int i=0;i<count;++i)
                {
                    if(arr[i].Check_Roll_num(Roll_num))
                    {
                        cout<<"\nCANNOT DO TWO ROLES BY ONE STUDENT !!!\n";
                        tag=1;
                        break;
                    }
                }
                if(!tag)
                {
                    cout<<"Select a role: "<<endl;
                    cout<<"1. PG Student                                - ENTER 1\n";
                    cout<<"2. Research Student                          - ENTER 2\n";
                    cin>>l;
                    switch(l)
                    {
                        case 1:{
                            role="Pg Student";
                            cout<<"Enter the course: ";             cin>>course;
                            cout<<"Enter Course - 1: ";             cin>>course1;
                            while(course1==course){
                                cout<<"Course is already taken !!!\nEnter another course - 1: ";
                                cin>>course1;
                            }
                            cout<<"Enter Course - 2: ";             cin>>course2;
                            while(course2==course || course1==course2){
                                cout<<"Course is already taken !!!\nEnter another course - 2: ";
                                cin>>course2;
                            }
                            cout<<"Enter Course - 3: ";             cin>>course3;
                            while(course3==course || course1==course3 || course2==course3){
                                cout<<"Course is already taken !!!\nEnter another course - 3: ";
                                cin>>course2;
                            }
                            arr[count++].Set(name,Roll_num,course,role,course1,course2,course3);
                            
                            break;
                        }
                        case 2:{
                            role="Research Student";
                            cout<<"Enter the Course       : ";                cin>>course;
                            cout<<"Enter the Research Area: ";                cin>>Research_area;
                            cout<<"Enter Course - 1: ";                       cin>>course_1;
                            while(course_1==course){
                                cout<<"Course is already taken !!!\nEnter another course - 1: ";
                                cin>>course_1;
                            }
                            arr[count++].Set(name,Roll_num,course,role,course_1,Research_area);

                            break;
                        }
                        default:{
                            cout<<"ENTER A VALID CHOICE !!!\n";
                        }
                    }
                    tag=0;
                }
                
                break;
            }
            case 2:{
                cout<<"Enter the Roll Number : ";           cin>>Roll_num;
                for(int i=0;i<count;++i)
                {
                    if(arr[i].Check_Roll_num(Roll_num)){
                        arr[i].Display();
                        flag=1;
                        break;
                    }
                }
                if(!flag){
                    cout<<"You have enteres a wrong Roll Number !!!\n";
                }

                break;
            }
            case 3:{
                t=0;
                break;
            }
            default:{
                cout<<"ENTER A VALID CHOICE !!!\n";
            }
        }
        
    }
    
    
    
    
    return 0;
}