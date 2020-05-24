#include "stdio.h"
#include "iostream"
using namespace std;
#define SD(n) scanf("%d",&n)
#define FOR(i,n) for(i=0;i<n;i++)

int main()
{
    int i,n,a,b,l=0,r=0;
    SD(n);
    FOR(i,n)
    {
        SD(a);SD(b);
        if(a)l++;
        if(b)r++;
    }
    printf("%d\n",min(n-l,l)+min(r,n-r));

    return 0;
}
