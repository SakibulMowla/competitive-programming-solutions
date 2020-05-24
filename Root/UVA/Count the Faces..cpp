#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int parent[1000];

int find(int r)
{
    if(r == parent[r])
        return r;
    return parent[r] = find(parent[r]);
}

void makeset(int n)
{
    for(int i=0; i<=n; i++)
        parent[i] = i;
}

map <char , int> c2i;

int main()
{
    int v, e, i, r, k, ans, x, y;
    char a,b;

    while(scanf("%d %d",&v,&e) == 2)
    {
        c2i.clear();
        makeset(v);
        k = 0;
        ans = 1;

        for(i=1; i<=e; i++)
        {
            scanf(" %c %c",&a,&b);
            if(c2i.find(a) == c2i.end()) c2i[a] = k++;
            if(c2i.find(b) == c2i.end()) c2i[b] = k++;

            x = find(c2i[a]);
            y = find(c2i[b]);
            if(x == y) ans++;
            parent[x] = y;
        }

        printf("%d\n",ans);
    }

    return 0;
}
