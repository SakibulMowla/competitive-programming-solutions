#include <bits/stdc++.h>

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
const int inf = 1;
const ll mod = 1000000LL;

#define SZ  3000010
#define SZ1 1000010

ll arr[SZ1];

int main() {
    ll a, b, c, d, cur, pre, sum1, sum2;
    int t, n, i, k;

    RD(t);

    while(t--){
        RD(n);
        RD(a, b);
        RD(c, d);
        mem(arr, 0);

        pre = d % mod;
        arr[pre]++;
        REP1(i, 1, n-1){
            cur = (a*pre*pre + b*pre + c) % mod;
            arr[cur]++;
            pre = cur;
        }

        sum1 = sum2 = 0;
        k = 1;

        REP2(i, 1000000, 0)
            while(arr[i]--){
                if(k) sum1 += i;
                else sum2 += i;
                k = !k;
            }

        sum1 = sum1 - sum2;
        if(sum1 < 0) sum1 = -sum1;

        PR(sum1);
    }


    return 0;
}


