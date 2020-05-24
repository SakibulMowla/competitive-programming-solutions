#include "stdio.h"
#include "string.h"
#include "vector"
#include "map"
#include "iostream"

using namespace std;

#define SZ 110
#define SZ1 100010

map <string , int> M;
vector <int> num[SZ];

bool col[SZ1];
char str[SZ];

int solve(vector <int> &V)
{
    int i, j, k, maxim;

    k = V.size();
    maxim = 0;
    memset(col, 0, sizeof(bool)*(k*1000+2));
    col[0] = 1;

    for(i=0; i<k; i++)
    {
        for(j=maxim; j>=0; j--)
        {
            if(col[j])
                col[j+V[i]] = 1;
        }
        maxim += V[i];
    }

    for(i=maxim/2; i>=0; i--)
        if(col[i])
            return (maxim-i);

    return 0;
}

int main()
{
    int n, m, i, k, ans;

    while(scanf("%d %d",&m,&n) && (m+n))
    {
        M.clear();

        for(i=0; i<m; i++)
        {
            scanf(" %s",str);
            M[str] = i;
            num[i].clear();
        }

        for(i=0; i<n; i++)
        {
            scanf("%d %s", &k, str);
            num[M[str]].push_back(k);
        }

        ans = 0;

        for(i=0; i<m; i++)
            ans += solve(num[i]);

        printf("%d\n",ans);
    }

    return 0;
}
