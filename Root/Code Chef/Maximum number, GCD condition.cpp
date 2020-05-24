#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

void RD(int &x){scanf("%d",&x);}
void RD(int &x,int &y){scanf("%d%d",&x,&y);}

void PR(int x) {printf("%d\n",x);}
void PR(int x,int y) {printf("%d %d\n",x,y);}

inline void inp( int &n ){
    n=0;
    int ch=getchar_unlocked();int sign=1;
    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
    while(  ch >= '0' && ch <= '9' )
            n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
    n=n*sign;
}

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
const int inf = 1;
const ll mod = 1LL;

#define SZ  100010
#define SZ1 10010

struct data{
    int val, indx;
    data(){}
    data(int a, int b){
        val = a, indx = b;
    }
};

bool arr[SZ];
vector <int> prime;
vector <data> adj[SZ1];
int mp[SZ];

void init(){
    int i;
    REP1(i, 0, 10000) clr(adj[i]);
}

void sieve(){
    int i, j, k;

    k = sqrt(SZ);
    for(i=3;i<=k;i+=2)
        if(!arr[i])
            for(j=i*i;j<SZ;j+=i+i)
                arr[j] = 1;
    k = 0;
    prime.pb(2);
    mp[2] = k++;
    for(i=3;i<SZ;i+=2)
        if(!arr[i])
            prime.pb(i), mp[i] = k++;
}

void factorize(int n, int indx){
    int i, j, k, m;
    m = n;

    k = sz(prime);
    for(i=0; i<k && (ll)((ll)prime[i]*(ll)prime[i])<=(ll)n; i++){
        if(n%prime[i] == 0){
            while(n%prime[i] == 0) n /= prime[i];
            adj[ mp[prime[i]] ].pb(data(m, indx));
        }
    }

    if(n != 1){
        adj[ mp[n] ].pb(data(m, indx));
    }
}

struct data1{
    int beg, end, mx, cnt;
};

vector <data1> tree[SZ1];

void build(int now, int node, int b, int e){
    if(b == e){
        tree[now][node].beg = adj[now][b].indx;
        tree[now][node].end = adj[now][b].indx;
        tree[now][node].mx = adj[now][b].val;
        tree[now][node].cnt = 1;
        return;
    }

    int mid = (b + e) / 2;

    build(now, 2*node, b, mid);
    build(now, (2*node)+1, mid+1, e);

    tree[now][node].beg = tree[now][2*node].beg;
    tree[now][node].end = tree[now][(2*node)+1].end;

    if(tree[now][2*node].mx > tree[now][(2*node)+1].mx){
        tree[now][node].mx = tree[now][2*node].mx;
        tree[now][node].cnt = tree[now][2*node].cnt;
    }
    else if(tree[now][2*node].mx < tree[now][(2*node)+1].mx){
        tree[now][node].mx = tree[now][(2*node)+1].mx;
        tree[now][node].cnt = tree[now][(2*node)+1].cnt;
    }
    else if(tree[now][2*node].mx == tree[now][(2*node)+1].mx){
        tree[now][node].mx = tree[now][2*node].mx;
        tree[now][node].cnt = tree[now][2*node].cnt + tree[now][(2*node)+1].cnt;
    }
}

pii query(int now, int node, int b, int e, int f, int t){
    if(tree[now][node].beg >= f && tree[now][node].end <= t)
        return MP(tree[now][node].mx, tree[now][node].cnt);
    else if(tree[now][node].beg > t || tree[now][node].end < f)
        return MP(-1, -1);

    if(b == e) return MP(-1, -1);

    int mid = (b + e) / 2;
    pii ret1 = MP(-1, -1), ret2 = MP(-1, -1), ret;

    if(f <= adj[now][mid].indx) ret1 = query(now, 2*node, b, mid, f, t);
    if(mid+1<=e) if(t >= adj[now][mid+1].indx) ret2 = query(now, (2*node)+1, mid+1, e, f, t);

    if(ret1.X > ret2.X){
        ret.X = ret1.X;
        ret.Y = ret1.Y;
    }
    else if(ret1.X < ret2.X){
        ret.X = ret2.X;
        ret.Y = ret2.Y;
    }
    else if(ret1.X == ret2.X){
        ret.X = ret1.X;
        if(ret.X != -1)
            ret.Y = ret1.Y + ret2.Y;
        else
            ret.Y = -1;
    }

    return ret;
}

pii solve(int n, int x, int y){
    int i, j, k;
    pii ans = MP(-1, -1), tmp;

    k = sz(prime);
    for(i=0; i<k && (ll)((ll)prime[i]*(ll)prime[i])<=(ll)n; i++){
        if(n%prime[i] == 0){
            while(n%prime[i] == 0) n /= prime[i];
            if(sz(adj[ mp[prime[i]] ])){
                tmp = query(mp[ prime[i] ], 1, 0, sz(adj[ mp[ prime[i] ] ])-1, x, y);
                if(tmp.X > ans.X)
                    ans = tmp;
            }
        }
    }

    if(n != 1){
        if(sz(adj[ mp[n] ])){
            tmp = query(mp[n], 1, 0, sz(adj[ mp[n] ])-1, x, y);
            if(tmp.X > ans.X)
                ans = tmp;
        }
    }

    return ans;
}

int main() {
    sieve();

    int n, m, i, j, k, x, y;
    pii ans;

    while(scanf("%d %d",&n,&m) == 2){
        init();
        REP1(i, 1, n) {
//            RD(j);
            inp(j);
            if(j == 1) continue;
            factorize(j, i);
        }

        REP1(i, 0, 10000){
            if(sz(adj[i])){
                tree[i].reserve(sz(adj[i])*4);
                build(i, 1, 0, sz(adj[i])-1);
            }
        }

        while(m--){
//            RD(k);
//            RD(x, y);
            inp(k);
            inp(x);
            inp(y);
            if(k == 1){
                printf("-1 -1\n");
                continue;
            }
            ans = solve(k, x, y);
            printf("%d %d\n",ans.X,ans.Y);
        }
    }


    return 0;
}













