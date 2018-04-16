#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node *next;
}Node,*LinkList;
int main()
{
    int n,num,s=0;
    LinkList p,h,q;
    h=(LinkList)malloc(sizeof(Node));
    h->next=NULL;
    scanf("%d",&num);
    while(scanf("%d",&n)&&n>=0)
    {
        p=(LinkList)malloc(sizeof(Node));
        p->data=n;
        p->next=h->next;
        h->next=p;
        s++;
    }
    if(num>s){
    	printf("NULL");
    	return 0;
	}
    p=h->next;
    s=1;
    while(s!=num)
    {
        p=p->next;
        s++;
    }
    printf("%d",p->data);
    return 0;
}
