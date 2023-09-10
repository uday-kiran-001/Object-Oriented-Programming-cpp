#include<iostream>
#include<vector>

using namespace std;

class C_L_L{
    private:
        int data;
        C_L_L* next;
    public:
        C_L_L(){
            data=0;
            next=NULL;
        }
        C_L_L* Create_A_Node(int);
        C_L_L* Insert(C_L_L* tail,int x);
        void Display(C_L_L* tail);
        C_L_L* Insert(C_L_L* tail,int x,int position);
        C_L_L* Delete(C_L_L* tail);
        C_L_L* Delete(C_L_L* tail,int position);
        int Search(C_L_L* tail,int x);
        ~C_L_L(){}
};

C_L_L* C_L_L:: Create_A_Node(int x)
{
    C_L_L* temp=new C_L_L;
    temp->data=x;
    temp->next=NULL;
    return temp;
}

C_L_L* C_L_L::Insert(C_L_L* tail,int x)
{ 
    C_L_L* temp=Create_A_Node(x);
    if(tail)
    {
        temp->next=tail->next;
        tail->next=temp;
    }else{
        temp->next=temp;
        tail=temp;
    }
    cout<<"SUCCESSFULLY INSERTED !!!\n";
    return tail;
    
}


C_L_L* C_L_L::Insert(C_L_L* tail,int x,int position)
{
    int count=1,flag=1;
    C_L_L* prev=tail,*temp=tail->next;
    while(count!=position)
    {
        prev=temp;
        temp=temp->next;
        if(temp==tail->next)
        {
            flag=0;
            break;
        }
        count++;
    }
    if(flag)
    {
        C_L_L* temp1=Create_A_Node(x);
        temp1->next=prev->next;
        prev->next=temp1;
        cout<<"SUCCESSFULLY INSERTED !!!\n";
        return tail;
    }else{
        if(count+1==position)
        {
            C_L_L* temp1=Create_A_Node(x);
            temp1->next=tail->next;
            tail->next=temp1;
            tail=temp1;
            cout<<"SUCCESSFULLY INSERTED !!!\n";
        }else{
            cout<<"ENTER A VALID POSITION !!!   (  TOTAL NO. OF NODES = "<<count<<"  )"<<endl;
        }
        return tail;
    }
    
}

C_L_L* C_L_L:: Delete(C_L_L* tail)
{
    if(tail==NULL)
    {
        cout<<"LIST IS ALREADY EMPTY !!!\n\n";
        return NULL;
    }
    else if(tail->next==tail)
    {
        delete(tail);
        tail=NULL;
        cout<<"SUCCESSFULLY DELETED !!!\n";
        return NULL;
    }else{
        C_L_L* temp=tail->next;
        tail->next=tail->next->next;
        delete(temp);
        temp=NULL;
        cout<<"SUCCESSFULLY DELETED !!!\n";
        return tail;
    }
}

C_L_L* C_L_L::Delete(C_L_L* tail,int position)
{
    if(tail)
    {
        int count=1,flag=1;
        C_L_L* prev=tail,*temp=tail->next;
        while(count!=position)
        {
            prev=temp;
            temp=temp->next;
            if(temp==tail->next)
            {
                flag=0;
                break;
            }
            count++;
        }
        if(flag)
        {
            C_L_L* temp=prev->next;
            prev->next=prev->next->next;
            if(temp==tail){
                tail=prev;
            }
            delete(temp);
            temp=NULL;
           cout<<"SUCCESSFULLY DELETED !!!\n";
        }else{
            cout<<"ENTER A VALID POSITION !!!   (  TOTAL NO. OF NODES = "<<count<<"  )"<<endl;
            
        }
    }else{
        cout<<"THE LIST IS ALREADY EMPTY !!! \n\n";
    }
    return tail;
}

int C_L_L::Search(C_L_L* tail,int x)
{
    int count=1,flag=1;
    C_L_L* prev=tail,*temp=tail->next;
    while(temp->data!=x)
    {
        prev=temp;
        temp=temp->next;
        if(temp==tail->next)
        {
            flag=0;
            break;
        }
        count++;
    }
    if(flag)
    {
        return count;
    }else{
        cout<<"THE GIVEN NUMBER IS NOT PRESENT !!!"<<endl;
        return -1;
    }
}

void C_L_L::Display(C_L_L* tail)
{
    if(tail)
    {
        C_L_L* temp=tail->next;
        cout<<temp->data<<"  ";
        temp=temp->next;
        while(temp!=tail->next)
        {
            cout<<temp->data<<"  ";
            temp=temp->next;
        }
        cout<<endl;
    }else{
        cout<<"LIST IS EMPTY !!!!!\n\n";
    }
}




int main()
{
    int t=1,k,p,x,index;
    C_L_L* tail=NULL;
    
    
    while(t)
    {
        cout<<"INSERT                           - ENTER 1\n";
        cout<<"DELETE                           - ENTER 2\n";
        cout<<"SEARCH                           - ENTER 3\n";
        cout<<"DISPLAY                          - ENTER 4\n";
        cout<<"EXIT                             - ENTER 5\n";
        cout<<"ENTER THE CHIOCE: ";
        cin>>k;
        
        switch(k){
            case 1:{
                cout<<"ENTER THE POSITION TO INSERT: ";
                cin>>p;
                cout<<"ENTER THE VALUE: ";
                cin>>x;
                if(p>1 && tail==NULL)
                {
                    cout<<"LIST IS EMPTY !!!\nENTER A VALID POSITION TO INSERT\n\n";
                }
                else if(p==1)
                {
                    tail=tail->Insert(tail,x);
                }else{
                    tail=tail->Insert( tail,x,p);
                }
                cout<<endl;
                break;
            }
            case 2:{
                cout<<"ENTER THE POSITION TO BE DELETED: ";
                cin>>p;
                if(p==1)
                {
                    tail=tail->Delete(tail);
                }else{
                    tail=tail->Delete(tail,p);
                }
                cout<<endl;
                break;
            }
            case 3:{
                if(tail){
                    cout<<"ENTER THE NUMBER TO BE SEARCHED: ";
                    cin>>x;
                    index=tail->Search(tail,x);
                    if(index!=-1)
                    {
                        cout<<"THE GIVEN NUMBER IS PRESENT AT POPSITION: "<<index<<endl;
                    }
                }else{
                    cout<<"THE LIST IS ALREADY EMPTY !!! \n\n";
                }
                cout<<endl;
                break;
            }
            case 4:{
                tail->Display(tail);
                cout<<endl;
                break;
            }
            case 5:{
                t=0;
                cout<<endl;
                break;
            }
            default:{
                cout<<"ENTER A VALID CHOICE !!!\n";
                cout<<endl;
            }
            
        }
    }
    
    cout<<"DELETING THE ENTIRE LINKED LIST.............\n";
    
    for(int i=0;tail!=NULL;++i)
    {
        tail=tail->Delete( tail);
    }
    cout<<"MEMORY IS CLEARED SUCCESSFULLY !!!\n";
    
    
    return 0;
}