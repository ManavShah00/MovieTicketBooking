#include<iostream>
using namespace std;

class Theater
{
    friend class Moviesearch;
    string thr_name;
public:
    void get()
    {
        cout<<"\nEnter Theater Name:";
        cin>>thr_name;
    }
    void print()
    {
        cout<<"THEATER:"<<thr_name<<endl;
    }
};

class Movie : public Theater
{
    friend class Moviesearch;
    string mov[2];
public:
    void getmovie()
    {
        int i;
        cout<<"Movie shown in Theater:\n";
        for(i=0;i<2;i++)
        {
            cin>>mov[i];
        }
    }
    void printmov()
    {
        int i;
        cout<<"MOVIES SHOWING\n";
        for(i=0;i<2;i++)
        {
            cout<<mov[i]<<endl;
        }
    }
};

class Time : public Movie
{
    friend class Moviesearch;
    int t[4];
public:
    void getty()
    {
        int i;
        cout<<"Enter Timing of movies:\n";
        for(i=0;i<4;i++)
        {
            cin>>t[i];
        }
    }
    void printty()
    {
        int i;
        cout<<"\n";
        for(i=0;i<4;i++)
        {
            cout<<t[i]<<" ";
        }
    }
};

int entermeal()
{
        int i;
        cout<<"Select combo:"<<endl;
        cout<<"1.Classic Combo (Medium Popcorn + Medium Soft Drink):Rs.110"<<endl;
        cout<<"2.French Combo  (Fries + Medium Soft Drink)         :Rs.150"<<endl;
        cout<<"3.American Combo(Burger + Medium Soft Drink)        :Rs.180"<<endl;
        cout<<"4.Pure Popcorn  (Large Popcorn)                     :Rs.90"<<endl;
        cout<<"5.Only Drinks   (Large Soft Drink)                  :Rs.80"<<endl;
        cin>>i;
        return i;
}


class Moviesearch
{
    friend class Movie;
    friend class Theater;
    friend class Time;
    friend class Meal;
    string movsher,ther;
    int tym;
public:
    void ser(Time m[3])
    {
        int i,n,z,o,h,j,combo,temp=0;
        float money=0,no,cc,fmoney;
        string name;
        char seat[10][2];
        int sn;
        cout<<"\nEnter Movie You Want To See:\n";
        cin>>movsher;
        cout<<"\nMovie Available in Theater:\n";
        for(i=0;i<3;i++)
        {
            for(j=0;j<2;j++)
            {
                if(movsher==m[i].mov[j])
                {
                    cout<<m[i].thr_name<<endl;
                    z=i;
                }
            }
        }
        cout<<"\nSelect Theater:";
        cin>>ther;
        cout<<"\nEnter Name:";
        cin>>name;
        cout<<"\nEnter Mobile Number:";
        cin>>no;
        m[z].printty();
        cout<<"\nSelect time:\n";
        cin>>tym;
        for(i=0;i<3;i++)
        {
            for(j=0;j<4;j++)
            {
                if(tym==m[i].t[j])
                {
                    n=i;
                    o=j;
                }
            }
        }
        cout<<"\n\n";
        cout<<"  1 2 3 4 5 6 7 8 9"<<endl;
        cout<<"-----RECLINERS-----"<<endl;
        cout<<"A * * * * * * * * *"<<endl;
        cout<<"-------ROYAL-------"<<endl;
        cout<<"B * * * * * * * * *"<<endl;
        cout<<"C * * * * * * * * *"<<endl;
        cout<<"D * * * * * * * * *"<<endl;
        cout<<"-----EXECUTIVE-----"<<endl;
        cout<<"E * * * * * * * * *"<<endl;
        cout<<"F * * * * * * * * *"<<endl;
        cout<<"G * * * * * * * * *"<<endl;
        cout<<"____________________"<<endl;
        cout<<"       SCREEN       "<<endl;
        cout<<"\nNOTE:\n";
        cout<<"EXECUTIVE:Rs.110"<<endl;
        cout<<"ROYAL:Rs.160"<<endl;
        cout<<"RECLINERS:Rs.200"<<endl;
        cout<<"Number of Seats:";
        cin>>sn;
        cout<<"Select Seat:\n";
        for(i=0;i<sn;i++)
        {
            for(j=0;j<2;j++)
            {
                cin>>seat[i][j];
            }
        }
        for(i=0;i<sn;i++)
        {
            switch(seat[i][0])
            {
            case 'A':
                money=money+200;
                break;
            case 'B':
                money=money+160;
                break;
            case 'C':
                money=money+160;
                break;
            case 'D':
                money=money+160;
                break;
            case 'E':
                money=money+110;
                break;
            case 'F':
                money=money+110;
                break;
            case 'G':
                money=money+110;
                break;
            default:
                cout<<"INvalid INPUT!";
                break;
            }
        }
        cout<<"\nWould you like to have any meal Combo:\n1.YES 0.NO"<<endl;
        cin>>combo;
        if(combo==1)
        {
            temp=entermeal();
        }
        cout<<"\n\n";
        cout<<"********************FINAL TICKET********************"<<endl;
        cout<<"CUSTOMER NAME:"<<name<<endl;
        cout<<"CUSTOMER PHONE NO.:"<<no<<endl;
        cout<<"MOVIE NAME:"<<movsher<<endl;
        cout<<"THEATER NAME:"<<ther<<endl;
        cout<<"TIME:"<<m[n].t[o]<<endl;
        cout<<"SEATS:";
        for(i=0;i<sn;i++)
        {
            for(j=0;j<2;j++)
            {
                cout<<seat[i][j];
            }
            cout<<" ";
        }
        if(combo==1)
        {
            cout<<"\nSelected combo:\n";
            switch(temp)
            {
            case 1:
                cout<<"Classic Combo (Medium Popcorn + Medium soft drink)";
                cc=cc+110;
                break;
            case 2:
                cout<<"French Combo (Fries + Medium soft drink)";
                cc=cc+150;
                break;
            case 3:
                cout<<"American Combo (Burger + Medium soft drink)";
                cc=cc+180;
                break;
            case 4:
                cout<<"Pure Popcorn (Large Popcorn)";
                cc=cc+90;
                break;
            case 5:
                cout<<"Only Soft Drink (Large soft drink)";
                cc=cc+80;
                break;
            default:
                cout<<"ERROR!";
                break;
            }
        }
        else
        {
            cout<<"\nNO Meal.\n";
            cc=0;
        }
        fmoney=cc+money;
        cout<<"\nMEAL COST:Rs."<<cc<<endl;
        cout<<"TICKET COST:Rs."<<money<<endl;
        cout<<"FINAL COST(including tax 6%):Rs."<<(fmoney+(fmoney*0.06))<<endl;
        cout<<"           SGST 3%(Rs."<<(fmoney*0.03)<<")"<<endl;
        cout<<"           CGST 3%(Rs."<<(fmoney*0.03)<<")"<<endl;
        cout<<"*****************************************************";
    }
};


int main()
{
    int i,j;
    Theater t[3];
    Time m[3];
    Moviesearch s;
    cout<<"*******************************************************************";
    cout<<"\nENTER DATA!\n";
    for(i=0;i<3;i++)
    {
        m[i].get();
        m[i].getmovie();
        m[i].getty();
    }
    cout<<endl<<endl<<endl;
    cout<<"*******************************************************************\n";
    cout<<"*******************************************************************\n";
    cout<<"MOVIES SHOWING NOW:\n";
    for(i=0;i<3;i++)
    {
        m[i].print();
        m[i].printmov();
        cout<<"\n";
    }
    s.ser(m);
}
