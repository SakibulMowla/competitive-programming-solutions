#include <stdio.h>

int main()
{
    int n,i,x1,y1,x2,y2,x3,y3,x4,y4;

    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d %d %d %d %d %d %d %d",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
        if((x3<=x1 && x4<=x1) || (y3<=y1 && y4<=y1) || (x3>=x2 && x4>=x2) || (y3>=y2 && y4>=y2))
            printf("No Overlap\n");
        else if((x3>=x1 && x4<=x2) && (y3>=y1 && y4<=y2))
            printf("%d %d %d %d\n",x3,y3,x4,y4);
        else if((x1>=x3 && x2<=x4) && (y1>=y3 && y2<=y4))
            printf("%d %d %d %d\n",x1,y1,x2,y2);
        else if(x3>=x1 && y3>=y1)
        {
            if(x4>=x2)
            {
                if(y4>=y1 && y4<=y2)
                    printf("%d %d %d %d\n",x3,y3,x2,y4);
                else if(y4>y2)
                    printf("%d %d %d %d\n",x3,y3,x2,y2);
                else if(y4<y1)
                    printf("%d %d %d %d\n",x3,y3,x2,y1);
            }
            else if(y4>=y2)
            {
                if(x4>=x1 && x4<=x2)
                    printf("%d %d %d %d\n",x3,y3,x4,y2);
                else if(x4>x2)
                    printf("%d %d %d %d\n",x3,y3,x2,y2);
                else if(x4<x1)
                    printf("%d %d %d %d\n",x3,y3,x1,y2);
            }
        }
        else if(x4<=x2 && y4 <=y2)
        {
            if(x3<=x1)
            {
                if(y3>=y1 && y3<=y2)
                    printf("%d %d %d %d\n",x1,y3,x4,y4);
                else if(y3>y2)
                    printf("%d %d %d %d\n",x1,y2,x4,y4);
                else if(y3<y1)
                    printf("%d %d %d %d\n",x1,y1,x4,y4);
            }
            else if(y3<=y1)
            {
                if(x3>x1 && x3<=x2)
                    printf("%d %d %d %d\n",x3,y1,x4,y4);
                else if(x3<x1)
                    printf("%d %d %d %d\n",x1,y1,x4,y4);
                else if(x3>x2)
                    printf("%d %d %d %d\n",x2,y1,x4,y4);
            }
        }

        if(i < n-1)
            printf("\n");
    }
    return 0;
}
