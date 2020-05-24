#include <stdio.h>
#include <string.h>
#include <math.h>

#define inf 1<<28

int main()
{
    int n,v,t,ans;
    double ano;

    while(scanf("%d",&n) == 1 && n)
    {
        ans = inf;
        while(n--)
        {
            scanf("%d %d",&v,&t);
            if(t>=0)
            {
                ano = 4500 / (v * 10.0 / 36.0);
                if(ano - (int)ano > 0.0) ano++;
                ano += t;

                if(ano < ans) ans = ano;
            }
        }
        printf("%d\n",ans);
    }

    return 0;
}
