#include <iostream>
#include "time.h"
using namespace std;

int main()
{
    int hour,minute,second;
    int i;
    Time myTime;
    Time TimeArray[24];
    Time mTime(0,0,0);//create object with construct with 3 parameters
    Time copyTime(mTime);//create object with copy construct
    Time *p;//use new and delete
    p=new Time;
    delete p;
    Time *Pointer;
    Pointer=TimeArray;//create object array pointer
    cout << endl;
    for(i=1;i<24;i++)//ergodic to assign with subscript
    {
        TimeArray[i]=Time(i,i,i);
        cout << endl;
    }
    for(i=0;Pointer<TimeArray+24;Pointer++)//ergodic to assign with pointer
    {
        *Pointer=Time(i,i,i);
        i++;
        cout << endl;
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
