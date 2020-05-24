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

#define SZ 1010
const ll inf = 1LL<<28;
const ll mod = 1LL;

//%I64d
int main()
{
    ll n,m,i,j,k;
    map<ll,ll>M;

    while(cin >> n >> m)
    {
        M.clear();
        for(i=0;i<m;i++)
        {
            cin >> j>>k;
            M[j]=1;
            M[k]=1;
        }
        for(i=1;i<=n;i++)
            if(M.find(i) == M.end())
            {
                k = i;
                break;
            }
        cout << n-1 << "\n";
        for(i=1;i<=n;i++)
        {
            if(i == k)
                continue;
            cout << k <<" "<< i << "\n";
        }
    }

    return 0;
}
