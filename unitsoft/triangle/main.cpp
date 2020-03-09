#include <stdio.h>

int n;
int arr[100][2];
int max=0;

int main(){
    freopen("triangles.in","r",stdin);
    freopen("triangles.out","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d %d",&arr[i][0],&arr[i][1]);
    }
    int tmp;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                if(arr[i][0]==arr[j][0]){
                    if(arr[k][1]==arr[j][1]){
                        tmp=(arr[j][1]-arr[i][1])*(arr[k][0]-arr[j][0]);
                    }
                    if(arr[i][1]==arr[k][1]){
                        tmp=(arr[j][1]-arr[i][1])*(arr[k][0]-arr[i][0]);
                    }
                    else continue;
                }
                if(arr[i][0]==arr[k][0]){
                    if(arr[k][1]==arr[j][1]){
                        tmp=(arr[i][1]-arr[k][1])*(arr[k][0]-arr[j][0]);
                    }
                    if(arr[i][1]==arr[j][1]){
                        tmp=(arr[i][1]-arr[k][1])*(arr[i][0]-arr[j][0]);
                    }
                    else continue;
                }
                if(arr[j][0]==arr[k][0]){
                    if(arr[i][1]==arr[j][1]){
                        tmp=(arr[j][1]-arr[k][1])*(arr[i][0]-arr[j][0]);
                    }
                    if(arr[i][1]==arr[k][1]){
                        tmp=(arr[k][1]-arr[j][1])*(arr[i][0]-arr[k][0]);
                    }
                    else continue;
                }
                else continue;
                if(tmp<0) tmp*=(-1);
                if(tmp>max) max=tmp;
            }
        }
    }
    printf("%d",max);
}
