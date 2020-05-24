#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <iostream>
#include <algorithm>

using namespace  std;

#define inf 1<<28
#define SZ 1010


int main()
{
    int i,j,flag;
    char arr[10][10];
    for(i=0;i<8;i++) scanf("%s",arr[i]);
    flag = 0;
    for(i=0;i<8;i++)
    {
        for(j=0;j<7;j++)
        {
            if(arr[i][j] == 'W' && arr[i][j+1] != 'B')
            {
                flag = 1;
                break;
            }
            if(arr[i][j] == 'B' && arr[i][j+1] != 'W')
            {
                flag = 1;
                break;
            }
        }
        if(flag) break;
    }

    if(flag) printf("NO\n");
    else printf("YES\n");
    return 0;
}
