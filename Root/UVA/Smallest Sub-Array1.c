#include <stdio.h>
#include <string.h>
#include <math.h>

#define N 1000000+10
#define M 1000+10

int sub[N],pos[M],nextPos[N];
int freq[M];

int main()
{
    int t,i,j,res,n,m,k,count,left,right;
    scanf("%d",&t);
    for(i=0; i<t; i++)
    {
        scanf("%d %d %d",&n,&m,&k);
        sub[0]=1;
        sub[1]=2;
        sub[2]=3;
        for(j=3; j<n; j++)
            sub[j]=(sub[j-1] + sub[j-2] + sub[j-3]) % m + 1;

        memset(pos,-1,sizeof(pos));

        for(j=n-1; j>=0; j--)
        {
            nextPos[j]=pos[sub[j]];
            pos[sub[j]]=j;
        }

        memset(freq,0,sizeof(freq));
        count=0;
        left=0;
        right=-1;

        for(j=0; j<n; j++)
        {
            if(sub[j]<=k && !freq[sub[j]])
            {
                freq[sub[j]]=1;
                count++;
            }
            if(count==k)
            {
                right=j;
                break;
            }
        }
        if(right==-1)
        {
            printf("Case %d: sequence nai\n",i+1);
            continue;
        }

        res=right-left+1;
        while(left<right)
        {
            if(sub[left]>k)
                left++;
            else if(nextPos[left]==-1) break;
            else if(nextPos[left]<=right)
                left++;
            else
            {
                right=nextPos[left];
                left++;
            }
            if(res > right-left+1)
                res= right-left+1;
        }

        printf("Case %d: %d\n",i+1,res);
    }
    return 0;
}
