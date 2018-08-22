#include <iostream>

void GetRating(char&);//prototype

using namespace std;

int main()
{
    char rating;
    rating='x';
    GetRating(rating);//call
    cout << "That rating is " <<rating;
    return 0;
}

void GetRating(char& rating)
{
    char& rate=rating;//reference
    cout<<"E(excellent)   G(good)   A(middle)   P(bad)"<<endl<<"Please input the char which stands for the grade:";
    cin>>rate;
    while (rate!='E'&&rate!='G'&&rate!='A'&&rate!='P')//deal with the error of inputting
    {
        cout<<"E(excellent)   G(good)   A(middle)   P(bad)"<<endl<<"Please input the char which stands for the grade:";
        cin>>rate;
    }
}
