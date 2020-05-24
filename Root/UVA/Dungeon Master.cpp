// 532 - Dungeon Master

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <queue>

#define SZ 35

using namespace std;

int l,r,c;
queue<int>Q;

char arr[SZ][SZ][SZ];

bool color[SZ][SZ][SZ];
int dist[SZ][SZ][SZ];

int x[]={0, 0, 0, 0, 1, -1};
int y[]={-1, 0, 1, 0, 0, 0};
int z[]={0, 1, 0, -1, 0, 0};

int BFS(int s1,int s2,int s3,int t1,int t2,int t3)
{
    while( !Q.empty() )
        Q.pop();
    int u,v,w,i,a,b,d,flag;
    Q.push(s1);
    Q.push(s2);
    Q.push(s3);
    color[s1][s2][s3] = 1;
    dist[s1][s2][s3] = 0;
    flag=0;

    while( !Q.empty() )
    {
        a=Q.front();
        Q.pop();
        b=Q.front();
        Q.pop();
        d=Q.front();
        Q.pop();

        for(i=0;i<6;i++)
        {
            u=a+x[i];
            v=b+y[i];
            w=d+z[i];
            if(u>=0 && v>=0 && w>=0 && u<l && v<r && w<c && color[u][v][w]==0 && (arr[u][v][w]=='.' || arr[u][v][w]=='E'))
            {
                color[u][v][w] = 1;
                Q.push(u);
                Q.push(v);
                Q.push(w);
                dist[u][v][w] = dist[a][b][d] + 1;
                if(arr[u][v][w] == 'E')
                {
                    flag=1;
                    break;
                }
            }
        }
        color[a][b][c] = 1;
        if(flag == 1)
            break;
    }
    return dist[t1][t2][t3];
}

int main()
{
    int i,j,k,s1,s2,s3,t1,t2,t3,ans;
    char ch;
    while(scanf("%d %d %d",&l,&r,&c) == 3)
    {
        if(l==0 && r==0 && c==0)
            break;

        for(i=0;i<l;i++)
            for(j=0;j<r;j++)
                for(k=0;k<c;k++)
                {
                    cin >> arr[i][j][k];
                    color[i][j][k] = 0;
                    dist[i][j][k] = -1;
                    if(arr[i][j][k] == 'S')
                    {
                        s1=i;
                        s2=j;
                        s3=k;
                    }
                    if(arr[i][j][k] == 'E')
                    {
                        t1=i;
                        t2=j;
                        t3=k;
                    }
                }
        ans=BFS(s1,s2,s3,t1,t2,t3);

        if(ans == -1)
            printf("Trapped!\n");
        else
            printf("Escaped in %d minute(s).\n",ans);
    }

    return 0;
}
