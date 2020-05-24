using namespace std;

#include "stdio.h"
#include "string.h"
#include "string"
#include "set"
#include "vector"
#include "map"
#include "iostream"

#define SZ 110

int low[SZ] , T[SZ] , tym , root;
vector <int> adj[SZ];

map <string , int> msi;
map <int , string> mis;
set <string> myset;
set <string>::iterator it;

void init(int n)
{
    myset.clear();
    mis.clear();
    msi.clear();

    int i;
    for(i=0;i<=n;i++)
    {
        adj[i].clear();
        T[i] = 0;
    }

}

void articulation(int u,int p)
{
    int i,j,k,v,child=0;

    low[u] = T[u] = ++tym;
    k = adj[u].size();

    for(i=0;i<k;i++)
    {
        v = adj[u][i];
        if(p == v) continue;

        if(T[v] == 0)
        {
            child++;
            articulation(v,u);
            low[u] = min(low[u] , low[v]);
            if(low[v] >= T[u] && u != root)
                myset.insert(mis[u]);
        }

        else if(T[v] < T[u])
            low[u] = min(low[u] , T[v]);
    }

    if(u == root && child >= 2)
        myset.insert(mis[u]);
}

int main()
{
    int test=0,n,m,i,j,k=0;
    string s,s1;
    while(scanf("%d",&n) == 1 && n)
    {
        if(k) printf("\n") , k = 1;

        init(n);
        m = 0;

        for(i=0;i<n;i++)
        {
            cin >> s;
            msi[s] = ++m;
            mis[m] = s;
        }

        scanf("%d",&m);

        for(i=0;i<m;i++)
        {
            cin >> s >> s1;
            j = msi[s];
            k = msi[s1];
            adj[j].push_back(k);
            adj[k].push_back(j);
        }

        tym = 0;

        for(i=1;i<=n;i++)
        {
            root = i;
            if(T[i] == 0)
                articulation(i , -1);
        }

        printf("City map #%d: %d camera(s) found\n",++test,myset.size());

        for(it=myset.begin();it!=myset.end();it++)
            printf("%s\n",(*it).c_str());

    }

    return 0;
}
