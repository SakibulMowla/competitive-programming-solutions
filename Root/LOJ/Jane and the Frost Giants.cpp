#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

char arr[220][220];
queue <int> Q;
queue <int> FQ;
int dist[220][220];
int r,c;


int x[]= {-1,1,0,0};
int y[]= {0,0,-1,1};

int BFS(int start1,int start2)
{
    memset(dist,-1,sizeof(dist));
    Q.push(start1);
    Q.push(start2);

    dist[start1][start2] = 1;
    arr[start1][start2] = '#';

    if(start1 == 0 || start1 == r || start2 == 0 || start2 == c)
        return dist[start1][start2];

    int i,u,v,p,q;
    while( !Q.empty() )
    {
        if( !FQ.empty() )
        {
            u=FQ.front();
            FQ.pop();
            v=FQ.front();
            FQ.pop();
            for(i=0; i<4; i++)
            {
                p = x[i] + u;
                q = y[i] + v;
                if(p>=0 && q>=0 && p<r && q<c && arr[p][q]!='F')
                {
                    FQ.push(p);
                    FQ.push(q);
                    arr[p][q] = 'F';
                }
            }
        }

        u = Q.front();
        Q.pop();
        v = Q.front();
        Q.pop();

        for(i=0; i<4; i++)
        {
            p = x[i] + u;
            q = y[i] + v;
            if(p>=0 && q>=0 && p<r && q<c && arr[p][q]=='.')
            {
                Q.push(p);
                Q.push(q);
                arr[p][q] = '#';
                dist[p][q] = dist[u][v] + 1;
                if(p == 0 || p == r || q == 0 || q == c)
                    return dist[p][q];
            }
        }
    }

    return -1;
}


int main()
{
    int i,j,k,l,test,t,start1,start2,ans;
    scanf("%d",&test);
    for(t=1; t<=test; t++)
    {
        scanf("%d %d",&r,&c);
        for(i=0; i<r; i++)
            scanf("%s",arr[i]);

        while( !Q.empty() )
            Q.pop();
        while( !FQ.empty() )
            FQ.pop();

        for(i=0; i<r; i++)
        {
            for(j=0; j<c; j++)
            {
                if(arr[i][j] == 'J')
                {
                    start1=i;
                    start2=j;
                }
                if(arr[i][j] == 'F')
                {
                    FQ.push(i);
                    FQ.push(j);
                }
            }
        }
        ans = BFS(start1,start2);
        if(ans == -1)
            printf("Case %d: IMPOSSIBLE\n",t);
        else
            printf("Case %d: %d\n",t,ans);
    }

    return 0;
}
