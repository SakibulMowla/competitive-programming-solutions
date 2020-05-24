#include <bits/stdc++.h>

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

//template <class T> inline T gcd(T a, T b){if(b == 0) return a;return gcd(b,a%b);}
//template <class T> inline T lcm(T a, T b){return (a/gcd(a,b)) * b;}

//ll x[] = {0,0,-1,1};//4-way
//ll y[] = {-1,1,0,0};//4-way
//ll x[] = {-1,-1,-1,0,0,1,1,1};//8-way
//ll y[] = {-1,0,1,-1,1,-1,0,1};//8-way
//inline long FastMax(long x, long y) { return (((y-x)>>(32-1))&(x^y))^y; }
//inline long FastMin(long x, long y) { return (((y-x)>>(32-1))&(x^y))^x; }


typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const ll inf = 1;
const ll mod = 1LL;

#define SZ 100010

int N1, N2;
int dp[110][10];
string arr1, arr2;

int solve(int indx1, int indx2){
//    printf("-----------------------%d %d\n",indx1,indx2);
    if(indx2 == N2) {
//        printf("-----------------------indx2 N2 %d %d\n",indx2,N2);
        return 1;
    }
    if(indx1 == N1) {
//        printf("-----------------------indx1 N1 %d %d\n",indx1,N1);
        return 0;
    }

    int &ret = dp[indx1][indx2];
    if(ret != -1) {
//        printf("-----------------------ret = %d\n",ret);
        return ret;
    }

    ret = solve(indx1+1, indx2);
    if(arr1[indx1] == arr2[indx2])
        ret = max(ret, solve(indx1+1, indx2+1));

    return ret;
}

class LongWordsDiv2 {
public:
	string find(string word) {
	    arr1 = word;
		int i, j, k;
		bool flag = 0;

		k = sz(word);
		REP(i, k)
            if(!(word[i]>='A' && word[i]<='Z'))
                flag = 1;
		REP1(i,1,k-1)
            if(word[i]==word[i-1])
                flag = 1;

//        printf("flag = %d\n",flag);

        N1 = k;
        N2 = 4;
//        printf("n1 n2 %d %d\n",N1,N2);
        for(i=0; i<26; i++){
            if(flag)
                break;
            for(j=0; j<26; j++){
                arr2 = "";
                arr2 += (char)(i+'A');
                arr2 += (char)(j+'A');
                arr2 += (char)(i+'A');
                arr2 += (char)(j+'A');
                mem(dp, -1);
                flag |= solve(0, 0);
                if(flag == 1){
//                    printf("key = %s\n",arr2.c_str());
                    break;
                }
            }
            if(flag)
                break;
        }
        printf("flag = %d\n",flag);

        if(flag) return "Dislikes";
        else return "Likes";
	}
};
