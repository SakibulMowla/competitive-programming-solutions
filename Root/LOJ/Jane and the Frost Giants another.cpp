#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <iostream>

#define SZ 205

using namespace std;

int r,c;
char arr[SZ][SZ];
queue<int>q;
int dist[SZ][SZ];

int x[]={-1,1,0,0};
int y[]={0,0,-1,1};

int BFS(void)
{
    int i,p,t,a,b;

    while( !q.empty() )
    {
        a = q.front();
        q.pop();
        b = q.front();
        q.pop();
        if(arr[a][b] == 'J')
        {
            for(i=0;i<4;i++)
            {
                p = a + x[i];
                t = b + y[i];
                if(p>=0 && t>=0 && p<r && t<c && arr[p][t]=='.')
                {
                    arr[p][t] = 'J';
                    dist[p][t] = dist[a][b] + 1;
                    q.push(p);
                    q.push(t);
                }
                if(p<0 || t<0 || p>=r || t>=c)
                    return dist[a][b] + 1;
            }
        }

        else if(arr[a][b] == 'F')
        {
            for(i=0;i<4;i++)
            {
                p = a + x[i];
                t = b + y[i];
                if(p>=0 && t>=0 && p<r && t<c && (arr[p][t]=='.' || arr[p][t]=='J'))
                {
                    arr[p][t] = 'F';
                    q.push(p);
                    q.push(t);
                }
            }
        }
    }


    return -1;
}

int main()
{
    int test,i,j,ans,Case;
    scanf("%d",&test);
    Case = 0;
    while(test--)
    {
        scanf("%d %d",&r,&c);
        for(i=0;i<r;i++)
            scanf("%s",arr[i]);
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                if(arr[i][j] == 'J' || arr[i][j] == 'F')
                {
                    q.push(i);
                    q.push(j);
                }
            }
        }
        memset(dist,0,sizeof(dist));
        ans = BFS();
        if(ans == -1)
            printf("Case %d: IMPOSSIBLE\n",++Case);
        else
            printf("Case %d: %d\n",++Case,ans);

        while( !q.empty() )
            q.pop();
    }

    return 0;
}
