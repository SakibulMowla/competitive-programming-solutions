#include <bits/stdc++.h>
using namespace  std;

#define sz(x) (int)x.size()
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define mem(a, b) memset(a, b, sizeof(a))

int main() {
    #if defined(JESI)
        freopen("1.txt", "r", stdin);
    #endif

    string s, myman;
    int i, j, k, tmp;
    int cnt[10];

    while(cin >> s){
        k = sz(s);
        mem(cnt, 0);
        cnt[1] = cnt[6] = cnt[8] = cnt[9] = -1;
        REP(i, k) cnt[s[i]-'0']++;

        myman = "1689";
        do{
            tmp = 0;
            REP(i, 4) tmp = (tmp*10 + myman[i]-'0') % 7;
            REP(i, 10) REP(j, cnt[i]) tmp = (tmp*10 + i) % 7;
            if(tmp == 0){
                printf("%s",myman.c_str());
                REP(i, 10) while(cnt[i]--) printf("%d",i);
                puts("");
                break;
            }
        }while(next_permutation(myman.begin(), myman.end()));
    }

    return 0;
}
