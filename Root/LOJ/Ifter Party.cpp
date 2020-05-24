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
#include <deque>

//#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

void RD(int &x)
{
    scanf("%d",&x);
}
void PR(int x)
{
    printf(" %d",x);
}

#define read(a) freopen("a", "r", stdin)
#define write(a) freopen("a", "w", stdout)

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define snuke(c, itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define pb push_back
#define ssort(a) stable_sort(a.begin(), a.end())

#define X first
#define Y second

typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const ll inf = 1LL<<28;
const ll mod = 1LL;

set <int> ans;
//vector <int> ans;

void solve(ll p, ll l){
    ll i, j, k;
    for(i=1; i*i<p; i++){
        if(p%i == 0){
            if(i > l)
                ans.insert(i);
            if(p/i > l)
                ans.insert(p/i);
        }
    }
    if(i*i == p && i > l)
        ans.insert(i);
}

int main(){
    int test=0, t, i, l, p;

    RD(t);

    while(t--){
        RD(p);
        RD(l);
        ans.clear();

        solve(p-l, l);
        l = sz(ans);
//        ssort(ans);

        printf("Case %d:",++test);
        if(!l) printf(" impossible");
        else snuke(ans, it) PR(*it);
//        else REP(i, l) PR(ans[i]);
        printf("\n");
    }


    return 0;
}

















