#include "stdio.h"
#include "string.h"
#include "iostream"
using namespace std;

#define SZ 2505


int aco[SZ][SZ] , cnt[SZ];

int main()
{
    int test,i,j,k,acos,t,h,f;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d %d %d",&t,&h,&f);
        memset(aco,0,sizeof(aco));
        memset(cnt,0,sizeof(cnt));
        for(i=0;i<t;i++)
        {
            scanf("%d",&acos);
            for(j=0;j<acos;j++)
            {
                scanf("%d",&k);
                aco[i][k]++;
            }
        }
        for(i=h;i>=0;i--)
        {
            for(j=0;j<t;j++)
            {
                k = max(aco[j][i+1] , cnt[i+f]);
                aco[j][i] += k;
                if(aco[j][i] > cnt[i])
                    cnt[i] = aco[j][i];
            }
        }
        printf("%d\n",cnt[0]);
    }

    return 0;
}
