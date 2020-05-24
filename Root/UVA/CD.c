#include<stdio.h>

unsigned long long arr1[1000005];
unsigned long long arr2[1000005];

int main()
{
    unsigned long long n,m,i,j,c,a1,b1,a2,b2,a,b;
    while(scanf("%llu %llu",&n,&m)==2)
    {
        if(n==0 && m==0)
            break;
        for(i=0; i<n; i++)
        {
            scanf("%llu",&j);
            arr1[j]++;
            if(i==0)
                a1=j;
            if(i==n-1)
                b1=j;
        }
        for(i=0; i<m; i++)
        {
            scanf("%llu",&j);
            arr2[j]++;
            if(i==0)
                a2=j;
            if(i==n-1)
                b2=j;
        }

        c=0;
        if(a1>=a2)a=a1;
        else a=a2;
        if(b1<=b2)b=b1;
        else b=b2;
        for(i=a; i<=b; i++)
        {
            if(arr1[i]==1 && arr2[i]==1)
                c++;
        }
        printf("%llu\n",c);
        for(i=0; i<1000005; i++)
        {
            arr1[i]=0;
            arr2[i]=0;
        }
    }

    return 0;
}
