#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

void RD(int &x){scanf("%d",&x);}
void RD(ll &x){scanf("%I64d",&x);}
void RD(double &x){scanf("%lf",&x);}
void RD(int &x,int &y){scanf("%d%d",&x,&y);}
void RD(ll &x,ll &y){scanf("%I64d%I64d",&x,&y);}
void RD(double &x,double &y){scanf("%lf%lf",&x,&y);}
void RD(char *s){scanf("%s",s);}
void RD(char &s){scanf("%c",&s);}
void RD(string &s){cin>>s;}

void PR(int x) {printf("%d\n",x);}
void PR(int x,int y) {printf("%d %d\n",x,y);}
void PR(ll x) {printf("%I64d\n",x);}
void PR(char x) {printf("%c\n",x);}
void PR(char *x) {printf("%s\n",x);}
void PR(string x) {cout<<x<<endl;}

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
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);

#define X first
#define Y second

//ll extGcd(ll a, ll b, ll& x, ll& y){if (b == 0){x = 1;y = 0;return a;}else{int g = extGcd(b, a % b, y, x);y -= a / b * x;return g;}}
//ll modInv(ll a, ll m){ll x, y; extGcd(a, m, x, y); x %= m; while (x < 0){x += m;} return x;}
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
ll BigMod(ll B,ll P){     ll R=1; while(P>0)      {if(P%2==1){R=(R*B);}P/=2;B=(B*B);} return R;} /// (B^P)%M

//template <class T> inline T gcd(T a, T b){if(b == 0) return a;return gcd(b,a%b);}
//template <class T> inline T lcm(T a, T b){return (a/gcd(a,b)) * b;}

//ll x[] = {0,0,-1,1};//4-way
//ll y[] = {-1,1,0,0};//4-way
//ll x[] = {-1,-1,-1,0,0,1,1,1};//8-way
//ll y[] = {-1,0,1,-1,1,-1,0,1};//8-way
//inline long FastMax(long x, long y) { return (((y-x)>>(32-1))&(x^y))^y; }
//inline long FastMin(long x, long y) { return (((y-x)>>(32-1))&(x^y))^x; }


typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const ll inf = 1;
const ll mod = 1LL;

#define SZ 20

string ans[SZ];
int mark[SZ];
vector <ll> lft;
map <ll, int> rht;

ll calc (ll half, int n, int base) {
    ll need = 0LL;
    for (int i = 0; i < n; i++) {
        ll now = half % base;
        if(now > mark[n-i-1]) return -1;
        need += (mark[n-i-1] - now) * BigMod(base, i);
        now /= base;
    }
    return need;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            cin >> ans[i] >> mark[i];
        }

        int m1 = m / 2, m2 = m - m1;
        int base = max(m1, m2);

        clr(lft);
        for (int mask = 0; mask < (1<<m1); mask++) {
            ll tmp = 0LL;
            for (int i = 0; i < n; i++) {
                int cnt = 0;
                for (int j = 0; j < m1; j++) {
                    if(ans[i][j] == (bool)(mask&(1<<j)))
                        cnt++;
                }
                tmp = tmp * base + (ll)cnt;
            }
            lft.pb(tmp);
        }

        clr(rht);
        for (int mask = 0; mask < (1<<m2); mask++) {
            ll tmp = 0LL;
            for (int i = 0; i < n; i++) {
                int cnt = 0;
                for (int j = 0; j < m2; j++) {
                    if(ans[i][m1+j] == (bool)(mask&(1<<j)))
                        cnt++;
                }
                tmp = tmp * base + (ll)cnt;
            }
            rht[tmp]++;
        }

        printf("%d %d\n", sz(lft), sz(rht));

        ll ans = 0LL;
        for (int i = 0; i < sz(lft); i++) {
            ll need = calc(lft[i], n, base);
            if (need == -1) continue;
            ans += rht.count(need);
        }

        printf("%I64d solutions\n", ans);
    }

    return 0;
}









