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
    int i,flag,len;
    string s;
    while(cin >> s)
    {
        len = s.size();
        flag = 0;
        for(i=0;i<len-1;i++)
        {
            if(s[i] == '0'&& flag == 0)
            {
                flag = 1;
                continue;
            }
            cout<<s[i];
        }
        if(flag == 1) cout<<s[i];
        printf("\n");
    }

    return 0;
}
