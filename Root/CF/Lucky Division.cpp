#include <stdio.h>

int arr[] = {4,7,47,44,74,77,444,447,474,744,774,747,477,777};

int main()
{
    int i,n;
    bool flag;
    while(scanf("%d",&n) == 1)
    {
        flag = false;
        for(i=0; i<14; i++)
        {
            if(n % arr[i] == 0)
            {
                flag = true;
                break;
            }
        }
        if(flag)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}
