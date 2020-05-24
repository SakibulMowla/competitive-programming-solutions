#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    int n,i,j,flag;
    while(scanf("%d",&n)==1)
    {
        vector <int> input;
        for(i=0;i<n;i++)
        {
            scanf("%d",&j);
            input.push_back(j);
        }
        for(i=1;i<n && input[0]==input[i];i++)
            ;
        if(n <=2 || i == n)
        {
            printf("-1\n");
            continue;
        }
        flag = 0;
        for(i=1;i<n;i++)
        {
            if(input[i-1] != input[i])
            {
                swap(input[i],input[i-1]);
                bool down = true , up = true;
                for(j=1;j<n;j++)
                {
                    if(input[j] > input[j-1]) down = false;
                    if(input[j] < input[j-1]) up = false;
                    if(!down && !up) break;
                }
                if(!down && !up)
                {
                    printf("%d %d\n",i,i+1);
                    return 0;
                }
                swap(input[i],input[i-1]);
            }
        }
        printf("-1\n");
    }

    return 0;
}
