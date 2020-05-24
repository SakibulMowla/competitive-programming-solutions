#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;

long arr[10000010];
int main()
{
    long i,k,l,n;

    scanf("%ld",&k);
    for(l=0; l<k; l++)
    {
        scanf("%ld",&n);
        double sum=0;
        for(i=1; i<=n; i++)
        {
            sum+=log10(i);
            arr[i]=ceil(sum);
        }
        arr[0]=arr[1]=1;
        printf("%ld\n",arr[n]);
    }

    return 0;
}
