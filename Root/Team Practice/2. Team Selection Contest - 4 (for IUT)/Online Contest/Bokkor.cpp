#include <cstdio>
#include <vector>
#include <algorithm>

#define pb push_back
#define x first
#define y second
#define mp make_pair
#define sz(a) ((int)(a).size())
using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef vector<double> VD;
typedef vector<VD> VVD;
typedef vector<VI> VVI;
typedef pair<int, int> PI;
typedef vector<PI> VPI;

#define SZ 1010000


ll seg[SZ*4];
int upd[SZ*4][4];
bool reset[SZ*4];
bool isupd[SZ*4];
ll pre[SZ][4];
const ll mod = 1000000LL;

void build(int cur,int st,int ed)
{
    seg[cur] = 0;
    isupd[cur] = 0;
    reset[cur] = 0;
    if(st==ed)
    {
        seg[cur] = 0;
        isupd[cur] = 0;
        reset[cur] = 0;
        return;
    }

    int mid = (st+ed)>>1;
    build(cur*2 , st , mid);
    build(cur*2+1 , mid+1 , ed);
    return;
}


void res(int cur,int st,int ed)
{
    reset[cur] = false;
    if(st!=ed) reset[cur*2] = reset[cur*2+1]= 1;
    seg[cur] = 0;
    for(int i = 0 ; i<4 ; i++) upd[cur][i] = 0;
    isupd[curr] = 0;
    return;
}

void relax_upd(int cur,int st,int ed)
{
    for(int i =  0 ; i<4; i++)
    {
        seg[cur] += ((pre[ed][i]-pre[st-1][i])*upd[cur][i])%mod;
        seg[cur] %= mod;
        seg[cur] = (seg[cur]+mod)%mod;
        if(st!=ed)
        {
            upd[cur*2][i] = upd[cur][i];
            upd[cur*2+1][i] = upd[cur][i];
        }
        upd[cur][i] = 0;
    }

    if(st!=ed) isupd[cur*2] = isupd[cur*2+1] = isupd[cur];
    isupd[cur] = 0;
    return;

}

ll inp[4];

void update(int cur,int st,int ed,int l,int r,int isreset)
{
    if(reset[cur]) res(cur,st,ed);
    if(isupd[cur]) relax_upd(cur ,st,ed);

    if(st>r || ed<l) return;

    if(st>=l && ed<=r)
    {
        if(isreset)
        {
            reset[cur] = 1;
            res(cur,st,ed);
            return;
        }
        for(int i = 0 ; i<4 ; i++) upd[cur][i] = inp[i];
        isupd[cur] = 1;
        relax_upd(cur,st,ed);
        return;
    }

    int mid = (st+ed)>>1;

    update(cur*2 , st,mid , l,r , isreset);
    update(cur*2+1 , mid+1 , ed,l,r,isreset);

    if(reset[cur*2]) res(cur*2 , st,mid);
    if(reset[cur*2+1]) res(cur*2+1 ,mid+1 , ed);

    if(isupd[cur*2]) relax_upd(cur*2 , st,mid);
    if(isupd[cur*2+1]) relax_upd(cur*2+1 , mid+1 ,ed);

    seg[cur] =seg[cur*2]+seg[cur*2+1];
    seg[cur] %=mod;
    seg[cur] = (seg[cur]+mod)%mod;

    return;
}

ll query(int cur,int st,int ed ,int l,int r)
{
    if(reset[cur]) res(int cur,int st,int ed);
    if(isupd[cur]) relax_upd(cur ,st,ed);

    if(st>r || ed<l) return 0;
    if(st>=l && ed<=r) return seg[cur];

    int mid = (st+ed)>>1;

    ll ret =  query(cur*2 , st,mid , l,r)+query(cur*2+1 , mid+1 ,ed,l,r);
    return ret%mod;
}

int main()
{
    scanf("%d", &t);
    for (int cs = 1; cs <= t; cs++) {
        scanf("%d", &q);
        n = 1000500;
        build(1, 0, n - 1);

        for(int i = 0; i < q; i++) {
            scanf("%c", &cmd);
            if(cmd == 'p') {
                scanf("%d %d %lld %lld %lld %lld", &x, &y, &a, &b, &c, &d)
            }

        }
        printf("Case #%d: %d\n", cs, ans / 2);
    }
    return 0;
}


