#include <stdio.h>

int win(char a,char b){
    if(a==b) return 0;
    if(a=="R"){
        if(b=="S") return 1;
        if(b=="P") return -1;

    }
    if(a=="S"){
        if(b=="P") return 1;
        if(b=="R") return -1;
    }
    if(a=="P"){
        if(b=="R") return 1;
        if(b=="S") return -1;
    }
}

int main(){
    char a,b;
    int sum=0;
    for(int i=0;i<5;i++){
        scanf("%c %c",&a,&b);
        sum+=win(a,b);
        printf("%d\n",sum);

    }
    if(sum>0){
        printf("�Ѿ���");
    }
    else if(sum==0){
        printf("����");
    }
    else{
        printf("�ξ���");
    }
}
