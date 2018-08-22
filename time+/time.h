#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED

class Time//create a new class
{
public:
    Time (){}//default construct
    Time (int hour, int minute, int second);//construct with 3 parameters
    Time (Time &p);//copy construct
    void setTime(int newH=0, int newM=0, int newS=0);
    void showTime();
private:
    int hour, minute, second;
};

#endif // TIME_H_INCLUDED
