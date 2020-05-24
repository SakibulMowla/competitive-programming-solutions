#include "stdio.h"
#include "string.h"
#include "string"
#include "vector"
#include "map"
#include "algorithm"
#include "iostream"

using namespace std;

#define SZ 110
#define Union(a,b) par[find(a)] = find(b)

struct data { int a,b,c; };
bool comp(data p,data q){ return p.c < q.c; }

vector <data> input;
map <string , int> msi;
map <int , string> mis;
int par[SZ] , matrix[SZ][SZ] , col[SZ] , ances[SZ];
bool found;
int tot_n;

void init(int n)
{
    input.clear();
    msi.clear();
    mis.clear();
    int i,j;
    for(i=0;i<=n;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            matrix[i][j] = matrix[j][i] = 0;
        }
        par[i] = i;
    }
}

int find(int r)
{
    if(r == par[r]) return r;
    return par[r] = find(par[r]);
}

void mst()
{
    sort(input.begin(),input.end(),comp);
    int i,u,v;
    for(i=0;i<input.size();i++)
    {
        u = find(input[i].a);
        v = find(input[i].b);
        if(u != v)
        {
            Union(u,v);
            matrix[ input[i].a ][ input[i].b ] = matrix[ input[i].b ][ input[i].a ] = input[i].c;
        }
    }
}

void dfs(int start,int end)
{
    if(found == true) return;
    int i;
    for(i=1;i<=tot_n;i++)
    {
        if(matrix[start][i] != 0 && col[i] == 0)
        {
            col[i] = 1;
            ances[i] = start;
            if(i == end)
            {
                found = true;
                return;
            }
            dfs(i,end);
        }
    }

}

void print(int start,int end)
{
    int i,j;
    if(start == end) return;
    print(start,ances[end]);
    cout << mis[ ances[end] ] << " " << mis[ end ] << " (" << matrix[ ances[end] ][end] << ")" << endl;
}

int main()
{
    data u;
    int que,t,test,n,m,i,j,cost,nodes,start,end;
    string node1,node2;
    t = 0;
    scanf("%d",&test);
    while(test--)
    {
        que = 0;
        scanf("%d %d",&n,&m);
        tot_n = n;
        init(n);
        nodes = 0;
        for(i=0;i<m;i++)
        {
            cin >> node1 >> node2 >> cost;
            if(msi.find(node1) == msi.end())
            {
                msi[node1] = ++nodes;
                mis[nodes] = node1;
            }
            if(msi.find(node2) == msi.end())
            {
                msi[node2] = ++nodes;
                mis[nodes] = node2;
            }
            u.a = msi[node1];
            u.b = msi[node2];
            u.c = cost;
            input.push_back(u);
        }
        printf("Case %d:\n",++t);
        mst();
        scanf("%d",&i);
        while(i--)
        {
            cin >> node1 >> node2;
            for(j=0;j<=n;j++) col[j] = ances[j] = 0;
            found = false;
            start = msi[node1];
            end = msi[node2];
            dfs(start,end);
            printf("* Query %d\n",++que);
            print(start,end);
        }
    }

    return 0;
}
