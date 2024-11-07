#include <stdio.h>

    long long int A[10'000'000];

int main()
{
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
