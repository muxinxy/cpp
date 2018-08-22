#include <iostream>

using namespace std;

class Time//element of dynamic time array
{
public:
    Time():hour(0),minute(0),second(0){}
    Time(int h,int m,int s):hour(h),minute(m),second(s){}
    void setTime(int h,int m,int s){hour=h;minute=m;second=s;}
    int getHour(){return hour;}
    int getMinute(){return minute;}
    int getSecond(){return second;}
    void setHour(int h){hour=h;}
    void setMinute(int m){minute=m;}
    void setSecond(int s){second=s;}
private:
    int hour;
    int minute;
    int second;
};

class DynamicTimeArray
{
public:
    DynamicTimeArray(){}
    DynamicTimeArray(int row):row(row)
    {
        TimeArray=new Time[row];
    }
    friend istream & operator>>(istream &,DynamicTimeArray &);//>> operator overload
    friend ostream & operator<<(ostream &,DynamicTimeArray &);//<< operator overload
    int getRow(){return row;}//return the length of array
    int Search(Time &);
    void Edit(Time &);
    void Sort();
    ~DynamicTimeArray()
    {
        delete[] TimeArray;
    }
private:
    Time *TimeArray;
    int row;
};

istream & operator>>(istream & input,DynamicTimeArray & t)
{
    int hour,minute,second;
    for(int i=0;i<t.row;i++)
    {
        cout << "Please input the time(hour minute second):";
        input >> hour >> minute >> second;
        t.TimeArray[i].setTime(hour,minute,second);
    }
    return input;
}

ostream & operator<<(ostream & output,DynamicTimeArray & t)
{
    for(int i=0;i<t.row;i++)
    {
        output << t.TimeArray[i].getHour() << ":" << t.TimeArray[i].getMinute() << ":" << t.TimeArray[i].getSecond() << endl;
    }
    return output;
}

int DynamicTimeArray::Search(Time & t)
{
    int i;
    for(i=0;i<row;i++)
    {
        if((t.getHour()==TimeArray[i].getHour())&&(t.getMinute()==TimeArray[i].getMinute())&&(t.getSecond()==TimeArray[i].getSecond()))
        {
            return 1;
            break;
        }
    }
    return 0;
}

void DynamicTimeArray::Edit(Time & t)
{
    int i,flag=0,hour,minute,second;
    for(i=0;i<row;i++)
    {
        if((t.getHour()==TimeArray[i].getHour())&&(t.getMinute()==TimeArray[i].getMinute())&&(t.getSecond()==TimeArray[i].getSecond()))
        {
            flag=1;//mark whether the time is found
            cout << "Please input new time(hour minute second):";
            cin >> hour >> minute >> second;
            TimeArray[i].setTime(hour,minute,second);
            cout << "Edit successfully" << endl;
            break;
        }
    }
    if(flag==0)cout << "Not found" << endl;
}

void DynamicTimeArray::Sort()
{
    int i,j,sum1,sum2;
    Time t;
    for(i=0;i<row;i++)
    {
        sum1=TimeArray[i].getHour()*3600+TimeArray[i].getMinute()*60+TimeArray[i].getSecond();//calculate the seconds of time
        for(j=i+1;j<row;j++)
        {
            sum2=TimeArray[j].getHour()*3600+TimeArray[j].getMinute()*60+TimeArray[j].getSecond();
            if(sum1>sum2)
            {
                t=TimeArray[i];
                TimeArray[i]=TimeArray[j];
                TimeArray[j]=t;//change the TimeArray[i] and TimeArray[j]
            }
        }
    }
}

int main()
{
    int row,hour,minute,second,op=1;
    Time t;
    cout << "Please input the row of TimeArray:";//input the length of time array
    cin >> row;
    DynamicTimeArray mTime(row);
    cin >> mTime;
    while(op!=0)
    {
        cout << "1.size 2.search 3.edit 4.display 0.exit\nPlease choose the option:";
        cin >> op;
        while(op!=1 && op!=2 && op!=3 && op!=4 && op!=0)//build the menu
        {
            cout << "1.size 2.search 3.edit 4.display 0.exit\nPlease choose the option:";
            cin >> op;
        }
        if(op==0)break;
        else if(op==1)cout << "The size of time array is:" << mTime.getRow() << endl;
        else if(op==2)
        {
            cout << "Please input the time to search:";
            cin >> hour >> minute >> second;
            t.setTime(hour,minute,second);
            if(mTime.Search(t))cout << "Exit" << endl;
            else cout << "Not found" << endl;
        }
        else if(op==3)
        {
            cout << "Please input the time to edit:";
            cin >> hour >> minute >> second;
            t.setTime(hour,minute,second);
            mTime.Edit(t);
        }
        else if(op==4)
        {
            mTime.Sort();
            cout << mTime;
        }
    }
    return 0;
}
