#include<stdio.h>
#include<string.h>

int f[27][27][352];
int L, S;
int main()
{
    int t = 0;
    int i, j, k;
    f[0][0][0] = 1;
    for(i = 1; i <= 26; i ++)
        for(j = 0; j <= i; j ++)
            for(k = 0; k <= 351; k ++)
            {
                f[i][j][k] = f[i - 1][j][k];
                if(j && k >= i)
                    f[i][j][k] += f[i - 1][j - 1][k - i];
            }
    for(;;)
    {
        inp(L);inp(S);
        if(!L && !S)
            break;
        printf("Case %d: ", ++ t);
        if(L > 26 || S > 351)
            printf("0\n");
        else
            printf("%d\n", f[26][L][S]);
    }
    return 0;
}
