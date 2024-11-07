#include <stdio.h>

int main()
{
    long long int A[100];
    int a , i;

    scanf("%d",&a);
    A[0]=0;
    A[1]=1;

    for(i=2;i<=a;i++){
        A[i]=A[i-1]+A[i-2];
    }

    printf("%lld",A[a]);

    return 0;
}
