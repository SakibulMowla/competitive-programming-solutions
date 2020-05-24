#include "stdio.h"
#include "string.h"

char arr[20010];

int main()
{
    char *str;
    int test,pre,now,cnt,maxcnt;
    scanf("%d",&test);
    while(test--)
    {
        scanf(" %[^\n]",arr);
        str = strtok(arr," '\t''\r'");
        pre = cnt = maxcnt = 0;
        while(str)
        {

            now = strlen(str);
            if(now == pre)
            {
                cnt++;
            }
            else
            {
                if(cnt > maxcnt)
                    maxcnt = cnt;
                cnt = 1;
            }
            pre = now;
            str = strtok(NULL," '\t''\r'");
        }
        if(cnt > maxcnt)
            maxcnt = cnt;
        printf("%d\n",maxcnt);
    }

    return 0;
}
