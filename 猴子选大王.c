#include<stdio.h>
typedef struct Node{
    int data;
    struct Node *next;
}Node,*LinkList;
int main()
{
    int N,i,s=0;
    LinkList p,h,q;
    do{
        scanf("%d",&N);
    }while(N<0||N>1000);
    h=(LinkList)malloc(sizeof(Node));
    /*if(!h)
        {
            printf("³õÊ¼»¯Á´±í´íÎó£¡\n");
            exit(0);
        }*/
    h->next=h;
    for(i=N;i>0;i--)
    {
        p=(LinkList)malloc(sizeof(Node));
        p->data=i;
        p->next=h->next;
        h->next=p;
    }
    p=h->next;
    while(p!=h)
    {

        printf("%d  ",p->data);
        p=p->next;
    }
    p=h;
    while(N!=2)
    {
		s++;
        if(s==3){
        	q=h;
        	p->next=h->next;
        	free(q);
        	s=0;
        	N--;
		}
		else{
			p=h;
			h=h->next;
		}

    }
    printf("\n%d",p->data);
    return 0;

}
