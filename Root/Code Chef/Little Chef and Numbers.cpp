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

const ll inf = 1LL<<28;
const ll mod = 1LL;

int arr[100010];
int cum[100010];
int two[100010];

int main() {
    int test=0, t, i, j, k, n;
    ll ans;

    RD(t);

    while(t--){
        RD(n);

        REP1(i, 1, n){
            RD(arr[i]);

            if(arr[i] >= 3) cum[i] = 1;
            else cum[i] = 0;
            cum[i] += cum[i-1];

            if(arr[i] == 2) two[i] = 1;
            else two[i] = 0;
            two[i] += two[i-1];
        }

        ans = 0LL;

        REP1(i, 1, n-1){
            if(arr[i] >= 3)
                ans += (cum[n]-cum[i]) + (two[n]-two[i]);
            else if(arr[i] == 2)
                ans += cum[n]-cum[i];
        }

        PR(ans);
    }


    return 0;
}




