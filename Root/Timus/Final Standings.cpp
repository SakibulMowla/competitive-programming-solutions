#include "stdio.h"
#include "vector"
#include "algorithm"
#include "iostream"

using namespace std;

struct data
{
    int id,m;
};

bool comp(data p,data q)
{
    return p.m > q.m;
}

int main()
{
//    freopen("1.txt","r",stdin);
    data u;
    vector <data> v;
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&u.id,&u.m);
        v.push_back(u);
    }
    stable_sort(v.begin(),v.end(),comp);
    for(i=0;i<n;i++)
        printf("%d %d\n",v[i].id,v[i].m);

    return 0;
}
