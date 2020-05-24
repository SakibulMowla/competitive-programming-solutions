#include <stdio.h>

int main()
{
    int i, len, one1, one2;
    char arr[1010];

    while(scanf("%s",arr) == 1)
    {
        one1 = one2 = 0;
        for(i=0; arr[i]; i++)
            one1 += arr[i] == '1';
        scanf("%s",arr);
        for(i=0; arr[i]; i++)
            one2 += arr[i] == '1';
        one1 += one1 % 2;
        if(one1 >= one2)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}
