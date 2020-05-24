/*
ID: sakibul1
PROG: ride
LANG: C++
*/
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

int main()
{
    char group[10],comet[10];
    int i,g,c;
    freopen("ride.in","r",stdin);
    freopen("ride.out","w",stdout);
    while(scanf(" %s %s",group,comet) == 2)
    {
        g = 1;
        for(i=0;group[i];i++)
        {
            g *= (group[i]-64);
            g %= 47;
        }
        c = 1;
        for(i=0;comet[i];i++)
        {
            c *= (comet[i]-64);
            c %= 47;
        }
        if(g == c)
            printf("GO\n");
        else
            printf("STAY\n");
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
