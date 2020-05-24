#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <math.h>
#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int , int> pii;
#define MP(a,b) make_pair(a,b)
map <pii , bool> m;
long long cnt ;
int w , n;

int x[] = {0,1};
int y[] = {1,0};

void dfs(int p,int k)
{
    if(p == w && k == n)
    {
        cnt++;
        return;
    }
    int i,u,v;
    for(i=0;i<2;i++)
    {
        u = p + x[i] , v = k + y[i];
        if(u>=1 && v>=1 && u<=w && v<=n && !m[MP(u,v)] )
        {
            dfs(u,v);
        }
    }
}

int main()
{
    int test,i,j,k;
    char arr[510] , *str;
//    freopen("1.txt","r",stdin);
    scanf("%d",&test);
    while(test--)
    {
        m.clear();
        scanf("%d %d",&w,&n);
        for(i=0;i<w;i++)
        {
            scanf(" %[^\n]",arr);
            str = strtok(arr," ");
            k = atoi(str);
            str = strtok(NULL," ");
            while( str != NULL )
            {
                j = atoi(str);
                m[MP(k,j)] = 1;
                str = strtok(NULL," ");
            }
        }
        cnt = 0;
        dfs(1,1);
        printf("%lld\n",cnt);
        if(test) printf("\n");
    }

    return 0;
}
