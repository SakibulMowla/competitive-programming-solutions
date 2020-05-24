#include "bits/stdc++.h"

using namespace std;

map <int, bool> mp;

int main()
{
    int n, l, x, y;

    while(scanf("%d %d %d %d", &n, &l, &x, &y) == 4)
    {
        mp.clear();

        for(int i = 0; i < n; i++)
        {
            int val;
            scanf("%d", &val);
            mp[val] = 1;
        }

        int one = 0, two = 0;

        for(map <int, bool>::iterator it = mp.begin(); it != mp.end(); it++)
        {
            if(mp.find(it->first + x) != mp.end()) one = 1;
            if(mp.find(it->first + y) != mp.end()) two = 1;
            if(one && two) break;
        }

        if(one && two) printf("0\n");
        else if(two) printf("1\n%d\n",x);
        else if(one) printf("1\n%d\n",y);
        else
        {
            for(map <int, bool>::iterator it = mp.begin(); it != mp.end(); it++)
            {
                if(mp.find(it->first + y - x) != mp.end() && it->first + y <= l)
                {
                    printf("1\n%d\n", it->first + y);
                    goto HELL;
                }
                if(mp.find(it->first - y + x) != mp.end() && it->first - y >= 0)
                {
                    printf("1\n%d\n", it->first - y);
                    goto HELL;
                }
                if(mp.find(it->first + y + x) != mp.end())
                {
                    printf("1\n%d\n", it->first + x);
                    goto HELL;
                }
            }
            printf("2\n%d %d\n", x, y);
        }
        HELL:;
    }

    return 0;
}
