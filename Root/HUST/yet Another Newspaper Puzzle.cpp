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
const int inf = 1;
const ll mod = 1LL;

#define SZ  110

struct data {
    int n1, n2;
    char op;
    data () {}
    data(char a, char b, char c) {
        n1 = (int)a, n2 = (int)b, op = c;
    }
};

struct data2 {
    ll val;
    bool mrk;
    data2 () {}
    data2 (ll a, bool b) {
        val = a, mrk = b;
    }
};

vector <data> arr[30];
data2 root[30];

char str[1010];
char ch, ss[20], nn[20];

void prepare(char a, char b, char c, char op) {
    a -= 'A'; b -= 'A'; c -= 'A';

    arr[(int)a].pb(data(b, c, op));

    if(op == '+') arr[b].pb(data(a, c, '-'));
    else if(op == '-') arr[b].pb(data(a, c, '+'));
    else if(op == '*') arr[b].pb(data(a, c, '/'));
    else if(op == '/') arr[b].pb(data(a, c, '*'));

    if(op == '+') arr[c].pb(data(a, b, '-'));
    else if(op == '-') arr[c].pb(data(b, a, '-'));
    else if(op == '*') arr[c].pb(data(a, b, '/'));
    else if(op == '/') arr[c].pb(data(b, a, '/'));

    return;
}

void make(int a, ll b, ll c, char op) {
    if(op == '+') root[a].val = b + c;
    else if(op == '-') root[a].val = b - c;
    else if(op == '*') root[a].val = b * c;
    else if(op == '/') root[a].val = b / c;
    root[a].mrk = 1;
    return;
}

int main() {
    #if defined JESI
        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int t;
    scanf("%d", &t);

    for (int cs = 0; cs < t; cs++) {
        for (int i = 0; i < 26; i++) {
            arr[i].clear();
            root[i].mrk = 0;
        }

        int cnt = 26;
        for (int i = 0; i < 26; i++) {
            scanf(" %[^\n]", str);
            int len = sscanf(str, " %c %s %s", &ch, ss, nn);
            prepare(ch, ss[0], ss[2], ss[1]);
            if(len == 3) {
                root[ch-'A'].val = atol(nn);
                root[ch-'A'].mrk = 1;
                cnt--;
            }
        }

        while(cnt) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < arr[i].size(); j++) {
                    if ((root[i].mrk == 0)) {
                        if(root[ arr[i][j].n1 ].mrk == 1 && root[ arr[i][j].n2 ].mrk == 1) {
                            make(i, root[ arr[i][j].n1 ].val, root[ arr[i][j].n2 ].val, arr[i][j].op);
                            cnt--;
                        }
                        else if(arr[i][j].n1 == arr[i][j].n2) {
                            if(arr[i][j].op == '-') {
                                make(i, 1LL, 1LL, '-');
                                cnt--;
                            } else if(arr[i][j].op == '/') {
                                make(i, 1LL, 1LL, '/');
                                cnt--;
                            }
                        }
                    } else {
                        if(arr[i][j].n1 == arr[i][j].n2 && root[ arr[i][j].n1 ].mrk == 0) {
                            if(arr[i][j].op == '+') {
                                make(arr[i][j].n1, root[i].val, 2LL, '/');
                                cnt--;
                            } else if(arr[i][j].op == '*') {
                                make(arr[i][j].n1, (ll)sqrt((double)root[i].val), 0LL, '+');
                                cnt--;
                            }
                        }
                    }
                }
            }
        }

        for (int i = 0; i < 26; i++) {
            if(i) printf(" ");
            assert(root[i].mrk);
            printf("%lld", root[i].val);
        }
        puts("");
    }


    return 0;
}
