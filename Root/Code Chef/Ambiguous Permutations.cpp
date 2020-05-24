#include "stdio.h"
#include "map"
#include "iostream"
using namespace std;

#define SZ 100010
map <int , int> pos;
int seq[SZ];

int main()
{
    int n,i,j;
    while(scanf("%d",&n) == 1 && n)
    {
        pos.clear();
        for(i=1;i<=n;i++) scanf("%d",&seq[i]) , pos[seq[i]] = i;
        for(i=1;i<=n;i++)
        {
            j = pos[i];
//            printf("i = %d j = %d\n",i,j);
            if(j != seq[i]) break;
        }
        if(i == n+1) printf("ambiguous\n");
        else printf("not ambiguous\n");
    }

    return 0;
}
