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
//ll BigMod(ll B,ll P,ll M){     ll R=1%M; while(P>0)      {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

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
const int inf = 2E9;
const ll mod = 1LL;

#define SZ 100010

struct data{
    int x, y;
};

void make_rotation(data p[], int x, int y, int a, int b) {
    x -= a;
    y -= b;
    if(x >= 0 && y >= 0) {
        p[0].x = x; p[0].y = y; swap(x, y);
        p[1].x = -x; p[1].y = y; swap(x, y);
        p[2].x = -x; p[2].y = -y; swap(x, y);
        p[3].x = x; p[3].y = -y;
    }
    else if(x < 0 && y >= 0) {
        x = abs(x), y = abs(y);
        p[0].x = -x; p[0].y = y; swap(x, y);
        p[1].x = -x; p[1].y = -y; swap(x, y);
        p[2].x = x; p[2].y = -y; swap(x, y);
        p[3].x = x; p[3].y = y;
    }
    else if(x < 0 && y < 0) {
        x = abs(x), y = abs(y);
        p[0].x = -x; p[0].y = -y; swap(x, y);
        p[1].x = x; p[1].y = -y; swap(x, y);
        p[2].x = x; p[2].y = y; swap(x, y);
        p[3].x = -x; p[3].y = y;
    }
    else {
        x = abs(x), y = abs(y);
        p[0].x = x; p[0].y = -y; swap(x, y);
        p[1].x = x; p[1].y = y; swap(x, y);
        p[2].x = -x; p[2].y = y; swap(x, y);
        p[3].x = -x; p[3].y = -y;
    }
    for(int i = 0; i < 4; i++)
        p[i].x += a, p[i].y += b;
    return;
}

int dist(data a, data b) {
    int d = (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
    return d;
}

bool yes(data a, data b, data c, data d) {
    int num[4] = {0, 1, 2, 3};
    data bindu[4];
    do {
        if(num[0] == 0) bindu[0] = a; else if(num[0] == 1) bindu[0] = b; else if(num[0] == 2) bindu[0] = c; else if(num[0] == 3) bindu[0] = d;
        if(num[1] == 0) bindu[1] = a; else if(num[1] == 1) bindu[1] = b; else if(num[1] == 2) bindu[1] = c; else if(num[1] == 3) bindu[1] = d;
        if(num[2] == 0) bindu[2] = a; else if(num[2] == 1) bindu[2] = b; else if(num[2] == 2) bindu[2] = c; else if(num[2] == 3) bindu[2] = d;
        if(num[3] == 0) bindu[3] = a; else if(num[3] == 1) bindu[3] = b; else if(num[3] == 2) bindu[3] = c; else if(num[3] == 3) bindu[3] = d;
        if(dist(bindu[0], bindu[1]) == dist(bindu[1], bindu[2]) &&
           dist(bindu[1], bindu[2]) == dist(bindu[2], bindu[3]) &&
           dist(bindu[2], bindu[3]) == dist(bindu[3], bindu[0]) &&
           dist(bindu[3], bindu[0]) == dist(bindu[0], bindu[1]) &&
           dist(bindu[0], bindu[2]) == dist(bindu[1], bindu[3]) &&
           dist(bindu[0], bindu[1]) && dist(bindu[1], bindu[3]))
            return true;

    } while(next_permutation(num, num+4));
    return false;
}

int main() {
    #if defined JESI
        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int n;
    data point[4][4];

    while(scanf("%d", &n) == 1) {
        int i; REP(i, n) {
            int j; REP(j, 4) {
                int a, b, x, y;
                RD(x, y);
                RD(a, b);
                make_rotation(point[j], x, y, a, b);
            }

//            for(int ii = 0; ii < 4; ii++) {
//                printf("point[%d] = ", ii+1);
//                for(int jj = 0; jj < 4; jj++) {
//                    printf("%d %d ", point[ii][jj].x, point[ii][jj].y);
//                }
//                printf("\n");
//            }

            int ans = inf;
            int mm, nn, oo, pp;

            REP(mm, 4) REP(nn, 4) REP(oo, 4) REP(pp, 4) {
                if(yes(point[0][mm], point[1][nn], point[2][oo], point[3][pp]))
                    ans = min(ans, mm+nn+oo+pp);
            }

            if(ans == inf) ans = -1;
            PR(ans);
        }
    }

    return 0;
}










