#include "stdio.h"
#include "stdbool.h"

bool arr[26];

int main()
{
    int i,j,k,n,m,clock,anti,p;
    while(scanf("%d %d %d",&n,&m,&k) == 3 && (n + m + k))
    {
        p = n;
        for(i=0;i<=n;i++) arr[i] = 0;
        clock = 0;
        anti = n-1;
        while(n)
        {
            i = clock;
            j = 0;
            while(j != m)
            {
                if(!arr[i]) j++;
                if(j == m) {clock = i ; break;}
                i++;
                i %= p;
            }
            printf("%3d",i+1);
            n--;
            if(n)
            {
                i = anti;
                j = 0;
                while(j != k)
                {
                    if(!arr[i]) j++;
                    if(j == k) {anti = i , arr[i] = 1;break;}
                    i--;
                    i += p;
                    i %= p;
                }
                if(i == p)
                {
                    i++;
                    i %= n;
                    printf("yes\n");
                }
                if(i != clock)
                {
                    printf("%3d",i+1);
                    n--;
                }
            }
            arr[clock] = 1;
            if(n) printf(",");
        }
        printf("\n");
    }

    return 0;
}
