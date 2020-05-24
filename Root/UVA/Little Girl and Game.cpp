#include "stdio.h"
#include "string.h"
#include "string"
#include "iostream"

using namespace std;

int cnt[30];

int main()
{
    string s;
    int i,len,odd;
    while(cin >> s)
    {
        memset(cnt,0,sizeof(cnt));
        len = s.size();
        odd = 0;
        for(i=0;i<len;i++)
            cnt[s[i]-'a']++;
        for(i=0;i<26;i++)
            if(cnt[i] % 2 == 1)
                odd++;
        if(odd == 0) printf("First\n");
        else if(odd % 2 == 1) printf("First\n");
        else printf("Second\n");
    }

    return 0;
}
