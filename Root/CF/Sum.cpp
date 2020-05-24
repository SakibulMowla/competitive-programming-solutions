#include "stdio.h"
#include "string"
#include "iostream"

#define SZ 100010

int arr[SZ];
char str[SZ];

int main()
{
    int i,n,s;
    while(scanf("%d",&n) == 1)
    {
        for(i=0;i<n;i++) scanf("%d",arr+i);
        s = 0;
        for(i=n-1;i>=0;i--)
        {
            if(s + arr[i] <= arr[i]) s += arr[i] , str[i] = '+';
            else s -= arr[i] , str[i] = '-';
        }
        str[n] = '\0';
        if(s < 0) for(i=0;i<n;i++) str[i] = str[i] == '+' ? '-' : '+';
        printf("%s\n",str);
    }

    return 0;
}
