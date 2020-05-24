#include <bits/stdc++.h>

using namespace  std;

#define SZ 1000010

char arr[SZ];
int cum[SZ];

int main()
{

    int i, n, minim, now;

    while(~scanf("%d %s",&n,arr+1))
    {
        for(i=1; i<=n; i++)
        {
            if(arr[i] == arr[i-1])
                cum[i] = cum[i-1] + 1;
            else
                cum[i] = 1;
        }

        minim = 0;
        now = 1;

        for(i=n; i>0; i--)
        {
            if( (now == 1 && arr[i] == 'B') || (now == 0 && arr[i] == 'A') )
            {
                minim++;
                if(cum[i] == 1) continue;

                now = !now;
                i -= (cum[i] - 1);
            }
        }

        printf("%d\n",minim);
    }


    return 0;
}
