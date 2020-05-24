#include <stdio.h>

int main()
{
    long long n,i,j,k,a[3],temp;
    scanf("%lld",&n);
    for(i=0;i<n;i++)
    {
        scanf("%lld %lld %lld",&a[0],&a[1],&a[2]);
        for(j=0;j<3-1;j++)
            for(k=j+1;k<3;k++)
                if(a[j]>a[k])
                {
                    temp=a[j];
                    a[j]=a[k];
                    a[k]=temp;
                }
        if(a[0]<=0 || a[1]<=0 ||a[2]<=0)
            printf("Case %d: Invalid\n",i+1);
        else if(a[0]+a[1]<=a[2])
            printf("Case %d: Invalid\n",i+1);
        else if(a[0]==a[1] && a[1]==a[2])
            printf("Case %d: Equilateral\n",i+1);
        else if((a[0]==a[1]) || (a[0]==a[2]) ||(a[1]==a[2]))
            printf("Case %d: Isosceles\n",i+1);
        else
            printf("Case %d: Scalene\n",i+1);
    }

    return 0;
}
