#include "stdio.h"
#include "string.h"

#define SZ 1000010

char a[SZ], b[2*SZ];
int f[2*SZ];

int kmp()
{
    int n, i, k, n1 = strlen(a);

    for(i=0;i<n1;i++)
        b[i] = a[n1-i-1];

    b[n1] = '#';
    b[n1+1] = '\0';
    strcat(b, a);

    f[0] = k = 0;
    n = strlen(b);

    for(i=1;i<n;i++)
    {
        while(k>0 && b[i] != b[k])
            k =f[k-1];
        if(b[i] == b[k])
            k++;
        f[i] = k;
    }

    n1 = (n1*2) - f[n-1];

    return n1;
}

int main()
{
    int test = 0, t;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%s",a);
        printf("Case %d: %d\n",++test,kmp());
    }

    return 0;
}
