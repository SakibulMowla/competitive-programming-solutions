#include "stdio.h"
#include "string.h"
#include "queue"
#include "iostream"

using namespace std;

int main()
{
    int test,l,m,i,j,side,sum,cross;
    char arr[10];
    queue <int> left , right;
//    freopen("1.txt","r",stdin);
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d %d",&l,&m);
        l *= 100;
        for(i=0;i<m;i++)
        {
            scanf("%d %s",&j,arr);
            if(strcmp(arr,"left") == 0)
                left.push(j);
            else right.push(j);
        }
        side = 0;
        cross = 0;
        while( !left.empty() || !right.empty() )
        {
            sum = 0;
            if(side%2 == 0)
            {
                while( !left.empty() )
                {
                    if(sum + left.front() > l)break;
                    sum += left.front();
                    left.pop();
                }
            }
            else
            {
                while( !right.empty() )
                {
                    if(sum + right.front() > l)break;
                    sum += right.front();
                    right.pop();
                }
            }
            cross++;
            side++;
        }
        printf("%d\n",cross);
    }

    return 0;
}
