#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

#define pb push_back
#define sz(a) (int)a.size()

typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const int inf = 1;
const ll mod = 1LL;

#define SZ 200000+10

int tree[SZ], arr[SZ];
int N;

void update(int indx)
{
    while(indx <= N)
    {
        tree[indx] += 1;
        indx += (indx & -indx);
    }
    return;
}

int query(int indx)
{
    int sum = 0;
    while(indx > 0)
    {
        sum += tree[indx];
        indx -= (indx & -indx);
    }
    return sum;
}

struct data1{
    int val, indx;
};

data1 b[SZ];

bool comp(data1 p, data1 q)
{
    if(p.val == q.val) return p.indx < q.indx;
    return p.val < q.val;
}

int c[SZ], cn;

struct data2{
    int cmd, indx, x, y, mark;
    data2(){}
    data2(int p, int q, int r, int s, int t){
        cmd = p, indx = q, x = r, y = s, mark = t;
    }
};

ll res[SZ];
vector <data2> group[SZ];

int main() {
    int m, i, j, k, val, x, y;
    ll ans, tmp;

    scanf("%d %d",&N,&m);
    {
        for(i=1, j=0; i<=N; i++)
        {
            scanf("%d",&arr[i]);
            c[i-1] = arr[i];
        }

        sort(c, c+N);
        cn = unique(c, c+N)-c;

        for(i=1; i<=N; i++)
        {
            arr[i] = (lower_bound(c, c+cn, arr[i])-c)+1;
            b[i].val = arr[i];
            b[i].indx = i;
        }

        sort(b+1, b+N+1, comp);
        ans = 0LL;

        for(i=1; i<=N; i++)
        {
            ans += (ll)query(N) - (ll)query(b[i].indx);
            update(b[i].indx);
        }


        for(i=1; i<=m; i++)
            res[i] = ans;

        for(i=1; i<=m; i++)
        {
            scanf("%d %d",&x,&y);
            if(x > y) swap(x, y);
            group[ arr[y] ].pb(data2(1, i, x+1, y-1, 1)); ///cmd, indx, x, y, mark
            group[ arr[x] ].pb(data2(1, i, x+1, y-1, -1)); ///cmd, indx, x, y, mark
            if(arr[x] > arr[y]) res[i]--;
            if(arr[y] > arr[x]) res[i]++;
        }

        for(i=0; i<N; i++)
        {
            group[ arr[i] ].pb( data2(0, i, 0, 0, 0) );
        }

        memset(tree, 0, sizeof(tree));

        for(i=1; i<=N; i++)
        {
            k = sz(group[i]);
            for(j=0; j<k; j++)
            {
                if(group[i][j].cmd == 0)
                {
                    update(group[i][j].indx);
                }
                else
                {
                    tmp = query(group[i][j].y) - query(group[i][j].x-1);
                    if(group[i][j].mark == 1) res[ group[i][j].indx ] += tmp;
                    else res[ group[i][j].indx ]-= tmp;
                }
            }
        }

        memset(tree, 0, sizeof(tree));

        for(i=N; i>=1; i--)
        {
            k = sz(group[i]);
            for(j=0; j<k; j++)
            {
                if(group[i][j].cmd == 0)
                {
                    update(group[i][j].indx);
                }
                else
                {
                    tmp = query(group[i][j].y) - query(group[i][j].x-1);
                    if(group[i][j].mark == -1) res[ group[i][j].indx ] += tmp;
                    else res[ group[i][j].indx ]-= tmp;
                }
            }
        }

        for(i=1; i<=m; i++)
            printf("%lld\n",res[i]);
    }

    return 0;
}







