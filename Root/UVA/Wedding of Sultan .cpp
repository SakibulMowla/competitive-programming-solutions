#include <stdio.h>
#include <string.h>

int cnt[300];
char arr[1000];

int n,pos;

void dfs(int enter)
{
    pos++;
    for(; pos<n; pos++)
    {
        if(arr[pos] == arr[enter])
        {
            cnt[arr[pos]]++;
            return;
        }
        cnt[arr[enter]]++;
        dfs(pos);
    }
}

int main()
{
    int i,t=0,test;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%s",arr);
        n = strlen(arr);
        pos = 0;
        memset(cnt,0,sizeof(cnt));
        dfs(0);
        cnt[arr[0]]--;
        printf("Case %d\n",++t);
        for(i='A'; i<='Z'; i++)
            if(cnt[i]>=1)
                printf("%c = %d\n",i,cnt[i]);
    }

    return 0;
}
