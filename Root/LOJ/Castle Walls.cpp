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

//inline void inp( int &n ){
//    n=0;
//    int ch=getchar_unlocked();int sign=1;
//    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
//    while(  ch >= '0' && ch <= '9' )
//            n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
//    n=n*sign;
//}


#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define REP1(i,a,b) for((i)=a;(i)<=(int)(b);(i)++)
#define REP2(i,a,b) for((i)=a;(i)>=(int)(b);(i)--)
#define snuke(c, itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define pb push_back
#define ssort(a) stable_sort(a.begin(), a.end())

#define X first
#define Y second

typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const ll inf = 1LL<<28;
const ll mod = 1LL;

#define SZ 200010

struct data {
    int from, to;
};

data arr[SZ];

bool comp (data p, data q) {
    if(p.to == q.to) return p.from > q.from;
    return p.to < q.to;
}

int tree[SZ], N;

void Update(int indx) {
    while(indx <= N) {
        tree[indx]++;
        indx += (indx & -indx);
    }
    return;
}

int Query(int indx) {
    int sum = 0;
    while(indx > 0) {
        sum += tree[indx];
        indx -= (indx & -indx);
    }
    return sum;
}

int main() {
    #if defined JESI
//        freopen("1.txt","r",stdin);
//        freopen("2.txt","w",stdout);
    #endif // defined

    int test=0, t, i, n, m;
    ll ans;

    scanf("%d",&t);

    while(t--){
        scanf("%d %d",&n,&m);
        N = n + m;

        for(i = 0; i < N; i++) {
            scanf("%d %d", &arr[i].from, &arr[i].to);
//            inp(arr[i].from); inp(arr[i].to);
        }

        memset(tree, 0, sizeof(int) * (N+2));
        stable_sort(arr, arr+N, comp);
        ans = 0LL;

        for(i = 0; i < N; i++) {
            ans += (ll)Query(N) - (ll)Query(arr[i].from);
            Update(arr[i].from);
        }

        printf("Case %d: %lld\n", ++test, ans);
    }

    return 0;
}












