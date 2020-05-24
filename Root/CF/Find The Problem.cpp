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

#define SZ 100010
const ll inf = 1LL<<28;
const ll mod = 1LL;


map <string , int> r, p, c;
map <string , int> ::iterator it, it1;
map <int , string> rr, rp, rc;

void plusPrint(int n)
{
    printf("+");
    while(n--)
        printf("---+");
    printf("---+");
    printf("\n");
}

//%I64d
int main()
{
//    plusPrint(3);

    string s, a, b, cc;
    int arr[55][55];
    int i, j, k, n, t, cnt1, cnt2, cnt3;

    scanf("%d",&t);

    while(t--)
    {
        memset(arr, -1, sizeof(arr));
        r.clear();
        p.clear();
        c.clear();
        rr.clear();
        rp.clear();
        rc.clear();
        cnt1 = cnt2 = cnt3 = 0;

        scanf("%d",&n);

        for(i=0; i<n; i++)
        {
            cin >> s;
            s = s + string(3-sz(s),' ');
            a = s;
            if(r.find(s) == r.end())
            {
                r[s] = cnt1;
                rr[cnt1] = s;
                cnt1++;
            }

            cin >> s;
            s = s + string(3-sz(s),' ');
            b = s;
            if(p.find(s) == p.end())
            {
                p[s] = cnt2;
                rp[cnt2] = s;
                cnt2++;
            }

            cin >> s;
            s = s + string(3-sz(s),' ');
            cc = s;
            if(c.find(s) == c.end())
            {
                c[s] = cnt3;
                rc[cnt3] = s;
                cnt3++;
            }

            arr[r[a]][p[b]] = c[cc];

//            printf("ra pb = %d %d\n",r[a],p[b]);
//            printf("ab = %s %s\n",a.c_str(),b.c_str());
//            printf("cnt = %d %d\n",cnt1,cnt2);

            //            cout << s << "\n";
        }

        plusPrint(cnt2);
        printf("|   |");
        for(it=p.begin(); it!=p.end(); it++)
            printf("%s|",(it->first).c_str());
        printf("\n");
        plusPrint(cnt2);

        for(it=r.begin(); it!=r.end(); it++)
        {
            printf("|%s|",(it->first).c_str());
            i = it->second;
            for(it1=p.begin(); it1!=p.end(); it1++)
            {
                j = it1->second;
                if(arr[i][j] != -1)
                {
                    printf("%s|",rc[arr[i][j]].c_str());
                }
                else
                {
                    printf("   |");
                }
            }
            printf("\n");
            plusPrint(cnt2);
        }
    }


    return 0;
}

