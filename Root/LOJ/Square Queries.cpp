using namespace std;

#include "stdio.h"
#include "iostream"
#define SZ 510

typedef long long ll;
const ll inf = (1LL<<28);

ll tree[SZ][3*SZ] , mat[SZ][SZ];

void build(ll row,ll b,ll e,ll node)
{
//    printf("b = %lld e = %lld\n",b,e);
    if(b == e)
    {
        tree[row][node] = mat[row][b];
        return;
    }

    ll mid = (b + e) >> 1;
    build(row, b, mid, node<<1);
    build(row, mid+1, e, (node<<1) + 1);

    tree[row][node] = max(tree[row][node<<1] , tree[row][(node<<1)+1]);
}

ll query(ll row,ll b,ll e,ll node,ll f,ll t)
{
    if(e<f || b>t) return -inf;
    if(b>=f && e<=t) return tree[row][node];

    ll ret = -inf , mid = (b + e) >> 1;

    if(mid >= f) ret = max(ret , query(row, b, mid, node<<1, f, t));
    if(mid < t) ret = max(ret , query(row, mid+1, e, (node<<1)+1, f, t));

    return ret;
}

int main()
{
    ll t=0,test,n,m,i,j,I,J,S,ans;

    scanf("%lld",&test);

    while(test--)
    {
        scanf("%lld %lld",&n,&m);

        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                scanf("%lld",&mat[i][j]);
        for(i=1;i<=n;i++)
            build(i,1,n,1);

        printf("Case %lld:\n",++t);

        while(m--)
        {
            scanf("%lld %lld %lld",&I,&J,&S);

            ans = -inf;

            for(i=I;i<=I+S-1;i++)
                ans = max(ans , query(i, 1, n, 1, J, J+S-1));

            printf("%lld\n",ans);
        }
    }

    return 0;
}
