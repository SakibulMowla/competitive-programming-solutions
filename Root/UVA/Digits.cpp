#include <stdio.h>
#include <string.h>

int cnt;
char arr[1000010];

void recursion(int n)
{
    cnt++;
    int len;
    len = sprintf(arr,"%d",n);
    if(len == n)return;
    recursion(len);
}

int main()
{
    while(scanf("%s",arr) == 1)
    {
        if(strcmp(arr,"END") == 0)break;
        if(strcmp(arr,"1") == 0)
        {
            printf("1\n");
            continue;
        }
        cnt = 1;
        recursion(strlen(arr));
        printf("%d\n",cnt);
    }

    return 0;
}
