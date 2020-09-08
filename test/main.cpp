#include<iostream>
#include<cmath>
using namespace std;
int main(){
double pi=3.1415;
const double p=981,g=9.795,n=0.0000183,l=0.0015,b=0.00000617,P=76,d=0.005,e=1.60e-19;
double t,u;
double q,a,m,E,j,qSum=0,ESum=0;
int i;
//cout<<"U=";
//cin>>u;
for(int k=0;k<5 ;k++){
//cout<<"t=";
//cin>>t;
//a=sqrt(9*n*l/(2*p*g*t));
//m=(n*l)/((1+(b/P/a))*t);
//q=(18*pi)/sqrt(2*p*g)*sqrt(m*m*m)*(d/u);
//cout<<"q="<<q<<endl;
//qSum+=q;}
cin>>qSum;
//qSum=qSum/3;
j=qSum/e;i=j;
if((j-i)>=0.5) i=i+1;
else i=i;
E=qSum/i;
ESum+=E;}

//cout<<qSum;
cout<<ESum/5;
//<<endl<<i<<'\t'<<j<<endl<<E<<endl<<endl;
return 0;
}
