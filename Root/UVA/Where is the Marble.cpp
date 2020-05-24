            // Where is the Marble?
#include "stdio.h"
#include "string.h"
#include "algorithm"
#include "iostream"

using namespace std;

#define SZ 10010

int main()
{
    int n,q,i,j,num,test,arr[SZ];
    bool found;
//    freopen("1.txt","r",stdin);
    test = 0;
    while(scanf("%d %d",&n,&q) == 2)
    {
        if(n == 0 && q == 0)break;
        for(i=0;i<n;i++)
            scanf("%d",&arr[i]);
        sort(arr,arr+n);
        printf("CASE# %d:\n",++test);
        for(i=0;i<q;i++)
        {
            scanf("%d",&num);
            found = false;
            for(j=0;j<n;j++)
            {
                if(arr[j] == num)
                {
                    printf("%d found at %d\n",num,j+1);
                    found = true;
                    break;
                }
                if(arr[j] > num)
                    break;
            }
            if( !found )
                printf("%d not found\n",num);
        }
    }

    return 0;
}
