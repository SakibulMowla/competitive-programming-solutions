#include <stdio.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <iostream>

using namespace std;

#define SZ 310
#define FOR(a,b) for(a=0;a<b;a++)

const int inf = 1000000000;

struct data
{
    int x,y,jump;
};

queue <data> q;
char arr[SZ][SZ] ;
int dist[SZ][SZ][4] ;
int row,col;

int p[] = {-1,1,0,0};
int q1[] = {0,0,-1,1};

void BFS(int s1,int s2,int t1,int t2) // s = start && t = target
{
    int a,b,c,d,e,f,i,k,j;
    data u,v;
    u.x = s1;
    u.y = s2;
    u.jump = 1;
    q.push(u);
    dist[s1][s2][3] = 0;

    while( !q.empty() )
    {
        v = q.front();
        q.pop();
        FOR(i,4)
        {
            a = v.x + p[i];
            b = v.y + q1[i];
            c = v.x + p[i]*2;
            d = v.y + q1[i]*2;
            e = v.x + p[i]*3;
            f = v.y + q1[i]*3;
            if(v.jump == 1 )
            {
                if(a>=0 && b>=0 && a<row && b<col && dist[a][b][1] == -1 && arr[a][b] != '#')
                {
                    u.x = a;
                    u.y = b;
                    u.jump = 2;
                    q.push(u);
                    dist[a][b][1] = dist[v.x][v.y][3] + 1;
                }
            }
            else if(v.jump == 2)
            {
                if(c>=0 && d>=0 && c<row && d<col && dist[c][d][2] == -1 && arr[c][d] != '#' && arr[a][b] != '#')
                {
                    u.x = c;
                    u.y = d;
                    u.jump = 3;
                    q.push(u);
                    dist[c][d][2] = dist[v.x][v.y][1] + 1;
                }
            }
            else if(v.jump == 3)
            {
                if(e>=0 && f>=0 && e<row && f<col && dist[e][f][3] == -1  && arr[e][f] != '#' && arr[c][d] != '#' && arr[a][b] != '#')
                {
                    u.x = e;
                    u.y = f;
                    u.jump = 1;
                    q.push(u);
                    dist[e][f][3] = dist[v.x][v.y][2] + 1;
                }
            }
        }
    }

}

int main()
{
    int test,i,j,k,s1,s2,t1,t2,ans,a,b,c;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d %d",&row,&col);
        FOR(i,row)FOR(j,col)FOR(k,4)dist[i][j][k] = -1;
        FOR(i,row)FOR(j,col)
        {
            scanf(" %c",&arr[i][j]);
            if(arr[i][j] == 'S')
                s1 = i , s2 = j;
            if(arr[i][j] == 'E')
                t1 = i , t2 = j;
        }
        BFS(s1 , s2 , t1 , t2);
        ans = inf;
        a = dist[t1][t2][1];
        b = dist[t1][t2][2];
        c = dist[t1][t2][3];
        if(a > 0)
            ans = min( a , ans );
        if(b > 0)
            ans = min( b , ans );
        if(c > 0)
            ans = min( c , ans );
        if(ans == inf)
            printf("NO\n");
        else
            printf("%d\n",ans);

        while( !q.empty() )
            q.pop();
    }

    return 0;
}
