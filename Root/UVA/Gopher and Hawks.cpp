#include <stdio.h>
#include <string.h>

double distance;
int n;

int main()
{
    double m,v,start1,start2,target1,target2,node1[1010],node2[1010];
    char arr[100],z;
    while(scanf("%lf %lf",&v,&m) == 2 && v && m)
    {
        printf("Yes\n");
        distance=m*v*60;
        scanf("%lf %lf",&start1,&start1);
        scanf("%lf %lf%c",&target1,&target1,&z);
        n=0;
        while(gets(arr))
        {
            if(arr[0] == '\n')break;
            sscanf(arr,"%lf %lf",&node1[++n],&node2[++n]);

        }
    }
    return 0;
}
