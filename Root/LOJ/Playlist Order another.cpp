#include "stdio.h"
#include "string.h"
#include "math.h"

int main()
{
    int input[110] , ans[110] , t , test , n , i , j, pos , flag , cnt , v;
    t = 0;
    scanf("%d",&test);
    while(test--)
    {
        flag = 0;
        scanf("%d",&n);
        for(i=1; i<=n; i++) ans[i] = 0 , scanf("%d",&input[i]);
        for(i=1; i<=n; i++)
        {
            pos = input[i] + 1;
            if(pos > n )
            {
                flag = 1;
                break;
            }
            if(ans[pos] != 0)
            {
                v = pos;
                while(++pos <= n)
                {
                    if(ans[pos] == 0)
                        break;
                }
            }
            if(pos > n)
            {
                while(--v >= 0)
                {
                    if(ans[v] == 0)
                    {
                        pos = v;
                        break;
                    }
                }
                if(v < 0)
                {
                    flag = 1;
                    break;
                }
            }
            ans[pos] = i;
        }
        if(flag == 1)
        {
            printf("Case %d: impossible\n",++t);
            continue;
        }
        for(i=1; i<=n; i++)
        {
            cnt = 0;
            for(j=i-1; j>=1; j--)
            {
                if(ans[j] > ans[i])
                    cnt++;
            }
            if(ans[i] == 0 || cnt != input[ans[i]])
            {
                flag = 1;
                break;
            }
        }
        if(flag == 1)
        {
            printf("Case %d: impossible\n",++t);
            continue;
        }
        printf("Case %d:",++t);
        for(i=1; i<=n; i++) printf(" %d",ans[i]);
        printf("\n");
    }

    return 0;
}
