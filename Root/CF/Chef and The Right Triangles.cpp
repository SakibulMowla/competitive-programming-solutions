#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

bool chk(int x1,int y1,int x2,int y2,int x3,int y3)
{
    int d1, d2, d3;

    d1 = pow(x1-x2, 2) + pow(y1-y2, 2);
    d2 = pow(x1-x3, 2) + pow(y1-y3, 2);
    d3 = pow(x2-x3, 2) + pow(y2-y3, 2);

    if(d1 == (d2 + d3) || d2 == (d1 + d3) || d3 == (d1 + d2))
        return true;
    return false;
}

int main()
{
    int i, n, x1, y1, x2, y2, x3, y3, cnt = 0;

    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%d %d %d %d %d %d",&x1,&y1,&x2,&y2,&x3,&y3);
        if(chk(x1, y1, x2, y2, x3, y3))
            cnt++;
    }

    printf("%d\n",cnt);

    return 0;
}
