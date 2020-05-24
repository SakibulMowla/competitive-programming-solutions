#include "stdio.h"
#include "string.h"
#include "string"
#include "vector"
#include "algorithm"
#include "iostream"

using namespace std;

#define SD(a) scanf("%d",&a)
#define STR string

int main()
{
//    freopen("1.txt","r",stdin);

    int i,j,k,t,n;
    STR str;
    SD(t);
    while(t--)
    {
        str.erase();
        SD(n);
        if(n < 10)
        {
            printf("%d\n",n);
            continue;
        }
        for(i=9;i>1 && n!=1;i--)
        {
            while(n % i == 0)
            {
                str += i+'0';
                n /= i;
            }
        }
        if(n != 1)
        {
            printf("-1\n");
            continue;
        }
        sort(str.begin(),str.end());
        cout << str << "\n";
    }

    return 0;
}
