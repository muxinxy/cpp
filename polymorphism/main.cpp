#include <iostream>
#define PI 3.14

using namespace std;

class Shape
{
public:
    virtual void setValue()=0;//pure virtual method
    virtual double Area()=0;
    virtual double Perimeter()=0;
};

class Circle:public Shape
{
public:
    virtual void setValue();//set the value of radius
    virtual double Area();
    virtual double Perimeter();
private:
    double radius;
};

void Circle::setValue()
{
    cout << "Please input the radius of circle:";
    cin >> radius;
}

double Circle::Area()
{
    return PI*radius*radius;
}

double Circle::Perimeter()
{
    return 2*PI*radius;
}

class Square:public Shape
{
public:
    virtual void setValue();//set the value of length
    virtual double Area();
    virtual double Perimeter();
private:
    double length;
};

void Square::setValue()
{
    cout << "Please input the length of square:";
    cin >> length;
}

double Square::Area()
{
    return length*length;
}

double Square::Perimeter()
{
    return 4*length;
}

class Rectangle:public Shape
{
public:
    virtual void setValue();//set the value of length and width
    virtual double Area();
    virtual double Perimeter();
private:
    double length;
    double width;
};

void Rectangle::setValue()
{
    cout << "Please input the length and width of rectangle:";
    cin >> length >> width;
}

double Rectangle::Area()
{
    return length*width;
}

double Rectangle::Perimeter()
{
    return 2*(length+width);
}

int main()
{
    Shape **s;
    int i,n;
    cout << "Please input the number of element:";
    cin >> n;
    s=new Shape *[n];//build dynamic array
    for(i=0;i<n;i++)
    {
        Circle c;
        s[i]=&c;
        s[i]->setValue();
        cout << "The area of circle is " << s[i]->Area() << endl;
        cout << "The Perimeter of circle is " << s[i]->Perimeter() << endl;
        Square sq;
        s[i]=&sq;
        s[i]->setValue();
        cout << "The area of square is " << s[i]->Area() << endl;
        cout << "The perimeter of square is " << s[i]->Perimeter() << endl;
        Rectangle r;
        s[i]=&r;
        s[i]->setValue();
        cout << "The area of rectangle is " << s[i]->Area() << endl;
        cout << "The perimeter of rectangle is " << s[i]->Perimeter() << endl;
    }
    delete [] s;
    return 0;
}
