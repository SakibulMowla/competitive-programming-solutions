#include "bits/stdc++.h"
using namespace std;

#define SZ 100010

double dp[SZ];

double solve(int num)
{
    double &ret = dp[num];

    if(ret != -1) return ret;
    if(num == 1) return ret = 0;

    int i, k = 0;
    ret = 0;

    for(i=1; i*i < num; i++)
        if(num % i == 0)
        {
            ret += solve(i);
            if(i != 1) ret += solve(num/i);
            k += 2;
        }

    if(i*i == num)
        k++, ret += solve(i);

    ret += k;
    ret /= (k-1);

    return ret;
}

//inline void read (int &n)
//{
//    n = 0;
//    int i = getchar_unlocked();
//
//    while (i < '0' || i > '9')
//        i = getchar_unlocked();
//
//    while (i >= '0' && i <= '9')
//    {
//        n = (n << 3) + (n << 1) + i - '0';
//        i = getchar_unlocked();
//    }
//}
//

int main()
{
    int test=0, t, i;

    for(i=1; i<=100000; i++)
        dp[i] = -1;

//    read(t);
    scanf("%d", &t);

    while(t--)
    {
//        read(i);
        scanf("%d", &i);
        printf("Case %d: %lf\n",++test,solve(i));
    }

    return 0;
}
