#include "stdio.h"
#include "string.h"
#include "string"
#include "iostream"

using namespace std;

int main()
{
    string a,b;
    int i,j,k,l1,l2;
    while(cin>>a>>b)
    {
        l1 = a.size();
        l2 = b.size();
        if(l1 != l2)
        {
            printf("NO\n");
            continue;
        }
        else if(a == b)
        {
            printf("YES\n");
            continue;
        }
        for(i=0;i<l1;i++)
            if(a[i] == '1')
                break;
        if(i == l1)
        {
            printf("NO\n");
            return 0;
        }
        for(i=0;i<l2;i++)
            if(b[i] == '1')
                break;
        if(i == l2)
        {
            printf("NO\n");
            return 0;
        }
        printf("YES\n");
    }

    return 0;
}
