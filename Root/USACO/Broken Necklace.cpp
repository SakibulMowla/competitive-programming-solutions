/*
ID: sakibul1
PROG: beads
LANG: C++
*/


#include "bits/stdc++.h"

using namespace std;

char s[800], arr[400];

int main()
{
    freopen("beads.in", "r", stdin);
    freopen("beads.out", "w", stdout);

    int i, j, k, n;
    bool b, r;

    while(scanf("%d %s",&n,arr) == 2)
    {
        s[0] = '\0';
        strcat(s, arr);
        strcat(s, arr);

        k = 0;
        for(i=0; i<n; i++)
        {
            b = r = 0;
            for(j=0; j<n; j++)
            {
                if(s[i+j]=='b') b = 1;
                if(s[i+j]=='r') r = 1;
                if(b && r) break;
            }
            b = r = 0;
            for(; j<n; j++)
            {
                if(s[i+j]=='b') b = 1;
                if(s[i+j]=='r') r = 1;
                if(b && r) break;
            }
            k = max(k, j);
        }

        printf("%d\n",k);
    }

    return 0;
}


/*

77
rwrwrwrwrwrwrwrwrwrwrwrwbwrwbwrwrwrwrwrwrwrwrwrwrwrwrwrwrwrwrwrwrwrwrwrwrwrwr
9
rwbwrwbwr

*/
