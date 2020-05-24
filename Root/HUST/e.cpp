//E

#include <bits/stdc++.h>
#define ms(a,b) memset(a,b,sizeof(a))
#define inf 1<<28
#define clr(a) a.clear()
#define pb push_back
#define pob pop_back
#define vec_ vector
#define eps 1E-7
#define sort_n(a) sort(a.begin(),a.end())
#define sort_m(a) sort(a.begin(),a.end(),comp)
#define fop freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define scch(a) scanf("%c",&a)
#define scll1(a) scanf("%lld",&a)
#define scll2(a,b) scanf("%lld %lld",&a,&b)
#define scll3(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define sci1(a) scanf("%d",&a)
#define sci2(a,b) scanf("%d %d",&a,&b)
#define sci3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define scd1(a) scanf("%lf",&a)
#define scd2(a,b) scanf("%lf %lf",&a,&b)
#define scd3(a,b,c) scanf("%lf %lf %lf",&a,&b,&c)
#define mp make_pair
#define sz(a) a.size()
#define mt
using namespace std;
typedef long long ll;
//struct data //for dj()
//{
// int node,cost;
// bool operator < (const data& p) const
// {
// return cost > p.cost;
// }
//};
//template <class T> T lcm(T a, T b){return (a/__gcd(a,b)) * b;}
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//int X[]={0,-1,-1,-1,0,1,1,1};
//int Y[]={-1,-1,0,1,1,1,0,-1};
//int X[]={-1,0,1,0};
//int Y[]={0,1,0,-1};

#define SZ 410

ll par[SZ],arr[SZ];
map<ll,ll>M;
bool col[SZ];
vec_<ll>adj[SZ];
bool dfs(ll u)
{
    if(col[u])return 0;
    ll i,k,v;
    k=sz(adj[u]);
    for(i=0; i<k; i++)
    {
        v=adj[u][i];
        if(col[v]==0)
        {
            col[v]=1;
            if(par[v]==-1 || dfs(par[v]))
            {
                par[v]=u;
                return 1;
            }
        }
    }
    return 0;
}

ll bpm(int f)
{
    ll i,j,k=0;
    ms(par,-1);
    for(i=1; i<=f; i++)
    {
        ms(col,0);
        if(dfs(i))
        {
            k++;
// cout<<i<<endl;
        }
    }
    return k;
}

map <ll, ll> map1, map2;

void cnstr(ll f)
{
    ll i, j, k;
    for(i =1; i<=f; i++)
    {
        if(map2.find(i) != map2.end()) continue;
        for(j=1; j<=f; j++)
        {
            if(i == j) continue;
            if(M.find(arr[i]+arr[j])!=M.end())
            {
                adj[i].pb(j);
                map2[j] = 1;
            }
        }
    }
}

int main()
{
    ll t,f,b,i,j,k;
    cin>>t;
    while(t--)
    {
        clr(M);
        cin>>f>>b;
        for(i=1; i<=f; i++)
        {
            cin>>arr[i];
            clr(adj[i]);
        }

        for(i=1; i<=b; i++)
        {
            cin>>j;
            M[j]=1;
        }
//        for(i=1; i<=f; i++)
//        {
//            for(j=i+1; j<=f; j++)
//            {
//                if(i==j)
//                    continue;
//                if(M.find(arr[i]+arr[j])!=M.end())
//                {
//                    adj[i].pb(j);
////adj[j].pb(i);
//                }
//            }
//        }
        ll ans = 0;
        for(i=1; i<=f; i++)
        {
            map1.clear();
            map2.clear();
            for(k=0;k<=f;k++)
                adj[k].clear();
            for(j=1; j<=f; j++)
            {
                if(i == j) continue;
                if(M.find(arr[i]+arr[j])!=M.end())
                {
                    adj[i].pb(j);
                    map2[j] = 1;
                }
            }
            cnstr(f);
            ans = max(ans, bpm(f));
        }

//        for(i=1; i<=f; i++)
//        {
//            cout<<i<<"==== ";
//            for(j=0; j<sz(adj[i]); j++)
//                cout<<adj[i][j]<<" ";
//            cout<<endl;
//        }
        cout<<ans<<endl;
    }



    return 0;
}


/*
2
6 4
1 2 3 4 4 5
6 9 3 5
5 4
1 2 3 4 5
6 9 3 5
*/
