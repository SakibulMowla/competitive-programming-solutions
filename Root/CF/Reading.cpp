#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>


using namespace std;

struct data { int a,b; };
bool comp (data p,data q){ return p.b > q.b; }

int main()
{
    data u;
    int n,k,num,bad,limit,i;
    vector <data> v;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    while(scanf("%d %d",&n,&k) == 2)
    {
        v.clear();
        for(i=1;i<=n;i++)
        {
            scanf("%d",&num);
            u.a = i;
            u.b = num;
            v.push_back(u);
        }

        sort(v.begin(),v.end(),comp);
        bad = v.size() - k;
        limit = v.size() - bad -1;
        printf("%d\n",v[limit].b);
        printf("%d",v[limit].a);
        for(i=limit-1;i>=0;i--)
            printf(" %d",v[i].a);
        printf("\n");
    }
    fclose(stdin);
    fclose(stdout);

    return 0;
}
