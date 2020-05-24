#include <stdio.h>
#include <string.h>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct data
{
    int p,q;
};

int main()
{
    int a,b,x,y,i,j;
    vector <data> v;
    data u;
    scanf("%d %d %d %d",&x,&y,&a,&b);
    for(i=a;i<=x;i++)
    {
        for(j=b;j<=y;j++)
        {
            if(j < i)
            {
                u.p = i;
                u.q = j;
                v.push_back(u);
            }
            else break;
        }
    }
    printf("%d\n",v.size());
    for(i=0;i<v.size();i++)
        printf("%d %d\n",v[i].p,v[i].q);

    return 0;
}
