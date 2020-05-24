#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SZ 1000000
int arr[1000010];

int SOD(int n)
{
    int sum;
    sum = n;
    while(n)
    {
        sum += n%10;
        n /= 10;
    }
    return sum;
}

int main()
{
    int i,digit_sum;
    for(i=1;i<=SZ;i++)
    {
        if(arr[i] == 0)
        {
            digit_sum = SOD(i);
            while(digit_sum <= SZ)
            {
                arr[digit_sum] = 1;
                digit_sum = SOD(digit_sum);
                if(arr[digit_sum] == 1)
                    break;
            }
        }
    }
    for(i=1;i<=SZ;i++)
        if(arr[i] == 0)
            printf("%d\n",i);
    return 0;
}
