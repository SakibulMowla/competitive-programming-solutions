#include<stdio.h>

#define SZ 1000000

int dp[SZ+5];

int main()
{
    long long int n,a,b,i,c,pc,temp,d,e;

    for(i=0;i<SZ+2;i++) dp[i] = -1;

    while((scanf("%lld %lld",&a,&b))==2)
    {
        d=a;
        e=b;
        if(a>b)
        {
            temp=a;
            a=b;
            b=temp;
        }
        pc=1;

        for(i=a;i<=b;i++)
        {
            c=0;
            n=i;
            while(1)
            {
                if(n<SZ && dp[n] != -1)
                {
                    c += dp[n];
                    break;
                }
                if(n==1)
                {
                    c++;
                    break;
                }
                else
                {
                    if(n%2==1)
                    {
                        n=(3*n)+1;
                        c++;
                    }
                    else if(n%2==0)
                    {
                        n/=2;
                        c++;
                    }
                }
            }
            dp[i] = c;
            if(c>pc)
                pc=c;
        }

        printf("%lld %lld %lld\n",d,e,pc);
    }

    return 0;
}
