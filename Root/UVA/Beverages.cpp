#include "stdio.h"
#include "string.h"
#include "string"
#include "map"
#include "vector"
#include "iostream"

using namespace std;

#define SZ 110

vector <int> edge[SZ];
map <string , int> msi;
map <int , string> mis;
bool visited[SZ];
int in[SZ];

void init(int n)
{
    int i;
    msi.clear();
    mis.clear();
    for(i=0;i<=n;i++) edge[i].clear() , visited[i] = in[i] = 0;
}

int main()
{
    int n,m,i,j,k,t=0,flag;
    char str1[100],str2[100];
    while(scanf("%d",&n) == 1)
    {
        init(n);
        for(i=0;i<n;i++)
        {
            scanf("%s",str1);
            msi[str1] = i;
            mis[i] = str1;
        }
        scanf("%d",&m);
        for(i=0;i<m;i++)
        {
            scanf("%s %s",str1,str2);
            j = msi[str1] , k = msi[str2];
            in[k]++;
            edge[j].push_back(k);
        }
        printf("Case #%d: Dilbert should drink beverages in this order:",++t);
        flag = 0;
        while(!flag)
        {
            flag = 1;
            for(i=0;i<n;i++)
                if(!visited[i] && !in[i])
                {
                    visited[i] = 1;
                    printf(" %s",mis[i].c_str());
                    flag = 0;
                    for(j=0;j<edge[i].size();j++)
                    {
                        k = edge[i][j];
                        if(in[k]) in[k]--;
                    }
                    i = -1;
                }
        }
        printf(".\n\n");
    }

    return 0;
}
