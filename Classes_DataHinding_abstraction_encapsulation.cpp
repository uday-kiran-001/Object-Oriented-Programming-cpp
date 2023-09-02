#include<iostream>
#include"Stack Header.h"

using namespace std;

void Assign_Text(int x)
{
    switch(x){
        case 0:cout<<"Zero "; break;
        case 1:cout<<"One "; break;
        case 2:cout<<"Two "; break; 
        case 3:cout<<"Three "; break;
        case 4:cout<<"Four "; break;
        case 5:cout<<"Five "; break;
        case 6:cout<<"Six "; break;
        case 7:cout<<"Seven "; break;
        case 8:cout<<"Eight "; break;
        case 9:cout<<"Nine "; break;
    }
}

int main()
{
    int t=0, x,n, flag=0;
    Stack s1, s2,s3,s4;
    while(!t)
    {
        cout<<"1. GET NUMBER\n";
        cout<<"2. DIGIT IN TEXT\n";
        cout<<"3. REVERSE\n";
        cout<<"4. PALINDROME CHECK\n";
        cout<<"5. EXIT\n";
        
        cout<<"ENTER THE OPTION: ";
        cin>>x;
        cout<<"\n";
        switch(x)
        {
            case 1:
                while(!s1.IsEmpty())
                {
                    s1.Pop();
                }
                cout<<"ENTER THE NUMBER ( max size taken as 8 ) :";
                cin>>n;
                for(int i=n;i!=0;)
                {
                    s1.Push(i%10);
                    i=i/10;
                }
                break;


            case 2:
                while(!s1.IsEmpty())
                {
                    s2.Push(s1.peek());
                    Assign_Text(s1.peek());
                    s1.Pop();
                }
                while(!s2.IsEmpty())
                {
                    s1.Push(s2.peek());
                    s2.Pop();
                }
                cout<<"\n";

                break;


            case 3:
                while(!s1.IsEmpty())            // IN STACK WE CAN ACCESS ONLY THE TOP ELEMENT
                {                               // WE HAVE TO POP THE TOP ELEMENT TO ACCESS THE NEXT ELEMENT
                    s2.Push(s1.peek());         // WHEN POPPING, WE LOSE THE ELEMENT 
                    s1.Pop();                   // SO WE HAVE TO COPY IT INTO ANOTHER STACK
                }
                while(!s2.IsEmpty())
                {
                    cout<<s2.peek()<<" ";
                    s1.Push(s2.peek());
                    s2.Pop();
                }
                cout<<"\n";
                break;


            case 4:
                while(!s1.IsEmpty())
                {
                    s2.Push(s1.peek());
                    s3.Push(s1.peek());
                    s1.Pop();
                }
                while(!s2.IsEmpty())
                { 
                    s1.Push(s2.peek());
                    s4.Push(s2.peek());
                    s2.Pop();
                }
                while(!s4.IsEmpty() && !s3.IsEmpty())
                {
                    if(s4.peek()!=s3.peek()){ cout<<"NOT A PALINDROME\n";flag=0; break;}
                    else flag=1;
                    s4.Pop();       s3.Pop();
                }
                while(!s4.IsEmpty())
                { s4.Pop();  }
                while(!s3.IsEmpty())
                { s3.Pop();  }
                if(flag) cout<<"YES !!! IT's A PALINDROME\n";
                break;


            case 5:t=1;
                break;

        }
        flag=0;
        cout<<"\n\n";
    }


    return 0;
}