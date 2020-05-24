#include <stdio.h>
#include <string.h>

int main()
{
    int num1[300],num2[300],test,i,first,second;
    char arr1[1010],arr2[1010];
    scanf("%d",&test);
    while(test--)
    {
        memset(num1,0,sizeof(num1));
        memset(num2,0,sizeof(num2));
        first = second = 1;
        scanf("%s %s",arr1,arr2);
        for(i=0;i<strlen(arr1);i++)
            num1[arr1[i]]++;
        for(i=0;i<strlen(arr2);i++)
            num2[arr2[i]]++;
        for(i=0;i<300;i++)
        {
            if((num1[i]==0 && num2[i]!=0) || (num1[i]!=0 && num2[i]==0))
            {
                first = 0;
                break;
            }
        }
        for(i=0;i<300;i++)
        {
            if(num1[i] != num2[i])
            {
                second = 0;
                break;
            }
        }
        if(first == second) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}
