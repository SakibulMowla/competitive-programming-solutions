#include <stdio.h>
#include <string.h>
#include <math.h>

#define N 1000000+10
#define M 1000+10

int n,m,k,sub[N],pos[M],nextPos[N];
int freq[M];

void sub_array(void)
{
    int a,b,c,i;
    sub[1]=1;
    sub[2]=2;
    sub[3]=3;
    for(i=4;i<=n;i++)
        sub[i]=(sub[i-1] + sub[i-2] + sub[i-3]) % m + 1;
    return;
}

int main()
{
    int t,i,j,res;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d %d %d",&n,&m,&k);
        sub_array();

        memset(pos,-1,sizeof(pos));

        for(j=n-1;j>=0;j--)
        {
            nextPos[i]=pos[sub[i]];
            pos[sub[i]]=i;
        }

        memset(freq,0,sizeof(freq));
        int count=0;
        int left=0;
        int right=-1;

        for(j=0;j<n;j++)
        {
            if(sub[j]<=k && !freq[sub[i]])
            {
                freq[sub[i]]=1;
                count++;
            }
            if(count==k)
            {
                right=i;
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
                res=right-left+1;
        }

        printf("Case %d: %d\n",i+1,res);
    }
    return 0;
}
