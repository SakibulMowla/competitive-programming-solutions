#include "stdio.h"
#include "string.h"

int main()
{
    int arr[5][5],i=1,j,k;
    while(i==1)
    {
        for(i=1;i<=3;i++) for(j=1;j<=3;j++) scanf("%d",&arr[i][j]);
        arr[2][2] = (arr[2][1] + arr[2][3]) / 2;
        k = arr[2][1] + arr[2][2] + arr[2][3];
        if(arr[1][1] == 0) arr[1][1] = k - (arr[2][1] + arr[3][1]);
        if(arr[3][3] == 0) arr[3][3] = k - (arr[1][3] + arr[2][3]);
        if(arr[1][3] == 0) arr[1][3] = k - (arr[2][3] + arr[2][3]);
        if(arr[3][1] == 0) arr[3][1] = k - (arr[1][1] + arr[2][1]);
        for(i=1;i<=3;i++)
        {
            for(j=1;j<=3;j++) printf("%d ",arr[i][j]);
            printf("\n");
        }
    }

    return 0;
}
