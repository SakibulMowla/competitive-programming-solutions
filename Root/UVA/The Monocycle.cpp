#include "stdio.h"
#include "string.h"
#include "queue"
#include "iostream"
using namespace std;
#define SZ 30

int rr , c , dist[SZ][SZ][6][5] ,s11 , s2 , t1 , t2;
queue <int> Q;
char arr[SZ][SZ];

void doitforgodssake(int p1,int q1,int r1,int s1,int p,int q,int r,int s)
{
    if(p1 >= 0 && q1 >= 0 && p1 < rr && q1 < c && dist[p1][q1][r1][s1] == 00 && arr[p1][q1] != '#')
    {
        dist[p1][q1][r1][s1] = dist[p][q][r][s] + 1;
        Q.push(p1) , Q.push(q1) , Q.push(r1) , Q.push(s1) ;
    }
}

int BFS()
{
    while(!Q.empty()) Q.pop();
    int p,q,r,s,p1,q1,r1,s1;
    dist[s11][s2][0][0] = 0;
    Q.push(s11) , Q.push(s2) , Q.push(0) , Q.push(0);
    while(!Q.empty())
    {
        p = Q.front() ; Q.pop() ; q = Q.front() ; Q.pop() ; r = Q.front() ; Q.pop() ; s = Q.front() ; Q.pop() ;
        if(p == t1 && q == t2 && r == 0) return dist[p][q][r][s];
        if(s == 0)
        {
            p1 = p-1 , q1 = q , r1 = (r+1)%5 , s1 = s;
            doitforgodssake(p1,q1,r1,s1,p,q,r,s);
            doitforgodssake(p,q,r,(s+1)%4,p,q,r,s);
            doitforgodssake(p,q,r,(s+3)%4,p,q,r,s);
        }
        else if(s == 1)
        {
            p1 = p , q1 = q+1 , r1 = (r+1)%5 , s1 = s;
            doitforgodssake(p1,q1,r1,s1,p,q,r,s);
            doitforgodssake(p,q,r,(s+1)%4,p,q,r,s);
            doitforgodssake(p,q,r,(s+3)%4,p,q,r,s);
        }
        else if(s == 2)
        {
            p1 = p+1 , q1 = q , r1 = (r+1)%5 , s1 = s;
            doitforgodssake(p1,q1,r1,s1,p,q,r,s);
            doitforgodssake(p,q,r,(s+1)%4,p,q,r,s);
            doitforgodssake(p,q,r,(s+3)%4,p,q,r,s);
        }
        else if(s == 3)
        {
            p1 = p , q1 = q-1 , r1 = (r+1)%5 , s1 = s;
            doitforgodssake(p1,q1,r1,s1,p,q,r,s);
            doitforgodssake(p,q,r,(s+1)%4,p,q,r,s);
            doitforgodssake(p,q,r,(s+3)%4,p,q,r,s);
        }
    }
    return 0;
}

int main()
{
    int i,j,k,l,t=0;
    while(scanf("%d %d",&rr,&c) == 2)
    {
        if(rr == 0 and c == 0) break;
        if(t) printf("\n");
        for(i=0;i<rr;i++)
            for(j=0;j<c;j++)
            {
                scanf(" %c",&arr[i][j]);
                if(arr[i][j] == 'S')
                    s11 = i , s2 = j;
                if(arr[i][j] == 'T')
                    t1 = i , t2 = j;
                for(k=0;k<6;k++) for(l=0;l<5;l++) dist[i][j][k][l] = 0;
            }
        printf("Case #%d\n",++t);
        i = BFS();
        if(i) printf("minimum time = %d sec\n",i);
        else printf("destination not reachable\n");
    }

    return 0;
}
