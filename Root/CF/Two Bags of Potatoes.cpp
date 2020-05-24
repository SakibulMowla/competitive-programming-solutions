#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <iostream>

using namespace std;
int main()
{
    int p,y,n,k;

    while(scanf("%d %d %d",&y,&k,&n)==3)
    {
        bool flag = false;
        p = k;
        while(k<=n)
        {
            if(k > y)
            {
                if(flag) printf(" ");
                flag = true;
                printf("%d",k-y);
            }
            k += p;
        }
        if(flag == false)
            printf("-1");
        printf("\n");
    }
    return 0;
}
