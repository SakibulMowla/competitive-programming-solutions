#include <stdio.h>
#include <set>
using namespace std;

#define SZ 20010

int dra[SZ] , cost , n , m;
multiset <int> multi;

bool pay()
{
    cost = 0;
    int i;
    multiset <int>:: iterator it;
    for(i=0;i<n;i++)
    {
        it = multi.lower_bound(dra[i]); // find the knight
        if(it == multi.end()) return false;
        cost += *it;
        multi.erase(it); // remove the knight
    }

    return true;
}

int main()
{
    int i ,j;
    while(scanf("%d %d",&n,&m) == 2)
    {
        if(n == 0 && m == 0) break;
        for(i=0;i<n;i++)
            scanf("%d",&dra[i]);
        multi.clear();
        for(i=0;i<m;i++)
        {
            scanf("%d",&j);
            multi.insert(j);
        }
        if( !pay() ) printf("Loowater is doomed!\n");
        else printf("%d\n",cost);
    }

    return 0;
}
