#include <stdio.h>
#include <math.h>

int p[50000],store[20000],k=0;
void prime(void)
{
    p[0]=p[1]=1;
    store[k++]=2;
    int i,j;

    for(i=3; i<46341; i+=2)
        if(p[i]==0)
        {
            store[k++]=i;
            for(j=i*i; j<46341; j+=i*2)
                p[j]=1;
        }

    return;
}

int main()
{
    long n,i,j,pow,sum,r;
    prime();
    while(scanf("%ld",&n)==1)
    {
        j=sum=n;
        r=1;i=0;

        while(n!=1 && store[i]*store[i] <=n && store[i]!=0)
        {
            pow=0;
            if(n%store[i]==0)
            {
                sum-=sum/store[i];
                while(n%store[i]==0)
                {
                    n/=store[i];
                    pow++;
                }
                r*=(pow+1);
            }
            i++;
        }
        if(n!=1)
        {
            sum-=sum/n;
            r*=2;
        }
        printf("%ld\n",j-sum-r+1);
    }

    return 0;
}
