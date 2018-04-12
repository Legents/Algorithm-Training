#include<stdio.h>
#include<math.h>
int isPrime(long p)
{
    long i;
    for(i=2;i<sqrt(p);i++)
        if(p%i==0)
            return 0;
    return 1;
}
int main()
{
    long N;
    long i;
    do{
        scanf("%ld",&N);
    }while(N<=2||N>2000000000||N%2!=0);
    for(i=2;i<N/2;i++)
    {
        if(isPrime(i)&&isPrime(N-i)){
            printf("%ld = %ld + %ld",N,i,N-i);
            break;
        }
    }
    return 0;
}
