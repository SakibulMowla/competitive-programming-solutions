#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>
#include <queue>
#include <cmath>
#include <iostream>

using namespace std;

#define SZ 205
#define FOR(a,b) for(a=1;a<=b;a++)
#define mem(a,b) memset(a,b,sizeof(a))
#define clear(a) a.clear()
#define pb push_back

const int inf = 1000000000;
double matrix[SZ][SZ];
int n;
struct data{int a,b;};

void floyd_warshall()
{
    int i,j,k;
    FOR(k,n)FOR(i,n)FOR(j,n){matrix[i][j] = min(matrix[i][j] , max(matrix[i][k] , matrix[k][j]));}
    return;
}

int main()
{
    data arr[SZ];
    int i,j,test;
    double dist;
    test = 0;
    while(scanf("%d",&n) == 1 && n)
    {
        for(i=1;i<=n;i++)
            scanf("%d %d",&arr[i].a,&arr[i].b);
        FOR(i,n)FOR(j,n)matrix[i][j] = i==j ? 0 : inf;
        FOR(i,n-1)
            for(j=i+1;j<=n;j++)
            {
                dist = sqrt(pow((arr[i].a-arr[j].a),2) + pow((arr[i].b-arr[j].b),2));
                matrix[i][j] = matrix[j][i] = dist;
            }
        floyd_warshall();
        printf("Scenario #%d\n",++test);
        printf("Frog Distance = %.3lf\n\n",matrix[1][2]);
    }

    return 0;
}
