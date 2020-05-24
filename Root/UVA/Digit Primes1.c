#include <stdio.h>
#include <math.h>

int prime[1000000];
int main()
{
    int n,m,i,j,k,l,c;
    prime[0]=prime[1]=1;
    for(i=4;i<1000000;i+=2)
        prime[i]=1;
    for(i=3;i<=sqrt(1000000);i+=2)
    {
        if(prime[i]==0)
        {
            for(j=i*i;j<=n;j+=i*2)
                prime[j]=1;
        }
    }
    return 0;
}
