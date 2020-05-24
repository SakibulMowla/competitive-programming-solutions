#include "stdio.h"
#include "string.h"
#include "iostream"

using namespace std;

#define SZ 100010
#define SZ1 235

int arr[SZ];
int pre[SZ1];


int main()
{
    int t, n, q, i, j;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d %d",&n,&q);

        for(i=0;i<n;i++)
            scanf("%d",&arr[i]);

        memset(pre, -1, sizeof(pre));

        while(q--)
        {
            scanf("%d",&j);
            if(pre[j] == -1)
            {
                for(i=0;i<n;i++)
                    pre[j] = max(pre[j], arr[i]&j);
            }
            printf("%d\n",pre[j]);
        }
    }

    return 0;
}








