#include <iostream>

using namespace std;

int main(int argc, char** argv) {
	int total=0,p1=0,p2=0,p3=0,p4=0;
	int i,temp=0;
	cin>>total;
	for(i=1;i<=666;i++){
		if(temp==total){
			break;
		}else if(i%7==0 || i%10==7 || (i/10)%10==7 || i/100==7){
			switch(i%4){
				case 1:p1++;break;
				case 2:p2++;break;
				case 3:p3++;break;
				default:p4++;break;
			}
		}else{
			temp++;
		}
	}
	cout<<p1<<endl<<p2<<endl<<p3<<endl<<p4;
	return 0;
}
