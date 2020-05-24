#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

#define SZ 110
#define FOR(a,b) for(a=1;a<=b;a++)

const int inf = 1000000000;

int nodes , matrix[SZ][SZ];
map <int , int> m;

void floyd_warshall()
{
    int i,j,k;
    FOR(k,nodes)FOR(i,nodes)FOR(j,nodes){matrix[i][j] = min(matrix[i][j] , matrix[i][k] + matrix[k][j]);}
    return;
}

int main()
{
    int i,j,node1,node2,sum_dist,test;
    double avg;
    test = 0;
    while(scanf("%d %d",&node1,&node2) == 2)
    {
        if(node1 == 0 && node2 == 0)break;
        nodes = 0;
        m.clear();
        FOR(i,SZ-1)FOR(j,SZ-1)matrix[i][j] = i==j ? 0 : inf;
        if(m.find(node1) == m.end())m[node1] = ++nodes;
        if(m.find(node2) == m.end())m[node2] = ++nodes;
        matrix[m[node1]][m[node2]] = 1;
        while(scanf("%d %d",&node1,&node2) == 2)
        {
            if(node1 == 0 && node2 == 0)break;
            if(m.find(node1) == m.end())m[node1] = ++nodes;
            if(m.find(node2) == m.end())m[node2] = ++nodes;
            matrix[m[node1]][m[node2]] = 1;
        }
        floyd_warshall();
        sum_dist = 0;
        FOR(i,nodes)
            for(j=i+1;j<=nodes;j++)
                sum_dist += matrix[i][j] + matrix[j][i];
        avg = sum_dist*1.0/(nodes*(nodes-1));
        printf("Case %d: average length between pages = %.3lf clicks\n",++test,avg);
    }

    return 0;
}
