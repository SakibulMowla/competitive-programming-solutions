#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <iostream>

using namespace std;

int len;
char arr[20];

int compare( const void * a, const void * b)
{
    return( *(char*)a - *(char*)b );
}

void generator(void)
{
    int n,m,i,j,flag1,flag2;
    char temp;
    flag1=flag2=0;
    for(n=0;n<len-1;n++)
    {
        if(arr[n]<arr[n+1])
        {
            i=n;
            flag1=1;
        }
    }
    for(n=0;n<len;n++)
    {
        if(arr[n]>arr[i])
        {
            j=n;
            flag2=1;
        }
    }
    if(flag1==1 && flag2==1)
    {
        temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
        for(n=i+1,m=len-1;n<i+1+(len-i-1)/2;n++,m--)
        {
            temp=arr[n];
            arr[n]=arr[m];
            arr[m]=temp;
        }
        printf("%s\n",arr);
        generator();
    }
    else
        return;
    return;
}

int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%s",arr);
        len=strlen(arr);
        qsort (arr, len, sizeof(char), compare);
        printf("%s\n",arr);
        generator();
        printf("\n");
    }
    return 0;
}

