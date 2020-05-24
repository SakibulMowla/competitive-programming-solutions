#include <stdio.h>
#include <string.h>

int main()
{
    int test,pos,i,t=0,num[110];
    char arr[110];
    freopen("1.txt","r",stdin);
    scanf("%d",&test);
    while(test--)
    {
        memset(num,0,sizeof(num));
        pos = 0;
        scanf("%s",arr);
        for(pos=0;pos < strlen(arr);)
        {
            if(arr[pos] == '>') pos++ , pos %= 100;
            else if(arr[pos] == '<') pos-- , pos = (pos+100) %100;
            else if(arr[pos] == '+') num[pos]++;
            else if(arr[pos] == '-') num[pos]--;
        }
        printf("Case %d:",++t);
        for(i=0;i<100;i++)
            printf(" %02X",num[i]);
        printf("\n");
    }

    return 0;
}
