#include <stdio.h>

int recur(int left.int prev,int index){
    for(int i=left;i>=1;i--){
        if(index==1){
            printf("%d",prev);
        }
    }
}

int main(){
    int n;
    scanf("%d",&n);
    recur(n,n,0);
}
