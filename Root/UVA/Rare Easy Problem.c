#include <stdio.h>

int main()
{
    unsigned long long n,n1,n_m;
    while(scanf("%llu",&n_m)==1 && n_m)
    {
        n=(n_m)*10/9;
        n1=n-1;
        if(n1-(n1/10)==n_m)
            printf("%llu %llu",n1,n);
        else
            printf("%llu",n);
        printf("\n");
    }
    return 0;
}
