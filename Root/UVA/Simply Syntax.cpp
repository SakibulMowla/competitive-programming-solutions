#include "stdio.h"
#include "string.h"

int main()
{
    char arr[300];
    int len,i,flag,stack_element;
    while(scanf("%s",arr) == 1)
    {
        len = strlen(arr);
        stack_element = flag = 0;
        for(i=len-1; i>=0; i--)
        {
            if(arr[i]>='a' && arr[i]<='z') stack_element++;
            else
            {
                if(arr[i] == 'N')
                {
                    if(stack_element == 0)
                    {
                        flag = 1;
                        break;
                    }
                }

                else
                {
                    if(stack_element < 2)
                    {
                        flag = 1;
                        break;
                    }
                    stack_element--;
                }
            }
        }
        if(flag || stack_element != 1) printf("NO\n");
        else printf("YES\n");
    }

    return 0;
}
