#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

const ll mod = 1000000007LL;

#define SZ  100010

char s[SZ];

int main() {
    int t, i, j, k, lvl;
    ll ans;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%s",s);
        k = strlen(s);

        lvl = 1; ///level 1 means odd level, 0 means even level
        ans = 1;

        for(i = 0; i < k; i++)
        {
            ans *= 2;
            if(lvl)
            {
                if(s[i] == 'r') ans += 2;
            }
            else
            {
                if(s[i] == 'l') ans--;
                else ans++;
            }

            ans = (ans + mod) % mod;

            lvl ^= 1;
        }

        printf("%lld\n",ans);
    }

    return 0;
}














