#include "stdio.h"
#include "math.h"

int zeroes(int n)
{
    int res = 0;
    while(n >= 5)
    {
        res += n / 5;
        n /= 5;
    }
    return res;
}

int b_search(int item)
{
    int begin , end , mid , ans;
    begin = 5 , end = 400000015;
    while(begin <= end)
    {
        mid = (begin + end) / 2;
        ans = zeroes(mid);
        if(ans == item)
            return mid;
        else if(ans > item)
            end = mid - 1;
        else
            begin = mid + 1;
    }
    return -1;
}

int main()
{
    int t,test,item,ans;
    t = 0;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d",&item);
        ans = b_search(item);
        if(ans == -1)
        {
            printf("Case %d: impossible\n",++t);
            continue;
        }
        while(zeroes(ans-1) == item) ans--;
        printf("Case %d: %d\n",++t,ans);
    }

    return 0;
}
