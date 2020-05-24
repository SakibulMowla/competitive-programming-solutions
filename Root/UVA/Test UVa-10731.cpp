#include "stdio.h"
#include "string.h"
#include "string"
#include "vector"
#include "stack"
#include "map"
#include "iostream"
#include "algorithm"

using namespace std;

#define SZ 30

typedef vector <int> vi;
vector <vi> vii(SZ);
vector <string> ans;
int indx[SZ] , low[SZ] , cnt;
bool visited[SZ] , valid[SZ];
stack <int> stk;

void init()
{
    int i;
    cnt = 0;
    ans.clear();
    for(i=0;i<SZ;i++)
    {
        vii[i].clear();
        indx[i] = -1;
        low[i] = 0;
        visited[i] = false;
        valid[i] = 0;
    }
}

void tarjan(int n)
{
    low[n] = indx[n] = ++cnt;
    stk.push(n);
    visited[n] = true;
    int i,j;
    for(i=0;i<vii[n].size();i++)
    {
        j = vii[n][i];
        if(indx[j] == -1)
        {
            tarjan(j);
            low[n] = min(low[n] , low[j]);
        }
        else if(visited[j] == true)
            low[n] = min(low[n] , low[j]);
    }
    if(low[n] == indx[n])
    {
        string str;
        j = -1;
        while(j != n)
        {
            j = stk.top();
            stk.pop();
            visited[j] = false;
            str += j + 'A';
        }
        sort(str.begin(),str.end());
        ans.push_back(str);
    }
}

int main()
{
    char arr[6],ch;
    int n,m,i,j,k=0;
    while(scanf("%d",&n) == 1 && n)
    {
        if(k) printf("\n");
        k = 1;
        init();
        for(i=0;i<n;i++)
        {
            for(j=0;j<5;j++) scanf(" %c",&arr[j]) , valid[arr[j]-'A'] = 1;
            scanf(" %c",&ch);
            for(j=0;j<5;j++) vii[ch-'A'].push_back(arr[j]-'A');
        }
        for(i=0;i<26;i++)
            if(valid[i] == 1 && indx[i] == -1)
                tarjan(i);
        sort(ans.begin(),ans.end());
        for(i=0;i<ans.size();i++)
        {
            for(j=0;j<ans[i].size();j++)
            {
                if(j) printf(" ");
                printf("%c",ans[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}
