#include "stdio.h"
#include "string.h"
#include "iostream"

using namespace std;

#define SZ 10010

bool dp[SZ];
int koyta[36];
int used[SZ];
int mark[SZ];
int col[SZ];
int coin[] = {0, 1, 5, 10, 25};

int main()
{
    int i, j, k, n, price;

    while(scanf("%d %d %d %d %d",&price,&koyta[1],&koyta[2],&koyta[3],&koyta[4]) == 5)
    {
        if(price == 0 && koyta[1] == 0 && koyta[2] == 0 && koyta[3] == 0 && koyta[4] == 0)
            break;
        for(i=0; i<=price; i++)
        {
            dp[i] = 0;
            used[i] = 0;
        }
        dp[0] = 1;
        for(i=1; i<=4; i++)
        {
//            printf("i = %d %d %d\n",i,coin[i],koyta[i]);
            memset(col, 0, sizeof(int)*(price+2));
            for(j=coin[i]; j<=price /*&& dp[j-coin[i]] && used[j] <= used[ j-coin[i] ] + 1 && col[j-coin[i]] < koyta[i]*/; j++)
            {
                if(dp[j-coin[i]] && used[j] <= used[ j-coin[i] ] + 1 && col[j-coin[i]] < koyta[i])
                {
//                    if(i == 2)
//                    {
//                        printf("j = %d used[j] = %d used[j-coin[i]] = %d\n", j, used[j], used[j-coin[i]] );
//                    }
                    dp[j] = 1;
                    used[j] = used[ j-coin[i] ] + 1;
                    mark[j] = coin[i];
                    col[j] = col[ j-coin[i] ] + 1;
                }

            }
        }
        koyta[1] = koyta[5] = koyta[10] = koyta[25] = 0;
//        printf("uesd = %d\n",used[12]);
        if(dp[price])
        {
            while(price != 0)
            {
//                printf("prce = %d\n",price);
                koyta[ mark[price] ]++;
                price -= mark[price];
            }
            printf("Throw in %d cents, %d nickels, %d dimes, and %d quarters.\n",koyta[1],koyta[5],koyta[10],koyta[25]);
        }
        else
            printf("Charlie cannot buy coffee.\n");
    }

    return 0;
}
