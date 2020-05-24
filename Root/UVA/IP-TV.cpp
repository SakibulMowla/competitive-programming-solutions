using namespace std;

#include "stdio.h"
#include "string.h"
#include "string"
#include "vector"
#include "map"
#include "iostream"
#include "algorithm"

typedef long long ll;

#define SZ 2010

ll par[SZ] , cyc[SZ];
map <string , ll> M;

struct data
{
    ll x,y,d;
};

vector <data> lasta;

bool comp(data p,data q)
{
    return p.d < q.d;
}

ll find(ll r)
{
    if(r == par[r]) return r;
    return par[r] = find(par[r]);
}

void Union(ll a,ll b)
{
    par[a] = b;
}

void init(ll n)
{
    int i;
    M.clear();
    lasta.clear();
    for(i=0; i<=n; i++)
        par[i] = i , cyc[i] = 0;
}

ll MST(ll n)
{
    ll i,j,k,u,v,cost=0,edge=0;

    k = lasta.size();

    for(i=0; i<k ; i++)
    {
        u = find(lasta[i].x);
        v = find(lasta[i].y);
        if(u == v) continue;

        edge++;
        Union(u,v);
        cost += lasta[i].d;
    }

    return cost;
}


int main()
{
    ll t , n , m , i , cost , node;
    data u;
    string s1 , s2;

    scanf("%lld",&t);

    while(t--)
    {
        scanf("%lld %lld",&n,&m);

        node = 0;
        init(n);

        for(i=0; i<m; i++)
        {
            cin >> s1 >> s2;
            scanf("%lld",&cost);

            if(M.find(s1) == M.end()) M[s1] = node++;
            if(M.find(s2) == M.end()) M[s2] = node++;

            u.x = M[s1];
            u.y = M[s2];
            u.d = cost;

            lasta.push_back(u);
        }

        sort(lasta.begin() , lasta.end(),comp);

        printf("%lld\n",MST(n));

        if(t) printf("\n");

    }

    return 0;
}

/*

1

4
8
a b 10
b c 17
b d 19
a d 4
c e 14
e a 2
b e 2
a c 1

*/
