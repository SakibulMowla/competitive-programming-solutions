// Carmichael Numbers
#include "stdio.h"
#include "string.h"
#include "math.h"
#include "vector"
#include "iostream"

using namespace std;

#define SZ 65010
/*
int arr[SZ];
void sieve()
{
    int i,j;
    arr[0] = arr[1] = 1;
    for(i=3; i<sqrt(SZ); i+=2)
        if(arr[i] == 0)
            for(j=i*i; j<SZ; j+=i+i)
                arr[j] = 1;
}

void carmichael_numbers()
{
    freopen("Carmichael Numbers.txt","w",stdout);
    printf(" Carmichael Numbers :\n");
    unsigned long long a,n,i,cnt,res;
    for(n=2; n<SZ; n++)
    {
        if(arr[n] == 1)
        {
            cnt = 2;
            for(a=2; a<n; a++)
            {
                res = a;
                for(i=1; i<n; i++)
                {
                    res *= a;
                    res %= n;
                }
                if(res != a)
                    break;
                cnt ++;
            }
            if(cnt == n)
                printf("%d\n",n);
        }
    }
}*/

int carmichael[SZ];

int main()
{
    //sieve();
    //carmichael_numbers();
    //561, 1105, 1729, 2465, 2821, 6601, 8911, 10585, 15841, 29341, 41041, 46657, 52633, 62745, 63973
    carmichael[561] = carmichael[1105] = carmichael[1729] = carmichael[2465] = carmichael[2821] =
    carmichael[6601] = carmichael[8911] = carmichael[10585] = carmichael[15841] = carmichael[29341] =
    carmichael[41041] = carmichael[46657] = carmichael[52633] = carmichael[62745] = carmichael[63973] = 1;
    int n;
//    freopen("1.txt","r",stdin);
    while(scanf("%d",&n) == 1 && n)
    {
        if(carmichael[n])
            printf("The number %d is a Carmichael number.\n",n);
        else
            printf("%d is normal.\n",n);
    }
    return 0;
}
