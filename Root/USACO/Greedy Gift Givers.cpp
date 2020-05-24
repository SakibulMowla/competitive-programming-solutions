/*
ID: sakibul1
PROG: gift1
LANG: C++
*/
#include "stdio.h"
#include "string.h"
#include "string"
#include "map"
#include "iostream"

using namespace std;

int main()
{
    freopen("gift1.in","r",stdin);
    freopen("gift1.out","w",stdout);
    char arr[20][20],tmp[20];
    map<string , int> msi;
    int n,m,i,j,k,initial[20],final[20],total,getter,much;
    while(scanf("%d",&n) == 1)
    {
        msi.clear();
        for(i=0; i<n; i++)
        {
            scanf("%s",arr[i]);
            msi[arr[i]] = i;
            final[i] = 0;
        }
        for(i=0; i<n; i++)
        {
            scanf("%s",tmp);
            scanf("%d %d",&total,&getter);
            k = msi[tmp];
            initial[k] = total;
            if(getter != 0)
            {
                much = total / getter;
                final[k] += total % getter;
            }
            else
                final[k] += total;
            for(j=0; j<getter; j++)
            {
                scanf("%s",tmp);
                final[ msi[tmp] ] += much;
            }
        }
        for(i=0; i<n; i++)
            printf("%s %d\n",arr[i],final[ msi[arr[i]] ] - initial[ msi[arr[i]] ]);
    }

    return 0;
}
