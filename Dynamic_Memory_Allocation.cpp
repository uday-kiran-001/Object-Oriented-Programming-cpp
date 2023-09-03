#include<iostream>
using namespace std;

class Doubly_Linked_List
{   
    private:
        int data;
        Doubly_Linked_List* left;
        Doubly_Linked_List* right;
    public:
        Doubly_Linked_List* Create_A_Node(int x);
        Doubly_Linked_List* Insert(int x,Doubly_Linked_List* obj);
        void Display(Doubly_Linked_List* obj);
        Doubly_Linked_List* Delete(int pos,Doubly_Linked_List* obj);
        Doubly_Linked_List* Merge(Doubly_Linked_List* obj1,Doubly_Linked_List* obj2);
};

Doubly_Linked_List* Doubly_Linked_List::Create_A_Node(int x)
{
        Doubly_Linked_List* temp=new Doubly_Linked_List;
        temp->data=x;
        temp->left=NULL;
        temp->right=NULL;
        return temp;
}

Doubly_Linked_List* Doubly_Linked_List::Insert(int x,Doubly_Linked_List* obj)
{
    Doubly_Linked_List* temp=obj;
    Doubly_Linked_List* temp2=Create_A_Node(x);
    if(obj==NULL)
    {
        return temp2;
    }else{
        while(temp)
        {
            if(temp->data>=x)
            {
                if(temp->left!=NULL)
                {
                    temp->left->right=temp2;
                    temp2->left=temp->left;
                }else{
                    obj=temp2;
                }
                temp->left=temp2;
                temp2->right=temp;
                
                break;
            }else{
                if(temp->right==NULL)
                {   
                    temp->right=temp2;
                    temp2->left=temp;
                    //cout<<"DONE\n\n";
                    break;
                }else{
                    temp=temp->right;
                }
            }
        }

    }
    return obj;
}

Doubly_Linked_List* Doubly_Linked_List::Delete(int pos,Doubly_Linked_List* obj)
{
    Doubly_Linked_List* temp=obj;
    if(obj==NULL)
    {
        cout<<"\nLIST   IS    ALREADY    EMPTY !!!!!\n\n";
    }else if(obj->right==NULL && pos==1)
    {
        delete(obj);
        return NULL;
    }else if(pos==1)
    {
        temp->right->left=NULL;
        obj=temp->right;
        delete(temp);
        return obj;
    }else{
        while(pos!=1)
        {
            if(temp==NULL)
            {
                cout<<"\nEnter a valid position !!!\n";
                return obj;
            }
            temp=temp->right;
            pos--;
        }
        temp->left->right=temp->right;
        delete(temp);
    }
    
    return obj;
}

void Doubly_Linked_List::Display(Doubly_Linked_List* obj)
{
    if(obj==NULL)
    {
        cout<<"\nLIST  IS  EMPTY !!!!!\n\n";
    }
    while(obj!=NULL)
    {
        cout<<obj->data<<"  ";
        obj=obj->right;
    }
    cout<<endl<<endl;
}

Doubly_Linked_List* Doubly_Linked_List:: Merge(Doubly_Linked_List* obj1,Doubly_Linked_List* obj2)
{
    Doubly_Linked_List* obj3=NULL;
    Doubly_Linked_List* temp=NULL;
    Doubly_Linked_List* temp1=NULL;
    while(obj1 || obj2)
    {
        if(obj1!=NULL && obj2!=NULL && obj1->data<=obj2->data)
        {
            temp=Create_A_Node(obj1->data);
            if(temp1){
                temp1->right=temp;
                temp->left=temp1;
                temp1=temp;
            }else{
                temp1=temp;
                obj3=temp1;
            }
            obj1=obj1->right;
        }else if(obj1!=NULL && obj2!=NULL && obj1->data>obj2->data)
        {
            temp=Create_A_Node(obj2->data);
            if(temp1){
                temp1->right=temp;
                temp->left=temp1;
                temp1=temp;
            }else{
                temp1=temp;
                obj3=temp1;
            }
            obj2=obj2->right;
        }else if(obj1!=NULL && obj2==NULL)
        {
            while(obj1)
            {
                temp=Create_A_Node(obj1->data);
                if(temp1){
                    temp1->right=temp;
                    temp->left=temp1;
                    temp1=temp;
                }else{
                    temp1=temp;
                    obj3=temp1;
                }
                obj1=obj1->right;
            }
        }else if(obj2!=NULL && obj1==NULL)
        {
            while(obj2)
            {
                temp=Create_A_Node(obj2->data);
                if(temp1){
                    temp1->right=temp;
                    temp->left=temp1;
                    temp1=temp;
                }else{
                    temp1=temp;
                    obj3=temp1;
                }
                obj2=obj2->right;
            }
        }

    }
    return obj3;
}

int main()
{
    Doubly_Linked_List* obj1=NULL;
    Doubly_Linked_List* obj2=NULL;
    int x,k,k1,i,t=1;
    
    while(t)
    {
        cout<<"1. Insert            - ENTER 1\n";
        cout<<"2. Delete            - ENTER 2\n";
        cout<<"3. Display           - ENTER 3\n";
        cout<<"4. Merge             - ENTER 4\n";
        cout<<"5. Exit              - ENTER 5\n\nCHOICE  :  ";
        cin>>x;
        switch(x)
        {
            case 1:{
                
                cout<<"1. Doubly Linked List-1          - ENTER 1\n";
                cout<<"2. Doubly Linked List-2          - ENTER 2\n\nCHOICE  :  ";
                cin>>k1;
                if(k1==1)
                {
                    cout<<"Enter the element: ";
                    cin>>k;
                    obj1=obj1->Insert(k,obj1);
                }else if(k1==2)
                {
                    cout<<"Enter the element: ";
                    cin>>k;
                    obj2=obj2->Insert(k,obj2);
                }else{
                    cout<<"ENTER A VALID CHOICE !!!\n\n";
                }
                break;
            }
            case 2:
            {   
                cout<<"1. Doubly Linked List-1          - ENTER 1\n";
                cout<<"2. Doubly Linked List-2          - ENTER 2\n\nCHOICE  :  ";
                cin>>k1;
                if(k1==1)
                {
                    cout<<"Enter the position to be deleted: ";
                    cin>>k;
                    obj1=obj1->Delete(k,obj1);
                }else if(k1==2)
                {
                    cout<<"Enter the position to be deleted: ";
                    cin>>k;
                    obj2=obj2->Delete(k,obj2);
                }else{
                    cout<<"ENTER A VALID CHOICE !!!\n\n";
                }
                
                break;
            }
            case 3:
            {
                cout<<"1. Doubly Linked List-1          - ENTER 1\n";
                cout<<"2. Doubly Linked List-2          - ENTER 2\n\nCHOICE  :  ";
                cin>>k1;
                if(k1==1)
                {
                    cout<<"LIST -  1 : ";
                    obj1->Display(obj1);
                }else if(k1==2)
                {
                    cout<<"LIST -  2 : ";
                    obj2->Display(obj2);
                }else{
                    cout<<"ENTER A VALID CHOICE !!!\n\n";
                }
                break;
            }
            case 4:
            {
                cout<<"MERGING BOTH DOUBLY LINKED LISTS.................\n\n";
                cout<<"TO SAVE THE NEW MERGED LIST INTO LIST -1         - ENTER 1\n";
                cout<<"TO SAVE THE NEW MERGED LIST INTO LIST -2         - ENTER 2\n\nCHOICE  :  ";
                cin>>k1;
                if(k1==1)
                {
                    obj1=obj1->Merge(obj1,obj2);
                }else  if(k1==2){
                    obj2=obj2->Merge(obj1,obj2);
                }else{
                    cout<<"ENTER A VALID CHOICE !!!\n\n";
                }
                break;
            }
            case 5:
            {   
                t=0;
                break;
            }
            default:
            {
                cout<<"Enter a valid choice\n\n";
                break;
            }
        }
    }
    

    return 0;
}