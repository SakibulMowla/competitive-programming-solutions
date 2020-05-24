#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

void RD(int &x,int &y)
{
    scanf("%d%d",&x,&y);
}


#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define REP1(i,a,b) for((i)=a;(i)<=(int)(b);(i)++)
#define pb push_back


typedef pair<int , int> pii;

#define SZ 100010

struct data
{
    int p, q;
    data() {}
    data(int a, int b)
    {
        p = a, q = b;
    }
};

data arr[SZ];

map <pii, int> mp1;
map <int, int> mp2;
map <int, int> mp3;
int n;
bool found;
bool col[SZ];
vector <int> v[SZ];
vector <int> v1[SZ];

void dfs(int x, int y)
{
    if(found) return;
    if(x==n || y==1)
    {
        found = true;
        return;
    }

    col[mp1[MP(x, y)]] = 1;

    int i, k, p, q;

    if(mp2.find(x+1) != mp2.end())
    {
        k = sz(v[ mp2[x+1] ]);

        REP(i, k)
        {
            p = x + 1;
            q = v[ mp2[x+1] ][i];
            if(q >= y-1 && col[mp1[MP(p, q)]] == 0)
                dfs(p, q);
        }
    }

    if(mp3.find(y-1) != mp3.end())
    {
        k = sz( v1[ mp3[y-1] ] );

        REP(i, k)
        {
            q = y - 1;
            p = v1[ mp3[y-1] ][i];
            if(p-1 <= x && col[mp1[MP(p, q)]] == 0)
                dfs(p, q);
        }
    }

    return;
}

int main()
{
    int m, i, j, k, cnt, cnt1;

    while(scanf("%d %d",&n,&m) == 2)
    {
        clr(mp1);
        clr(mp2);
        clr(mp3);
        mem(col, 0);
        REP(i, 100001) clr(v[i]), clr(v1[i]);
        cnt = cnt1 = 0;

        REP(i, m)
        {
            RD(j, k);
            arr[i] = data(j, k);
            mp1[MP(j, k)] = i;
            if(mp2.find(j) == mp2.end()) mp2[j] = cnt++;
            v[ mp2[j] ].pb(k);
            if(mp3.find(k) == mp3.end()) mp3[k] = cnt1++;
            v1[ mp3[k] ].pb(j);
        }

        found = false;
        REP(i, m)
        {
            if(arr[i].p==1 || arr[i].q==n)
            {
                dfs(arr[i].p, arr[i].q);
                if(found) goto HELL;
            }
        }

        HELL:;
        found ? printf("-1\n") : printf("%d\n",2*n-2);
    }


    return 0;
}
















