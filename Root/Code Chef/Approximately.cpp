#include "stdio.h"
#define SZ 1000010

char arr[SZ];

void SIZE()
{
    int k=0,up=103993,down=33102;
    while(k<SZ)
    {
        if(up>=down)
        {
            arr[k++] = (up/down) + '0';
            up = up % down;
        }
        else
        {
            up *= 10;
            while(up < down)
            {
                up *= 10;
                arr[k++] = '0';
            }
        }
    }
}

int main()
{
    SIZE();
    int i,n,t;
    while(scanf("%d",&t) == 1)
    {
        while(t--)
        {
            scanf("%d",&n);
            if(n == 0) printf("3\n");
            else
            {
                printf("3.");
                for(i=1;i<=n;i++) printf("%c",arr[i]);
                printf("\n");
            }
        }
    }
}
