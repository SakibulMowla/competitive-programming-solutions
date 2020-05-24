#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

inline void inp( int &n ){
    n=0;
    int ch=getchar_unlocked();int sign=1;
    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
    while(  ch >= '0' && ch <= '9' )
            n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
    n=n*sign;
}


#define SZ  100010

struct data {
    ll x, y;
    data() {}
    data(ll _x, ll _y) {x = _x; y = _y;}
    bool operator < (const data &X) const {
        return x > X.x;
    }
};

priority_queue <data> pq;
int arr[SZ];

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int t;
//    scanf("%d", &t);
    inp(t);

    for (int cs = 0; cs < t; cs++) {
        int n, m;
//        scanf("%d %d", &n, &m);
        inp(n); inp(m);

        for (int i = 0; i < n; i++) {
//            scanf("%lld", &arr[i]);
            inp(arr[i]);
        }

        sort(arr, arr+n);
        reverse(arr, arr+n);

        while (!pq.empty()) pq.pop();

        for (int i = 0; i < m; i++) {
            int val;
//            scanf("%d", &val);
            inp(val);
            pq.push(data(0LL, (ll)val));
        }

        ll ans = 0LL;

        for (int i = 0; i < n; i++) {
            data d = pq.top(); pq.pop();
            ans = max(ans, d.x + (ll)arr[i]);
            pq.push(data(d.x + d.y, d.y));
        }

        printf("Case %d: %lld\n", cs+1, ans);
    }

    return 0;
}


/*
1
4 2
3 1 2 1
2 3
*/









