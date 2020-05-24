#include <bits/stdc++.h>

using namespace  std;

//p 0 1
//q 0 2
//r 1 2

bool bctk(int p,int q,int r,string s)
{
    if(p == 0 && q == 0 && r == 0)
        return s == "RGB";
    bool ret = 0;

    string str = s;
    swap(str[0], str[1]);
    if(p) ret = max(ret, bctk(p-1, q, r, str));
    str = s;
    swap(str[0], str[2]);
    if(q) ret = max(ret, bctk(p, q-1, r, str));
    str = s;
    swap(str[1], str[2]);
    if(r) ret = max(ret, bctk(p, q, r-1, str));

    return ret;
}

int main()
{
    int p, q, r;
    string s;

    while(cin >> p >> q >> r >> s)
    {
        if(p > 2) p = (p%2) + 2;
        if(q > 2) q = (q%2) + 2;
        if(r > 2) r = (r%2) + 2;
        if(bctk(p, q, r, s))
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}
