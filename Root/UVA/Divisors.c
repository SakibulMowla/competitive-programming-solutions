#include <stdio.h>
#include <math.h>

int prime[20000];
int tot_prime=0;
int div;
int num;

void func(int n,int m);
int main()
{
    int i,j,k,l,n,m,c,limit;
    limit=sqrt(1000000000);
    int arr[limit];
    memset(arr,0,sizeof(arr));
    prime[tot_prime++]=2;
    for(i=3;i<limit;i+=2)
    {
        if(arr[i]==0)
        {
            for(j=i*i;j<limit;j+=i*2)
            {
                arr[j]=1;
            }
            prime[tot_prime++]=i;
        }
    }
    scanf("%d",&k);
    for(l=0;l<k;l++)
    {
        scanf("%d %d",&n,&m);
        func(n,m);
        printf("Between %d and %d, %d has a maximum of %d divisors.\n",n,m,num,div);
    }

    return 0;
}
void func(int n,int m)
{
    div=0;
    num=0;
    int a,i,j,loc_div;

    for(;n<=m;n++)
    {
        a=n;
        for(i=0,loc_div=1;i<tot_prime && a!=1;i++)
        {
            j=1;
            while(a%prime[i] == 0)
            {
                a/=prime[i];
                j++;
            }
            loc_div*=j;
        }
        if(a!=1)
            loc_div*=2;
        if(div < loc_div)
        {
            div=loc_div;
            num=n;
        }
    }
}
