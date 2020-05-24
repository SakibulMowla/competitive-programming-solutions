#include <stdio.h>
#include <math.h>

int arr[1000005],prime[9];
void sieve(void)
{
    int i,j,k;
    arr[0]=arr[1]=1;
    prime[0]=2;
    for(i=3;i<sqrt(1000005);i+=2)
    {
        if(arr[i]==0)
        {
            for(j=i*i;j<1000005;j+=i+i)
                arr[j]=1;
        }
    }
    k=1;
    for(i=0;i<1000005;i++)
        if(arr[i]==0)
            k++;
        printf("%d\n",k);
}
int main()
{
    sieve();
    return 0;
}
