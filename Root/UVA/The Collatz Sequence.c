#include <stdio.h>

int main()
{
    long long n,i,l,a,c;

    i=1;
    while(scanf("%lld %lld",&n,&l)==2)
    {
        if(n<0 && l<0)
            break;
        c=1;
        a=n;
        while(a!=1 && a<=l)
        {
            if(a%2==0)
                a/=2;
            else
            {
                a=(3*a)+1;
                if(a>l)
                    break;
            }
            c++;
        }
        printf("Case %lld: A = %lld, limit = %lld, number of terms = %lld\n",i,n,l,c);
        i++;
    }

    return 0;
}
