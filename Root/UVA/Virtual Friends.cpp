#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
int parent[200010];
int circle[200010];

int find(int r)
{
    if(r != parent[r])
        parent[r] = find(parent[r]);
    return parent[r];
}

int Union(int a,int b)
{
    parent[b] = a;
    circle[a] += circle[b];
    circle[b] = circle[a];
    return circle[a];
}

void makeset(int n)
{
    parent[n] = n;
    circle[n] = 1;
    return;
}

int main()
{
    int i,x,y,test,f,nodes,total_circle;
    char str1[30],str2[30];
    map <string , int> m;
    scanf("%d",&test);

    while(test--)
    {
        nodes=0;
        m.clear();
        scanf("%d",&f);
        for(i=0; i<f; i++)
        {
            scanf("%s %s",str1,str2);
            if(m.find(str1) == m.end())
            {
                m[str1] = ++nodes;
                makeset(m[str1]);
            }
            if(m.find(str2) == m.end())
            {
                m[str2] = ++nodes;
                makeset(m[str2]);
            }
            x=find(m[str1]);
            y=find(m[str2]);

            if(x == y)
                total_circle = circle[x];

            else
                total_circle = Union(x,y);

            printf("%d\n",total_circle);
        }
    }

    return 0;
}
