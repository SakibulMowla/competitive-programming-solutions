#include <bits/stdc++.h>

using namespace  std;

#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))

typedef long long ll;
typedef pair<ll,ll> pii;


#define SZ 1010
const ll inf = 1LL<<28;
const ll mod = 1LL;



//%I64d
int main()
{
    ll n, i, j, cnt;
    char s[110];

    while(scanf("%I64d %s",&n,s+1) == 2){
    cnt = 0;

    for(i=1;i<n;i++)
        if(s[i] == s[i+1])
            cnt++;
    printf("%I64d\n",cnt);}

    return 0;
}
