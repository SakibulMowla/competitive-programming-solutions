#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

#define sz(x) (int)x.size()


class PotentialArithmeticSequence {
public:
    int noz(int n) { /// number of zeroes
        if(!n) return 1;
        int cnt = 0;
        while(n) {
            if(n % 2 == 0)
                cnt++, n /= 2;
            else
                break;
        }
        return cnt;
    }

    map <string , int> mp;

    int numberOfSubsequences(vector <int> dd) {
        int i, j, k, ans;
        string ss = "", tt = "";

        for(i = 1; i < 200; i++)
            ss = ss + (char)(noz(i)+'0');

        for(i = 0; i < 200; i++) {
            for(j = i; j < 200; j++) {
                mp[ ss.substr(i, j-i+1) ] = 1;
            }
        }

        k = sz(dd);
        for(i = 0; i < k; i++) {
            dd[i] = min(6, dd[i]);
            tt = tt + (char)(dd[i] + '0');
        }

        ans = 0;

        for(i = 0; i < k; i++) {
            for(j = i; j < k; j++) {
                if(mp.find( tt.substr(i, j-i+1) ) != mp.end())
                    ans++;
            }
        }

        return ans;
    }

};
