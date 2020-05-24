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

#define X first
#define Y second

typedef long long ll;
typedef pair<int , int> pii;
typedef pair<ll , ll> pll;

//ll extGcd(ll a, ll b, ll& x, ll& y){if (b == 0){x = 1;y = 0;return a;}else{int g = extGcd(b, a % b, y, x);y -= a / b * x;return g;}}
//ll modInv(ll a, ll m){ll x, y; extGcd(a, m, x, y); x %= m; while (x < 0){x += m;} return x;}
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//ll BigMod(ll B,ll P,ll M){     ll R=1%M; while(P>0)      {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

template <class T> T gcd(T a, T b)
{
    while(b == 0) return a;
    return gcd(b,a%b);
}
//template <class T> T lcm(T a, T b){return (a/gcd(a,b)) * b;}

//ll x[] = {0,0,-1,1};//4-way
//ll y[] = {-1,1,0,0};//4-way
//ll x[] = {-1,-1,-1,0,0,1,1,1};//8-way
//ll y[] = {-1,0,1,-1,1,-1,0,1};//8-way

#define SZ 20
const ll inf = 1LL<<28;
const ll mod = 1LL;

#define eps 1e-8

struct point
{
    int x, y;
};

set <pair <int , int> > myset;
set <pair <int , int> > ::iterator it;
point arr[SZ];


int dist(int a, int b)
{
    int d;
    d =  (arr[a].x-arr[b].x)*(arr[a].x-arr[b].x) + (arr[a].y-arr[b].y)*(arr[a].y-arr[b].y) ;
    return d;
}


//vector <double> v[8010];
vector <int> v[8010];


//%I64d
int main()
{

    int i, j, k, n, m, cnt, ans, tmp;
    double a, b, c, ang1, ang2, ang3;

    while(scanf("%d",&n) == 1 && n)
    {
        cnt = 0;

        myset.clear();

        for(i=0; i<n; i++)
        {
            scanf("%d %d",&j,&k);
//            arr[i].x = j;
//            arr[i].y = k;
            myset.insert(MP(j, k));
        }

        for(i=0; i<8005; i++)
            v[i].clear();

        i = 0;

        for(it=myset.begin();it!=myset.end();it++)
        {
            arr[i].x = it->first;
            arr[i++].y = it->second;
        }

        n = sz(myset);

        for(i=0; i<n; i++)
            for(j=i+1; j<n; j++)
                for(k=j+1; k<n; k++)
                {
                    double d = 0.5 * ( ( (arr[j].x*arr[k].y) - (arr[j].y*arr[k].x) )  - ( (arr[i].x*arr[k].y) - (arr[i].y*arr[k].x) ) + ( (arr[i].x*arr[j].y) - (arr[i].y*arr[j].x) ) );
//                    printf("d = %lf\n",d);
                    if(d == 0)
                        continue;
                    a = dist(i, j);
                    b = dist(j, k);
                    c = dist(k, i);

//                    ang1 = acos( (b*b + c*c - a*a) / (2*b*c) );
//                    ang2 = acos( (a*a + c*c - b*b) / (2*a*c) );
//                    ang3 = acos( (b*b + a*a - c*c) / (2*b*a) );

                    if(a == 0 || b == 0 || c == 0)
                        continue;

                    v[cnt].push_back((int)a);
                    v[cnt].push_back((int)b);
                    v[cnt++].push_back((int)c);

                }

        for(i=0; i<cnt; i++)
            sort(v[i].begin(), v[i].end());

        ans = 0;
        int g;
        int arr1[10];
        int arr2[10];

//        printf("cnt = %d\n",cnt);

        for(i=0; i<cnt; i++)
        {
            tmp = 0;

            for(j=i; j<cnt; j++)
            {
                g = gcd(v[i][0], v[j][0]);
//                if(g == 0) continue;
//                if(g != 0)
//                {
                    arr1[0] = v[i][0] / g;
                    arr2[0] = v[j][0] / g;
//                }
//                else
//                    arr1[0] = arr2[0] = 1;

                g = gcd(v[i][1], v[j][1]);
//                if(g == 0) continue;
//                if(g != 0)
//                {
                    arr1[1] = v[i][1] / g;
                    arr2[1] = v[j][1] / g;
//                }
//                else
//                    arr1[1] = arr2[1] = 1;


                g = gcd(v[i][2], v[j][2]);
//                if(g == 0) continue;
//                if(g != 0)
//                {
                    arr1[2] = v[i][2] / g;
                    arr2[2] = v[j][2] / g;
//                }
//                else
//                    arr1[2] = arr2[2] = 1;

//                if(arr1[0] == arr2[0] && arr1[1] == arr2[1] && arr1[2] == arr2[2])
                if(arr1[0] == arr1[1] && arr1[1] == arr1[2] && arr2[0] == arr2[1] && arr2[1] == arr2[2])
                    tmp++;
            }

//            if(tmp == 4)
//                printf("i = %d\n",i);

            ans = max(ans, tmp);
        }

        printf("%d\n",ans);
    }


    return 0;
}

















