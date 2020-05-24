#include "stdio.h"
#include "math.h"
#include "iostream"
using namespace std;
int main()
{
    int t=0,test,i,k,n,input[10],ans[10];
    scanf("%d",&test);
    while(test--)
    {
        ans[1] = ans[2] = ans[3] = -1<<28;
        ans[4] = ans[5] = ans[6] = 1<<28;
        scanf("%d",&n);
        while(n--)
        {
            scanf("%d%d%d%d%d%d",&input[1],&input[2],&input[3],&input[4],&input[5],&input[6]);
            ans[1] = max(ans[1],input[1]);
            ans[2] = max(ans[2],input[2]);
            ans[3] = max(ans[3],input[3]);
            ans[4] = min(ans[4],input[4]);
            ans[5] = min(ans[5],input[5]);
            ans[6] = min(ans[6],input[6]);
        }
        k = (ans[4]-ans[1]) * (ans[5]-ans[2]) * (ans[6]-ans[3]);
        printf("Case %d: %d\n",++t,k);
    }

    return 0;
}
