#include <stdio.h>
#include <math.h>

int main()
{
    int n,k,a,b,N,KK;
    unsigned long long ans;
    while(scanf("%d %d",&n,&k) == 2)
    {
        if(n==0 && k==0)break;
        if(n==k-1 || k==1)
        {
            printf("%d things taken %d at a time is %d exactly.\n",n,k,n);
            continue;
        }
        KK=k;
        if(k > n/2)
            k=n-k;
        N=n;
        a=n-k;
        b=k;
        ans=1;
        while(n>a)
        {
            ans*=n;
            n--;
            while(b>1 && ans%b==0)
            {
                ans/=b;
                b--;
            }
        }
        printf("%d things taken %d at a time is %llu exactly.\n",N,KK,ans);
    }
    return 0;
}
