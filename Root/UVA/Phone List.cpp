#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector <string> number;

int main()
{
    int test,n,i,j,len1,len2,flag;
    char str[100];
    scanf("%d",&test);
    while(test--)
    {
        number.clear();
        scanf("%d",&n);
        i = n;
        while(i--)
        {
            scanf("%s",str);
            number.push_back(str);
        }
        sort(number.begin() , number.end());
        flag = 0;
        for(i=0;i<n-1;i++)
        {
            len1 = number[i].size();
            len2 = number[i+1].size();
            if(len1 <= len2)
            {
                for(j=0;j<len1;j++)
                    if(number[i][j] != number[i+1][j])
                        break;
                if(j == len1)
                {
                    flag = 1;
                    break;
                }
            }
        }
        if(flag) printf("NO\n");
        else printf("YES\n");
    }

    return 0;
}
