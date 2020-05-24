#include "stdio.h"
#include "string.h"
#include "string"
#include "map"
#include "iostream"

using namespace std;

int main()
{
    map <string , int> m;
    int test,d,n,i,j,t=0;
    char arr[30];
//    freopen("1.txt","r",stdin);
    scanf("%d",&test);
    while(test--)
    {
        m.clear();
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%s %d",arr,&j);
            m[arr] = j;
        }
        scanf("%d %s",&d,arr);
        if(m.find(arr) == m.end() || m[arr] > d + 5)
        {
            printf("Case %d: Do your own homework!\n",++t);
        }
        else
        {
            if(m[arr] <= d)
                printf("Case %d: Yesss\n",++t);
            else if(m[arr] <= d+5)
                printf("Case %d: Late\n",++t);
        }
    }

    return 0;
}
