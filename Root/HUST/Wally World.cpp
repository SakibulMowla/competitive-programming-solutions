#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;
int main ()
{
    double flag,x1,y1,x2,y2,a1,b1,a2,b2,flag2,dis1,dis2,x,y;
    int test=1;
    while(cin>>x1>>y1>>x2>>y2)
    {
        if(x1==0&&y1==0&&x2==0&&y2==0)
        break;
        cin>>a1>>b1>>a2>>b2;
        if(a1>a2)
        swap(a1,a2);
        if(b1>b2)
        swap(b1,b2);
        if(a1==a2)
        flag=2;
        else
        flag=1;
        if(flag==2)
        {
            y=((a1-x1)*(y1-y2))/(x1-x2);
            y+=y1;
            x=a1;
            if(y<b1||y>b2)
            flag2=0;
            else
            flag2=1;
            if((x1>a1&&x2>a2)||(x1<a1&&x2<a2))
            flag2=0;
        }
        else
        {
            x=((b1-y1)*(x1-x2))/(y1-y2);
              x+=x1;
            y=b1;
            if(x<a1||x>a2)
            flag2=0;
            else
            flag2=1;
            if((y1>b1&&y2>b2)||(y1<b1&&y2<b2))
            flag2=0;
        }
        if(flag2==0)
        {
            dis1=sqrt(pow(x1-x2 ,2) + pow(y1-y2,2));
            dis1/=2.;
            printf("Case %d: %.3lf\n",test++,dis1);
        }
        else
        {
            dis1=sqrt(pow(x1-a1 ,2) + pow(y1-b1,2));
            dis1+=sqrt(pow(x2-a1 ,2) + pow(y2-b1,2));
            dis2=sqrt(pow(x1-a2 ,2) + pow(y1-b2,2));
            dis2+=sqrt(pow(x2-a2 ,2) + pow(y2-b2,2));
            if(dis1<=dis2)
            {
                dis1/=2.;
                printf("Case %d: %.3lf\n",test++,dis1);
            }
            else
            {
                dis2/=2.;
                printf("Case %d: %.3lf\n",test++,dis2);
            }
        }
    }
    return 0;
}
