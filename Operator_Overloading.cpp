#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

class Coordinate{
    int x;
    int y;
    public:
        Coordinate():x(0),y(0){}        // CONSTRUCTOR
        void operator ~();
        double operator -(Coordinate &c);       
        friend istream& operator >>(istream& obj,Coordinate &c);
        friend ostream& operator <<(ostream& obj,Coordinate &c);
        ~Coordinate(){}  // DESTRUCTOR
};

void Coordinate::operator~()
{
    x=x<0? -x:x;
    y=y<0? -y:y; 
}

istream& operator >>(istream& obj,Coordinate &c)
{
    cout<<"\nENTER THE X - COORDINATE: ";
    obj>>c.x;
    cout<<"ENTER THE Y - COORDINATE: ";
    obj>>c.y;
    // cout<<"\nCHECKING IF THE ENTERED COORDINATE IS IN POSITIVE QUADRANT OR NOT\n";
    // cout<<"ELSE -  COVERTING INTO POSITIVE QUADRANT COORDINATE THROUGH NEGATION...............\n\n";
    ~c;
    return obj;
}

ostream& operator <<(ostream& obj,Coordinate &c)
{
    obj<<"X : "<<c.x<<endl;
    obj<<"Y : "<<c.y<<endl<<endl;
    return obj;
}

double Coordinate::operator-(Coordinate &c)
{
    double d;
    d=sqrt((x-c.x)*(x-c.x)+(y-c.y)*(y-c.y));
    return d;
}

bool Check_Right_Angled_Triangle(double d1,double d2,double d3)
{
    if(d1==sqrt(d2*d2 +d3*d3) || d2==sqrt(d1*d1+d3*d3) || d3==sqrt(d1*d1+d2*d2)){return true;}
    else return false;
}


int main()
{
    Coordinate c1,c2,c3;
    double d1,d2,d3;
    int k,t=1;
    cout<<"ENTER THE COORDINATES FOR 1st POINT\n";
    cin>>c1;
    cout<<"ENTER THE COORDINATES FOR 2nd POINT\n";
    cin>>c2;
    cout<<"ENTER THE COORDINATES FOR 3rd POINT\n\n"; 
    cin>>c3;
    d1=c1-c2;
    d2=c2-c3;
    d3=c3-c1;

    while(t)
    {
        cout<<"SET or RESET                     - ENTER 1\n";
        cout<<"DISPLAY POINT                    - ENTER 2\n";
        cout<<"DISPLAY LENGTH                   - ENTER 3\n";
        cout<<"CHECK RIGHT ANGLED TRIANGLE      - ENTER 4\n";
        cout<<"EXIT                             - ENTER 5\n";
        cin>>k;
        switch(k)
        {
            case 1:
            {
                cout<<"ENTER THE COORDINATES FOR 1st POINT\n";
                cin>>c1;
                cout<<"ENTER THE COORDINATES FOR 2nd POINT\n";
                cin>>c2;
                cout<<"ENTER THE COORDINATES FOR 3rd POINT\n\n"; 
                cin>>c3;
            }
            case 2:
            {
                cout<<c1<<c2<<c3;
                break;
            }
            case 3:
            {
                cout<<"\nDISTANCE BETWEEN POINT 1 & 2: "<<d1<<endl;
                cout<<"DISTANCE BETWEEN POINT 2 & 3: "<<d2<<endl;
                cout<<"DISTANCE BETWEEN POINT 3 & 1: "<<d3<<endl<<endl;
                break;
            }
            case 4:
            {
                if(Check_Right_Angled_Triangle(d1,d2,d3)){
                    cout<<"YES !!!!!  IT IS A RIGHT ANGLED TRIANGLE\n\n";
                }else{
                    cout<<"NO !!!!!  IT IS NOT A RIGHT ANGLED TRIANGLE\n\n";
                }
                break;
            }
            case 5:{
                t=0;    break;
            }
            default:
                cout<<"ENTER A VALID CHOICE\n\n";
        }

    }



    

    return 0;
}