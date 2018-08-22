#include <iostream>
using namespace std;
class Complex{
public:
Complex( ){real=0;imag=0;}
Complex(double r,double i){real=r;imag=i;}
friend Complex operator ++ ( Complex & , int );
void display( );
private:
double real;
double imag;
};
Complex operator ++ (Complex & c, int )
{
Complex temp(c);
c.real ++;
c.imag ++;
return temp;
}
void Complex::display( )
{
cout<<"( "<<real<<","<<imag<<"i )"<<endl;
}
int main( )
{
Complex c1(3 , 4),c2;
cout<<"c1: ";
c1.display( );
c2=c1++; //or c2=operator++(c1, 0);
cout<< "c1 ++ : ";
c1.display( );
cout<<"c2: ";
c2.display( );
return 0;
}
