#include <stdio.h>
#include <string.h>

int prime[2000];
int main()
{
    char arr[1000];
    int i,j,k,l,n,m,len,sum;
    prime[0]=1;prime[2]=0;
    for(i=4;i<=2000;i+=2)
        prime[i]=1;
    for(i=3;i<45;i+=2)
    {
        if(prime[i]==0)
        {
            for(j=i*i;j<=2000;j+=i*2)
                prime[j]=1;
        }
    }
    while(gets(arr))
    {
        len=strlen(arr);
        sum=0;
        for(i=0;i<len;i++)
        {
            if(arr[i]>='a' && arr[i]<='z')
                sum+=arr[i]-96;
            else if(arr[i]>='A' && arr[i]<='Z')
                sum+=arr[i]-38;
        }
        if(prime[sum]==0)
            printf("It is a prime word.\n");
        else
            printf("It is not a prime word.\n");
    }

    return 0;
}
