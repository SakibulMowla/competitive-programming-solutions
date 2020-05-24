#include <stdio.h>
#include <math.h>

int arr[25]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
int prime[101];
int str[101];

int main()
{
    int i,j,n,m,k,l,c;prime[0]=prime[1]=1;prime[2]=0;
    for(i=4;i<=100;i+=2)
        prime[i]=1;
    for(i=3;i<10;i+=2)
    {
        if(prime[i]==0)
        {
            for(j=i*i;j<=100;j+=i*2)
                prime[j]=1;
        }
    }

    while(scanf("%d",&n)==1)
    {
        if(n==0)
            break;
        printf("%3d! =",n);
        for(i=n;i>1;i--)
        {
            if(prime[i]==0)
                str[i]++;
            else
            {
                for(c=0,j=i;j>1;)
                {
                    if(j%arr[c]==0)
                    {
                        str[arr[c]]++;
                        j/=arr[c];
                    }
                    else
                    {
                        c++;
                    }
                }
            }

        }
        c=0;
        for(i=0;i<=100;i++)
        {
            if(prime[i]==0)
            {
                if(str[i]!=0)
                {
                    if(c==15)
                    printf("\n      ");
                    printf("%3d",str[i]);
                    c++;
                }
                else if(str[i]==0)
                    break;
            }
        }
        printf("\n");
        for(i=0;i<=100;i++)
            str[i]=0;

    }

    return 0;
}
