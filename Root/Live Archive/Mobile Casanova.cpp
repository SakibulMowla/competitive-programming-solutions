#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <iostream>
#include <algorithm>

//#include <bits/stdc++.h>

using namespace  std;

#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))

typedef long long ll;
typedef pair<ll,ll> pii;


#define SZ 100010
const ll inf = 1LL<<28;
const ll mod = 1LL;


int arr[SZ];
char s[SZ][15];

void print(int a,int b)
{
    printf("%s-",s[a]);
    int i, j, k;
    k = strlen(s[0]);
    for(i=0;i<k;i++)
    {
        if(s[a][i] != s[b][i])
        {
            for(j = i;j<k;j++)
                printf("%c",s[b][j]);
            return;
        }
    }
}

//%I64d
int main()
{

    int i, j, k, n, m, test = 0;

    while(scanf("%d",&n) == 1 && n)
    {
        for(i=0;i<n;i++)
        {
            scanf(" %s",s[i]);
            arr[i] = atoi(s[i]);
        }

        printf("Case %d:\n",++test);

        for(i=0;i<n;i++)
        {
            j = i;
            while(j+1<n && arr[j+1] == arr[j] + 1)
                j++;
            if(j == i)
                printf("%s\n",s[i]);
            else
            {
                print(i, j);
                printf("\n");
                i = j;
            }
        }
        printf("\n");
    }

    return 0;
}
