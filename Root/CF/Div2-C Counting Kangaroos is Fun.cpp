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

#define SZ 5*100010

int arr[SZ];

bool f(int n, int mid){
    int i, j;
    for(i=0,j=n-mid;i<mid;i++,j++)
        if(arr[i]*2>arr[j])
            return 0;
    return 1;
}

int main() {
    int i, j, k, n, lo, hi, mid, ans;

    while(scanf("%d",&n) == 1){
        REP(i, n) RD(arr[i]);

        sort(arr, arr+n);
        lo=ans=0;
        hi=n/2;

        while(lo<=hi){
            mid = (lo+hi)>>1;
            if(f(n, mid))
                ans = mid, lo = mid+1;
            else
                hi = mid-1;
        }

        PR(n-ans);
    }


    return 0;
}
















