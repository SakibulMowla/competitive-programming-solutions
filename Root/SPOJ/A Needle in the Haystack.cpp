#include <cstdio>

using namespace  std;

int par[2500], i, k, n;
char s[2501], c;

int main() {
//    freopen("1.txt", "r", stdin);
    bool flag = true;

    while(scanf("%d\n",&n)!=EOF){
        fgets(s,2501,stdin);
        par[0] = 0;

        i = 1;

        while(i<n){
            k = par[i-1];

            while(k>0 && s[i]!=s[k]) k = par[k-1];
            if(s[i]==s[k]) ++k;

            par[i] = k;
            ++i;
        }

        k = i = 0;

        if(!flag) puts("");
        flag = false;

        while((c = getchar())!=EOF && c!='\n') {
            while(k>0 && c!=s[k]) k = s[k-1];
            if(c==s[k]) ++k;

            if(k == n){
                printf("%d\n",i+1-n);
                k = par[k-1];
            }

            ++i;
        }
    }

    return 0;
}
