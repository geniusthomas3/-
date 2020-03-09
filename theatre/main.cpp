#include <iostream>

using namespace std;
long long int D[100][100]={0,};
long long int cnt=0;

long long int combination(int n,int r){
    if(D[n][r]!=0){
        cnt++;
        return D[n][r];
    }
    else{
        if(n==r){
            cnt++;
            D[n][r]=1;
            return 1;
        }
        else if(r==1){
            cnt++;
            D[n][r]=n;
            return n;
        }
        else{
            cnt++;
            D[n][r]=combination(n-1,r-1)+combination(n-1,r);
            return D[n][r];
        }
    }
}

long long int combination1(int n,int r){
        if(n==r){
            cnt++;
            return 1;
        }
        else if(r==1){
            cnt++;
            return n;
        }
        else{
            cnt++;
            return combination1(n-1,r-1)+combination1(n-1,r);
        }
}
int main()
{
    int n,r;
    scanf("%d %d",&n,&r);
    printf("%lld ",combination(n,r));
    printf("%lld",cnt);
    return 0;
}
