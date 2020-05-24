#include "bits/stdc++.h"
using namespace std;

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

int main()
{
//    freopen("1.txt","r",stdin);
//    freopen("2.txt","w",stdout);
    int t, i, j, k, n;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d",&i);
        scanf("%d",&j);
        n = __gcd(i, j);
        k = 0;
        for(j=1; j*j<n; j++)
        {
            if(n % j == 0)
                k += 2;
        }
        if(j*j == n)
            k++;
        printf("%d\n",k);
    }

    return 0;
}
