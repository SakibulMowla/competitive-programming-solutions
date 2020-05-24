#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

void RD(int &x) {
    scanf("%d",&x);
}
void RD(ll &x) {
    scanf("%I64d",&x);
}
void RD(double &x) {
    scanf("%lf",&x);
}
void RD(int &x,int &y) {
    scanf("%d%d",&x,&y);
}
void RD(ll &x,ll &y) {
    scanf("%I64d%I64d",&x,&y);
}
void RD(double &x,double &y) {
    scanf("%lf%lf",&x,&y);
}
void RD(char *s) {
    scanf("%s",s);
}
void RD(char &s) {
    scanf("%c",&s);
}
void RD(string &s) {
    cin>>s;
}

void PR(int x) {
    printf("%d\n",x);
}
void PR(int x,int y) {
    printf("%d %d\n",x,y);
}
void PR(ll x) {
    printf("%I64d\n",x);
}
void PR(char x) {
    printf("%c\n",x);
}
void PR(char *x) {
    printf("%s\n",x);
}
void PR(string x) {
    cout<<x<<endl;
}

#define read(a) freopen("a", "r", stdin)
#define write(a) freopen("a", "w", stdout)

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define snuke(c, itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define pb push_back
#define ssort(a) stable_sort(a.begin(), a.end())

#define X first
#define Y second

typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const ll inf = 1LL<<28;
const ll mod = 1LL;

#define SZ 1010

ll strt[20], end[20];

int main() {
//    freopen("1.txt","r",stdin);
    ll i, j, k, ans, money, st, cost, tmp;
    bool flag;


    while(scanf("%I64d",&money) == 1){
        RD(st);
        RD(cost);

        j = 1, k = 9;

        for(i=1;i<=17;i++){
            strt[i] = j;
            end[i] = k;
            j *= 10;
            k *= 10;
            k += 9;
        }

        k = 0;
        j = st;

        while(j){
            k++;
            j/=10;
        }

        strt[k] = st;
        ans = 0;

        for(i=k;i<=17;i++){
            tmp = min(end[i]-strt[i]+1, (money/cost)/i);
            ans += tmp;
            money -= tmp*cost*i;
        }

        PR(ans);
    }


    return 0;
}
















