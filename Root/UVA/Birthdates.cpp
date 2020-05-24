#include <stdio.h>
#include <string.h>

int main()
{
    int n,maxim,minim,i,j,d,m,y;
    char old[20] , eld[20] , arr[20];
    while(scanf("%d",&n) == 1)
    {
        scanf("%s %d %d %d",old,&d,&m,&y);
        strcpy(eld,old);
        maxim = (y*365) + (m*30) + d;
        minim = maxim;
        for(i=0;i<n-1;i++)
        {
            scanf("%s %d %d %d",arr,&d,&m,&y);
            j = (y*365) + (m*30) + d;
            if(j < minim) strcpy(old,arr) , minim = j;
            if(j > maxim) strcpy(eld,arr) , maxim = j;
        }
        printf("%s\n%s\n",eld,old);
    }

    return 0;
}
