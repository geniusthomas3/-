#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
/*
int cnt=0;

int isprime(int n){
    int cnt=0;
    for(int i=0;i*i<n;i++){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}

int check(char* a){
    int flag=0;
    for(int i=0;a[i]!=NULL;i++){
        if(a[i]=='*'){
            for(int j=0;j<10;j++){
                a[i]=j+'0';
                check(a);
            }
            flag=1;
        }
    }
    if(flag==0&&isprime(atoi(a))){
        cnt++;
    }
    return 0;
}

int main(){
    char str[7];
    scanf("%s",&str);
    check(str);
    printf("%d",cnt);
}*/


int flag[4];

int isprime(int n){
    int cnt=0;
    for(int i=0;i*i<n;i++){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}

int main(){
    char str[7];
    int cnt=0,j=0,count=0;
    scanf("%s",&str);
    for(int i=0;str[i]!=NULL;i++){
        if(str[i]=='*'){
            cnt++;
            flag[j++]=i;
        }
    }
    if(cnt==0){
        printf("0");
    }
    if(cnt==1){
        for(int i=0;i<10;i++){
            str[flag[0]]=i;
            if(isprime(atoi(str))){
                count++;
            }
        }
    }
    if(cnt==2){

    }

}










