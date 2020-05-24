#include<stdio.h>

int main()
{
    int n,i,j,k,temp,x[10];
    scanf("%d",&n);
    for(k=0;k<n;k++)
    {
        for(i=0;i<3;i++)
            scanf("%d",&x[i]);
        for(j=0;j<2;j++)
            for(i=j+1;i<3;i++)
                if(x[j]>x[i])
                {
                    temp=x[j];
                    x[j]=x[i];
                    x[i]=temp;
                }
        if(x[2]<x[0]+x[1])
            printf("OK\n");
        else
            printf("Wrong!!\n");
    }

    return 0;
}
