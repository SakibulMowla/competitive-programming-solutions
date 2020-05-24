#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int main()
{
    char line[100];
    long n,i,len,time,pretime=0,h,m,s;
    double dis=0,speed,pre_speed=0;
    while(gets(line))
    {
        n=sscanf(line,"%ld:%ld:%ld %lf",&h,&m,&s,&speed);
        time=h*3600 + m*60 + s;
        dis+=pre_speed*(time-pretime)/3600;

        if(n==3)
            printf("%s %.2lf km\n",line,dis);
        else if(n==4)
            pre_speed=speed;

        pretime=time;
    }

    return 0;
}
