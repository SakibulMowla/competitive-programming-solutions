#include "stdio.h"
#include "map"
#include "vector"
#include "iostream"

using namespace std;

map <int , int> M;

int main()
{
    int i, j, t, n, beg, ans;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d",&n);

        M.clear();
        beg = 0;
        ans = 0;

        for(i=1;i<=n;i++)
        {
            scanf("%d",&j);
            if(M.find(j) == M.end() || M[j] < beg)
                M[j] = i;
            else
            {
                ans = max(ans, i-beg-1);
//                printf("ans = %d\n",ans);
                beg = M[j];
                M[j] = i;
            }
        }

//        printf("beg = %d\n",beg);

        ans = max(ans, n - beg);

        printf("%d\n",ans);
    }

    return 0;
}
