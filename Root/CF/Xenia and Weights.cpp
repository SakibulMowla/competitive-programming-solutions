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

int m;
bool found;
int num[12], cur;
char arr[12];
vector <int> ans;

void solve(int left,int riht,int last,int indx)
{
//    printf("indx = %d\n",indx);
    if(found) return;
    if(indx == m)
    {
        int i, k;
        k = sz(ans);
        printf("YES\n");
        for(i=0;i<k;i++)
            printf("%d ",ans[i]);
        printf("\n");
        found = true;
        return;
    }
    int i;
    for(i=1;i<=10;i++)
    {
        if(i == last || arr[i] == '0') continue;
        if(indx%2)
        {
            if(left + i > riht)
            {
                ans.push_back(i);
                solve(left+i, riht, i, indx+1);
                ans.pop_back();
            }
        }
        else
        {
            if(riht + i > left)
            {
                ans.push_back(i);
                solve(left, riht+i, i, indx+1);
                ans.pop_back();
            }
        }
    }
}

//%I64d
int main()
{
    int i, j, k;

    while(scanf("%s",arr+1) == 1)
    {
        ans.clear();
        found = false;
        scanf("%d",&m);
        solve(0, 0, 0, 0);
        if(!found)
            printf("NO\n");
    }

    return 0;
}
