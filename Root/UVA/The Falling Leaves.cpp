// 699 - The Falling Leaves
#include <stdio.h>
#include <string.h>

#define SZ 50
int left[SZ] , right[SZ];

void input(int n)
{
    int val;
    scanf("%d",&val);
    if(val != -1)
    {
        if(n > 0)
            right[n] += val;
        else
            left[-n] += val;
        input(n-1);
        input(n+1);
    }
}

void solve(int val)
{
    memset(left,0,sizeof(left));
    memset(right,0,sizeof(right));
    left[0] = val;
    input(-1);
    input(1);
    int i,n;
    for(i=SZ;i>=0 && !left[i] ;i--);
    for( ;i>=1;i--)
        printf("%d ",left[i]);
    printf("%d",left[0]);
    for(n=SZ;n>=0 && !right[n];n--);
    for(i=1;i<=n;i++)
        printf(" %d",right[i]);
    printf("\n\n");
}


int main()
{
    int val,test=0,i,n;
    while(scanf("%d",&val)==1 && val!=-1)
    {
        printf("Case %d:\n",++test);
        solve(val);
    }
    return 0;
}
