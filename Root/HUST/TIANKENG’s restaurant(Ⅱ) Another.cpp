#include <bits/stdc++.h>

using namespace  std;

using ll = long long;

#define mem(a,b) memset(a, b, sizeof(a))

#define SZ 1000010
#define SZ1 4782969+100

int mp[SZ1];
char s[SZ];
int len;

string stk, ans;

void bctk (int Hash = 0, int dep = 0) {
    if (dep >= len || dep > 7) return;

    if (!mp[Hash]) {
        len = dep;
        ans = stk;
        return;
    }

    for (int i = 0; i < 8; i++) {
        if (dep + 1 >= len) return;
        stk.push_back(char(i+'A'));
        bctk((Hash * 9) + i + 1, dep + 1);
        stk.pop_back();
    }

    return;
}

int main() {
    #if defined JESI
//        freopen("bubble.in", "r", stdin);
//        freopen("bubble.out", "w", stdout);
    #endif

    int t;
    scanf("%d", &t);

    for (int cs = 0; cs < t; cs++) {
        scanf("%s", s);
        int n = strlen(s);

        mem(mp, 0);

        mp[0] = 1;
        for (int i = 0; i < n; i++) {
            int Hash = 0;
            for (int j = 0; j < 7 && i + j < n; j++) {
                Hash = (Hash * 9) + (s[i+j] - 'A' + 1);
                mp[Hash] = 1;
            }
        }

        stk = "";
        len = 10;

        bctk();

        printf("%s\n", ans.c_str());
    }

    return 0;
}
