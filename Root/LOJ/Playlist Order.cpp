#include "stdio.h"
#include "string.h"
#include "math.h"

int main()
{
    int input[110] , ans[110] , t , test , n , i , j, pos , flag , cnt;
    t = 0;
    scanf("%d",&test);
    while(test--)
    {
        flag = 0;
        scanf("%d",&n);
        for(i=1;i<=n;i++) ans[i] = 0 , scanf("%d",&input[i]);
        for(i=1;i<=n;i++)
        {
            pos = input[i] + 1;
            if(pos > n || ans[pos] != 0)
            {
                flag = 1;
                break;
            }
            ans[pos] = i;
        }
        if(flag == 1)
        {
            printf("yes1\n");
            printf("Case %d: impossible\n",++t);
            continue;
        }
        for(i=1;i<=n;i++)
        {
            cnt = 0;
            for(j=i-1;j>=1;j--)
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
            printf("yes2\n");
            printf("Case %d: impossible\n",++t);
            continue;
        }
        printf("Case %d:\n",++t);
        for(i=1;i<=n;i++) printf(" %d",ans[i]);
        printf("\n");
    }

    return 0;
}
