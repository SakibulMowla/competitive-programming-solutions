#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <iostream>
#include <algorithm>

using namespace  std;

#define inf 1<<28
#define SZ 1010


int main()
{
    int flag,i;
    string s;
    while(cin >> s)
    {
        flag = 0;
        for(i=0;i<s.size()-1;i++)
        {
            if(s[i] == '0' && flag == 0) flag = 1;
            else cout << s[i];
        }
        if(flag == 1) cout << s[ s.size()-1 ];
        printf("\n");
    }


    return 0;
}
