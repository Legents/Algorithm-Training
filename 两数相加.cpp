#include<stdio.h>
#include<stdlib.h>
struct ListNode {
     int val;
    struct ListNode *next;
};
 
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *p, *q, *s, *r, *d;
    int a, b;
    s = (struct ListNode*) malloc(sizeof(struct ListNode));
    s->next = NULL;
    r = s;
    s->val = l1->val + l2->val;
    p = l1->next;
    q = l2->next;
    while(q!=NULL&&p!=NULL){
        d = (struct ListNode*) malloc(sizeof(struct ListNode));
        d->next = NULL;
        d->val = q->val + p->val;
        r->next = d;
        r = r->next;
        p = p->next;
        q = q->next;
    }
    if(p!= NULL)
        r->next = p;
    if(q!= NULL)
        r->next = q;
    r = s;
    while(r!= NULL){
        if(r->val>9){
            a = r->val / 10;
            b = r->val % 10;
            r->val = b;
            if(r->next!=NULL){
                r->next->val = r->next->val + a;
            }
            else{
                d = (struct ListNode*) malloc(sizeof(struct ListNode));
                d->next = NULL;
                d->val = a;
                r->next = d;
            }
        }
        r = r->next;
    }    
    return s;
} 
struct ListNode* initList(){
	struct ListNode* l=(struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* p=l;
	int n=3;
	while(n--){
		p->next=(struct ListNode*)malloc(sizeof(struct ListNode));
		p=p->next;
		p->val=n+5;
	}
	return l;
}
int main(){
	struct ListNode* l1=initList();
	struct ListNode* p=l1->next;
	while(p){
		printf("%d  ",p->val);
		p=p->next;
	}
	printf("\n");
	struct ListNode* l2=initList();
	p=l2->next;
	while(p){
		printf("%d  ",p->val);
		p=p->next;
	}
	printf("\n");
	struct ListNode* l3=addTwoNumbers(l1, l2);
	p=l3->next;
	while(p){
		printf("%d  ",p->val);
		p=p->next;
	}
	return 0;
}
