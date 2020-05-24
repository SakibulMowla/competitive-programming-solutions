#include "bits/stdc++.h"

using namespace std;

map <int, int> mp;

int main()
{
    int t;
    scanf("%d", &t);

    for (int cs = 0; cs < t; cs++) {
        int n, f;
        scanf("%d %d", &n, &f);

        mp.clear();
        for (int i = 0; i < n; i++) {
            int h;
            scanf("%d", &h);
            mp[h]++;
        }

        int ans = 0;
        for(map<int , int>::iterator it = mp.begin(); it != mp.end(); it++)
        {
            int tmp = it->second;
            ans += (tmp*(tmp-1)/2);
            int play = it->first;
            while(play != 0 && play % f == 0)
            {
                play /= f;
                ans += mp[play] * tmp;
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}
