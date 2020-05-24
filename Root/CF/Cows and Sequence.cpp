#include "stdio.h"
#include "iostream"
using namespace std;
#define SZ 200010

typedef long long ll;
ll arr[SZ],lazy[SZ];

int main()
{
    ll i,j,k,n,sum,c;
    while(cin >> c)
    {
        sum = 0;
        n = 1;
        while(c--)
        {
            cin >> k;
            if(k == 1)
            {
                cin >> i >> j;
                lazy[i] += j;
                sum += i * j;
            }
            else if(k == 2)
            {
                cin >> i;
                n++;
                arr[n] = i;
                sum += i;
            }
            else
            {
                sum -= (lazy[n] + arr[n]);
                lazy[n-1] += lazy[n];
                lazy[n] = 0;
                n--;
            }
            printf("%.10lf\n",(double)sum/(double)n);
        }
    }

    return 0;
}
