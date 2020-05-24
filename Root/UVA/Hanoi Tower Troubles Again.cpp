#include "stdio.h"
#include "string.h"
#include "math.h"

int ans[55] , top[55];

void pregenerate()
{
    int i,j,k,peg,num,cnt,now_peg;
    double d;
    cnt  = 1;
    for(peg = 1; peg<=50 ; peg++)
    {
        for(now_peg = 1; now_peg<=peg; )
        {
            d = sqrt(top[now_peg] + cnt);
            if(top[now_peg] == 0)
                top[now_peg] = cnt , cnt++ , now_peg = 1;
            else if(d == (int)d)
                top[now_peg] = cnt , cnt++ , now_peg = 1;
            else
                now_peg++;
        }
        ans[peg] = cnt-1;
    }
}

int main()
{
    memset(top,0,sizeof(top));
    pregenerate();
    int test,n;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d",&n);
        printf("%d\n",ans[n]);
    }

    return 0;
}
