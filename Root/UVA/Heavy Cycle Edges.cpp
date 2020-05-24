#include "stdio.h"
#include "string.h"
#include "vector"
#include "algorithm"
#include "iostream"

using namespace std;

#define SZ 1010
#define makeset(n) for(i=0;i<=n;i++) par[i] = i

struct data {  int a,b,c;  };
bool comp(data p,data q){ return p.c < q.c; }

int par[SZ];
vector <data> v;

int find(int r)
{
    return par[r] == r ? r : par[r] = find(par[r]);
}

vector <int> result;

void MST(int n,int e)
{
    result.clear();
    sort(v.begin(),v.end(),comp);
    int i,p,q;
    for(i=0;i<v.size() /*&& i < e-1*/;i++)
    {
        p = find(v[i].a);
        q = find(v[i].b);
        if(p == q)
            result.push_back(v[i].c);
        else
            par[p] = q;
    }
    if(result.size())
    {
        printf("%d",result[0]);
        for(i=1;i<result.size();i++)
            printf(" %d",result[i]);
        printf("\n");
    }
    else
        printf("forest\n");
}

int main()
{
    data u;
    int n,e,i;
//    freopen("1.txt","r",stdin);
    while(scanf("%d %d",&n,&e) == 2)
    {
        if(n==0 && e==0)break;
        makeset(n);
        v.clear();
        for(i=0;i<e;i++)
        {
            scanf("%d %d %d",&u.a,&u.b,&u.c);
            v.push_back(u);
        }
        MST(n,e);
    }

    return 0;
}
