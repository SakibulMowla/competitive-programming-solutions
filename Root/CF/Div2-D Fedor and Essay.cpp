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


typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const ll inf = 1;
const ll mod = 1LL;

#define SZ 3*100010

vector <string> cntr;
string ss, tt;
map <string, int> mp;
struct data{
    int node;
    pii xx;
};
data cost[SZ];
vector <int> adj[SZ];

bool comp(data p, data q) {
    if(p.xx.second == q.xx.second)
        return p.xx.first < q.xx.first;
    return p.xx.second < q.xx.second;
}

void convert(string &s) {
    int i, k = sz(s);
    for(i = 0; i < k; i++)
        s[i] = tolower(s[i]);
    return;
}

bool col[SZ];
pii ans[SZ];
int RealToVua[SZ];

void dfs(int u, int par) {
    col[u] = 1;

    int i, j, k = sz(adj[u]);

    for(i = 0; i < k; i++) {
        j = adj[u][i];
        if(j == par || col[j] == 1) continue;
        cost[ RealToVua[j] ].xx = cost[ RealToVua[u] ].xx;
        dfs(j, u);
    }

    return;
}

void doit(string &ss, int &cnt) {
    int j, k, l;

    if(mp.find(ss) == mp.end()) {
        k = sz(ss);
        l = 0;
        for(j = 0; j < k; j++) {
            if(ss[j] == 'r')
                l++;
        }
        mp[ss] = ++cnt;
        cost[cnt].node = cnt;
        cost[cnt].xx = MP(k, l); /// size, R_count
    }

    return;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int n, m, i, j, k, l, cnt;
    ll ans1, ans2;
    pii tmp;

    while(cin >> n) {
        clr(cntr);
        clr(mp);
        cnt = 0;

        for(i = 0; i < n; i++) {
            cin >> ss;

            convert(ss);
            cntr.pb(ss);

            doit(ss, cnt);
        }


        cin >> m;

        for(i = 0; i <= n+m*2; i++) {
            adj[i].clear();
        }

        for(i = 0; i < m; i++) {
            cin >> ss >> tt;

            convert(ss);
            convert(tt);

            doit(ss, cnt);
            doit(tt, cnt);

            if(mp[ss] != mp[tt])
                adj[ mp[tt] ].pb( mp[ss] );
        }

        sort(cost+1, cost+cnt+1, comp);

        for(i = 1; i<= cnt; i++) {
            RealToVua[ cost[i].node ] = i;
        }

        mem(col, 0);
        ans1 = ans2 = 0LL;

        for(i = 1; i <= cnt; i++) {
            k = cost[i].node;
            if(col[k] == 0) {
                dfs(k, -1);
            }
        }

        for(i = 0; i < n; i++) {
            ans1 += (ll)cost[ RealToVua[ mp[ cntr[i] ] ] ].xx.first;
            ans2 += (ll)cost[ RealToVua[ mp[ cntr[i] ] ] ].xx.second;
        }

        printf("%I64d %I64d\n", ans2, ans1);
    }

    return 0;
}










