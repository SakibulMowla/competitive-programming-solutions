#include "stdio.h"
#include "string.h"
#include "string"
#include "iostream"

using namespace std;

int main()
{
    int a,b,n,i,j,cur;
    string s;
    while(scanf("%d %d %d",&a,&b,&n) == 3)
    {
        s.erase();
        cur = a % b;
        for(i=0; i<n; i++)
        {
            for(j=0; j<10; j++)
            {
                if((cur*10+j) % b == 0)
                {
                    cur = 0;
                    s += j + '0';
                    break;
                }
            }
            if(j == 10)
            {
                i = -1;
                break;
            }
        }
        if(i == -1) printf("-1\n");
        else {printf("%d",a) , cout << s << "\n";}
    }

    return 0;
}
