#include "stdio.h"
#include "string.h"

int cnt[12];

int main()
{
    int i,j,k,n,sum;
    while(scanf("%d",&n) == 1)
    {
        sum = 0;
        memset(cnt,0,sizeof(cnt));
        for(i=0; i<n; i++)
            scanf("%d",&j) , cnt[j]++ , sum += j;
        sum %= 3;
        if(cnt[0] == 0)
        {
            printf("-1\n");
            continue;
        }
        if(cnt[0] == n)
        {
            printf("0\n");
            continue;
        }
        if(sum == 1)
        {
            if(cnt[1]) cnt[1]--;
            else if(cnt[4]) cnt[4]--;
            else if(cnt[7]) cnt[7]--;
            else if(cnt[2] >= 2) cnt[2] -= 2;
            else if(cnt[5] && cnt[2] ) cnt[5]-- , cnt[2]--;
            else if(cnt[3] >= 1 && cnt[2] >= 2) cnt[2] -= 2 , cnt[3]--;
            else
            {
                printf("-1\n");
                return 0;
            }
        }
        else if(sum == 2)
        {
            if(cnt[2]) cnt[2]--;
            else if(cnt[5]) cnt[5]--;
            else if(cnt[8]) cnt[8]--;
            else if(cnt[1] >= 2) cnt[1] -= 2;
            else if(cnt[4] && cnt[1]) cnt[4]-- , cnt[1]--;
            else if(cnt[4] >= 2) cnt[4] -= 2;
            else if(cnt[7] && cnt[1]) cnt[7]-- , cnt[1]--;
            else if(cnt[1] >= 2 && cnt[3]) cnt[3]-- , cnt[1] -= 2;
            else if(cnt[3] && cnt[4] && cnt[1]) cnt[3]-- , cnt[4]-- , cnt[1]--;
            else if(cnt[6] && cnt[1] >= 2) cnt[1] -= 2 , cnt[6]--;
            else if(cnt[3] >= 2 && cnt[1] >= 2) cnt[3] -= 2 , cnt[1] -= 2;
            else if(cnt[1] >= 5) cnt[1] -= 5;
            else if(cnt[1] >= 4 && cnt[4] ) cnt[4]-- , cnt[1] -= 4;
            else if(cnt[1] >= 5 && cnt[3]) cnt[3]-- , cnt[1] -= 5;
            else if(cnt[1] >= 8) cnt[1] -= 8;
            else
            {
                printf("-1\n");
                return 0;
            }
        }
        if((cnt[1] || cnt[2] || cnt[3] || cnt[4] || cnt[5] || cnt[6] || cnt[7] || cnt[8] || cnt[9]) == 0)
            printf("0\n");
        else
            for(i=9; i>=0; i--)
                for(j=cnt[i]; j>0; j--)
                    printf("%d",i);
        printf("\n");
    }

    return 0;
}


#include<iostream>
using namespace std;
int n,d[10],a,sum;

int main()
{
    while(cin>>n)
    {
        while(n--) cin>>a,++d[a],sum+=a;
        if(sum%3)for(int i=1; i<10; ++i)if(i%3==sum%3 && d[i])--d[i], sum-=i,i=10;
        for(n=0; n<2; ++n)for(int i=1; i<10; ++i)if(sum%3 && i%3 && d[i])--d[i], sum-=i,i=10;
        if(!sum) d[0]=1;
        if(!d[0] || sum%3) cout<<-1;
        else for(int i=9; i>=0; --i)while(d[i]--)cout<<i;
    }
}
