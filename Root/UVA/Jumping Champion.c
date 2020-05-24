#include <stdio.h>
#include <math.h>

long int arr[1000010],prime[1000010],dif[1000];
int main()
{
    long int p,i,j,k,l,n,m,c,u,v,s,cam;
    prime[0]=2;
    for(i=3;i<sqrt(1000010);i+=2)
    {
        if(arr[i]==0)
        {
            for(j=i*i;j<1000010;j+=i*2)
                arr[j]=1;
        }
    }
    c=1;
    for(i=3;i<1000010;i+=2)
    {
        if(arr[i]==0)
        {
            prime[c++]=i;
        }
    }
    scanf("%ld",&n);
    for(l=0;l<n;l++)
    {
        scanf("%ld %ld",&u,&v);
        s=0;c=0;
        for(i=0;i<1000010;i++)
        {
            if(prime[i]>=u)
            {
                for(j=i+1;j<1000010;j++)
                {
                    if(prime[j]>v)
                    {
                        s=1;
                        break;
                    }
                    c++;
                    dif[prime[j]-prime[j-1]]++;
                }
            }
            if(s==1)
                break;
        }
        if(c==0)
        {
            printf("No jumping champion\n");
            continue;
        }
        cam=0;
        for(i=1;i<1000;i++)
        {
            if(dif[i] > cam)
            {
                cam=dif[i];
                k=i;
                c=1;
            }
            else if(dif[i] != 0 && dif[i]==cam)
                c=0;
        }
        if(c==0)
            printf("No jumping champion\n");
        else
            printf("The jumping champion is %ld\n",k);
        for(i=0;i<1000;i++)
                dif[i]=0;
    }

    return 0;
}
