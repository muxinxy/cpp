#include <iostream>
#include "time.h"
using namespace std;

int main()
{
    int hour,minute,second;
    int i;
    Time myTime;
    Time TimeArray[24];
    Time mTime(0,0,0);
    Time *p;
    p=new Time;
    delete p;
    Time *Pointer;
    Pointer=TimeArray;
    for(i=0;i<24;i++)
    {
        TimeArray[i]=Time(i,i,i);
    }
    for(i=0;Pointer<TimeArray+24;Pointer++)
    {
        *Pointer=Time(i,i,i);
        i++;
    }
    cout << "Time set (hour minute second):";
    cin >> hour >> minute >> second;//input time
    while(hour<0 || hour>23 || minute<0 || minute>59 || second<0 || second>59)//deal with the error of input
    {
        cout << "Time set (hour minute second):";
        cin >> hour >> minute >> second;
    }
    myTime.setTime(hour,minute,second);//set time
    cout << "Time output:";
    myTime.showTime();//show time
    return 0;
}
