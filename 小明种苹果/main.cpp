#include <iostream>

using namespace std;

int main()
{
    int N,M,i,j,T=0,k=0,P=1;
    cin >> N >> M;
    int apple[N][M+1];
    for(i=0;i<N;i++){
        for(j=0;j<=M;j++){
            cin >> apple[i][j];
        }
    }
    int temp_P=0;
    for(i=0;i<N;i++){
        temp_P=0;
        for(j=0;j<=M;j++){
            T+=apple[i][j];
            if(j!=0){
                temp_P+=apple[i][j];
            }
        }
        if(temp_P<P){
            P=temp_P;
            k=i+1;
        }
    }
    P=-P;
    cout << T << " " <<k <<  " " << P;
    return 0;
}
