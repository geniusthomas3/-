#include <stdio.h>

int main(){
    int n,m,cnt=1;
    scanf("%d %d",&n,&m);
    cnt=m%2;
    for(int j=0;j<n;j++){
        for(int i=0;i<m;i++){
            if(i%2==cnt){
                printf("%d ",m*n-(i*n+1+j)+1);
            }
            else{
                printf("%d ",m*n-(i*n+n-j)+1);
            }
        }
        printf("\n");
    }
}
/*
#include <stdio.h>

int main(){
    int n,m,cnt=1;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i%2==0){
                printf("%d ",i*m+1+j);
            }
            else{
                printf("%d ",i*m+m-j);
            }
        }
        printf("\n");
    }
}

#include <stdio.h>

int main(){
    int n,cnt=1;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",n*j+1+(n-1-i));
        }
        printf("\n");
    }
}

*/
