#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <iostream>

using namespace  std;

typedef long long ll;

#define SZ 27

bool col[SZ] , print;
ll in[SZ], mat[SZ][SZ], n;
string s;

void rec(ll indx)
{
    int i,j;

    if(indx == n)
    {
        print = 17;
        j = s.size();
        for(i=0; i<j; i++)
        {
            if(i) printf(" ");
            printf("%c", s[i]);
        }
        printf("\n");
        return;
    }

    for(i=0; i<26; i++)
    {
        if(col[i] == 1 && in[i] == 0)
        {
            col[i] = 0;
            s += i+'A';
            for(j=0; j<26; j++)
            {
                if(mat[i][j] == 1)
                    in[j]--;
            }

            rec(indx+1);

            col[i] = 1;
            s.erase(s.size()-1);
            for(j=0; j<26; j++)
            {
                if(mat[i][j] == 1)
                    in[j]++;
            }
        }
    }
}

int main()
{
    ll t, i, j, k, m, cnt;
    char ch, ch1, arr[10000];

    scanf("%lld",&t);

    while(t--)
    {
        n = 0;
        scanf(" %[^\n]", arr);
        memset(col, 0, sizeof(col));
        for(i=0; i<arr[i]; i++)
        {
            if(arr[i] != ' ')
                n++ , col[arr[i]-'A'] = 1;
        }

        scanf(" %[^\n]", arr);
        memset(in, 0, sizeof(in));
        memset(mat, 0, sizeof(mat));

        cnt = 0;

        for(i=0; arr[i]; i++)
        {
            if(arr[i] != ' ')
            {
                if(cnt == 0) ch = arr[i];
                if(cnt == 2) ch1 = arr[i];
                cnt++;
            }

            if(cnt == 3)
            {
                in[ch1-'A']++;
                mat[ch-'A'][ch1-'A'] = 1;
                cnt = 0;
            }
        }

        print = false;
        rec(0);
        if(!print) printf("NO\n");
        if(t) printf("\n");
    }

    return 0;
}
