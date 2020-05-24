#include "stdio.h"
#include "string.h"
#include "math.h"

int main()
{
    int t,i,j,k,k1,n,c,q;
    while(scanf("%d",&t) == 1)
    {
        while(t--)
        {
            scanf("%d %d %d",&n,&c,&q);
            while(q--)
            {
                scanf("%d %d",&i,&j);
                if(c>=i && c<=j)
                {
//                    printf("yes\n");
                    if((j-i)%2 == 0)
                    {
                        k = (i+j) / 2;
                        if(c < k)
                        {
                            c = j - (c-i);
                        }
                        else if(c > k)
                        {
                            c = i + (j-c);
                        }
                    }
                    else
                    {
                        k = (i+j)/2;
                        k1 = k + 1;
//                        printf("k = %d k1 = %d\n",k,k1);
                        if(c <= k)
                        {
                            c = k1 + (k-c);
                        }
                        else if(c >= k1)
                        {
                            c = k - (c-k1);
                        }
                    }
                }
//                printf("c = %d\n",c);
            }

            printf("%d\n",c);
        }
    }

    return 0;
}
