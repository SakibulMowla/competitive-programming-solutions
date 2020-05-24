
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

//#include <bits/stdc++.h>

using namespace  std;

#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())

typedef long long ll;
typedef pair<ll,ll> pii;

//ll extGcd(ll a, ll b, ll& x, ll& y){if (b == 0){x = 1;y = 0;return a;}else{int g = extGcd(b, a % b, y, x);y -= a / b * x;return g;}}
//ll modInv(ll a, ll m){ll x, y; extGcd(a, m, x, y); x %= m; while (x < 0){x += m;} return x;}
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//ll BigMod(ll B,ll P,ll M){     ll R=1%M; while(P>0)      {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

//template <class T> T gcd(T a, T b){while(b == 0) return a;return gcd(b,a%b);}
//template <class T> T lcm(T a, T b){return (a/gcd(a,b)) * b;}

//ll x[] = {0,0,-1,1};//4-way
//ll y[] = {-1,1,0,0};//4-way
//ll x[] = {-1,-1,-1,0,0,1,1,1};//8-way
//ll y[] = {-1,0,1,-1,1,-1,0,1};//8-way

#define SZ 410
const ll inf = 1LL<<28;
const ll mod = 1LL;

char a[SZ], b[SZ], c[SZ];
int len1, len2, len3;
int dp[SZ][SZ];

vector <char> s;

int solve(int indx1, int indx2)
{
    if(indx1+indx2 == len3)
    {
//        printf("indx1 indx2  %d %d\n",indx1,indx2);
//        printf(" S = %d ",s.size());
//        for(int i=0;i<s.size();i++)
//            cout << s[i] << "|";
//        cout << "\n";
        return 1;
    }

    int &ret = dp[indx1][indx2];
    if(ret != -1) return ret;

    ret = 0;

    if(indx1 == len1)
    {
        if(b[indx2] == c[indx1+indx2])
            ret = max(ret, solve(indx1, indx2+1));
    }

    else if(indx2 == len2)
    {
        if(a[indx1] == c[indx1+indx2])
           ret = max(ret, solve(indx1+1, indx2));
    }

    else
    {
        if(a[indx1] == c[indx1+indx2])
            ret = max(ret, solve(indx1+1, indx2));
        if(b[indx2] == c[indx1+indx2])
            ret = max(ret, solve(indx1, indx2+1));
    }

    return ret;
}


//%I64d
int main()
{
    int t, test= 0, i, j;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%s %s %s",a,b,c);
//        printf("a = %s b = %s c = %s\n",a,b,c);
        len1 = strlen(a);
        len2 = strlen(b);
        len3 = strlen(c);

        for(i=0;i<=len1;i++)
            for(j=0;j<=len2;j++)
                dp[i][j] = -1;

        i = solve(0, 0);

        if(i == 1) printf("Data set %d: yes\n",++test);
        else printf("Data set %d: no\n",++test);
    }


    return 0;
}










