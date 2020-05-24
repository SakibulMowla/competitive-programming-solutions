#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

#define FOR(a,b) for(a=1;a<=b;a++)
#define mem(a,b) memset(a,b,sizeof(a))
#define clear(a) a.clear()
#define SZ 205

int matrix[SZ][SZ];
int n,r;

void floyd_warshall()
{
    int i,j,k;
    FOR(k,n)FOR(i,n)FOR(j,n){ matrix[i][j] = max( matrix[i][j] , min( matrix[i][k] , matrix[k][j] ) ); }
}

int main()
{
    int i,j,k,l,nodes,cost,ans,test;
    char node1[35],node2[35];
    map<string , int> m;
    test = 0;
    while(scanf("%d %d",&n,&r) == 2)
    {
        if(n==0 && r==0)break;
        FOR(i,n)FOR(j,n)matrix[i][j] = i==j ? 0 : -1;
        clear(m);
        nodes = 0;
        FOR(i,r)
        {
            scanf(" %s %s %d",node1,node2,&cost);
            if(m.find(node1) == m.end())m[node1] = ++nodes;
            if(m.find(node2) == m.end())m[node2] = ++nodes;
            matrix[m[node1]][m[node2]] = matrix[m[node2]][m[node1]] = cost;
        }
        floyd_warshall();
        scanf(" %s %s",node1,node2);
        ans = matrix[m[node1]][m[node2]];
        printf("Scenario #%d\n",++test);
        printf("%d tons\n\n",ans);
    }

    return 0;
}
