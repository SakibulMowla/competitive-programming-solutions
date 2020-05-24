#include <stdio.h>
#include <math.h>

int arr[10000+10],prime[5000],str[10010];

int main()
{
    int n,m,i,j,k,h,l,pow,fac;
    arr[0]=arr[1]=1;
    prime[0]=2;
    for(i=4; i<10010; i+=2)
        arr[i]=1;
    for(i=3; i<sqrt(10010); i+=2)
    {
        if(arr[i]==0)
        {
            for(j=i*i; j<10010; j+=i*2)
            {
                arr[j]=1;
            }
        }
    }

    k=1;
    for(i=3; i<10010; i+=2)
        if(arr[i]==0)
            prime[k++]=i;

    str[0]=str[1]=0;
    for(i=2; i<10010; i++)
    {
        n=i;
        k=n;
        fac=1;
        for(j=0; prime[j]<n/2 && k!=1 ; j++)
        {
            if(k%prime[j]==0)
            {
                pow=0;
                while(k%prime[j]==0)
                {
                    k/=prime[j];
                    pow++;
                }
                fac*=(pow+1);
            }
        }

        if(k!=1)
            fac*=2;

        if(arr[fac]==0) str[i]=1;
        else str[i]=0;
    }

    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d %d",&l,&h);
        for(j=l,k=0; j<=h; j++)
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
