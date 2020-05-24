#include "stdio.h"
#include "string.h"
#include "string"
#include "vector"
#include "stack"
#include "map"
#include "iostream"

using namespace std;

#define SZ 30

vector <int> edge[SZ];
int indx[SZ] , low[SZ] , cnt;
bool visited[SZ];
stack <int> stk;
map <string , int> msi;
map <int , string> mis;

void init(int n)
{
    int i;
    cnt = 0;
    mis.clear();
    msi.clear();
    for(i=0; i<=n; i++)
    {
        edge[i].clear();
        indx[i] = -1;
        low[i] = -1;
        visited[i] = false;
    }
    while( !stk.empty() ) stk.pop();
}

void tarjan(int n)
{
    indx[n] = low[n] = cnt++;
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
        {
            low[n] = min(low[n] , low[j]);
        }
    }
    if(low[n] == indx[n])
    {
        j = -1;
        i= 0;
        while(j != n)
        {
            j = stk.top();
            stk.pop();
            visited[j] = false;
            if(i) printf(", ");
            i = 1;
            cout << mis[ j ];
        }
        printf("\n");
    }
}

int main()
{
    int i,k,n,m,t = 0;
    string s1 , s2;
    bool blank = false;
//    freopen("1.txt","r",stdin);
    while(scanf("%d %d",&n,&m) == 2 && (n+m))
    {
        if(blank) printf("\n");
        blank = true;
        init(n);
        k = 0;
        for(i=0; i<m; i++)
        {
            cin >> s1 >> s2;
            if(msi.find(s1) == msi.end())
            {
                msi[s1] = ++k;
                mis[k] = s1;
            }
            if(msi.find(s2) == msi.end())
            {
                msi[s2] = ++k;
                mis[k] = s2;
            }
            edge[ msi[s1] ].push_back(msi[s2]);
        }
        printf("Calling circles for data set %d:\n",++t);
        for(i=1;i<=k;i++)
        {
            if(indx[i] == -1)
                tarjan(i);
        }
    }


    return 0;
}
