#include <stdio.h>

int flag[150000]={0, };

int main(){
    int n,tmp,k;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&tmp);
        flag[tmp+50000]=1;
    }
    scanf("%d",&k);
    for(int i=-50000;(i<=50000)&&(2*i<k);i++){
        if(flag[i+50000]&&flag[k-i+50000]){
            printf("%d %d",i,k-i);
            return 0;
        }
    }
    printf("0 0");
    return 0;
}


///i+j=k
///i=flag[i+5000]
///j=k-i=flag[k-i+5000]
