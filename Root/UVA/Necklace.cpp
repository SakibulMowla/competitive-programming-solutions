#include <stdio.h>
#include <math.h>

int main()
{
    int i,p,q,ans;
    double best,tmp,part;
    while(scanf("%d %d",&p,&q) == 2)
    {
        if(p == 0 && q == 0)break;
        ans = 0;
        best = 0;
        for(i=1;i<=p;i++)
        {
            part = (double)p/i;
            if(part > 0)
                tmp = .3*sqrt(part - q)*i;
            else
                break;
            if(fabs(tmp - best) < 1e-12)
            {
                ans = 0;
                break;
            }
            if(tmp > best)
            {
                best = tmp;
                ans = i;
            }
            else if(tmp < best)
                break;
        }
        printf("%d\n",ans);
    }

    return 0;
}
