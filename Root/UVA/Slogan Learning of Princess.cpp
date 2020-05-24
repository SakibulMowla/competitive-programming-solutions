#include "stdio.h"
#include "string.h"

#define SZ 110

char M[118][110];
const int mod1 = 49;
const int mod2 = 67;

int main()
{
    int i,j,k,n,m,p,q;
    char arr[110];
    while(scanf("%d",&n) == 1)
    {

        for(i=0;i<n;i++)
        {
            scanf(" %[^\n]",arr);
            k = strlen(arr);
            p = q = 0;
            for(j=0;j<k;j++)
            {
                p = (p + (arr[j] * j+1)) % mod1;
                q = (q + (arr[j] * j+1)) % mod2;
            }
            p = (p + q) % (mod1 + mod2);
            scanf(" %[^\n]",M[p]);
        }
        scanf("%d",&k);
        while(k--)
        {
            scanf(" %[^\n]",arr);
            m = strlen(arr);
            p = q = 0;
            for(i=0;i<m;i++)
            {
                p = (p + (arr[i] * i+1)) % mod1;
                q = (q + (arr[i] * i+1)) % mod2;
            }
            p = (p + q) % (mod1 + mod2);
            printf("%s\n",M[p]);
        }
    }

    return 0;
}
