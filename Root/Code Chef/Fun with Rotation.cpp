#include <bits/stdc++.h>

using namespace  std;

#define SZ  100010

int arr[SZ];

int main() {
    int n, m, i, k, pos;
    char cmd;

    scanf("%d %d",&n,&m);

    for(i = 0; i < n; i++)
        scanf("%d",&arr[i]);

    pos = 0;
    while(m--)
    {
        scanf(" %c %d",&cmd,&k);
        if(cmd == 'C') pos -= k;
        else if(cmd == 'A') pos += k;
        else
        {
            printf("%d\n",arr[ (k-1-pos+n)%n ]);
        }
        pos = (pos + n) % n;
    }


    return 0;
}














