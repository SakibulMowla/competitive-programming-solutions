#include "stdio.h"
#include "vector"
#include "iostream"
#include "algorithm"

std::vector <int> V;

int main()
{
    int t=0, test, i, j, k, n, m, q;

    scanf("%d",&test);

    while(test--)
    {
        scanf("%d %d",&n,&q);
        V.clear();
        for(i=0; i<n; i++)
        {
            scanf("%d",&m);
            V.push_back(m);
        }
        std::vector <int>:: iterator low, up;
        printf("Case %d:\n",++t);
        while(q--)
        {
            scanf("%d %d",&j,&k);
            low = lower_bound(V.begin(),V.end(),j);
            up = upper_bound(V.begin(),V.end(),k);
            printf("%d\n", (up-V.begin()) - (low-V.begin()) );
        }
    }

    return 0;
}
