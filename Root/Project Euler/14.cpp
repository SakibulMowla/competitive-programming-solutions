#include<stdio.h>

int main()
{
    long long int n,a,b,i,c,pc,temp,d,e,maxnum;

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
            if(c>pc)
                pc=c , maxnum = i;
        }

        printf("%lld %lld %lld\n",d,e,pc);
        printf("%lld\n",maxnum);
    }

    return 0;
}
