#include "stdio.h"
#include "string.h"
#include "stdlib.h"

const int mod = 131071;

int main()
{
    int remain = 0;
    char ch;
    while(scanf(" %c",&ch) == 1)
    {
        if(ch == '#')
        {
            if(remain == 0) printf("YES\n");
            else printf("NO\n");
            remain = 0;
            continue;
        }
        remain = (remain * 2 + ch - '0') % mod;
    }

    return 0;
}
