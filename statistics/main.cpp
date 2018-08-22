#include <iostream>

using namespace std;

void statistics (char data[],int n)
{
    int i,sum=0,j,k,flag,m=0;
    char data2[100];
    for(i=0;i<n;i++)
    {
        sum=0;
        flag=0;
        for (k=0;k<n && i!=0;k++)
        {
            if(data[i]==data2[k])flag=1;
        }
        if (flag==0)data2[m++]=data[i];
        if (flag==1)continue;
        cout << data[i] << " : ";
        for (j=i;j<n;j++)
        {
            if(data[j]==data[i])
            {
                sum++;
                cout << j << " ";
            }
        }
        cout << "time " << sum <<endl;
    }
}

int main()
{
    char data[100];
    int n,i;
    cout << "Please input the length of data:";
    cin >> n;
    cout << "Please input the data:";
    for (i=0;i<n;i++)
    {
        cin >> data[i];
    }
    statistics (data,n);
    return 0;
}
