#include <iostream>

using namespace std;

class client//the class of client
{
public:
    client(){}
    friend istream & operator >> (istream &,client &);//operator >> overloading
    int getCode()
    {
        return code;
    }
    int getRisk()
    {
        return risk;
    }
    int getAccount()
    {
        return account;
    }
    int getMoney()
    {
        return money;
    }
private:
    int account;
    string name;
    string id;
    long tel;
    string address;
    string job;
    int risk;
    int code;
    double money;
};

istream &operator >> (istream &input,client &c)//operator >> overloading
{
    cout << "Please input account:" ;
    input >> c.account;
    cout << "Please input name:" ;
    input >> c.name;
    cout << "Please input id:" ;
    input >> c.id;
    cout << "Please input tel:" ;
    input >> c.tel;
    cout << "Please input address:" ;
    input >> c.address;
    cout << "Please input job:" ;
    input >> c.job;
    cout << "Please input risk:" ;
    input >> c.risk;
    cout << "Please input code:" ;
    input >> c.code;
    cout << "Please input money:" ;
    input >> c.money;
    return input;
}

class product//the class of product
{
public:
    product(){}
    friend istream & operator >> (istream &,product &);//operator >> overloading
    int getCode()
    {
        return code;
    }
    int getCb()
    {
        return collect_beg;
    }
    int getCe()
    {
        return collect_end;
    }
    int getRisk()
    {
        return risk;
    }
    int getSb()
    {
        return save_beg;
    }
    int getSe()
    {
        return save_end;
    }
    double getPercent()
    {
        return percent;
    }
private:
    int code;
    string name;
    int risk;
    int collect_beg;
    int collect_end;
    int save_beg;
    int save_end;
    double percent;
};

istream &operator >> (istream &input,product &p)//operator >> overloading
{
    cout << "Please input code:" ;
    input >> p.code;
    cout << "Please input name:" ;
    input >> p.name;
    cout << "Please input risk:" ;
    input >> p.risk;
    cout << "Please input collect_beg:" ;
    input >> p.collect_beg;
    cout << "Please input collect_end:" ;
    input >> p.collect_end;
    cout << "Please input save_beg:" ;
    input >> p.save_beg;
    cout << "Please input save_end:" ;
    input >> p.save_end;
    cout << "Please input percent:" ;
    input >> p.percent;
    return input;
}

int check(int j,product *p,int code,int date,int risk)//check whether the client can buy the product
{
    int flag=0,m=0;
    for(m=0;m<j;m++)
    {
        if(p->getCode()==code && date>=p->getCb() && date<=p->getCe() && risk<=p->getRisk())
        {
            flag=1;
            break;
        }
        p++;
    }
    return flag;
}

void calculate(int i,int j,int date,client *c,product p[])//calculate the profit
{
    double profit=0;
    int m=0,n=0;
    cout << "account " << "code " << "money " << "profit" << endl;
    for(m=0;m<i;m++)
    {
        for(n=0;n<j;n++)
        {
            if(c->getCode()==p[n].getCode() && p[n].getSe()-date<=3)
            {
                profit=(p[n].getSe()-p[n].getSb())/365.0*p[n].getPercent()*c->getMoney();
                cout << c->getAccount() << " " << c->getCode() << " " << c->getMoney() << " " << profit << endl;
            }
        }
        c++;
    }
}

int main()
{
    int choice=1,i=0,j=0,date;
    client cli[100],temp;
    product pro[100];
    product *p;
    p=pro;
    client *c;
    c=cli;
    while(choice!=0)//build the menu
    {
        cout << "1.input client information 2.input product information 3.calculate 0.exit" << endl;
        cout << "Please input the choice:";
        cin >> choice;
        while(choice!=1 && choice!=2 && choice!=3 && choice!=0)
        {
            cout << "1.input client information 2.input product information 3.calculate 0.exit" << endl;
            cout << "Please input the choice:";
            cin >> choice;
        }
        switch(choice)
        {
            case 1:
                if(j==0)
                {
                    cout << "No product!" << endl;
                    break;
                }
                else
                {
                    cin >> temp;
                    cout << "Please input current date:";
                    cin >> date;
                    p=pro;
                    if(check(j,p,temp.getCode(),date,temp.getRisk())==1)
                    {
                        cli[i++]=temp;
                        cout << "Input successfully!" << endl;
                    }
                    else cout << "Can't buy the product!" << endl;
                }
                break;
            case 2:
                cin >> pro[j++];
                cout << "Input successfully!" << endl;
                break;
            case 3:
                cout << "Please input current date:";
                cin >> date;
                c=cli;
                p=pro;
                calculate(i,j,date,c,pro);
                break;
            case 0:break;
        }
        if(choice==0)break;
    }
    return 0;
}
