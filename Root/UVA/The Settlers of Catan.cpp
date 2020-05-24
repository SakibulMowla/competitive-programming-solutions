//using macro to find max value for this problem gives verdict time limit ........mysterious!!!!!!!!!!!!!!
#include <stdio.h>
#include <string.h>
#include <iostream>

#define mem(a,b) memset(a,b,sizeof(a))
//#define max(a,b) a > b ? a : b
using namespace std;
int matrix[26][26] , used[26][26];
int nodes;

int dfs(int n)
{
    int i,path=0;
    for(i=0;i<nodes;i++)
    {
        if(matrix[n][i] && !used[n][i])
        {
            used[n][i] = used[i][n] = 1;
            path = max(path , dfs(i) + 1);
            used[n][i] = used[i][n] = 0;
        }
    }
    return path;
}

int main()
{
    int n,m,i,a,b,maxim;
    while(scanf("%d %d",&n,&m) == 2)
    {
        if(n==0 && m==0)break;
        nodes = n;
        mem(matrix,0);
        mem(used,0);
        for(i=0;i<m;i++)
        {
            scanf("%d %d",&a,&b);
            matrix[a][b] = matrix[b][a] = 1;
        }

        maxim = 0;
        for(i=0;i<n;i++)
            maxim = max(maxim , dfs(i));

        printf("%d\n",maxim);
    }

    return 0;
}
