        //423 - MPI Maelstrom
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <climits>
#include <iostream>

using namespace std;

const int inf = 1000000000;
int matrix[110][110];
int main()
{
    int n,i,j,k,ans,num;
    char arr[100];
//    freopen("1.txt","r",stdin);
    scanf("%d",&n);
    for(i=1; i<n; i++)
    {
        for(j=0; j<i; j++)
        {
            scanf(" %s",arr);
            if(strcmp("x",arr) == 0)
                matrix[i][j] = matrix[j][i] = inf;
            else
            {
                num = atoi(arr);
                matrix[i][j] = matrix[j][i] = num;
            }
        }
        matrix[i][i] = 0;
    }

    for(k=0; k<n; k++)
        for(i=0; i<n; i++)
            for(j=0; j<n; j++)
                matrix[i][j] = min( matrix[i][j] , matrix[i][k] + matrix[k][j] );

    ans = -1;
    for(i=0; i<n; i++)
        ans = max(ans , matrix[0][i]);
    printf("%d\n",ans);

    return 0;
}
