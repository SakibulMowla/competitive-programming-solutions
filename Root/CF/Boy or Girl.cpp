#include "stdio.h"
#include "string.h"
#include "string"
#include "map"
#include "iostream"

using namespace std;

int main()
{
    string s;
    int n,cnt,i;
    map <char , int> m;

    getline(cin , s);
    cnt = 0;
    for(i=0; i<s.size(); i++)
        if(m.find(s[i]) == m.end())
            cnt++ , m[s[i]] = 1;
    if(cnt % 2 == 1) printf("IGNORE HIM!\n");
    else printf("CHAT WITH HER!\n");


    return 0;
}
