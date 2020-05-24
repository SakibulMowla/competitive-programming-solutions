#include "stdio.h"
#include "string.h"
#include "math.h"

int main()
{
    unsigned long long t,test,n,num,ans;
    char ch;
    t = 0;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%llu",&n);
        n--;
        scanf("%llu",&ans);
        while(n--)
        {
            scanf(" %c %llu",&ch,&num);
            if(ch == '+')
            {
                ans = ans + num;
            }
            else if(ch == '*')
            {
                ans = ans * num;
            }
            else if(ch == '-')
            {
                ans = ans - num;
            }
        }
        printf("Case %llu: %llu\n",++t,ans);
    }

    return 0;
}
