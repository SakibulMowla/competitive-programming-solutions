#include "stdio.h"
#include "map"
#include "iostream"

using namespace std;

map <int , int> M;

int arr[100010];

int main()
{
    int i,j,k,n;
    while(scanf("%d %d",&n,&k) == 2)
    {
        M.clear();
        for(i=1;i<=n;i++)
        {
            scanf("%d",&arr[i]);
            M[arr[i]] = 1;
            if(M.size() == k)
            {
                M.clear();
                j = i;
                while(j >= 1)
                {
                    M[arr[j]] = 1;
                    if(M.size() == k)
                        break;
                    j--;
                }
                printf("%d %d\n",j,i);
                return 0;
            }
        }
        printf("-1 -1\n");
        return 0;
    }

    return 0;
}
