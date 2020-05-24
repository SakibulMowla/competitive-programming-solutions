//Acepted
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

using namespace  std;

#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())

#define SZ 1010
const ll inf = 1LL<<28;
const ll mod = 1LL;

string s;
int N;

bool chk(char a, char b)
{
    if(a == 'R' && b == 'G') return true;
    if(a == 'G' && b == 'B') return true;
    if(a == 'B' && b == 'R') return true;
    return false;
}

int dp[20];

int solve(int indx)
{
    if(indx == N-1) return 0;

    int &ret = dp[indx];

    if(ret != -1)
        return ret;

    int i;
    ret = 1<<28;

    for(i=indx+1;i<N;i++)
    {
        if(chk(s[indx], s[i]))
            ret = min(ret, solve(i) + (indx-i)*(indx-i));
    }

    return ret;
}

class ColorfulRoad
{
public:
    int getMin(string road)
    {
        s = road;
        N = sz(road);

        mem(dp, -1);

        int k = solve(0);
        if(k >= 1<<28) return -1;
        return k;
    }
};

