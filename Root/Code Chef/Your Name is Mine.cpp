using namespace std;

#include "stdio.h"
#include "string.h"
#include "string"
#include "iostream"

bool check(string a,string b)
{
    int i,j,len1,len2;
    len1 = a.size();
    len2 = b.size();
    for(i=0,j=0; i<len1; i++)
    {
        if(j == len2) return false;
        for(; j<len2; j++)
        {
            if(a[i] == b[j])
            {
                j++;
                break;
            }
            if(j == len2-1) return false;
        }
    }
    return true;
}

int main()
{
    int t;
    string a,b;
    scanf("%d",&t);
    while(t--)
    {
        cin >> a >> b;
        if(check(a,b) || check(b,a)) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}
