#include <stdio.h>
#include <string.h>

int main()
{
    int i,j,n,k,t,test,ans;
    char arr[510];
    scanf("%d",&test);
    for(t=1;t<=test;t++)
    {
        scanf("%d %d %s",&n,&k,arr);
        ans = 0;
        for(i=1;i<n;i++)
        {
            for(j=i-1;j>=0 && i-j <= k ;j--)
            {
                if(arr[j] == arr[i])
                {
                    ans++;
                    break;
                }
            }
        }
        printf("Case %d: %d\n",t,ans);
    }

    return 0;
}
