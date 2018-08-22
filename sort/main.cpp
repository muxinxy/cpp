#include <iostream>

using namespace std;

void Sort(int n,int a[])//sort of int
{
    int i,j,k;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
            {
                k=a[i];
                a[i]=a[j];
                a[j]=k;
            }
        }
    }
    cout << "The sort result is ";
    for(i=0;i<n;i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
void Sort(int n,float a[])//sort of float
{
    int i,j;
    float k;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
            {
                k=a[i];
                a[i]=a[j];
                a[j]=k;
            }
        }
    }
    cout << "The sort result is ";
    for(i=0;i<n;i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
void Sort(int n,double a[])//sort of double
{
    int i,j;
    double k;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
            {
                k=a[i];
                a[i]=a[j];
                a[j]=k;
            }
        }
    }
    cout << "The sort result is ";
    for(i=0;i<n;i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    int i,choice=1,n,ints[100];
    float floats[100];
    double doubles[100];
    while (choice==1 || choice==2 || choice==3)
    {
        cout << "1.int\t2.float\t3.double\nPlease choose a kind of numbers to sort or other numbers to exit:";
        cin >> choice;
        if (choice!=1 && choice!=2 && choice!=3)break;
        cout << "Please input the number of numbers:";
        cin >> n;
        switch(choice)//deal with menu
        {
            case 1:
                cout << "Please input " << n <<" integers:";
                for(i=0;i<n;i++)
                {
                    cin >> ints[i];
                }
                Sort(n,ints);
                break;
            case 2:
                cout << "Please input " << n <<" float numbers:";
                for(i=0;i<n;i++)
                {
                    cin >> floats[i];
                }
                Sort(n,floats);
                break;
            case 3:
                cout << "Please input " << n <<" double numbers:";
                for(i=0;i<n;i++)
                {
                    cin >> doubles[i];
                }
                Sort(n,doubles);
                break;
        }
    }
    return 0;
}
