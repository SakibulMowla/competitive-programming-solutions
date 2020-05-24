#include <bits/stdc++.h>

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

//ll extGcd(ll a, ll b, ll& x, ll& y){if (b == 0){x = 1;y = 0;return a;}else{int g = extGcd(b, a % b, y, x);y -= a / b * x;return g;}}
//ll modInv(ll a, ll m){ll x, y; extGcd(a, m, x, y); x %= m; while (x < 0){x += m;} return x;}
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//ll BigMod(ll B,ll P,ll M){     ll R=1%M; while(P>0)      {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

//template <class T> T gcd(T a, T b){if(b == 0) return a;return gcd(b,a%b);}
//template <class T> T lcm(T a, T b){return (a/gcd(a,b)) * b;}

//ll x[] = {0,0,-1,1};//4-way
//ll y[] = {-1,1,0,0};//4-way
//ll x[] = {-1,-1,-1,0,0,1,1,1};//8-way
//ll y[] = {-1,0,1,-1,1,-1,0,1};//8-way

typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const int inf = 1E9;
const ll mod = 1LL;

#define SZ  300

struct data {
    double money;
    int adv;
};

struct data2 {
    int beds, adv;
    double rent;
};

struct data3 {
    int adv, cnt, fri, apt;
};

data friends[SZ];
data2 apart[SZ];
data3 ans;

int main() {
    #if defined JESI
        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    double zmoney;
    int adv[3];

    while(cin >> zmoney >> adv[1] >> adv[2]) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            cin >> friends[i].money >> friends[i].adv;
        }

        int m;
        cin >> m;;
        for (int i = 0; i < m; i++) {
            cin >> apart[i].beds >> apart[i].rent >> apart[i].adv;
        }

        ans.adv = -1e9;
        for (int i = 0; i < m; i++) {
            if(apart[i].rent <= zmoney && apart[i].adv + adv[ apart[i].beds ] > ans.adv) {
                ans.adv = apart[i].adv + adv[ apart[i].beds ];
                ans.cnt = 1;
                ans.apt = i + 1;
            }
            if(apart[i].beds == 2)
            for (int j = 0; j < n; j++) {
                if(zmoney >= apart[i].rent/2.0 && friends[j].money >= apart[i].rent/2.0 && apart[i].adv + friends[j].adv > ans.adv) {
                    ans.adv = apart[i].adv + friends[j].adv;
                    ans.cnt = 2;
                    ans.fri = j + 1;
                    ans.apt = i + 1;
                }
            }
        }

        if(ans.adv == -1e9) printf("Forget about apartments. Live in the dormitory.\n");
        else if(ans.cnt == 1) printf("You should rent the apartment #%d alone.\n", ans.apt);
        else printf("You should rent the apartment #%d with the friend #%d.\n", ans.apt, ans.fri);
    }

    return 0;
}






