#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int func(int n);
int arr[1000010],emirp[1000010];
int main()
{
    int n,i,j;
    arr[0]=arr[1]=1;
    for(i=4;i<1000010;i+=2)
        arr[i]=1;
    for(i=3;i<sqrt(1000010);i+=2)
        if(arr[i]==0)
            for(j=i*i;j<1000010;j+=i*2)
                arr[j]=1;

    for(i=3;i<1000000;i+=2)
    {
        if(arr[i]==0);
            emirp[i]=func(i);
    }
    while(scanf("%d",&n)==1)
    {
        if(arr[n]==1)
            printf("%d is not prime.\n",n);
        else if(arr[n]==0 && emirp[n]==1)
            printf("%d is emirp.\n",n);
        else if(arr[n]==0 && emirp[n]==0)
            printf("%d is prime.\n",n);
    }

    return 0;
}

int func(int n)
{
    char arr2[100],arr1[100];
    int l,i,c,k;
    l=sprintf(arr2,"%d",n);
    c=0;
    for(i=l-1;i>=0;i--)
    {
        arr1[c++]=arr2[i];
    }
    arr1[c]='\0';
    k=atoi(arr1);
    if(arr[k]==0 && k!=n)
        return 1;
    else
        return 0;
}
