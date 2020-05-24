#include <stdio.h>
#include <math.h>

int arr[10000+10],prime[5000],str[10010];
void sieve(void)
{
    int i,j,k;
    arr[0]=arr[1]=1;
    prime[0]=2;
    for(i=4;i<10010;i+=2)
        arr[i]=1;
    for(i=3;i<sqrt(10010);i+=2)
    {
        if(arr[i]==0)
        {
            for(j=i*i;j<10010;j+=i<<1)
            {
                arr[j]=1;
            }
        }
    }
    k=1;
    for(i=3;i<10010;i+=2)
        if(arr[i]==0)
            prime[k++]=i;
    return;
}

int terrorist(int n)
{
    int i,k,pow,fac;
    k=n;
    fac=1;
    for(i=0;prime[i]<n/2 && k!=1 ;i++)
    {
        if(k%prime[i]==0)
        {
            pow=0;
            while(k%prime[i]==0)
            {
                k/=prime[i];
                pow++;
            }
            fac*=(pow+1);
        }
    }

    if(k!=1)
        fac*=2;

    if(arr[fac]==0) return 1;
    else return 0;
}

int main()
{
    sieve();
    int n,m,i,j,k,h,l;
    str[0]=str[1]=0;
    for(i=2;i<10010;i++)
    {
        str[i]=terrorist(i);
    }

    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&l,&h);
        for(j=l,k=0;j<=h;j++)
        {
            if(str[j]==1 && j>0)
            {
                if(k==0)
                {
                    printf("%d",j);
                    k++;
                }
                else
                    printf(" %d",j);
            }
        }
        if(k==0)
            printf("-1");
        printf("\n");
    }
    return 0;
}
