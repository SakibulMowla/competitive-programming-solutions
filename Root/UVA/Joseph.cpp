#include <stdio.h>
#include <string.h>

int joseph[15];

int main()
{
    int i,j,k,l,n,m,new_n,dead;
    while(scanf("%d",&n) == 1 && n)
    {
        if(joseph[n])
        {
            printf("%d\n",joseph[n]);
            continue;
        }

        k = 2 * n;
        for (m=n; ; m++)
        {
            new_n = k;
            dead = (m-1) % new_n;
            while(dead>=n && new_n>=n)
            {
                new_n--;
                dead = (dead-1+m) % new_n;
            }
            if(new_n == n)
            {
                joseph[n] = m;
                break;
            }
        }
        printf("%d\n",m);
    }

    return 0;
}
