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

void RD(int &x){scanf("%d",&x);}
void RD(ll &x){scanf("%lld",&x);}
void RD(double &x){scanf("%lf",&x);}
void RD(int &x,int &y){scanf("%d%d",&x,&y);}
void RD(ll &x,ll &y){scanf("%lld%lld",&x,&y);}
void RD(double &x,double &y){scanf("%lf%lf",&x,&y);}
void RD(char *s){scanf("%s",s);}
void RD(char &s){scanf("%c",&s);}
void RD(string &s){cin>>s;}

void PR(int x) {printf("%d\n",x);}
void PR(int x,int y) {printf("%d %d\n",x,y);}
void PR(ll x) {printf("%lld\n",x);}
void PR(char x) {printf("%c\n",x);}
void PR(char *x) {printf("%s\n",x);}
void PR(string x) {cout<<x<<endl;}

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

#define SZ  5010

char str[SZ];
int revSA[SZ],SA[SZ];
int cnt[SZ] , nxt[SZ];
bool bh[SZ],b2h[SZ];
int lcp[SZ];


bool cmp(int i,int j){
    return str[i]<str[j];
}

void sortFirstChar(int n){
    int i;
    for(i=0; i<n; i++)
        SA[i] = i;
    sort(SA, SA+n,cmp);

    for(i=0; i<n; i++)
    {
        bh[i] = ( i==0  || str[SA[i]]!=str[SA[i-1]]);
        b2h[i] = false;
    }
    return;
}

int CountBucket(int n){
    int i, j, bucket = 0;

    for(i=0,j; i<n ;i=j){
        j = i+1;
        while(j<n && bh[j]==false) j++;
        nxt[i] = j;
        bucket++;
    }
    return bucket;
}

void SetRank(int n){
    int i, j;
    for(i=0; i<n; i=nxt[i]){
        cnt[i] = 0;
        for(j=i; j<nxt[i] ;j++){
            revSA[SA[j]] = i;
        }
    }
    return;
}

void findNewRank(int l,int r,int step){
    int j, head;
    for(j=l; j<r; j++){
        int pre = SA[j] - step;
        if(pre>=0){
            head = revSA[pre];
            revSA[pre] = head+cnt[head]++;
            b2h[revSA[pre]] = true;
        }
    }
    return;
}

void findNewBucket(int l,int r,int step){
    int j, k, pre;
    for(j=l; j<r; j++){
        pre = SA[j] - step;
        if(pre>=0 && b2h[revSA[pre]]){
            for(k=revSA[pre]+1; b2h[k] && !bh[k]; k++) b2h[k] = false;
        }
    }
    return;
}

void buildSA(int n){
    int h, i;
    sortFirstChar(n);
    for(h=1; h<n; h<<=1){
        if(CountBucket(n)==n) break;
        SetRank(n);
        b2h[revSA[n-h]] = true;
        cnt[revSA[n-h]]++;

        for(i=0; i<n; i=nxt[i]){
            findNewRank(i,nxt[i] , h);
            findNewBucket(i , nxt[i] , h);
        }
        for(i=0; i<n; i++){
            SA[revSA[i]] = i;
            bh[i] |= b2h[i];
        }
    }
    return;
}

void buildLCP(int n){
    int len = 0, i, k, j;

    for(i=0; i<n; i++)
        revSA[SA[i]] = i;
    for(i=0; i<n; i++){
        k = revSA[i];
        if(k == 0){
            lcp[k] = 0;
            continue;
        }
        j = SA[k-1];
        while(str[i+len]==str[j+len]) len++;
        lcp[k] = len;
        if(len) len--;
    }
    return;
}

void printSA(int n){
    int i;
    printf("SA: ");
    for(i=0; i<n; i++) printf("%d ",SA[i]);puts("");
    printf("lcp: ");
    for(i=1; i<n; i++) printf("%d ",lcp[i]);puts("");
    return;
}

int solve(int n){
    int i, ans = 0;

    REP1(i, 1, n-1)
        ans = max(ans,lcp[i]);

    return ans;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int test, n, p, q;

    scanf("%d",&test);

    while(test--)
    {
        scanf("%s",str);
        n = strlen(str);

        buildSA(n);
        buildLCP(n);

        PR(solve(n));

//        printSA(n);
    }

    return 0;
}






