#include "stdio.h"
#define SZ 110

bool matrix[SZ][SZ];
int cnt[SZ];

int main()
{
    int n, m, i, j, k;

    scanf("%d %d",&n,&m);

    for(i=0; i<m; i++)
    {
        scanf("%d %d",&j,&k);
        matrix[j][k] = 1;
    }

//    for(i=1; i<=n; i++)
//    {
//        for(j=1; j<=n; j++)
//            printf("%d ",matrix[i][j]);
//        printf("\n");
//    }

    for(k=1; k<=n; k++)
        for(i=1; i<=n; i++)
            for(j=1; j<=n; j++)
            {
//                printf("i j k %d %d %d\n",i,j,k);
//                if(i == 4 && j == 5 && k == 2)
//                {
//                    printf("matrix[%d][%d] = %d matrix[%d][%d] = %d\n",i,k,matrix[i][k],k,j,matrix[k][j]);
//                }
                if(matrix[i][k] & matrix[k][j])
                matrix[i][j] = 1;
            }

    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            if(matrix[i][j])
                cnt[i]++, cnt[j]++;

//     printf("\n");

//    for(i=1; i<=n; i++)
//    {
//        for(j=1; j<=n; j++)
//            printf("%d ",matrix[i][j]);
//        printf("\n");
//    }
    k = 0;
//printf("n = %d\n",n);

    for(i=1; i<=n; i++)
    {
//        printf("i = %d %d\n",i,cnt[i]);
        if(cnt[i] == n-1)
            k++;
    }

    printf("%d\n",k);

    return 0;
}
