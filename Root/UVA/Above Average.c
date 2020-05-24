#include<stdio.h>
int main()
{
    int i,j,m,n;
    int num[1000];
    double per[1000];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        int sum=0;
        scanf("%d",&m);
        for(j=0;j<m;j++)
        {
            scanf("%d",&num[j]);
            sum+=num[j];
        }
        double avg=sum/m;
        double c=0;
        for(j=0; j<m; j++)
        {
            if(num[j]>avg)
            {
                c++;
            }
        }
        per[i]=((c/m)*100);
    }
    for(i=0; i<n; i++)
    {
        printf("%.3lf%%\n",per[i]);
    }
    return 0;
}
