#include<stdio.h>
int main()
{
    long long int a,b,i,n;

    scanf("%lld",&n);
    for(i=0;i<n;i++)
    {
        scanf("%lld %lld",&a,&b);
        if(a>b)
            printf(">\n");
        if(a<b)
            printf("<\n");
        if(a==b)
            printf("=\n");
    }
    return 0;
}
