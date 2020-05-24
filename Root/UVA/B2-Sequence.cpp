#include "stdio.h"
#include "string.h"
#include "map"
#include "iostream"

using namespace std;

map <int ,int> mii;

int arr[1012];

int main()
{
    int t=0,n,i,j,k,flag;
    while(scanf("%d",&n) == 1)
    {
        flag  = 0;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&arr[i]);
            if(arr[i] <= arr[i-1]) flag = 1;
        }
        if(flag)
        {
            printf("Case #%d: It is not a B2-Sequence.\n\n",++t);
            continue;
        }
        mii.clear();
        for(i=1;i<=n;i++)
            for(j=i;j<=n;j++)
            {
                if(mii.find( arr[i] + arr[j] ) != mii.end())
                {
                    flag = 1;
                    break;
                }
                mii[ arr[i] + arr[j] ] = 1;
            }
        if(flag == 1) printf("Case #%d: It is not a B2-Sequence.\n",++t);
        else printf("Case #%d: It is a B2-Sequence.\n",++t);
        printf("\n");
    }

    return 0;
}
