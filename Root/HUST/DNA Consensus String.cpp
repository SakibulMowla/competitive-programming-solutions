#include "stdio.h"
#include "string.h"

int cnt[300];
char arr[55][1010] , ans[1010];

int main()
{
    int i,j,k,t,n,m,dis;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        for(i=0;i<n;i++) scanf("%s",arr[i]);
        dis = 0;
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                cnt[arr[j][i]]++;
            }
            k = 0;
            if(cnt['A'] > k) k = cnt['A'] , ans[i] = 'A';
            if(cnt['C'] > k) k = cnt['C'] , ans[i] = 'C';
            if(cnt['G'] > k) k = cnt['G'] , ans[i] = 'G';
            if(cnt['T'] > k) k = cnt['T'] , ans[i] = 'T';
            dis += n - k;
            cnt['A'] = 0;
            cnt['C'] = 0;
            cnt['G'] = 0;
            cnt['T'] = 0;
        }
        ans[m] = '\0';
        printf("%s\n%d\n",ans,dis);
    }

    return 0;
}
