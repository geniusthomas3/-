#include <stdio.h>
#include <stdlib.h>

int n,tmp;

typedef struct Node{
    Node* left;
    Node* right;
    int data;
}Node;

Node * new_Node(int data);

int main()
{
    scanf("%d",&n);
    scanf("%d",&tmp);
    Node * head=new_Node(tmp);
    Node * cur=NULL;
    for(int i=1;i<n;i++){
        scanf("%d",&tmp);
        Node * p= new_Node(tmp);
        cur=head;
        for(;;){
            if(tmp==cur->data) break;
            if(tmp>cur->data){
                if(cur->right==NULL){
                    cur->right=p;
                    break;
                }
                else{
                    cur=cur->right;
                }
            }
            if(tmp<cur->data){
                if(cur->left==NULL){
                    cur->left=p;
                    break;
                }
                else{
                    cur=cur->left;
                }
            }
        }

    }
    cur=head;
    for(;cur->right!=NULL;){
        cur=cur->right;
    }
    printf("%d ",cur->data);
    cur=head;
    for(;cur->left!=NULL;){
        cur=cur->left;
    }
    printf("%d",cur->data);
    return 0;
}

Node * new_Node(int data){
    Node * p=(Node*)malloc(sizeof(Node));
    p->data=data;
    p->left=NULL;
    p->right=NULL;
}
