#include "stdio.h"
#include "string.h"

int main()
{
    int inst[110],n,i,j,k,left,right,t;
    char arr[20],str1[10],str2[10];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        left = right = 0;
        for(i=1;i<=n;i++)
        {
            scanf(" %[^\n]",arr);
            k = sscanf(arr,"%s %s %d",str1,str2,&j);
            if(k == 1)
            {
                if(strcmp(str1,"LEFT") == 0) inst[i] = -1 , left++;
                else if(strcmp(str1,"RIGHT") == 0) inst[i] = 1 , right++;
            }
            else
            {
                if(inst[j] == -1) left++;
                else right++;
                inst[i] = inst[j];
            }
        }
        printf("%d\n",right-left);
    }

    return 0;
}
