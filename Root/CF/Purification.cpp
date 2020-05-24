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

typedef long long ll;
typedef pair<ll,ll> pii;

#define SZ 210
const ll inf = 1LL<<28;
const ll mod = 1LL;

char arr[SZ][SZ];
ll par[SZ];
bool col[SZ];
vector <ll> adjacency[SZ];

int main()
{
    ll n,i,j,k,l;

    while(cin >> n)
    {
        for(i=0;i<n;i++)
            adjacency[i].clear(), scanf(" %s",arr[i]);
        k = 0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
                if(arr[i][j] == '.')
                {
                    adjacency[i].push_back(j);
                    k++;
                    break;
                }
        }
        if(k == n)
        {
            for(i=0;i<n;i++)
                printf("%I64d %I64d\n",i+1,adjacency[i][0]+1);
            return 0;
        }

        k = 0;
        for(i=0;i<=n;i++)
            adjacency[i].clear();

        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
                if(arr[j][i] == '.')
                {
                    adjacency[i].push_back(j);
                    k++;
                    break;
                }
        }
        if(k == n)
        {
            for(i=0;i<n;i++)
                printf("%I64d %I64d\n",adjacency[i][0]+1,i+1);
            return 0;
        }
        printf("-1\n");
    }

    return 0;
}
