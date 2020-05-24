#include<stdio.h>
#include<string.h>

int main()
{
    unsigned long long int n,k,m,p,c;
    scanf("%llu",&p);
    for(m=0;m<p;m++)
    {
        scanf("%llu",&n);
        k=0;
        for(;n!=0;n/=2)
        {
            if(n%2==1)k++;
        }
        if(k%2==0)
        printf("Case %llu: even\n",m+1);
        else
        printf("Case %llu: odd\n",m+1);


    }
    return 0;
}
