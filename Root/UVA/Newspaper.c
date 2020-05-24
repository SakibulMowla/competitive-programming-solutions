#include <stdio.h>
#include <string.h>

double arr[500];
char str[10010];
int main()
{
    int n,m,i,j,k,l,q;
    char ch,h,z;
    double p,sum;

    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d",&k);
        scanf("%c",&z);
        for(j=0; j<k; j++)
        {
            scanf("%c %lf",&ch,&p);
            scanf("%c",&z);
            arr[ch]=p;
        }

        scanf("%d%c",&m,&z);
        sum=0;
        for(j=0; j<m; j++)
        {
            gets(str);
            for(q=0; q<strlen(str); q++)
            {
                h=str[q];
                sum+=(arr[h]/100);
            }
        }
        printf("%.2lf$\n",sum);
        memset(arr,0,sizeof(arr));
    }


    return 0;
}
