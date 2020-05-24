
#include "iostream"
#include "stdio.h"
#include "math.h"

typedef long long ll;

int main()
{
    int k, n;

    scanf("%d",&k);

    while(k--)
    {
        scanf("%d",&n);
        printf("%d\n",1+(int)(0.5*log10(2*2*acos(0)*n)+n*log10(n/exp(1))));
    }

    return 0;
}
