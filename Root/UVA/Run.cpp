#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;

int ok(int n)
{
    int i;
    char arr[10];
    memset(arr,0,sizeof(arr));
    while(n)
    {
        i = n%10;
        n /= 10;
        arr[i]++;
        if(arr[i] > 1 || i == 0)
            return 0;
    }
    return 1;
}

int runa(int n)
{
    int round,i,len;
    bool visit[10];
    char arr[10];
    memset(visit,false,sizeof(visit));
    len = sprintf(arr,"%d",n);
    round = (arr[0] - '0') % len;
    for(i=0;i<len;i++)
    {
        visit[round] = true;
        round = (round + arr[round] - '0') % len;
    }
    if(count(visit,visit+len,true) == len)
        return 1;
    return 0;
}

int pregenerate[9999999+5];

int main()
{
    int i,test=0;
    for(i=9999999;i>=1;i--)
    {
        if(ok(i) && runa(i))
            pregenerate[i] = i;
        else
            pregenerate[i] = pregenerate[i+1];
    }
//    freopen("1.txt","r",stdin);
    while(scanf("%d",&i) == 1 && i)
        printf("Case %d: %d\n",++test,pregenerate[i]);

    return 0;
}
