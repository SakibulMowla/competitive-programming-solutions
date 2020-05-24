#include <stdio.h>
#include <string>
#include <map>
#include <iostream>

using namespace  std;

typedef long long ll;

#define SZ 1000100

ll cumu[SZ];
map <ll , ll> M , faltu;

int main()
{
    ll n,m,i,j,k,ans,x,y,p,q;
    string s;
    while(cin >> k >> s)
    {
        m = j = s.size();
        ans = 0;
        if(k == 0)
        {
            for(i=0; i<j; i++)
                if(s[i] == '0')
                {
                    p=0;
                    do
                    {
                        p++;
                        i++;
                    }
                    while(i<j && s[i] == '0');
                    ans += (p*(p+1)) / 2;
                }
            printf("%lld\n",ans);
            return 0;
        }
        M[0] = faltu[0] = 0LL ;
        for(i=0; i<j; i++)
        {
            cumu[i+1] = cumu[i] + s[i] - '0';
            if(M.find(cumu[i+1]) == M.end())
                M[ cumu[i+1] ] = i + 1;
            faltu[ cumu[i+1] ] = i + 1;
        }
        for(i=1; i<=m; i++)
        {
            if(cumu[i] >= k && s[i-1] == '1')
            {
                p = q = 0;
                j = cumu[i] - k;
                x = M[j];
                y = faltu[j];
                p = y - x;
                y = faltu[cumu[i]];
                q = y-i;
                ans += 1 + p + q + (p * q);
            }
        }
        cout << ans << "\n";
    }

    return 0;
}
