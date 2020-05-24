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


typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const ll inf = 1;
const ll mod = 1LL;

#define SZ 10000010

int num[SZ];
int prime[SZ/10];
int cnt[SZ/10];
int arr[SZ];
int pn;

void sieve(){
    pn=1;
    int i, j, k;

    prime[1] = 2;
    for(i=2;i<=10000000;i+=2){
        cnt[pn] += num[i];
    }

    for(i=3;i<SZ;i+=2)
        if(arr[i] == 0){
            pn++;
            prime[pn] = i;
            for(j=i;j<SZ;j+=i)
                arr[j] = 1, cnt[pn] += num[j];
        }

    prime[pn+1] = 10000000+10;
}

int b_search(int val){
    int i, j, k, lo, hi, mid;

    k = pn+1;
    lo = 1;
    hi = pn;

    while(lo <= hi){
        mid = (lo + hi) >> 1;
        if(prime[mid] >= val)
            k = min(k, mid), hi = mid - 1;
        else lo = mid + 1;
    }

    return k;
}

int bb_search(int val){
    int i, j, k, lo, hi, mid;

    k = 0;
    lo = 1;
    hi = pn;

    while(lo <= hi){
        mid = (lo + hi) >> 1;
        if(prime[mid] <= val)
            k = max(k, mid), lo = mid + 1;
        else hi = mid - 1;
    }

    return k;
}

int cum[SZ/10];

int main() {
    int n, m, i, j, k, kk, l, ans;

    while(scanf("%d",&n) == 1){
        REP(i, n){
            RD(j);
            num[j]++;
        }

        sieve();

        REP1(i, 1, pn)
            cum[i] = cum[i-1] + cnt[i];


        RD(m);

        while(m--){
            RD(i, j);

            if(i > 10000000)
                {ans = 0; goto HELL;}
            if(j > 10000000)
                j = 10000000;

            k = b_search(i);
            kk = bb_search(j);
            ans = 0;

            if(kk < k){
                goto HELL;
            }

            ans = cum[kk] - cum[k-1];

            HELL:;

            PR(ans);
        }

        return 0;
    }


    return 0;
}
















