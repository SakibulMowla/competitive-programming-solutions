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
#include <assert.h>
#include <time.h>

using namespace  std;

typedef long long ll;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back

#define X first
#define Y second


typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const int inf = 1E9;
const ll mod = 1LL;

#define SZ 50000+10

ll a[SZ];
ll sum[SZ];
//map <ll, ll> mp;
ll cnt[1000000+10];
int col[1000000+10];
int now;

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    //scanf("%I64d", &t);

    for (int cs = 0; cs < t; cs++) {
        ll d;
        int n;
        cin >> d >> n;
        //scanf("%I64d %d", &d, &n);

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            //scanf("%I64d", &a[i]);
        }

//        clr(mp);
//        mp[0] = 1LL;

        now++;
        cnt[0] = 1LL;
        col[0] = now;

        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            sum[i] = (a[i] + sum[i-1]) % d;
//            if (mp.find(sum[i]) == mp.end())
//                mp[sum[i]] = 0;
            if (col[sum[i]] != now) {
                col[sum[i]] = now;
                cnt[ sum[i] ] = 0;
            }
//            mp[sum[i]]++;
            cnt[ sum[i] ]++;
            ans += cnt[ sum[i] ] - 1LL;
        }


//        for (map <ll, ll> ::iterator it = mp.begin(); it != mp.end(); it++) {
//            ans += (it->Y * (it->Y - 1LL)) / 2LL;
//        }

        cout << ans << '\n';
//        printf("%I64d\n", ans);
    }

    return 0;
}







