#include <iostream>
#include <cstdio>

using namespace std;

int n, i,j,nums[19];
long long p ;
long long maxP = 0 ;

long long search()
{
    maxP = 0;
    for (i=0 ; i<n ; i++)
    {
        p = 1;
        for (j=i ; j<n && p ; j++)
        {
            p*=nums[j];
            if ( p>maxP)
                maxP = p;
        }
    }
    return maxP;
}

int main()
{
    int t = 0;
    while (scanf("%d", &n)==1)
    {
        for(int i = 0; i < n; ++i)
        {
            scanf("%d",&nums[i]);
        }
        printf("Case #%d: The maximum product is %lld.\n\n", ++t, search());
    }
}
