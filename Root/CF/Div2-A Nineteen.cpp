#include <bits/stdc++.h>

using namespace  std;

void PR(int x) {printf("%d\n",x);}

#define sz(x) (int)x.size()
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)

map <char , int> mp;

int main() {
    int i, j, k;
    string s;

    while(cin >> s){
        mp['n'] = mp['t'] = mp['i'] = mp['e'] = 0;
        REP(i, sz(s)) mp[s[i]]++;
        if(mp['n'] < 3) k = 0;
        else k = 1 + (mp['n']-3)/2;
        k = min(k, mp['t']);
        k = min(k, mp['e']/3);
        k = min(k, mp['i']);
        PR(k);
    }

    return 0;
}















