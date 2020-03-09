    #include <stdio.h>

    int flag[5][1001];
    int score[1000];

    int main(){
        int n;
        int num[1000][5];
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d %d %d %d %d",&num[i][0],&num[i][1],&num[i][2],&num[i][3],&num[i][4]);
        }
        for(int i=0;i<5;i++){
            for(int j=0;j<n;j++){
                flag[i][num[j][i]]++;
            }
            for(int j=0;j<n;j++){
                if(flag[i][num[j][i]]==1){
                    score[j]+=num[j][i];
                }
            }
        }
        for(int i=0;i<n;i++){
            printf("%d\n",score[i]);
        }
    }
