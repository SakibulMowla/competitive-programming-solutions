#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;


#define SZ 10000000000LL

ll arr[130];
ll valid[15];
ll n;

bool chk(ll num)
{
    while(num)
    {
        if(!valid[num%10]) return false;
        num /= 10;
    }
    return true;
}


int main()
{
    valid[0] = valid[1] = valid[4] = valid[9] = 1;
    ll t, i, k, a, b;

    for(i=0;;i++)
    {
        if(i*i > SZ) break;
        if(chk(i*i))
            arr[n++] = i*i;
    }

    scanf("%lld",&t);

    while(t--)
    {
        k = 0;
        scanf("%lld %lld",&a,&b);
        for(i=0;i<121;i++)
            if(arr[i] >= a && arr[i] <= b)
                k++;
        printf("%lld\n",k);
    }

    return 0;
}



