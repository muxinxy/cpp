#include <iostream>
#include <string>

using namespace std;

int n=0;

class timetable//the declaration of class timetable
{
public:
    void Add();
    void Search();
    void Edit();
    void Display();
private:
    int hour,minute,second;
    string act;
}tab[100];

void timetable::Add()//function to add a piece of data to array
{
    int i,flag=0;
    cout << "Please input hour minute second activity:";
    cin >> tab[n].hour >> tab[n].minute >> tab[n].second >> tab[n].act;
    for(i=0;i<n;i++)//check whether it exists
    {
        if(tab[i].hour==tab[n].hour && tab[i].minute==tab[n].minute && tab[i].second==tab[n].second)
            {
                flag=1;
                break;
            }
    }
    while(flag==1)
    {
        cout << "Exist" << endl;
        cout << "Please input hour minute second activity:";
        cin >> tab[n].hour >> tab[n].minute >> tab[n].second >> tab[n].act;
        flag=0;
        for(i=0;i<n;i++)
        {
            if(tab[i].hour==tab[n].hour && tab[i].minute==tab[n].minute && tab[i].second==tab[n].second)
            {
                flag=1;
                break;
            }
        }
    }
    cout << "Input successfully" << endl;
    n++;
}

void timetable::Search()//function to search data in array
 {
    int i,flag=0;
    cout << "Please input hour minute second to search:";
    cin >> hour >> minute >> second;
    for(i=0;i<100;i++)//search
    {
        if(tab[i].hour==hour && tab[i].minute==minute && tab[i].second==second)
            {
                flag=1;
                break;
            }
    }
    if(flag)cout << tab[i].act << endl;
    else cout << "Not found" << endl;
}

void timetable::Edit()//function to edit data in array
{
    int i,flag=0;
    cout << "Please input hour minute second to edit:";
    cin >> hour >> minute >> second;
    for(i=0;i<100;i++)//search
    {
        if(tab[i].hour==hour && tab[i].minute==minute && tab[i].second==second)
            {
                flag=1;
                break;
            }
    }
    if(flag)//edit
    {
        cout << "Please input new activity:";
        cin >> tab[i].act;
        cout << "Edit successfully" << endl;
    }
    else cout << "Not found" << endl;
}

void timetable::Display()//function to display data
{
    int i;
    timetable temp;
    for(i=0;i<n-1;i++)//sort data
    {
        if((tab[i].hour*3600+tab[i].minute*60+tab[i].second)>(tab[i+1].hour*3600+tab[i+1].minute*60+tab[i+1].second))
        {
            temp=tab[i];
            tab[i]=tab[i+1];
            tab[i+1]=temp;
        }
    }
    for(i=0;i<n && n>0;i++)//display data
    {
        cout << tab[i].hour << ":" << tab[i].minute << ":" << tab[i].second << " " << tab[i].act << endl;
    }
    if(n==0)cout << "Empty" << endl;
}

int main()
{
    int choice=1;
    timetable mytime;
    while(choice!=0)//build the menu
    {
        cout << "1.Add   2.Search   3.Edit   4.Display   0.Exit\nPlease choose the menu:";
        cin >> choice;

        switch(choice)
        {
            case 1:mytime.Add();break;
            case 2:mytime.Search();break;
            case 3:mytime.Edit();break;
            case 4:mytime.Display();break;
            case 0:break;
        }
    }
    return 0;
}
