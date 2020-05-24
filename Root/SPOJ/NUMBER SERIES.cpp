#include "stdio.h"

int main()
{
    long long i,t[110];
    t[1] = 1 , t[2] = 2 , t[3] = 3;
    printf("1\n2\n3\n");
    for(i=4;i<=100;i++)
    {
        t[i] = t[i-1] + t[i-3];
        printf("%lld\n",t[i]);
    }

    return 0;
}
