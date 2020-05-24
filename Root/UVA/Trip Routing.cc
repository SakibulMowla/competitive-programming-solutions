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

//#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;


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
const int inf = 1e9;
const ll mod = 1LL;

#define SZ 210

map <string , int> msi;
map <int , string> mis;

int dist[SZ][SZ];
int mid[SZ][SZ];
char route[SZ][SZ][25];

void floyd(int n){
    int i, j, k;

    REP1(k, 1, n) REP1(i, 1, n) REP1(j, 1, n){
        if(dist[i][j] > dist[i][k] + dist[k][j]){
            dist[i][j] = dist[i][k] + dist[k][j];
            mid[i][j] = k;
        }
    }
}

void path(int from, int to){
    if(mid[from][to] == -1){
        printf("%-21s%-21s%-11s%5d\n",mis[from].c_str(), mis[to].c_str(), route[from][to], dist[from][to]);
        return;
    }

    path(from, mid[from][to]);
    path(mid[from][to], to);
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    char *s, s1[25], s2[25], s3[25], arr[100];
    int i, j, k;

    REP1(i, 1, 205){
        REP1(j, 1, 205) {
            dist[i][j] = inf;
            mid[i][j] = -1;
        }
        dist[i][i] = 0;
    }

    k = 0;

    while(gets(arr)){
        if(arr[0] == '\0') break;

        s = strtok(arr, ",");
        i = 1;
        while(s != NULL){
            if(i == 1) strcpy(s1, s);
            else if(i == 2) strcpy(s2, s);
            else if(i == 3) strcpy(s3, s);
            else j = atoi(s);
            s = strtok(NULL, ",");
            i++;
        }

        if(msi.find(s1) == msi.end()) msi[s1] = ++k, mis[k] = s1;
        if(msi.find(s2) == msi.end()) msi[s2] = ++k, mis[k] = s2;

        if(j < dist[ msi[s1] ][ msi[s2] ]){
            dist[ msi[s1] ][ msi[s2] ] = j;
            dist[ msi[s2] ][ msi[s1] ] = j;

            strcpy(route[ msi[s1] ][ msi[s2] ], s3);
            strcpy(route[ msi[s2] ][ msi[s1] ], s3);
        }
    }

    floyd(k);

    while(gets(arr)){
        s = strtok(arr,",");
        strcpy(s1, s);
        s = strtok(NULL,",");
        strcpy(s2, s);

        puts("");
        puts("");

        puts("From                 To                   Route      Miles");
        puts("-------------------- -------------------- ---------- -----");
        path(msi[s1], msi[s2]);
        puts("                                                     -----");
        printf("                                          Total      ");
        printf("%5d\n",dist[ msi[s1] ][ msi[s2] ]);
    }


    return 0;
}














