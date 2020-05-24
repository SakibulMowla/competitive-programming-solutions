#include "stdio.h"
#include "string.h"
#include "vector"
#include "algorithm"
#include "iostream"

using namespace std;

#define SZ 510
#define makeset(n) for(i=0;i<=n;i++) par[i] = i

struct data { int a,b,c; };
bool comp(data p,data q){ return p.c < q.c; }

int par[SZ];
vector <data> v;

int find(int r)
{
    return par[r] == r ? r : par[r] = find(par[r]);
}

int MST()
{
    sort(v.begin(),v.end(),comp);
    int p,q,i,cost;
    cost  = 0;
    for(i=0;i<v.size();i++)
    {
        p = find(v[i].a);
        q = find(v[i].b);
        if(p == q)continue;
        par[p] =q;
        cost += v[i].c;
    }
    return cost;
}

int main()
{
    data u;
    int i,j,k,n,test,dif,tmp,ans,mini;
    char arr[SZ][5];
//    freopen("1.txt","r",stdin);
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d",&n);
        makeset(n);
        v.clear();
        for(i=0;i<n;i++)
            scanf(" %s",arr[i]);
        for(i=0;i<n-1;i++)
        {
            for(j=i+1;j<n;j++)
            {
                dif = 0;
                for(k=0;k<4;k++)
                {
                    tmp = abs(arr[i][k] - arr[j][k]);
                    if(tmp > 5)
                        tmp = 10 - tmp;
                    dif += tmp;
                }
                u.a = i;
                u.b = j;
                u.c = dif;
                v.push_back(u);
            }
        }
        ans = MST();
        mini = 100000000;
        for(i=0;i<n;i++)
        {
            dif = 0;
            for(k=0;k<4;k++)
            {
                tmp = arr[i][k] - '0';
                if(tmp > 5)
                    tmp = 10 - tmp;
                dif += tmp;
            }
            if(dif < mini)
                mini = dif;
        }
        ans += mini;
        printf("%d\n",ans);
    }

    return 0;
}
