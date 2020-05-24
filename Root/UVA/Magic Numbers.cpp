#include <stdio.h>
#include <string.h>
#include <math.h>

int check(long long n)
{
    long long i;
    char arr[12];
    memset(arr,0,sizeof(arr));
    while(n)
    {
        i = n%10;
        n/=10;
        arr[i]++;
        if(arr[i] > 1)
            return 0;
    }
    return 1;
}

int main()
{
    long long test,n,m,i;
    scanf("%lld",&test);
    while(test--)
    {
        scanf("%lld",&n);
        m = 1;
        for(i=n;i<=9876543210 && m <= 9876543210;i=n*m)
        {
            if(check(i) && check(m))
            {
                printf("%lld / %lld = %lld\n",i,m,n);
            }
            m++;
        }
        if(test) printf("\n");
    }
    return 0;
}
