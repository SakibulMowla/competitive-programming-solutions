using namespace std;

#include "stdio.h"
#include "string.h"
#include "vector"
#include "iostream"

#define MAX 65
#define MAX1 3210

typedef long long ll;

struct data
{
    ll vol, impo, tag, child[3];
    data()
    {
        child[0] = child[1] = -1;
    }
};

data input[MAX];
ll dp[MAX][MAX1] , n;

ll solve(ll indx,ll space)
{
//    printf("%lld %lld\n",indx, space);

    ll &ret = dp[indx][space];

    if(indx == n) return ret = 0;
    if(ret != -1) return ret;

    ll cal , cal1, cal2, now, now1, now2, ch1, ch2;
    ret = 0;

    if(!input[indx].tag && space - input[indx].vol >= 0)
    {
        cal = input[indx].vol * input[indx].impo * 10LL;
        now = space-input[indx].vol;
        ret = max(ret , cal + solve(indx+1 , now));

        ch1 = input[indx].child[0];
        ch2 = input[indx].child[1];

        if(ch1 != -1)
        {
            if(now - input[ch1].vol >= 0)
            {
                cal1 = input[ch1].vol * input[ch1].impo * 10LL;
                now1 = space - input[indx].vol - input[ch1].vol;
                ret = max(ret , cal + cal1 + solve(indx+1 , now1));
            }
        }

        if(ch2 != -1)
        {
            if(now - input[ch2].vol >= 0)
            {
                cal2 = input[ch2].vol * input[ch2].impo * 10LL;
                now2 = space - input[indx].vol - input[ch2].vol;
                ret = max(ret , cal + cal2 + solve(indx+1 , now2));
            }
        }

        if(ch1 != -1 && ch2 != -1)
        {
            if(now - input[ch1].vol - input[ch2].vol >= 0)
            {
//                printf("yes\n");
                now1 = space - input[indx].vol - input[ch1].vol - input[ch2].vol;
                cal1 = (input[ch1].vol * input[ch1].impo * 10LL) + (input[ch2].vol * input[ch2].impo * 10LL);
                ret = max(ret , cal + cal1 + solve(indx+1 , now1));
            }
        }
    }

    ret = max(ret , solve(indx+1 , space));

    return ret;
}

int main()
{
    ll t, i, j, space, mark;

    scanf("%lld", &t);

    while(t--)
    {
        scanf("%lld %lld",&space, &n);

        space /= 10;

        for(i=0;i<=n;i++)
            input[i] = data();

        for(i=0;i<n;i++)
        {
            scanf("%lld %lld %lld", &input[i].vol, &input[i].impo, &mark);

            input[i].vol /= 10;
            input[i].tag = mark;

            if(mark)
            {
                mark--;
                if(input[mark].child[0] == -1) input[mark].child[0] = i;
                else input[mark].child[1] = i;
            }
        }

        for(i=0;i<=n;i++)
            for(j=0;j<=space;j++)
                dp[i][j] = -1;

        printf("%lld\n", solve(0,space));
    }

    return 0;
}
