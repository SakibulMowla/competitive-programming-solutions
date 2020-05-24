#include "stdio.h"
#include "string.h"
#include "queue"
#include "iostream"
using namespace std;
int dist[100][100];
bool color[100][100];
queue <int> q;
int x[] = {2,2,-2,-2,1,1,-1,-1};
int y[] = {-1,1,-1,1,-2,2,-2,2};

int BFS(int s1,int s2,int t1,int t2)
{
    memset(color,0,sizeof(color));
    while( !q.empty() )q.pop();
    int i,u,v,p,q1;
    dist[s1][s2] = 0;
    color[s1][s2] = 1;
    q.push(s1);
    q.push(s2);
    while( !q.empty() )
    {
        u = q.front();
        q.pop();
        v = q.front();
        q.pop();
        for(i=0;i<8;i++)
        {
            p = u + x[i];
            q1 = v + y[i];
            if(p>=1 && q1>=1 && p<=8 && q1<=8 && !color[p][q1])
            {
                color[p][q1] = 1;
                dist[p][q1] = dist[u][v] + 1;
                q.push(p);
                q.push(q1);
                if(t1 == p && t2 == q1)
                    return dist[p][q1];
            }
        }
    }
    return dist[t1][t2];
}

int main()
{
    int ans,s1,s2,t1,t2;
    char a[3],b[3];
//    freopen("1.txt","r",stdin);
    while(scanf(" %s %s",a,b) == 2)
    {
        s1 = a[0] - 'a' + 1;
        s2 = a[1] - '0';
        t1 = b[0] - 'a' + 1;
        t2 = b[1] - '0';
        ans = BFS(s1,s2,t1,t2);
        printf("To get from %s to %s takes %d knight moves.\n",a,b,ans);
    }

    return 0;
}
