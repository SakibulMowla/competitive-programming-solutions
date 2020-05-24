// Accepted

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
#include <time.h>
#include <iostream>
#include <algorithm>

//#include <bits/stdc++.h>

using namespace  std;

#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())

typedef long long ll;
typedef pair<ll,ll> pii;


#define SZ 1010
const ll inf = 1LL<<28;

ll mod[1000];

class SparseFactorialDiv2
{
public:
    long long getCount(long long lo, long long hi, long long divisor)
    {
        ll i, j, k, range, up, down, val;

        mem(mod, 0);

        range = hi - lo;

        for(i=0;;i++)
        {
            if(hi-(ll)(i*i) <= 0) break;

            up = hi - (ll)(i*i);
            down = up - range;

            val = up / divisor;

            if(down > 1) val -= (down-1) / divisor;

            k = up%divisor;

            if(mod[k]) continue;

            mod[k] = val;
        }

        j = 0;

        for(i=0;i<divisor;i++)
            j += mod[i];

        return j;
    }
};
