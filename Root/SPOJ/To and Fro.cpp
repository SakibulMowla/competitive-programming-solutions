#include "stdio.h"
#include "string.h"
#include "vector"
#include "iostream"
#include "algorithm"
using namespace std;

char arr[205];
vector <char> ans[25] , tmp;

int main()
{
    int i,n,j,k,row;
    char ch;
    while(scanf("%d",&n) == 1 && n)
    {
        scanf("%s",arr);
        row = strlen(arr) / n;
        j = 0;
        for(i=0;i<row;i++)
        {
            tmp.clear();
            for(k=0;k<n && j<strlen(arr);k++,j++)
            {
                tmp.push_back(arr[j]);
            }
            if(i%2 == 1)
                reverse(tmp.begin(),tmp.end());
            ans[i] = tmp;
        }
        for(j=0;j<n;j++)
            for(i=0;i<row;i++)
                printf("%c",ans[i][j]);
        printf("\n");
        for(i=0;i<row;i++)
            ans[i].clear();
    }

    return 0;
}
