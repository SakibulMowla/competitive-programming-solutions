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
const int inf = 1;
const ll mod = 1LL;

#define SZ  110

map <string, int> mp;

string str[200] = {
        "H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar", "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr", "Y", "Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb", "Te", "I", "Xe", "Cs", "Ba", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au", "Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds", "Rg", "Cn", "Fl", "Lv", "", "La", "Ce", "Pr", "Nd", "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "", "Ac", "Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm", "Md", "No", "Lr"
    };

void pre()
{
    int i, j, k, l;


    for(i=0; i<200; i++)
    {
        l = sz(str[i]);

        for(j=0; j<l; j++)
        {
            str[i][j] = tolower(str[i][j]);
        }
        mp[ str[i] ] = 1;
//        cout <<
    }

    return;
}

string arr;
int dp[50000+100];

int N;

int solve(int pos)
{

    if(pos == N) return 1;

    int &ret = dp[pos];
    if(ret != -1) return ret;

    ret = 0;
    string tmp = "";
    tmp += arr[pos];

    if(mp.find(tmp) != mp.end()) ret = solve(pos+1);

//    cout << pos << ' ' << arr[pos] <<  ' ' << tmp << ' ' << ret << endl;
    if(ret) return ret;

//    cout << pos << ' ' << arr[pos] <<  ' ' << tmp << ' ' << ret << endl;

    if(pos+1 < N) tmp = tmp + arr[pos+1];
//    cout << pos << ' ' << arr[pos+1] <<  ' ' << tmp << ' ' << ret << endl;

    if(mp.find(tmp) != mp.end()) ret = max(ret, solve(pos+2));
//    cout << pos << ' ' << arr[pos+1] <<  ' ' << tmp << ' ' << ret << endl;



    return ret;
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("2.txt", "w", stdout);


    pre();

    int t, i, j, k, n, m;

    scanf("%d",&t);

    while(t--)
    {
        cin >> arr;

        N = arr.size();

        mem(dp, -1);

        printf("%s\n",solve(0)?"YES":"NO");
    }


    return 0;
}

















