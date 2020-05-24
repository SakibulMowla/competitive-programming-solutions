#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <iostream>
#include <climits>

using namespace std;

#define inf 1<<28
#define oo INT_MAX
#define FOR(a,b) for(a=1;a<=b;a++)

int main()
{
    int test,i,j,k,n,f,matrix[510][510],fs[110],good[510],best;
    char arr[100];
//    freopen("1.txt","r",stdin);
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d %d",&f,&n);
        FOR(i,f)scanf("%d",&fs[i]);
        FOR(i,n)
        {
            for(j=i+1; j<=n; j++)
                matrix[i][j] = matrix[j][i] = inf;
            matrix[i][i] = 0;
        }
        getchar();
        while(gets(arr))
        {
            if(strcmp(arr,"\0") == 0)break;
            sscanf(arr,"%d %d %d",&i,&j,&k);
            matrix[i][j] = matrix[j][i] = k;
        }
        FOR(k,n)FOR(i,n)FOR(j,n) matrix[i][j] = min(matrix[i][j] , matrix[i][k] + matrix[k][j]);

        FOR(i,n)good[i] = inf;
        FOR(i,n)
            FOR(j,f)
                good[i] = min(good[i] , matrix[fs[j]][i]);
        best = inf;
        f = 1;
        FOR(i,n)
        {
            k = 0;
            FOR(j,n)
                k = max(k , min(good[j],matrix[i][j]));
            if(k < best)
            {
                best = k;
                f = i;
            }
        }
        printf("%d\n",f);
        if(test) printf("\n");
    }
    return 0;
}
