#include "stdio.h"
#include "string.h"
#include "stdbool.h"

int main()
{
    bool sol[200] , guess[200];
    char arr[200] , text[200];
    int t,i,j,k,len1,len2;
    while(scanf("%d",&t) == 1 && t != -1)
    {
        scanf("%s %s",arr,text);
        len1 = strlen(arr);
        len2 = strlen(text);
        memset(sol,0,sizeof(sol));
        memset(guess,0,sizeof(guess));
        for(i=0;i<len1;i++) sol[ arr[i] ] = 1;

        printf("Round %d\n",t);
        for(i=0;i<len2;i++)
        {
            for(j=0;j<len1;j++)
            {
                if(arr[j] == text[i])
                {
                    sol[ arr[j] ] = 0;
                    break;
                }
            }
            if(j == len1) guess[ text[i] ] = 1;
            for(j=0;j<200 && sol[j] == 0;j++);
            if(j == 200) {printf("You win.\n");break;}
            k = 0;
            for(j=0;j<200;j++) if(guess[j] == 1) k++;
            if(k >= 7) {printf("You lose.\n");break;}
        }
        if(i == len2) printf("You chickened out.\n");
    }

    return 0;
}
