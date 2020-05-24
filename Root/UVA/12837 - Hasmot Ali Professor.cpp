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

#define SZ  1010

struct trie
{
    int words;
    map <char , int> M;
};

trie T[1000010];
int cnt;
char arr[SZ];
bool ok[SZ][SZ];

void addWord(int strt, int len)
{
    int pos, node = 0;
    for(pos = 0; pos < len; pos++)
    {
        ok[strt][strt+pos] = 0;
        if( T[node].M.find(arr[strt+pos]) == T[node].M.end() )
        {
            T[cnt+1].words = 0;
            T[cnt+1].M.clear();
            T[node].M[arr[strt+pos]] = ++cnt;
            ok[strt][strt+pos] = 1;
        }
        node = T[node].M[arr[strt+pos]];
    }
    return;
}

void addWord2(int strt1, int end1, int strt2, int end2)
{
    int pos, node = 0;
    for(pos = strt1; pos <= end1; pos++)
    {
        if( T[node].M.find(arr[pos]) == T[node].M.end() )
        {
            T[cnt+1].words = 0;
            T[cnt+1].M.clear();
            T[node].M[arr[pos]] = ++cnt;
        }
        node = T[node].M[arr[pos]];
    }

    if( T[node].M.find('#') == T[node].M.end() )
    {
        T[cnt+1].words = 0;
        T[cnt+1].M.clear();
        T[node].M['#'] = ++cnt;
    }
    node = T[node].M['#'];

    for(pos = strt2; pos <= end2; pos++)
    {
        if( T[node].M.find(arr[pos]) == T[node].M.end() )
        {
            T[cnt+1].words = 0;
            T[cnt+1].M.clear();
            T[node].M[arr[pos]] = ++cnt;
        }
        node = T[node].M[arr[pos]];
    }
    T[node].words++;
    return;
}

char X[11], Y[11];

int Find()
{
;
}

int main() {
    #if defined JESI
        freopen("2.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    double tym = clock();

    int test;

    scanf("%d",&test);

    while(test--)
    {
        cnt = 0;
        T[0].M.clear();
        T[0].words = 0;

        scanf("%s", arr);
        int n = strlen(arr);

        for (int i = 0; i < n; i++)
        {
            addWord(i, n-i);
        }

        printf("cnt before %d\n", cnt);

        cnt = 0;
        T[0].M.clear();
        T[0].words = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++) if(ok[i][j])
            {
                int end1 = min(i+10-1, n-1);
                int strt2 = max(j-10+1, i);
                for (int p = i; p <= end1; p++)
                {
                    for (int q = strt2; q <= j; q++)
                    {
                        addWord2(i, p, q, j);
                    }
                }
            }
        }

        printf("cnt after %d\n", cnt);
//        scanf("%d", &n);
//        while(n--) scanf("%s %s", arr, arr);

        printf("%d\n", cnt);
    }

    printf("%lf\n", (clock()-tym)/CLOCKS_PER_SEC);

    return 0;
}












