#include <stdio.h>
#include <string.h>

int main()
{
    bool high[20],low[20];
    char arr[30],z;
    int num,flag,i;
    memset(high,0,sizeof(high));
    memset(low,0,sizeof(low));
    while(scanf("%d%c",&num,&z) == 2)
    {
        if(num==0)break;
        gets(arr);
        if(strcmp(arr,"too high") == 0)
            high[num]=1;
        else if(strcmp(arr,"too low") == 0)
            low[num]=1;
        else if(strcmp(arr,"right on") == 0)
        {
            flag=0;
            for(i=1;i<=10;i++)
            {
                if(high[i] == 1 && num >= i)
                    flag=1;
            }
            for(i=1;i<=10;i++)
            {
                if(low[i] == 1 && num <= i)
                    flag=1;
            }
            if(flag==1)
                printf("Stan is dishonest\n");
            else if(flag==0)
                printf("Stan may be honest\n");
            memset(high,0,sizeof(high));
            memset(low,0,sizeof(low));
            flag=0;
        }
    }

    return 0;
}
