#include<iostream>
#include<string>

#define MAX 5


using namespace std;


int count=1;

class Bank_Data{
    protected:
        string name;
        int age;
        double amnt;
        string User_id;
        string Password;
    public:
        Bank_Data(){}
        void Set_Name_and_Age(string name,int age){
            this->name=name;
            this->age=age;
        }
        void Generate_Username_and_Set_Password(char type)
        {
            User_id=type+to_string(count)+"2022";
            cout<<"YOUR USER ID FOR THE BANK ACCOUNT IS "<<User_id<<endl;
            cout<<"Create a new password: ";
            cin>>Password;
            cout<<"\nNOTE: Remember your User ID and Password for login purposes.\n\n";
            cout<<"ACCOUNT DETAILS -> USER ID: "<<User_id<<"\n                   PASSWORD: "<<Password<<endl;
        }
        bool Check_User_id(string s)
        {
            if(s==User_id){  return true;}
            else{return false;}
        }
        bool Check_Password(string p)
        {
            if(p==Password){
                return true;
            }else{return false;}
        }
        void Set_Amount(double amnt)
        {
            this->amnt=amnt;
        }
        void Credit(double x){
            amnt+=x;
        }
        void Debit(double x){
            if(x<=amnt)
            {
                amnt=amnt-x;
            }else{
                cout<<"Insufficient Balance !!!\n";
            }
        }
        void Print_Details()
        {
            cout<<"Name          :        "<<name<<endl;
            cout<<"Age           :        "<<age<<endl;
            cout<<"Total amnt    :        "<<amnt<<endl;
        }


        ~Bank_Data(){}
};

class Savings_Acc:public Bank_Data {
        
        double I_rate;
        
    public:
        Savings_Acc(){
            I_rate= 0.05;
        }

        void Change_Intrest_Rate(double I_rate)
        {
            this->I_rate=I_rate;
        }
        void Calculate_Intrest(double years)
        {
            cout<<"Total amount= "<<amnt*years*I_rate<<endl;
        }
        void Calculate_and_Update_Intrest(double years)
        {
            amnt+=amnt+amnt*years*I_rate;
        }

        ~Savings_Acc(){}
};

class Checking_Acc:public Bank_Data{
    
    double Fee,Collected_fee;
    public:
        Checking_Acc(){
            Fee=5;
            Collected_fee=0;
        }
        void Change_Fee_Amount(double fee){
            Fee=fee;
        }
        void Collect_Fee()
        {
            Collected_fee+=Fee;
            amnt=amnt-Fee;
            cout<<"TRANSACTION FEE= "<<Fee<<endl<<endl;
        }
        void Print_Collected_Fee()
        {
            cout<<"Total Collected Fee for all the past transactions = "<<Collected_fee<<endl<<endl;
        }
        
};


int Sav_Search_Details(Savings_Acc* arr,string User_id)
{
    for(int i=0;i<MAX;++i)
    {
        if(arr[i].Check_User_id(User_id))
        {
            return i;
        }
        
    }
    return -1;
}

int Chc_Search_Details(Checking_Acc* arr,string User_id)
{
    for(int i=0;i<MAX;++i)
    {
        if(arr[i].Check_User_id(User_id))
        {
            return i;
        }
        
    }
    return -1;
}

void Search_Details(Savings_Acc* Sav,Checking_Acc* Chc, string User_id)
{
    int f;
    if(User_id[0]=='s'){
        f= Sav_Search_Details(Sav,User_id);
        if(f!=-1)
        {
            Sav[f].Print_Details();
        }
    }else if(User_id[0]=='c')
    {
        f=Chc_Search_Details(Chc,User_id);
        if(f!=-1)
        {
            Chc[f].Print_Details();
        }
    }else{
        cout<<"ERROR: INCORRECT USER ID !!! PLEASE TRY AGAIN\n\n";
    }
    if(f==-1){
        cout<<"ERROR: User id not found !!! Please check and try again\n\n";
    }
}




int main()
{
    int k,t=1,i1=0,i2=0,f;
    double amnt,rate,fee,years;
    string name,User_id,Pass;
    int age;
    char type;
    Savings_Acc* Sav=new Savings_Acc[MAX];
    Checking_Acc* Chc=new Checking_Acc[MAX] ;
    while(t)
    {
        cout<<"OPEN ACCOUNT                                                 - ENTER 1\n";
        cout<<"CREDIT                                                       - ENTER 2\n";
        cout<<"DEBIT                                                        - ENTER 3\n";
        cout<<"CHANGE/UPDATE INTREST RATE                                   - ENTER 4\n";
        cout<<"CALCULATE INTREST                                            - ENTER 5\n";
        cout<<"CALCULATE AND UPDATE PRINCIPLE AMOUNT WITH INTREST           - ENTER 6\n";
        cout<<"CHANGE/UPDATE FEE AMOUNT                                     - ENTER 7\n";
        cout<<"PRINT CHECKING FEE                                           - ENTER 8\n";
        cout<<"SEARCH CUSTOMER DETAILS                                      - ENTER 9\n";
        cout<<"EXIT                                                         - ENTER 10\n";
        cin>>k;


        switch(k){
            case 1:{
                cout<<"ENTER YOUR NAME: ";                                  cin>>name;
                cout<<"ENTER YOUR AGE: ";                                   cin>>age;
                cout<<"SELECT WHICH TYPE OF ACCOUNT YOU WANT \n";
                cout<<"1. SAVINGS ACCOUNT                       - ENTER - 's'\n";
                cout<<"2. CHECKINGS ACCOUNT                     - ENTER - 'c'\n";
                cin>>type;
                type=tolower(type);
                
                switch(type)
                {
                    case 's':{
                        Sav[i1].Set_Name_and_Age(name,age);
                        Sav[i1].Generate_Username_and_Set_Password(type);
                        cout<<"ENTER THE INITIAL AMOUNT: ";             cin>>amnt;
                        Sav[i1].Set_Amount(amnt);
                        cout<<"THE INTREST PER ANNUM IS  ( 5% ) OF THE TOTAL AMOUNT\n\n";
                        i1++;
                        break;
                    }
                    case 'c':{
                        Chc[i2].Set_Name_and_Age(name,age);
                        Chc[i2].Generate_Username_and_Set_Password(type);
                        cout<<"ENTER THE INITIAL AMOUNT: ";             cin>>amnt;
                        Chc[i2].Set_Amount(amnt);
                        cout<<"THE FEE PER TRANSACTION IS $5 !!!\n\n";
                        i2++;
                        break;
                    }
                    default:{cout<<"ENTER A VALID CHOICE !!!\n";}
                }
                count++;
                break;
            }
            case 2:{
                cout<<"Enter your User_Id: ";                   cin>>User_id;
                if(User_id[0]=='s')
                {
                    f= Sav_Search_Details(Sav,User_id);
                    if(f!=-1)
                    {
                        cout<<"Enter the amount: ";                                 cin>>amnt;
                        cout<<"Enter the Password: ";                               cin>>Pass;
                        if(Sav[f].Check_Password(Pass))
                        {
                            Sav[f].Credit(amnt);
                            cout<<"Succesfully Credited!!\n\n";
                        }else{
                            cout<<"WRONG PASSWORD !!! \n\n";
                        }
                    }else{
                        cout<<"WRONG USER ID\n\n";
                    }
                }else if(User_id[0]=='c')
                {
                    f=Chc_Search_Details(Chc,User_id);
                    if(f!=-1)
                    {
                        cout<<"Enter the amount: ";                                 cin>>amnt;
                        cout<<"Enter the Password: ";                               cin>>Pass;
                        if(Chc[f].Check_Password(Pass))
                        {
                            Chc[f].Credit(amnt);
                            Chc[f].Collect_Fee();
                            cout<<"Succesfully Credited!!\n\n";
                        }else{
                            cout<<"WRONG PASSWORD !!! \n\n";
                        }
                    }else{
                        cout<<"WRONG USER ID\n\n";
                    }
                }else{
                    cout<<"ERROR: INCORRECT USER ID !!! PLEASE TRY AGAIN\n\n";
                }


                break;
            }
            case 3:{
                cout<<"Enter your User_Id: ";                   cin>>User_id;
                if(User_id[0]=='s')
                {
                    f= Sav_Search_Details(Sav,User_id);
                    if(f!=-1)
                    {
                        cout<<"Enter the amount: ";                                 cin>>amnt;
                        cout<<"Enter the Password: ";                               cin>>Pass;
                        if(Sav[f].Check_Password(Pass))
                        {
                            Sav[f].Debit(amnt);
                            cout<<"Succesfully Debited!!\n\n";
                        }else{
                            cout<<"WRONG PASSWORD !!! \n\n";
                        }
                    }else{
                        cout<<"WRONG USER ID\n\n";
                    }
                }else if(User_id[0]=='c')
                {
                    f=Chc_Search_Details(Chc,User_id);
                    if(f!=-1)
                    {
                        cout<<"Enter the amount: ";                                 cin>>amnt;
                        cout<<"Enter the Password: ";                               cin>>Pass;
                        if(Chc[f].Check_Password(Pass))
                        {
                            Chc[f].Debit(amnt);
                            Chc[f].Collect_Fee();
                            cout<<"Succesfully Debited!!\n\n";
                        }else{
                            cout<<"WRONG PASSWORD !!! \n\n";
                        }
                    }else{
                        cout<<"WRONG USER ID\n\n";
                    }
                }else{
                    cout<<"ERROR: INCORRECT USER ID !!! PLEASE TRY AGAIN\n\n";
                }

                break;
            }
            case 4:{
                cout<<"Enter your User_Id: ";                   cin>>User_id;
                if(User_id[0]=='s')
                {
                    f= Sav_Search_Details(Sav,User_id);
                    if(f!=-1)
                    {
                       cout<<"Enter the new intrest rate: ";            cin>>rate;
                       Sav[f].Change_Intrest_Rate(rate);
                       cout<<"Succesfully Changed !!!\n\n";
                    }else{
                        cout<<"WRONG USER ID\n\n";
                    }
                }else{
                    cout<<"ERROR: INCORRECT USER ID !!! PLEASE TRY AGAIN\n\n";
                }

                break;
            }
            case 5:{
                cout<<"Enter your User_Id: ";                   cin>>User_id;
                if(User_id[0]=='s')
                {
                    f= Sav_Search_Details(Sav,User_id);
                    if(f!=-1)
                    {
                        cout<<"Enter the time period of the amount (in years ): ";              cin>>years;
                        Sav[f].Calculate_Intrest(years);
                    }else{
                        cout<<"WRONG USER ID\n\n";
                    }
                }else{
                    cout<<"ERROR: INCORRECT USER ID !!! PLEASE TRY AGAIN\n\n";
                }
                break;
            }
            case 6:{
                cout<<"Enter your User_Id: ";                   cin>>User_id;
                if(User_id[0]=='s')
                {
                    f= Sav_Search_Details(Sav,User_id);
                    if(f!=-1)
                    {
                        cout<<"Enter the time period of the amount (in years ): ";              cin>>years;
                        Sav[f].Calculate_and_Update_Intrest(years);
                        cout<<"Succesfully Updated !!!\n\n";
                    }else{
                        cout<<"WRONG USER ID\n\n";
                    }
                }else{
                    cout<<"ERROR: INCORRECT USER ID !!! PLEASE TRY AGAIN\n\n";
                }
                break;
            }
            case 7:{
                cout<<"Enter your User_Id: ";                   cin>>User_id;
                if(User_id[0]=='c')
                {
                    f=Chc_Search_Details(Chc,User_id);
                    if(f!=-1)
                    {
                        cout<<"Enter the new fee amount: ";                             cin>>fee;
                        Chc[f].Change_Fee_Amount(fee);
                        cout<<"Succesfully Changed !!!\n\n";
                    }else{
                        cout<<"WRONG USER ID\n\n";
                    }
                }else{
                    cout<<"ERROR: INCORRECT USER ID !!! PLEASE TRY AGAIN\n\n";
                }

                break;
            }
            case 8:{
                cout<<"Enter your User_Id: ";                   cin>>User_id;
                if(User_id[0]=='c')
                {
                    f=Chc_Search_Details(Chc,User_id);
                    if(f!=-1)
                    {
                        Chc[f].Print_Collected_Fee();
                    }else{
                        cout<<"WRONG USER ID\n\n";
                    }
                }else{
                    cout<<"ERROR: INCORRECT USER ID !!! PLEASE TRY AGAIN\n\n";
                }
                break;
            }
            case 9:{
                cout<<"Enter your User_Id: ";                   cin>>User_id;
                Search_Details(Sav,Chc,User_id);

                break;
            }
            case 10:{
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