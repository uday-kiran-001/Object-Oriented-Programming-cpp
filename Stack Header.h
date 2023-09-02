#include<iostream>
#define size 8

using namespace std;


class Stack{
  private:
    int arr[size];
    int top=-1;
  public:
    void Push(int x);
    void Pop();
    int peek();
    void display();
    bool IsEmpty();
    bool IsFull();
};

void Stack::Push(int x)
{
    if(top!=size-1)arr[++top]=x;
}

void Stack::Pop()
{
    if(top!=-1) top=top-1;
}

int Stack::peek()
{
    if(top!=-1){ return arr[top];}
}

void Stack::display()
{
    int n=top, t=0;
    int arr2[n+1];
    while(n!=-1)
    {
                                // FOR DISPLAYING, WE HAVE TO TRAVERSE THE STACK 
        arr2[t]=arr[n];         // FOR TRAVERSING, WE HAVE TO POP OUT THE ELEMENT AFTER VISTING IT 
        t++;                    // IF WE POP, WE LOSE THE DATA
        n--;                    // SO I COPIED INTO ANOTHER STACK 
    }
    while(n!=top)
    {
        t=t-1;
        arr[n+1]=arr2[t];
        n++;
    }
    free(arr2);
}

bool Stack::IsEmpty()
{
    if(top==-1){ return true;}
    else {return false;}
}

bool Stack:: IsFull()
{
    if(top==(size-1)) {return true;}
    else {return false;}
}
