#include "stdio.h"
#include "string.h"
#include "iostream"
#include "algorithm"

using namespace std;

#define SZ 15

struct data
{
    int num, deg;
};

data arr[SZ];
int matrix[SZ][SZ];

bool comp(data p,data q)
{
    return p.deg > q.deg;
}

int main()
{
    int t, n, i, j, k, f, odd, zero;

    scanf("%d",&t);

    while(t--)
    {
        memset(matrix, 0, sizeof(matrix));
        f = 1;
        odd = 0;
        scanf("%d",&n);
        for(i=1; i<=n; i++)
        {
            scanf("%d",&arr[i].deg);
            arr[i].num = i;
            if(arr[i].deg >= n)
                f = 0;
            odd += arr[i].deg % 2;
        }
        if(odd%2)
            f = 0;
        if(f)
        {
            for(i=1; i<=n; i++)
            {
                sort(arr+i,arr+n+1,comp);
                zero = 1;
//                printf("i = %d\n",i);
                for(j=i; j<=n; j++)
                {
//                    printf("%d ",arr[j].deg);
                    if(arr[j].deg < 0)
                    {
                        f = 0;
                        goto here;
                    }
                    if(arr[i].deg != 0)
                        zero = 0;
                }
//                printf("\n");
                if(zero)
                    goto here;
                k = arr[i].deg;
                for(j=i+1; k ; j++,k--)
                {
                    matrix[ arr[i].num ][ arr[j].num ] = matrix[ arr[j].num ][ arr[i].num ] = 1;
                    arr[j].deg--;
                }
            }
        }
here:
        ;
        if(!f)
            printf("NO\n");
        else
        {
            printf("YES\n");
            for(i=1; i<=n; i++)
            {
                for(j=1; j<=n; j++)
                {
                    if(j > 1)   printf(" ");
                    printf("%d",matrix[i][j]);
                }
                printf("\n");
            }
        }
        if(t)
            printf("\n");
    }

    return 0;
}
