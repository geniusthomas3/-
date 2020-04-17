#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n,len;
int arr[1000];

int isgood(){
    for(int i=1; i<=len/2; i++){
        char a[1000],b[1000];
        int asize=0,bsize=0;
        for(int j=0; j<i; j++){
            a[asize++]=arr[len - (2*i) + j]+'0';
            b[bsize++]=arr[len - i + j]+'0';
        }
        a[asize]=NULL;
        b[bsize]=NULL;
        if(strcmp(a,b)==0) return 0;
    }
    return 1;
}

int dfs(int idx){
    if(idx==n+1){
        for(int i=0;i<n;i++){
            printf("%d",arr[i]);
        }
        exit(0);
    }
    len=idx;
    for(int i=1;i<=3;i++){
        arr[idx]=i;
        if(isgood()) dfs(idx+1);
        arr[idx]=0;
    }
}

int main(){
    scanf("%d",&n);
    dfs(0);
}
