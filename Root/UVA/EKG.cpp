using namespace std;

#include "stdio.h"
#include "string.h"
#include "string"
#include "vector"
#include "stack"
#include "set"
#include "iostream"
#include "algorithm"

#define SZ 10100

vector <int> adj[SZ];
stack <int> S;
int vis[SZ], num;

void init(int n)
{
    int i;
    for(i=0;i<=n;i++)
        vis[i] = 0, adj[i].clear();
    while(!S.empty()) S.pop();
}

void dfs(int n)
{
    int i, k;
    k = adj[n].size();

    vis[n] = 1;

    for(i=0;i<k;i++)
        if(vis[adj[n][i]] == 0)
            dfs(adj[n][i]);
}

int cnt,inchnk,chunkpos;

void dfs1(int n,int p)
{
    cnt++;
    int i, k;
    k = adj[n].size();

    vis[n] = 1;
    if(n == num)
    {
        inchnk = 1;
        chunkpos = p;
    }

    for(i=0;i<k;i++)
        if(vis[adj[n][i]] == 0)
            dfs1(adj[n][i], p+1);
}

int chunk[1010],cv;

int main()
{
    int t=0, test, n, m, i, j, k;

//    scanf("%d",&test);

    while(scanf("%d %d",&n,&num)==2)
    {
        init(n);

        for(i=1;i<=n;i++)
        {
            scanf("%d",&j);
            adj[j].push_back(i);
        }

        for(i=1;i<=n;i++)
            if(vis[i] == 0)
                dfs(i) , S.push(i);

        for(i=1;i<=n;i++)
            vis[i] = 0;
        k = 0;
        inchnk = 0;
        int f,chnklen;
        while(!S.empty())
        {
            j = S.top();
            S.pop();
            if(vis[j] == 0)
            {
                cnt = 0;
                f = inchnk;
                dfs1(j,1);
                if(f == 0 && inchnk==1)
                {
                    chnklen = cnt;
                }
                else
                chunk[k++] = cnt;
            }
        }

        sort(chunk,chunk+k);

        int sum;

        for(i=0;i<k;i++)
            sum += chunk[i];
        sum += chnklen;

        int free = n - sum;

        set <int> S;
        set <int> :: iterator it;

        int now;

        if(inchnk)
            now = chunkpos, S.insert(chunkpos);
        else
            now = 1, S.insert(1);

        long long lim = 1LL<<k;
        while(lim--)
        {
            int tmp=0;;
            for(i=0;i<k;i++)
                if(lim & (1LL<<i))
                    tmp += chunk[i];
                if(tmp == 0) continue;
            S.insert(now+tmp);
            printf("tmp = %d\n",tmp);

            for(j=0;j<free;j++)
            {
                S.insert(now+tmp+j+1);
            }
        }

        for(i=0;i<k;i++)
        {
            for(j=0;j<free;j++)
            {
                S.insert(now+j+1);
            }
            now += chunk[i];
            S.insert(now);
        }





        for(it=S.begin();it!=S.end();it++)
            if((*it) <= n)
                printf("%d\n",(*it));

    }

    return 0;
}

