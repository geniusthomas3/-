#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    char data;
    struct Node *link;
    struct Node *blink;
}Node;

typedef struct List {
    int node_cnt;
    Node *head,*tail;
}List;

struct cursor{
    Node* next;
    Node* before;
}cursor;

Node *new_Node(char);
List *new_List();
void List_Stat(List *);
void Insert(List *, char, int);
void InsertCURSOR(List *, char);
void Delete(List *,int);
void DeleteCURSOR(List *);

int main(){
    List *list=new_List();
    char string[100000+1],tmp;
    char add;
    int cnt=0;
    int n;
    Node *p;
    scanf("%s", string);
    for(int i=0;string[i]!='\0';i++){
        Insert(list,string[i],i-1);
    }
    cursor.before=list->tail;
    cursor.next=NULL;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf(" %c",&tmp);
        if(tmp=='L'){
            if(cursor.before==NULL) continue;
            cursor.next=cursor.before;
            if(cursor.next->blink==NULL){
                cursor.before=NULL;
            }
            else{
                cursor.before=cursor.next->blink;
            }
        }
        else if(tmp=='D'){
            if(cursor.next==NULL) continue;
            cursor.before=cursor.next;
            if(cursor.before->link==NULL){
                cursor.next=NULL;
            }
            else{
                cursor.next=cursor.before->link;
            }
        }
        else if(tmp=='B'){
            if(cursor.before==NULL) { continue;}
            if(cursor.next==NULL && cursor.before==list->head){
                Delete(list,0);
                cursor.before=NULL;
                continue;
            }
            DeleteCURSOR(list);
            cursor.before=cursor.before->blink;

        }
        else if(tmp=='P'){
            scanf(" %c",&add);
            if(cursor.before==NULL&&cursor.next==NULL){
                Insert(list,add,0);
                cursor.before=list->head;
                continue;
            }
            if(cursor.before==NULL){
                Insert(list,add,-1);
                cursor.before=cursor.next->blink;
                continue;
            }
            InsertCURSOR(list,add);
            cursor.before=cursor.before->link;
        }
    }
    List_Stat(list);
}

void InsertCURSOR(List *list, char data){
    list->node_cnt++;
    Node *node = new_Node(data);///CREATE NEW NODE & INSERT data
        Node *p = cursor.before;///////////////////////////////
        if(p->link != NULL){
            node->link = p->link;
            p->link=node;
            node->blink= p;
            node->link->blink = node;
        }
        else {
            cursor.before->link = node;
            node->blink = cursor.before;
            list->tail=node;
        }
}

Node * new_Node(char data){
    Node *node=(Node*)malloc(sizeof(Node));
    node->data = data;
    node->link = NULL;
    node->blink= NULL;
    return node;
}

List *new_List(){
    List *list=(List*)malloc(sizeof(List));
    list->head=NULL;
    list->tail=NULL;
    list->node_cnt=0;
    return list;
}

void List_Stat(List *list){
    if(list->head==NULL&&list->tail==NULL) return;
    Node *p=list->head;
    while(p->link!=NULL){
        printf("%c",p->data);
        p=p->link;
    }
    ///One node left
    printf("%c",p->data);
}

void Insert(List *list, char data, int k){
    if(k >list->node_cnt){
        return;
    }
    list->node_cnt++;
    Node *node = new_Node(data);///CREATE NEW NODE & INSERT data
    if(list->head == NULL && list->tail == NULL){///EMPTY_LIST
        list->head = node;
        list->tail = node;
        return;
    }
    else if(k==-1){
        node->link = list->head;
        list->head->blink=node;
        list->head = node;
    }
    else {
        Node *p = list->head;
        while(k-- && p->link !=NULL) p=p->link;
        if(p->link != NULL){
            node->link = p->link;
            p->link=node;
            node->blink= p;
            node->link->blink = node;
        }
        else {
            p->link = node;
            node->blink = p;
            list->tail=node;
        }
    }
}

void Delete(List *list,int k){
    if(list->head == list->tail){
        list->head=NULL;
        list->tail=NULL;
    }
    else if(list->head->link==list->tail){
        if(!k){
            Node* p=list->head;
            list->head->link = NULL;
            list->tail->blink = NULL;
            list->head = list->tail;
            free(p);
        }
        else{
            Node *p = list->tail;
            list->head->link= NULL;
            list->tail->blink = NULL;
            list->tail = list->head;
            free(p);
        }
    }
    else{
        Node *p=list->head;
        if(!k){
            list->head=p->link;
            list->head->blink=NULL;
            p->link=NULL;
            free(p);
        }
        else{
            while(--k) p= p->link;
            Node *x = p->link;
            if(p->link!=list->tail){
                p->link= p->link->link;
                p->link->blink=p;
            }
            else{
                p->link = NULL;
                list->tail=p;
            }
            free(x);
        }
    }
    list->node_cnt--;
}

void DeleteCURSOR(List *list){
    if(list->head == list->tail){
        list->head=NULL;
        list->tail=NULL;
    }
    else if(list->head->link==list->tail){///List_Length = 2
        if(cursor.before==list->head){///k==0 delete the first one
            Node* p=list->head;
            list->head->link = NULL;
            list->tail->blink = NULL;
            list->head = list->tail;
            free(p);
        }
        else{///k!=0 the one on the back
            Node *p = list->tail;
            list->head->link= NULL;
            list->tail->blink = NULL;
            list->tail = list->head;
            free(p);
        }
    }
    else{
        Node *p=list->head;
        if(cursor.before==list->head){
            list->head=p->link;
            list->head->blink=NULL;
            p->link=NULL;
            free(p);
        }
        else{
            p= cursor.before->blink;
            Node *x = cursor.before;
            if(cursor.before!=list->tail){
                p->link= cursor.next;///p의 다음 노드 삭제
                cursor.next->blink=p;
            }
            else{
                cursor.before->blink->link = NULL;
                list->tail=cursor.before->blink;
            }
            free(x);
        }
    }
    list->node_cnt--;
}
