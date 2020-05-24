#include "stdio.h"
#include "string.h"
#include "string"
#include "iostream"

using namespace std;

string str , rstr;

bool check(string s)
{
//    cout << s << "\n";
    int i,j,k,len1,len2;
    len1 = rstr.size();
    len2 = s.size();
    for(i=0;i<len1;i++)
    {
        for(j=0;j<len2 && rstr[i+j] == s[j];j++);
        if(j == len2) return 1;
    }
    return 0;
}

int main()
{
    int t,i,j,k,c;
    scanf("%d",&t);
    while(t--)
    {
        cin >> str;
        k = str.size();
        rstr.erase();
        for(i=k-1;i>=0;i--)
            rstr += str[i];
//        cout << "rstr " << rstr << "\n";
        c = 0;
        for(i=0;i<k;i++)
        {
            for(j=i;j<k;j++)
            {
                if( !check(str.substr(i,j-i+1)) )
                {
                    printf("NO\n");
                    c = 1;
                    break;
                }
            }
            if(c == 1) break;
        }
        if(c == 0) printf("YES\n");
    }

    return 0;
}
