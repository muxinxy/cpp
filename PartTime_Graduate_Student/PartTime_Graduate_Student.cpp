#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
    Person(string n,int a,char s)
    {
        name=n;
        age=a;
        sex=s;
        cout << "name:" << name << endl << "age:" << age << endl << "sex:" << sex << endl;
    }
private:
    string name;
    int age;
    char sex;
};

class Employee:virtual public Person
{
public:
    Employee(string n,int a,char s,double sa,string p):Person(n,a,s)
    {
        salary=sa;
        position=p;
        cout << "salary:" << salary << endl << "position:" << position << endl;
    }
private:
    double salary;
    string position;

};

class Student:virtual public Person
{
public:
    Student(string n,int a,char s,string num):Person(n,a,s)
    {
        number=num;
        cout << "number:" << number << endl;
    }
private:
    string number;
};

class PartTime_Graduate_Student:public Employee,public Student
{
public:
    PartTime_Graduate_Student(string n,int a,char s,double sa,string p,string num,string uni):Person(n,a,s),Employee(n,a,s,sa,p),Student(n,a,s,num)
    {
        university=uni;
        cout << "university:" << university << endl;
    }
private:
    string university;
};

int main()
{
    string n="Jack",p="manager",num="1001",uni="OUC";
    PartTime_Graduate_Student obj(n,20,'m',5000,p,num,uni);
    return 0;
}
