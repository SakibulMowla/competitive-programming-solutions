#include <stdio.h>
#include <string.h>
#include <string>
#include <math.h>
#include <iostream>

using namespace std;

void solve(string s)
{
    int out[10] = {0};
    int cp=0,dp=1;
    bool erase;
    while(cp >= 0 && cp < s.length())
    {
        erase = false;
        if(s[cp] >= '0' && s[cp] <= '9')
        {
            out[s[cp]-'0']++;
            s[cp]--;
            if(s[cp] < '0')
                erase = true;
        }
        else
        {
            if(s[cp] == '<')
                dp = -1;
            else
                dp = 1;
            if(cp+dp >= 0 && cp+dp < s.length() && (s[cp+dp] == '<' || s[cp+dp] == '>'))
                erase = true;
        }
        if(erase)
        {
            s.erase(cp,1);
            if(dp == -1)
                cp--;
        }
        else
            cp += dp;
    }
    printf("%d",out[0]);
    for(int i=1;i<10;i++)
        printf(" %d",out[i]);
    printf("\n");
}

int main()
{
    int n,q,l,r;
    string s;
    scanf("%d %d",&n,&q);
    cin >> s;
    while(q--)
    {
        scanf("%d %d",&l,&r);
        solve(s.substr(l-1,r-l+1));
    }

    return 0;
}
