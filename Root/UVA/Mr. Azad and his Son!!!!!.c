#include <stdio.h>
#include <math.h>

int arr[32];
int main()
{
    unsigned long long n,i,j,p;
    arr[0]=arr[1]=1;
    for(i=4;i<32;i+=2)
        arr[i]=1;
    for(i=3;i<sqrt(32);i+=2)
    {
        if(arr[i]==0)
        {
            for(j=i*i;j<32;j+=i*2)
                arr[j]=1;
        }
    }
    while(scanf("%llu",&n)==1)
    {
        if(n==0) break;
        if(n==2 || n==3 || n==5 || n==7 || n==13 || n==17 ||n==19 ||n==31)
        {
            p=(pow(2,n-1))*(pow(2,n)-1);
            printf("Perfect: %llu!\n",p);
        }
        else if(arr[n]==1)
            printf("Given number is NOT prime! NO perfect number is available.\n");
        else
            printf("Given number is prime. But, NO perfect number is available.\n");
    }

    return 0;
}
