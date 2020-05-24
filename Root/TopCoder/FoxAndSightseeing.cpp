// Acepted

#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <iostream>
#include <algorithm>

using namespace  std;

#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())

typedef long long ll;
typedef pair<ll,ll> pii;

#define SZ 1010
const ll inf = 1LL<<28;
const ll mod = 1LL;

class FoxAndSightseeing
{
public:
    int getMin(vector <int> position)
    {
        int i, j , k , dist, pre, ans;

        dist = 0;

        k = sz(position);
        ans = 1<<28;

        for(i=1; i<k-1; i++)
        {
            pre = 0;
            dist = 0;
            for(j=1; j<k; j++)
            {
                if(j == i) continue;
                dist += abs(position[j]-position[pre]);
                pre = j;
            }

            ans = min(ans, dist);
        }

        return ans;
    }
};

