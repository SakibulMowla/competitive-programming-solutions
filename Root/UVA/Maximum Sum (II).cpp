#include <stdio.h>

int main()
{
    int n,num,print,blank;
    while(scanf("%d",&n) == 1 && n)
    {
        blank = print = 0;
        while(n--)
        {
            scanf("%d",&num);
            if(num > 0)
            {
                if(blank) printf(" ");
                printf("%d",num);
                print = blank = 1;
            }
        }
        if( !print )printf("0");
        printf("\n");
    }

    return 0;
}
