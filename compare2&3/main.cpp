#include <iostream>

using namespace std;

int max_number(int a,int b,int c=0);//prototype

int main()
{
    int x,y,z;
    int num=2;
    while (num!=0)
    {
        cout << "Please input 2 or 3 to determine the number of integers or 0 to quit:";//choose the number of integers
        cin>>num;
        while (num!=2&&num!=3&&num!=0)//deal with the error of number
        {
            cout << "Please input 2 or 3 to determine the number of integers or 0 to quit:";
            cin>>num;
        }
        if (num==2)//divide into two situations
        {
            cout << "Please input 2 integers(>0) to choose the biggest:";
            cin>>x>>y;
            while (x<=0||y<=0)
            {
                cout << "Please input 2 integers(>0) to choose the biggest:";
                cin>>x>>y;
            }
            cout<<"The biggest number is "<<max_number(x,y)<<endl;
        }
        else if (num==3)
        {
            cout << "Please input 3 integers(>0) to choose the biggest:";
            cin>>x>>y>>z;
            while (x<=0||y<=0||z<=0)
            {
                cout << "Please input 3 integers(>0) to choose the biggest:";
                cin>>x>>y>>z;
            }
            cout<<"The biggest number is "<<max_number
            (x,y,z)<<endl;
        }
        else break;
    }
    return 0;
}

int max_number(int a,int b,int c)//definition
{
    int biggest;
    biggest=a>b?a:b;
    biggest=biggest>c?biggest:c;
    return biggest;
}
