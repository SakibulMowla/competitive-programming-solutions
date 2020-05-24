#include "bits/stdc++.h"
using namespace std;


char s[4];


int main()
{
    int pre, n, i, j, k, group;

    scanf("%d",&n);

    pre = -1;
    group = 1;

    while(n--)
    {
        scanf("%s",s);
        if(s[0]-'0' == pre)
            group++;
        pre = s[1]-'0';
    }

    printf("%d\n",group);


    return 0;
}
