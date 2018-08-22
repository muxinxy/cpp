#include <iostream>

using namespace std;

template <typename T>

void Sort(T num[],int n)
{
    int i=0,j=0,Min=0;
    T tmp;
    for (i=0;i<n-1;i++)
    {
        Min=i;
        for (j=i;j<n;j++)
        {
            if(num[Min]>num[j])
            {
                Min=j;
            }
        }
        if(Min!=i)
        {
            tmp=num[Min];
            num[Min]=num[i];
            num[i]=tmp;
        }
    }
    cout << "The result is :";
    for(i=0;i<n;i++)
    {
        cout << num[i] << " ";
    }
    cout << endl;
}

int main()
{
    int Inum[100],choice=1,n,i;
    double Dnum[100];
    float Fnum[100];
    while (choice==1 || choice==2 || choice==3)
    {
        cout << "Please choose type of data (1.int 2.float 3.double) or input others to exit:";
        cin >> choice;
        if (choice!=1 && choice!=2 && choice!=3)break;
        cout << "Please input the number of numbers:";
        cin >> n;
        cout << "Please the numbers:";
        switch(choice)
        {
            case 1:
                for (i=0;i<n;i++)
                {
                    cin >> Inum[i];
                }
                Sort (Inum,n);break;
            case 2:
                for (i=0;i<n;i++)
                {
                    cin >> Fnum[i];
                }
                Sort (Fnum,n);break;
            case 3:
                for (i=0;i<n;i++)
                {
                    cin >> Dnum[i];
                }
                Sort (Dnum,n);break;
        }
    }
    return 0;
}
