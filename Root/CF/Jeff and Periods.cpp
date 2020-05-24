#include <bits/stdc++.h>

using namespace  std;

#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define X first
#define Y second

typedef long long ll;
typedef pair<int , int> pii;


#define SZ 100010
const ll inf = 1LL<<28;
const ll mod = 1LL;


vector <pii> v, ans;
map <int , int> M;

int main()
{
    int i, j, k, n, m;

    while(scanf("%d",&n) == 1)
    {
        v.clear();
        M.clear();
        ans.clear();

        for(i=0; i<n; i++)
        {
            scanf("%d",&j);
            v.push_back(MP(j,i));
            if(M.find(j) == M.end())
                M[j] = 1;
            else
                M[j]++;
        }

        stable_sort(v.begin(), v.end());

        for(i=0; i<n; i++)
        {
            if(M[ v[i].X ] == 1)
            {
                ans.push_back(MP(0, v[i].X));
            }
            else
            {
                j = v[i+1].Y - v[i].Y;

                for(k=i+2;k<n && v[k].X == v[i].X;k++)
                    if(v[k].Y - v[k-1].Y != j)
                        break;

                if(k == i + M[ v[i].X ])
                    ans.push_back( MP(j, v[i].X) );

                i += M[ v[i].X ];
                i--;
            }
        }

        printf("%d\n",sz(ans));

        k = sz(ans);

        for(i=0;i<k;i++)
            printf("%d %d\n",ans[i].Y,ans[i].X);
    }

    return 0;
}

















