#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

int col[300] , arr[100];

long long per(long long n)
{
    if(n == 1)return 1;
    long long i,j,mul=1;
    j = 0;
    for(i=n; i>1; i--)
    {
        mul *= i;
        for(; j<26;)
        {
            if(arr[j]<2) j++;
            else if(mul % arr[j] == 0)
            {
                while(mul % arr[j] == 0)
                {
                    mul /= arr[j];
                    arr[j]--;
                    if(arr[j] < 2)
                        break;
                }
                if(arr[j] < 2) j++;
                else break;
            }
            else
                break;
        }
    }
    return mul;
}


void solve(string s)
{
    long long i,j,k,ans=0;
    char a;
    string tmp;
    while(s.size() > 1)
    {
        a = s[0];
        memset(col,0,sizeof(col));
        for(i=1; i<s.size(); i++)
        {
            if(s[i] < a && !col[s[i]])
            {
//                printf("s[i] = %c  col = %d i = %lld\n",s[i],col[s[i]],i);
                col[s[i]] = 1;
//                printf("col[%c] = %d\n",s[i])
                memset(arr,0,sizeof(arr));
                for(j=0; j<s.size(); j++)
                {
                    if(j == i) continue;
                    arr[s[j] - 'a']++;
                }
                ans += per(s.size()-1);
//                printf("ans = %lld\n",ans);
            }
        }
        s.erase(0,1);
    }
    printf("%10lld\n",ans+1);
}

int main()
{
    string s;
//    freopen("1.txt","r",stdin);
    while(cin>>s && s!="#")
        solve(s);
    return 0;
}
