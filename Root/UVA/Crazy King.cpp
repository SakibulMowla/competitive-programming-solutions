#include <stdio.h>
#include <string.h>
#include <queue>
#include <iostream>

#define SZ 110

using namespace std;

bool color[SZ][SZ];
char arr[SZ][SZ];
int dist[SZ][SZ];
int m,n;

queue<int>a;
queue<int>b;

int x[]={2,2,-2,-2,-1,-1,1,1};
int y[]={1,-1,-1,1,2,-2,2,-2};

int p[]={-1,-1,-1,0,0,1,1,1};
int q[]={-1,0,1,-1,1,-1,0,1};

void BFS_knight(void)
{
    int i,j,k,l,d;
    while( !a.empty() )
    {
        i=a.front();
        a.pop();
        j=a.front();
        a.pop();
        for(d=0;d<8;d++)
        {
            k=i+x[d];
            l=j+y[d];
            if(k>=0 && l>=0 && k<m && l<n && arr[k][l]=='.')
            {
                arr[k][l]='Z';
            }
        }
    }
    return;
}

int BFS_king(int s1,int s2,int t1,int t2)
{
    int i,j,k,flag,u,v;
    while( !b.empty() )
        b.pop();
    memset(color,0,sizeof(color));
    memset(dist,-1,sizeof(dist));
    dist[s1][s2]=0;
    color[s1][s2]=1;

    b.push(s1);
    b.push(s2);
    flag=0;

    while( !b.empty() )
    {
        i=b.front();
        b.pop();
        j=b.front();
        b.pop();
        for(k=0;k<8;k++)
        {
            u=i+p[k];
            v=j+q[k];
            if(u>=0 && v>=0 && u<m && v<n && color[u][v]==0 && arr[u][v]!='Z')
            {
                color[u][v]=1;
                b.push(u);
                b.push(v);
                dist[u][v]=dist[i][j] + 1;
                if(u==t1 && v==t2)
                {
                    flag=1;
                    break;
                }
            }
        }
        if(flag==1)
            break;
    }
    return dist[t1][t2];
}

int main()
{
    int test,i,j,s1,s2,t1,t2,ans;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d %d",&m,&n);
        for(i=0;i<m;i++)
            scanf("%s",arr[i]);

        while( !a.empty() )
            a.pop();
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(arr[i][j]=='Z')
                {
                    a.push(i);
                    a.push(j);
                }
                if(arr[i][j]=='A')
                {
                    s1=i;
                    s2=j;
                }
                if(arr[i][j]=='B')
                {
                    t1=i;
                    t2=j;
                }
            }
        }
        BFS_knight();

        ans=BFS_king(s1,s2,t1,t2);
        if(ans==-1)
            printf("King Peter, you can't go now!\n");
        else
            printf("Minimal possible length of a trip is %d\n",ans);
    }

    return 0;
}
