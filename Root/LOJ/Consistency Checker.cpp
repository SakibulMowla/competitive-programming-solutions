#include "stdio.h"
#include "string.h"
#include "string"
#include "vector"
#include "algorithm"
#include "iostream"

using namespace std;

#define SZ 10010

bool check(string a,string b)
{
    int i,len1,len2;
    len1 = a.size();
    len2 = b.size();
    for(i=0;i<len1 && i <len2;i++)
        if(a[i] != b[i])
            return false;
    if(i == len1)
        return true;
}

int main()
{
    int t=0,test,i,j,n;
    vector <string> vs;
    string str;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d",&n);
        vs.clear();
        for(i=0;i<n;i++)
        {
            cin >> str;
            vs.push_back(str);
        }
        sort(vs.begin(),vs.end());
        j = 0;
        for(i=0;i<n-1;i++)
        {
            if(check(vs[i],vs[i+1]) == true)
            {
                j = 1;
                break;
            }
        }
        if(j == 1) printf("Case %d: NO\n",++t);
        else printf("Case %d: YES\n",++t);
    }

    return 0;
}
