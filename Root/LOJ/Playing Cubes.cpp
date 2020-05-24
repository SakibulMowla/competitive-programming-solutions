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

bool arr[200010];

int main()
{
    int n,m,a,b,red,blue,i;
    while(scanf("%d %d",&n,&m) == 2)
    {
        if(n >= m) red = n , blue = m;
        else red = m , blue = n;
        memset(arr,0,sizeof(arr));
        if(blue % 2 == 0)
        {
            blue--;
        }
        else
        {
            arr[0] = 1;
            blue--;
        }
        i = 1;
        while((red || blue) && i < n+m)
        {
            if(arr[i-1] == 0)
            {
                if(i%2 == 1)
                {
                    if(blue > 0)
                    {
                        blue--;
                        arr[i] = 1;
                    }
                    else
                    {
                        red--;
                        arr[i] = 0;
                    }
                }
                else
                {
                    if(red > 0)
                    {
                        red--;
                        arr[i] = 0;
                    }
                    else
                    {
                        blue--;
                        arr[i] = 1;
                    }
                }
            }
            else
            {
                if(i%2 == 1)
                {
                    if(red > 0)
                    {
                        red--;
                        arr[i] = 0;
                    }
                    else
                    {
                        blue--;
                        arr[i] = 1;
                    }
                }
                else
                {
                    if(blue > 0)
                    {
                        blue--;
                        arr[i] = 1;
                    }
                    else
                    {
                        red--;
                        arr[i] = 0;
                    }
                }
            }
            i++;
        }
        a = b = 0;
        for(i=1;i<n+m;i++)
            if(arr[i] == arr[i-1])
                a++;

        for(i=1;i<n+m;i++)
            if(arr[i] != arr[i-1])
                b++;
        printf("%d %d\n",a,b);
    }


    return 0;
}
