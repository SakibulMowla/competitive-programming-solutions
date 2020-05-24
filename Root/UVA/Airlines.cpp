// 10075 - Airlines

#include <stdio.h>
#include <string.h>
#include <map>
#include <string>
#include <iostream>
#include <cmath>

using namespace std;

#define SZ 350
#define pi 3.141592653589793
#define inf 100000000
#define min(a,b) a<b?a:b


int matrix[SZ][SZ];
double lat[SZ],lon[SZ];
double latitude1,latitude2,longitude1,longitude2,R=6378.00;


int main()
{
    int test,i,j,k,point1,point2,a_dis;
    int m,n,q;
    char node[SZ],node1[SZ],node2[SZ];
    double dis;
    test=0;
    while(scanf("%d %d %d",&m,&n,&q) == 3)
    {
        if(m==0 && n==0 && q==0)break;

        map<string , int>map;
        for(i=1; i<=m; i++)
        {
            scanf("%s %lf %lf",node,&lat[i],&lon[i]);
            if( !map[node])
                map[node]=i;
        }
        for(i=1; i<=m; i++)
        {
            for(j=1; j<=m; j++)
            {
                matrix[i][j] = inf;
            }
        }
        for(i=1; i<=n; i++)
        {
            scanf("%s %s",node1,node2);
            point1=map[node1];
            point2=map[node2];

            latitude1=(lat[point1] * pi / 180.0);
            latitude2=(lat[point2] * pi / 180.0);
            longitude1=(lon[point1] * pi / 180.0);
            longitude2=(lon[point2] * pi / 180.0);
            dis=R * acos( cos(latitude1) * cos(latitude2) * cos(longitude1-longitude2) +
                         sin(latitude1) * sin(latitude2) );
            a_dis=(int)(dis+0.5);

            matrix[point1][point2]  = a_dis;
        }

        for(k=1; k<=m; k++)
            for(i=1; i<=m; i++)
                for(j=1; j<=m; j++)
                    matrix[i][j] = min(matrix[i][j] , matrix[i][k] + matrix[k][j]);

        if(test != 0)
            printf("\n");
        printf("Case #%d\n",++test);
        for(i=1; i<=q; i++)
        {
            scanf("%s %s",node1,node2);
            point1=map[node1];
            point2=map[node2];
            if(matrix[point1][point2] < inf)
                printf("%d km\n",matrix[point1][point2]);
            else
                printf("no route exists\n");
        }

    }

    return 0;
}
