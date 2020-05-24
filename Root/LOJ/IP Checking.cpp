#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int b[5] , d[5] , t , test , i ;
    char arr[200] , z;
    t = 0;
    scanf("%d",&test);
    while(test--)
    {
        for(i=0;i<5;i++) d[i] = b[i] = 0;
        scanf("%s",&arr);

        for(i=0;arr[i]!='.';i++) b[0] = (b[0] * 10) + arr[i] - '0';
        i++;
        for(;arr[i]!='.';i++) b[1] = (b[1] * 10) + arr[i] - '0';
        i++;
        for(;arr[i]!='.';i++) b[2] = (b[2] * 10) + arr[i] - '0';
        i++;
        for(;arr[i];i++) b[3] = (b[3] * 10) + arr[i] - '0';

        for(i=0;i<8;i++)
        {
            scanf(" %c",&z);
            if(z == '1')
            d[0] += pow(2,7-i);
        }
        scanf(" %c",&z);
        for(i=0;i<8;i++)
        {
            scanf(" %c",&z);
            if(z == '1')
            d[1] += pow(2,7-i);
        }
        scanf(" %c",&z);
        for(i=0;i<8;i++)
        {
            scanf(" %c",&z);
            if(z == '1')
            d[2] += pow(2,7-i);
        }
        scanf(" %c",&z);
        for(i=0;i<8;i++)
        {
            scanf(" %c",&z);
            if(z == '1')
            d[3] += pow(2,7-i);
        }

        if(d[0]==b[0] && d[1]==b[1] && d[2]==b[2] && d[3]==b[3]) printf("Case %d: Yes\n",++t);
        else printf("Case %d: No\n",++t);
    }

    return 0;
}
