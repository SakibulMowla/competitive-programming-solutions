#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <iostream>
#include <algorithm>

using namespace  std;

#define inf 1<<28
#define SD(n) scanf("%d",&n)
#define SS(n) scanf("%s",n)
#define FOR(i,n) for(i=0;i<n;i++)
#define FORI(i,a,n) for(i=a;i<=n;i++)
#define SZ 1010

int main()
{
    int i,j,k,pos;
    char s[100] , t[100];
    while(scanf("%s %s",s,t) == 2)
    {
        pos = 0;
        for(i=0;t[i];i++)
        {
            if(t[i] == s[pos]) pos++;
        }
        pos++;
        printf("%d\n",pos);
    }

    return 0;
}
