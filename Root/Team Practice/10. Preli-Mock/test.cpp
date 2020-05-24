#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int test, match;
    char c[5001], g;
    register int t, next, i, ok, x, j, cnt;

    scanf("%d",&test);
    for (t=1 ; t<=test ; t++)
    {
        next = 1;
        cnt = 0;
        scanf("%d\n",&match);

        for (i=1 ; i<=match ; i++)
        {
            scanf("%c%c",&c[i],&g);

            if (i%3==0 && next==1 && i>=3)
            {
                ok = 0;
                for (j=i-2 ; j<=i ; j++)
                {
                    cnt++;
                    if (c[j]=='W')
                    {
                        ok = 1;
                    }
                }
                if (!ok) next = 0;
            }
        }
        x = match%3;
        if (x!=0 && next ==1)
        {
            ok = 0;
            for (j=match ; j>=match-x+1 ; j--)
            {
                if (c[j]=='W')
                {
                    ok = 1;
                }
            }
            cnt = cnt + x;
        }
        if (ok!=1) next = 0;
        if (next==1 && cnt==match)
            printf("Case %d: Yay! Mighty Rafa persists!\n",t);
        else
        {
// if (cnt%3!=0) cnt = cnt + (3-(cnt%3));
            printf("Case %d: %d\n",t,cnt);
        }
    }
    return 0;
}
