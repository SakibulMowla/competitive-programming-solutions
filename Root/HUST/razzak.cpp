#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <iostream>
#include <algorithm>

using namespace  std;

typedef long long ll;


int main()
{
    char arr[100];
    int n, m, i, j, k;

    while(scanf("%d",&n) == 1)
    {
        scanf("%d",&k);
        scanf("%s",arr);

        for(i=0;i<k;i++)
        {
            for(j=1;j<strlen(arr);j++)
            {
                if(arr[j-1] == 'B' && arr[j] == 'G')
                    swap(arr[j],arr[j-1]),j++;
            }
        }

        printf("%s\n",arr);
    }

    return 0;
}

