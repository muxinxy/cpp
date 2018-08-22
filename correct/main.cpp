//Experiment 9-1
//CORRECTION:

#include<iostream>
using namespace std;
class X{
public:
    X(int x)
    {a=x;}
    void showX()
    {cout<<"a="<<a<<endl;}
private:
    int a;
};
class Y: private X{
public:
    Y(int x,int y):X(x)
    {b=y;}
    void showX()
    {
        X::showX();
    }
    void showY()
    {
        showX();
        cout<<"b="<<b<<endl;
	}
private:
    int b;
};
class Z: public Y{
public:
    Z(int x, int y, int z):Y(x,y)
    { c=z; }
    void showZ( )
    {
        showY();
        cout<<"c="<<c<<endl;
	}
private:
    int c;
};
int main( )
{
Z obj(10, 20, 30);
obj.showX( );
obj.showY( );
obj.showZ( );
}

/*
Requirement:
*Y is a private subclass of X.
*Z is a public subclass of Y.
*a, b, and c are encapsulated data members.
*Do not change function main().
*Output:
  a=10
a=10
b=20
a=10
b=20
c=30
*/

