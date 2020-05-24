#include <bits/stdc++.h>

using namespace  std;

#define SZ  100010

char txt[SZ];
char tmp[SZ];
char pat[SZ];
int par[SZ];

void pre_process(int patsz)
{
    int k = 0;
    par[0] = 0;
    for(int i = 1; i < patsz; i++)
    {
        while(k > 0 && pat[i] != pat[k])
            k = par[k-1];
        if(pat[i] == pat[k])
            k++;
        par[i] = k;
    }
    return;
}

int now;
int txtsz;

bool kmp(int patsz)
{
    int k = 0;
    for(int i = now; i < txtsz; i++)
    {
        while(k > 0 && txt[i] != pat[k])
            k = par[k-1];
        if(txt[i] == pat[k])
            k++;
        if(k == patsz)
        {
            now = i + 1;
            return true;
        }
    }
    return false;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int n;

    while(scanf("%d", &n) == 1)
    {
        scanf("%s", txt);
        txtsz = strlen(txt);

        for(int i = 0; i < n; i++)
        {
            now = 0;

            scanf("%s", tmp);
            int tmpsz = strlen(tmp);
            tmp[tmpsz++] = '*';

            int cnt = 0;
            int flag = 1;

            for(int j = 0; j < tmpsz; j++)
            {
                if(tmp[j] == '*')
                {
                    if(cnt)
                    {
                        pre_process(cnt);
                        flag = kmp(cnt);
                        if(!flag) break;
                        cnt = 0;
                    }
                }
                else
                    pat[cnt++] = tmp[j];
            }

            printf("%s\n", flag ? "yes" : "no");
        }
    }

    return 0;
}













