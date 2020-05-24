            //Kadane's Algorithm
#include <stdio.h>
#include <string.h>

#define SZ 110
#define dif(i,j,k) (table[i+k][j] - table[i][j])

int table[SZ][SZ];

void solve(int n)
{
    int i,j,k,sum,maxim;
    for(i=1;i<=n;i++)
        for(j=0;j<n;j++)
            table[i][j] = table[i][j] + table[i-1][j];
    maxim = table[1][0];
    for(k=1;k<=n;k++)
        for(i=0;i<=n-k;i++)
        {
            sum = 0;
            for(j=0;j<n;j++)
            {
                if(sum >=0 )
                    sum += dif(i,j,k);
                else
                    sum = dif(i,j,k);
                if(sum > maxim)
                    maxim = sum;
            }
        }
    printf("%d\n",maxim);
}

void take_input(int n)
{
    int i,j;
    for(i=1;i<=n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&table[i][j]);
}

int main()
{
    int n,i,j,k,sum,best;
    while(scanf("%d",&n) == 1)
    {
        take_input(n);
        solve(n);
    }

    return 0;
}
