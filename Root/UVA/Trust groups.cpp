#include "stdio.h"
#include "string.h"
#include "string"
#include "vector"
#include "map"
#include "stack"
#include "iostream"

using namespace std;

#define SZ 1010

vector <int> edge[SZ];
bool visited[SZ];
int indx[SZ] , low[SZ] , cnt , scccnt;
map <string , int> msi;
stack <int> stk;

void init(int n)
{
    int i;
    msi.clear();
    cnt = scccnt = 0;
    for(i=0;i<=n;i++)
    {
        edge[i].clear();
        indx[i] = -1;
        low[i] = 0;
        visited[i] = false;
    }
}

void tarjan(int n)
{
    low[n] = indx[n] = ++cnt;
    visited[n] = true;
    stk.push(n);
    int i,j;
    for(i=0;i<edge[n].size();i++)
    {
        j = edge[n][i];
        if(indx[j] == -1)
        {
            tarjan(j);
            low[n] = min(low[n] , low[j]);
        }
        else if(visited[j] == true)
            low[n] = min(low[n] , low[j]);
    }
    if(indx[n] == low[n])
    {
        scccnt++;
        j = -1;
        while(j != n)
        {
            j = stk.top();
            stk.pop();
            visited[j] = false;
        }
    }
}

int main()
{
    int n,m,i,j,k,p;
    char str1[100],str2[100];
    while(scanf("%d %d",&n,&m) == 2 && (n+m))
    {
        init(n);
        k = 0;
        for(i=0;i<n;i++)
        {
            scanf(" %[^\n]",str1);
            if(msi.find(str1) == msi.end())
                msi[str1] = k++;
        }
        for(i=0;i<m;i++)
        {
            scanf(" %[^\n] %[^\n]",str1,str2);
            j = msi[str1] , p = msi[str2];
            edge[j].push_back(p);
        }
        for(i=0;i<k;i++)
            if(indx[i] == -1)
                tarjan(i);
        printf("%d\n",scccnt);
    }

    return 0;
}
