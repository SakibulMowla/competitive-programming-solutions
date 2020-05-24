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
#define snuke(c, itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define pb push_back
#define ssort(a) stable_sort(a.begin(), a.end())
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);

#define X first
#define Y second



namespace matching
{
    int val_t;
    const int SIZE = 100000+10;
    int v1, v2;
    vector<int> graph[SIZE];
    int mx[SIZE], my[SIZE];
    int total_matching;
    int dist[SIZE];
    int inf_dist;

    bool bfs()
    {
        int x, y;
        queue<int> q;
        for (x = 0 ; x < v1 ; x++)
        {
            if (mx[x] == -1)
            {
                dist[x] = 0;
                q.push(x);
            }
            else
                dist[x] = -1;
        }
        bool flg = false;
        while (!q.empty())
        {
            x = q.front();
            q.pop();
            for (int i = 0 ; i < graph[x].size() ; i++)
            {
                y = graph[x][i];
                if (my[y] == -1)
                {
                    inf_dist = dist[x] + 1;
                    flg = true;
                }
                else if (dist[my[y]] == -1)
                {
                    dist[my[y]] = dist[x] + 1;
                    q.push(my[y]);
                }
            }
        }
        return flg;
    }

    bool dfs(int x)
    {
        if (x == -1) return true;
        for (int i = 0 ; i < graph[x].size() ; i++)
        {
            int y = graph[x][i];
            int tmp = (my[y] ==
                       -1) ? inf_dist : dist[my[y]];
            if (tmp == dist[x] + 1 && dfs(my[y]))
            {
                mx[x] = y;
                my[y] = x;
                return true;

            }

        }
        dist[x] = -1;
        return false;
    }

    int hopcroft()
    {
        memset(mx,
               -1, sizeof(mx));
        memset(my,
               -1, sizeof(my));
        total_matching = 0;
        while (bfs())
        {
            for (int x = 0 ; x < v1 ; x++)
                if (mx[x] == -1 && dfs(x))
                    total_matching++;

        }
        return total_matching;
    }
} // namespace matching

#define SZ 100010

ll arr[SZ];
int col[SZ];
map <ll, int> mp;

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ll n, a, b, i, j, cnt, indx1, indx2;

    while(scanf("%I64d %I64d %I64d", &n, &a, &b) == 3) {
        clr(mp);
        cnt = 0LL;
        mem(col, 0);

        for(i = 1; i <= n; i++) {
            RD(arr[i]);
            mp[ arr[i] ] = i-1;
        }

        matching::v1 = n;

        REP1(i, 1, n) {
            if(mp.find(a-arr[i]) != mp.end())  matching::graph[ i-1 ].pb( mp[a-arr[i]] );
            if(mp.find(b-arr[i]) != mp.end()) matching::graph[ i-1 ].pb( mp[b-arr[i]] );
        }

        if(matching::hopcroft() != n) {
            printf("NO\n");
            continue;
        }

        REP(i, n) {
            if(arr[i+1] + arr[ matching::my[i]+1 ] == a) {
                col[i] = col[ matching::my[i] ] = 0;
            }
            else {
                col[i] = col[ matching::my[i] ] = 1;
            }
        }

        printf("YES\n");
        REP(i, n) printf("%d ",col[i]);
        printf("\n");
    }

    return 0;
}



