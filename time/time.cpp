#include <iostream>
#include "time.h"

using namespace std;

void Time::setTime(int newH, int newM, int newS)//function to set time
{
    hour=newH;
    minute=newM;
    second=newS;
}
void Time::showTime()//function to set time
{
    cout << hour << ":" << minute << ":" << second;
}
