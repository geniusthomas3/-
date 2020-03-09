#include <stdio.h>


int n;
char tmp;
int A[1001];
int B[1001];
int C[1001];

int main(){


    freopen("breedflip.in","r",stdin);
    freopen("breedflip.out","w",stdout);
    scanf("%d\n",&n);
    for(int i=0;i<n;i++){
        scanf("%c",&tmp);
        if(tmp=='H'){
            A[i]=-1;
        }
        else A[i]=1;
    }
    scanf("\n");
    for(int i=0;i<n;i++){
        scanf("%c",&tmp);
        if(tmp=='H'){
            B[i]=-1;
        }
        else B[i]=1;
    }
    for(int i=0;i<n;i++){
        if(B[i]!=A[i]) C[i]=1;
    }
    int cnt=0;
    if(C[0]==1) cnt++;
    for(int i=1;i<n;i++){
        if(C[i]==1&&C[i-1]==0) cnt++;
    }
    printf("%d",cnt);
}
