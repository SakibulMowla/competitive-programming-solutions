#include <stdio.h>
#include <string.h>

int arr[200][20][50];

int main()
{
    int n,q,i,j,k,l,flag,t,cnt;
    char str[50] , tmp[50] , ans[50];
    scanf("%d %d",&n,&q);
    scanf("%s",str);
    for(i=0; i<n; i++)
    {
        for(j=0; j<17; j++)
        {
            scanf("%s",tmp);
            for(k=0; k<strlen(tmp); k++)
            {
                if(tmp[k] == '*')
                    arr[str[i]][j][k]++;
            }
        }
    }

    for(t=0; t<q; t++)
    {
        scanf("%s",tmp);
        for(i=0; i<strlen(tmp); i++)
        {
            flag = 0;
            for(k=0; k<17; k++)
            {
                for(l=0; l<44; l++)
                {
                    if(arr[tmp[i]][k][l] == 1)
                    {
                        cnt = 0;
                        for(j=0; j<strlen(tmp); j++)
                        {
                            if(i==j) continue;
                            if(arr[tmp[j]][k][l] == 0) cnt++;
                        }
                        if(cnt == strlen(tmp) - 1)
                        {
                            flag = 1;
                            break;
                        }
                    }
                    if(flag == 1) break;
                }
                if(flag == 1) break;
            }
            if(flag == 1) ans[i] = 'Y';
            else ans[i] = 'N';
        }

        ans[i] = '\0';
        printf("Query %d: %s\n",t+1,ans);

    }

    return 0;
}
