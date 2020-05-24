#include "stdio.h"
#include "string.h"
#include "vector"
#include "iostream"
#include "algorithm"
using namespace std;
int r,c,cnt;
vector <int> v;
char arr[55][55];
int x[] = {-1,1,0,0};
int y[] = {0,0,-1,1};

void dfs1(int n,int m)
{
    arr[n][m] = '*';
    int i,p,q;
    for(i=0;i<4;i++)
    {
        p = n + x[i];
        q = m + y[i];
        if(p>=0 && q>=0 && p<r && q<c && arr[p][q]=='X')
            dfs1(p,q);
    }
}

void dfs(int n,int m)
{
    int i,p,q;
    if(arr[n][m] == 'X')
    {
        cnt++;
        dfs1(n,m);
    }
    arr[n][m] = '.';
    for(i=0;i<4;i++)
    {
        p = n + x[i];
        q = m + y[i];
        if(p>=0 && q>=0 && p<r && q<c && arr[p][q]!='.')
            dfs(p,q);
    }
}

int main()
{
    int i,j,test=0;
//    freopen("1.txt","r",stdin);
    while(scanf("%d %d",&c,&r) == 2 && c && r)
    {
        v.clear();
        for(i=0; i<r; i++)
            scanf(" %s",arr[i]);
        for(i=0; i<r; i++)
            for(j=0; j<c; j++)
                if(arr[i][j] != '.')
                {
                    cnt = 0;
                    dfs(i,j);
                    v.push_back(cnt);
                }
        sort(v.begin(),v.end());
        printf("Throw %d\n",++test);
        cout<<v[0];
        for(i=1;i<v.size();i++)
            cout << " " << v[i];
        printf("\n\n");
    }

    return 0;
}
