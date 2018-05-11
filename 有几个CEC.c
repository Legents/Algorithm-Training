#include<stdio.h>
#include<stdlib.h>
int main()
{
    char a[100000];
    long count=0;
    gets(a);
    int i=0;
    while(a[i]){
        if(a[i]=='C'){
            int j=i+1;
            while(a[j]){
            if(a[j]=='E'){
                int k=j+1;
                while(a[k]){
                if(a[k]=='C')
                    count++;
                k++;
                }
            }
        j++;
        }
    }
    i++;
}
        printf("%ld",count%1000000007);
        return 0;
}
