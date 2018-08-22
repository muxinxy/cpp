#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main()
{
    int a[10],i,j,temp;
    fstream iofile1("first.dat",ios::in|ios::out|ios::binary);
    fstream iofile2("second.dat",ios::in|ios::out|ios::binary);
    if(!iofile1)
    {
        cerr<<"open error!"<<endl;
        exit(1);
    }
    if(!iofile2)
    {
        cerr<<"open error!"<<endl;
        exit(1);
    }
    cout<<"Enter 10 integer numbers:"<<endl;
    for(i=0;i<5;i++)//write the first 5 numbers to first.dat
    {
        cin>>a[i];
        iofile1.write((char *)&a[i],sizeof(a[i]));
    }
    cout << "first.dat" << endl;
    for(i=0;i<5;i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    cout << "second.dat" << endl;
    for(i=0;i<5;i++)//write the last 5 numbers to second.dat
    {
        cin>>a[i];
        iofile2.write((char *)&a[i],sizeof(a[i]));
        cout << a[i] << " ";
    }
    cout << endl;
    iofile1.seekp(5*sizeof(a[0]),ios::beg);
    iofile2.seekg(0,ios::beg);
    for(i=0;i<5;i++)//read 5 numbers from second.dat and wirte to the last of first.dat
    {
        iofile2.read((char *)&a[i],sizeof(a[i]));
        iofile1.write((char *)&a[i],sizeof(a[i]));
    }
    cout << "first.dat" << endl;
    iofile1.seekg(0,ios::beg);
    for(i=0;i<10;i++)//read 10 numbers from first.dat
    {
        iofile1.read((char *)&a[i],sizeof(a[i]));
        cout << a[i] << " ";
    }
    cout << endl;
    for(i=0;i<10;i++)//sort
    {
        for(j=i+1;j<10;j++)
        {
            if(a[i]>a[j])
            {
                temp=a[j];
                a[j]=a[i];
                a[i]=temp;
            }
        }
    }
    iofile2.seekp(0,ios::beg);
    for(i=0;i<10;i++)//write the 10 sorted numbers to second.dat
    {
        iofile2.write((char *)&a[i],sizeof(a[i]));
    }
    cout << "second.dat" << endl;
    for(i=0;i<10;i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    iofile1.close();
    iofile2.close();
    return 0;
}
