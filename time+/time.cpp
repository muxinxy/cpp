#include <iostream>
#include "time.h"

using namespace std;

void Time::setTime(int newH, int newM, int newS)//function to set time
{
    hour=newH;
    minute=newM;
    second=newS;
}
Time::Time(int hour,int minute,int second)
{
    cout << hour << ":" << minute << ":" << second;
}
Time::Time(Time &p)
{
    hour=p.hour;
    minute=p.minute;
    second=p.second;
}
void Time::showTime()//function to set time
{
    cout << hour << ":" << minute << ":" << second;
}
