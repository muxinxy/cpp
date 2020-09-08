#include <iostream>

using namespace std;

struct Point{
    int x;
    int y;
    char type;
    int num;
};

struct Query{
    int th0;
    int th1;
    int th2;
};

int main()
{
    Point p[1001];
    Query q[21];
    // first_A:第一个为A的点，first_B:第一个为B的点，flag1:A是(0)否(1)异号，flag2:B是(0)否(1)异号，flag_A:A的正(1)负(0)，flag_B:B的正(1)负(0)
    int n,m,i,j,first_A,first_B,flag1,flag2,flag_A,flag_B;
    cin >> n >> m;
    for (i=1;i<=n;i++)
    {
        cin >> p[i].x >> p[i].y >> p[i].type;
    }
    for (i=1;i<=m;i++)
    {
        cin >> q[i].th0 >> q[i].th1 >> q[i].th2;
    }
    first_A = 0;
    first_B = 0;
    for (i=1;i<=n;i++)
    {
        if(p[i].type=='A')
            first_A = i;
        else if(p[i].type=='B')
            first_B = i;
        if(first_A&&first_B)
            break;
    }
    for (i=1;i<=m;i++)
    {
        for (j=1;j<=n;j++)
        {
            p[j].num = q[i].th0 + q[i].th1 * p[j].x + q[i].th2 * p[j].y;
        }
        flag1 = 1;
        if(p[first_A].num>0)
            flag_A = 1;
        else
            flag_A = 0;
        for (j=first_A+1;j<=n;j++)
        {
            int temp_flag;
            if(p[j].type=='A')
            {
                if(p[j].num>0)
                    temp_flag = 1;
                else
                    temp_flag = 0;
                if(temp_flag!=flag_A)
                {
                    cout << "No" << endl;
                    flag1 = 0;
                }
            }
            if(flag1==0)
                break;
        }
        flag2 = 1;
        if(p[first_B].num>0)
            flag_B = 1;
        else
            flag_B = 0;
        for (j=first_B+1;j<=n && flag1==1;j++)
        {
            int temp_flag;
            if(p[j].type=='B')
            {
                if(p[j].num>0)
                    temp_flag = 1;
                else
                    temp_flag = 0;
                if(temp_flag!=flag_B)
                {
                    cout << "No" << endl;
                    flag2=0;
                }
            }
            if(flag2==0)
                break;
        }
        if(flag1==1 && flag2==1 && flag_A==flag_B)
            cout << "No" << endl;
        else if(flag1==1 && flag2==1 && flag_A!=flag_B)
            cout << "Yes" << endl;
    }

    return 0;
}
