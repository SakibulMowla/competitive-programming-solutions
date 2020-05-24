#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
    long int k,n,i,j,l,a[2];
    scanf("%ld",&n);
    i=1;
    while(n--)
    {
        scanf("%ld",&k);
        l=0;
        for(j=2;j<=(int)sqrt(k);j++)
        {
            if(k%j==0)
                a[l++]=j;
            if(l==2) break;
        }
        printf("Case #%ld: %ld = %ld * %ld = %ld * %ld\n",i,k,a[0],k/a[0],a[1],k/a[1]);
        i++;
    }

    return 0;
}
