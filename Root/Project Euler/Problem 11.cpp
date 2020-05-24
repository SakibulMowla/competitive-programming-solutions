#include <stdio.h>

#define SZ 20

int arr[SZ+2][SZ+2];

int main()
{
    int i,j,k,n,m,maxim;
    for(i=1;i<=SZ;i++)
        for(j=1;j<=SZ;j++)
            scanf("%d",&arr[i][j]);
    maxim = 0;
    for(i=1;i<=SZ;i++)
    {
        for(j=1;j<=SZ;j++)
        {
            if(j+3 <= 20)
            {
                k = arr[i][j] * arr[i][j+1] * arr[i][j+2] * arr[i][j+3];
            }
            if(k > maxim) maxim = k;

            if(i+3 <= 20)
            {
                k = arr[i][j] * arr[i+1][j] * arr[i+2][j] * arr[i+3][j];
            }
            if(k > maxim) maxim = k;

            if(j-3 >= 1)
            {
                k = arr[i][j] * arr[i][j-1] * arr[i][j-2] * arr[i][j-3];
            }
            if(k > maxim) maxim = k;

            if(i-3 >= 1)
            {
                k = arr[i][j] * arr[i-1][j] * arr[i-2][j] * arr[i-3][j];
            }
            if(k > maxim) maxim = k;

            if(i+3 <=20 && j+3 <= 20)
            {
                k = arr[i][j] * arr[i+1][j+1] * arr[i+2][j+2] * arr[i+3][j+3];
            }
            if(k > maxim) maxim = k;

            if(i+3 <=20 && j-3 >= 1)
            {
                k = arr[i][j] * arr[i+1][j-1] * arr[i+2][j-2] * arr[i+3][j-3];
            }
            if(k > maxim) maxim = k;

            if(i-3 >=1 && j+3 <= 20)
            {
                k = arr[i][j] * arr[i-1][j+1] * arr[i-2][j+2] * arr[i-3][j+3];
            }
            if(k > maxim) maxim = k;

            if(i-3 >=1 && j-3 >= 1)
            {
                k = arr[i][j] * arr[i-1][j-1] * arr[i-2][j-2] * arr[i-3][j-3];
            }
            if(k > maxim) maxim = k;
        }


    }

    printf("%d\n",maxim);

    return 0;
}
