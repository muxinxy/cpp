#include <iostream>

using namespace std;

int main()
{
    int i,j,N,M,temp_T;
    int T=0,D=0,E=0;
    int drop[1001];
    int apple[1001][1001];
    cin >> N;
    for(i=0;i<N;i++){
        cin >> M;
        apple[i][0]=M;
        for(j=1;j<=M;j++){
            cin >> apple[i][j];
        }
    }
    for(i=0;i<N;i++){
        temp_T=0;
        drop[i]=0;
        for(j=1;j<=apple[i][0];j++){
            if(j==1 || (j!=1 && apple[i][j]<=0)){
                temp_T+=apple[i][j];
            }else if(temp_T>apple[i][j]){
                D++;
                drop[i]=1;
            }
        }
        T+=temp_T;
    }
    for(i=0;i<N;i++){
        if(i==0 && drop[0]==1 && drop[N-1]==1 && drop[1]==1){
            E++;
        }else if(i==N-1 && drop[N-1]==1 && drop[0]==1 && drop[N-2]==1){
            E++;
        }else if(drop[i]==1 && drop[i-1]==1 && drop[i+1]==1){
            E++;
        }
    }
    cout << T << " " << D << " " << E;
    return 0;
}
