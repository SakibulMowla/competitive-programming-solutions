#include <stdio.h>
#include <string.h>
#include <map>
#include <iostream>
using namespace std;

int main()
{
    int n,net[20],i,j,k,t=0,money,div;
    char arr[20],name[20][20];
    map <string , int> m;
//    freopen("1.txt","r",stdin);
    while(scanf("%d",&n) == 1)
    {
        m.clear();
        memset(net,0,sizeof(net));
        if(t) printf("\n");
        t++;
        for(i=0;i<n;i++)
        {
            scanf("%s",name[i]);
            m[name[i]] = i;
        }
        for(i=0;i<n;i++)
        {
            scanf("%s %d %d",arr,&money,&div);
            if(div == 0) j = 0;
            else j = money / div;
            net[m[arr]] -= j * div;
            for(k=0;k<div;k++)
            {
                scanf("%s",arr);
                net[m[arr]] += j;
            }
        }
        for(i=0;i<n;i++)
            printf("%s %d\n",name[i],net[i]);
    }
    return 0;
}
