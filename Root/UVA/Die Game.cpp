#include <stdio.h>
#include <string.h>

//enum {top , north , west , east , south , down} ;

int main()
{
    int test , t , n , w , d , s , e , tmp1 , tmp2;
    char arr[10];
    while(scanf("%d",&test) == 1 && test)
    {
        t = 1 , n = 2 , w = 3 , d = 6 , s = 5 , e = 4;
        while(test--)
        {
            scanf(" %[^\n]",arr);
            if(strcmp(arr,"north") == 0)
            {
                tmp1 = s , tmp2 = n , n = t , s = d , t = tmp1 , d = tmp2;
            }
            else if(strcmp(arr,"south") == 0)
            {
                tmp1 = s , tmp2 = n , s = t , n = d , t = tmp2 , d = tmp1;
            }
            else if(strcmp(arr,"east") == 0)
            {
                tmp1 = e , tmp2 = w , e = t , w = d , t = tmp2 , d = tmp1;
            }
            else if(strcmp(arr,"west") == 0)
            {
                tmp1 = w , tmp2 = e , w = t , e = d , t = tmp2 , d = tmp1;
            }
        }
        printf("%d\n",t);
    }

    return 0;
}
