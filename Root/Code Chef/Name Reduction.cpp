#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "stdbool.h"
#define SZ 30

int cnt1[SZ] , cnt2[SZ];
char arr[201000];

bool check()
{
    int i;
    for(i=0; i<=25; i++)
    {
        if(cnt1[i] < cnt2[i])
            return false;
    }
    return true;
}

int main()
{
    int i,k,t,l;
    scanf("%d",&t);
    while(t--)
    {
        for(i=0; i<=26; i++) cnt1[i] = cnt2[i] = 0;
        scanf(" %s",&arr);
        l = strlen(arr);
        for(i=0; i<l; i++) cnt1[ arr[i]-'a' ]++;
        scanf(" %s",&arr);
        l = strlen(arr);
        for(i=0; i<l; i++) cnt1[ arr[i]-'a' ]++;
        scanf(" %d",&k);
        while(k--)
        {
            scanf(" %s",&arr);
            l = strlen(arr);
            for(i=0; i<l; i++) cnt2[ arr[i]-'a' ]++;
        }
        if(check()) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}
