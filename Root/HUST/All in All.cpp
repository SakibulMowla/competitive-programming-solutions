#include "stdio.h"
#include "string"
#include "iostream"

using namespace std;

int main()
{
    string s,t;
    int i,j,len1,len2;
    while(cin >> s >> t)
    {
        len1 = s.size();
        len2 = t.size();
        j = 0;
        for(i=0;i<len2 && j != len1;i++)
            if(t[i] == s[j])
                j++;
        if(j == len1) printf("Yes\n");
        else printf("No\n");
    }

    return 0;
}
