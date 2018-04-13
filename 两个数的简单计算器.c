#include<stdio.h>
int main()
{
    int a,b;
    char c;
    do{
            scanf("%d %c %d",&a,&c,&b);
    }while((c=='/'||c=='%')&&b==0);
    switch(c)
    {
        case '+':printf("%d",a+b);break;
        case '-':printf("%d",a-b);break;
        case '*':printf("%d",a*b);break;
        case '/':printf("%d",a/b);break;
        case '%':printf("%d",a%b);break;
        default:printf("ERROR");
    }
    return 0;
}
