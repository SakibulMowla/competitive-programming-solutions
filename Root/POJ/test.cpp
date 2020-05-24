#include <iostream>
#include <cstring>
#include <cstdio>
#define N 10010
using namespace std;

int a[N], mode[N];
int n;

int main()
{
    scanf("%d", &n);
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        s = (s + a[i]) % n;
        mode[i] = s;
    }
    int k, l;
    int f = 0;
    for (int i = 0; i < n; i++)
    {
        if (mode[i] == 0)
        {
            f = 1;
            printf("%d\n", i + 1);
            for (int t = 0; t <= i; t++)
                printf("%d\n", a[t]);
            break;
        }
        for (int j = i + 1; j < n; j++)
        {
            if(mode[i] == mode[j])
            {
                f = 2;
                k = i; 
                l = j;
                break;
            }
        }
        if (f == 2)
            break;
    }
    if (f == 2)
    {
        printf("%d\n", l - k);
        for (int i = k + 1; i <= l; i++)
            printf("%d\n", a[i]);
    }
    return 0;
}
