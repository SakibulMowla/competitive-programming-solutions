#include<stdio.h>
#include<string.h>

unsigned long long int store[21];
int sign[92];

int main()
{
    unsigned long long int i,k,n,m,len;
    char z,arr[30];
    store[0]=1;
    for(i=1;i<21;i++)
    {
        store[i]=i*store[i-1];
    }

    scanf("%llu%c",&n,&z);
    for(k=0;k<n;k++)
    {
        gets(arr);
        len=strlen(arr);
        m=store[len];
        for(i=0;i<len;i++)
            sign[arr[i]]++;
        for(i=65;i<91;i++)
        {
            if(sign[i]>1)
                m/=store[sign[i]];
        }
        printf("Data set %llu: %llu\n",k+1,m);
        for(i=0;i<92;i++)
            sign[i]=0;
    }

    return 0;
}
