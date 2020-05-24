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


typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const ll inf = 1LL<<28;
const ll mod = 1LL;

#define SZ 1010


int main() {
//    freopen("1.txt", "r", stdin);
    ll n, m, i, j, k, k1, maxim, minim, num1, num2, one, two;
    ll arr[5];

    while(scanf("%I64d",&n) == 1){
        k = sqrt(n);
        minim = 1e18;
        maxim = 0LL;

        for(i=1;i<=k;i++) if(n%i == 0){
            num1 = i;
            num2 = n/i;

            k1 = sqrt(num2);

            for(j=1;j<=k1;j++) if(num2%j == 0){
                one = j;
                two = num2/j;
                arr[0] = num1;
                arr[1] = one;
                arr[2] = two;
                sort(arr,arr+3);
                maxim = max(maxim, ((arr[0]+2)*(arr[1]+2)*(arr[2]+1))-(arr[0]*arr[1]*arr[2]));
                minim = min(minim, ((arr[2]+2)*(arr[1]+2)*(arr[0]+1))-(arr[0]*arr[1]*arr[2]));
            }

            k1 = sqrt(num1);

            for(j=1;j<=k1;j++) if(num1%j == 0){
                one = j;
                two = num1/j;
                arr[0] = num2;
                arr[1] = one;
                arr[2] = two;
                sort(arr,arr+3);
                maxim = max(maxim, ((arr[0]+2)*(arr[1]+2)*(arr[2]+1))-(arr[0]*arr[1]*arr[2]));
                minim = min(minim, ((arr[2]+2)*(arr[1]+2)*(arr[0]+1))-(arr[0]*arr[1]*arr[2]));
            }


        }

        printf("%I64d %I64d\n",minim,maxim);
    }


    return 0;
}
















