#include "stdio.h"
#include "string.h"
#include "string"
#include "iostream"
using namespace std;
int main()
{
    int i,j,k,l,n,m;
    string s;
    while(scanf("%d %d",&n,&k) == 2)
    {
        cin >> s;
        m = 0;
        if(k == 2)
        {
            int cnt1=0,cnt2=0;
            string s1,s2;
            for(i=0; i<n; i++)
            {
                s1 += (i%2) + 'A';
                s2 += !(i%2) + 'A';
                if(s1[i] != s[i]) cnt1++;
                if(s2[i] != s[i]) cnt2++;
            }
            if(cnt1 < cnt2)printf("%d\n%s\n",cnt1,s1.c_str());
            else printf("%d\n%s\n",cnt2,s2.c_str());
        }
        else
        {
            for(i=1; i<n; i++)
            {
                if(s[i] == s[i-1])
                {
                    m++;
                    j = (s[i] - 'A' + 1) % k;
                    printf("j = %d\n",j);
                    if(i+1 < n)
                    {
                        l = s[i+1] - 'A';
                        printf("l = %d\n",l);
                        while(j == l)
                        {
                            j++;
                            j %= k;
                        }
                    }

                    s[i] = j + 'A';
//                    printf("j = %d s[%d] = %c  s = %s\n",j,i,s[i],s.c_str());
                }
            }
            printf("%d\n%s\n",m,s.c_str());
        }
    }
    return 0;
}
//
