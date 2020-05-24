#include "stdio.h"
#include "string.h"
#include "math.h"

#define SZ 1010

int a[SZ] , t[SZ] , timea[SZ],timet[SZ];

int main()
{
    int te,test,n,i,flag,house;
    te = 0;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d",&n);
        for(i=0;i<=n;i++) scanf("%d",&a[i]);
        for(i=0;i<=n;i++) scanf("%d",&t[i]);

        timet[n+1] = 0;

        for(i=1;i<=n;i++) timea[i] = a[i-1] + timea[i-1];
        for(i=n;i>=0;i--) timet[i] = t[i] + timet[i+1];

        flag = 0;

        for(i=1;i<=n;i++)
        {
            if(timea[i] == timet[i])
            {
                flag = 1;
                house = i;
                break;
            }
        }

        if(flag == 0) printf("Case %d: no\n",++te);
        else printf("Case %d: yes %d\n",++te,house);
    }
    return 0;
}
