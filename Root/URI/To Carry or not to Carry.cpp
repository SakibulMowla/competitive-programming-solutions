#include "bits\stdc++.h"

int main()
{
    unsigned int a, b;

    while(scanf("%u %u",&a,&b) == 2)
    {
        a = a ^ b;
        printf("%u\n",a);
    }

    return 0;
}
