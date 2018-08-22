#include <iostream>
#include <iomanip>
#define PI 3.14
using namespace std;
double c_area()//calculate the area of circle
{
    double radius;
    cout<<"Please input radius:";
    cin>>radius;
    while(radius<0)
    {
        cout<<"Please input again:";
        cin>>radius;
    }
    return PI*radius*radius;
}
double r_area()//calculate the area of rectangle
{
    double length,width;
    cout<<"Please input length width:";
    cin>>length>>width;
    while(length<0||width<0)
    {
        cout<<"Please input again:";
        cin>>length>>width;
    }
    return length*width;
}
double s_area()//calculate the area of square
{
    double length;
    cout<<"Please input length:";
    cin>>length;
    while(length<0)
    {
        cout<<"Please input again:";
        cin>>length;
    }
    return length*length;
}
int main()
{
    int choice;
    double area;
    while (choice!=4){
    cout <<"Area Calculating\nPlease choose a patterning(1.circle 2.rectangle 3.square 4.quit):";
    cin>>choice;//input the choice
    while(choice!=1&&choice!=2&&choice!=3&&choice!=4)
    {
        cout<<"Please choose again(1.circle 2.rectangle 3.square 4.quit):";
        cin>>choice;
    }
    switch (choice)
    {
        case 1:area=c_area();break;
        case 2:area=r_area();break;
        case 3:area=s_area();break;
        case 4:break;
    }
    if(choice!=4){
    cout<<fixed;
    cout<<"Area is "<<setprecision(2)<<area<<endl;}//output the result
    else break;}
    return 0;
}
