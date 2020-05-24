using namespace std;

#include "stdio.h"
#include "map"
#include "iostream"

#define SZ 200010

typedef long long ll;

ll arr[SZ];
map <ll , ll> M;
map <ll , ll>::iterator it;

int main()
{
    ll n, m, i, j, two, ans;

    while(scanf("%I64d",&n) == 1)
    {
        M.clear();
        two = 0;

        for(i=1;i<=2*n;i++)
        {
            scanf("%I64d",&arr[i]);
            if(M.find(arr[i]) == M.end()) M[ arr[i] ] = 1;
            else M[ arr[i] ]++;

            if(i > n && arr[i] == arr[i-n]) two++;
        }

        scanf("%I64d",&m);
        ans = 1;

        for(it=M.begin();it!=M.end();it++)
        {
            for(i=1;i<=it->second;i++)
            {
                j = i;
                while(two && j%2==0) j /= 2, two--;
                ans = (ans * j) % m;
            }
        }

        printf("%I64d\n",ans);
    }

    return 0;
}
