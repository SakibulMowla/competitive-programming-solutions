#include <stdio.h>
#include <string.h>

typedef struct{
        char job[100];
        int m;
}data;

int main()
{
    data arr[1010];
    char des[1000];
    int i,j,k,l,n,sum,len;
    scanf("%d %d",&i,&n);
    for(j=0;j<i;j++)
        scanf("%s %d",arr[j].job,&arr[j].m);

    for(j=0;j<n;j++)
    {
        sum=0;len=0;des[0]=' ';
        while(len!=1 || des[0]!='.')
        {
            scanf("%s",des);
            len=strlen(des);

            for(l=0;l<i;l++)
            {
                if(strcmp(des,arr[l].job)==0)
                    sum+=arr[l].m;
            }
        }
        printf("%d\n",sum);
    }

    return 0;
}
