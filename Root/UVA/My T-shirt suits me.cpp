#include "stdio.h"
#include "string.h"
#include "map"
#include "iostream"

using namespace std;

int limit[7], n , m;
char arr[10][10] = {"XXL", "XL", "L", "M" , "S", "XS"};
bool found;
struct data
{
    int ch1,ch2;
}volunteer[35];

void reset(int x)
{
    for(int i=0; i<6; i++)
        limit[i] = x;
}

void backtrack(int a)
{
    if(found)return;
    if(a == m)
    {
        found = true;
        return;
    }
    if(limit[volunteer[a].ch1])
    {
        limit[volunteer[a].ch1]--;
        backtrack(a+1);
        limit[volunteer[a].ch1]++;
    }
    if(limit[volunteer[a].ch2])
    {
        limit[volunteer[a].ch2]--;
        backtrack(a+1);
        limit[volunteer[a].ch2]++;
    }
}

int main()
{
    int i,j,test;
    char sz1[10],sz2[10];
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d %d",&n,&m);
        for(i=0; i<m; i++)
        {
            scanf("%s %s",sz1,sz2);
            for(j=0; j<6; j++)
            {
                if(strcmp(sz1,arr[j]) == 0)
                    volunteer[i].ch1 = j;
                if(strcmp(sz2,arr[j]) == 0)
                    volunteer[i].ch2 = j;
            }
        }
        reset(n/6);
        found = false;
        backtrack(0);
        if(found)printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}
