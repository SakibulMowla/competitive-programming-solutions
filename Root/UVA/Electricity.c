#include <stdio.h>

typedef struct
{
    int dd,mm,yy,read;
} data;

int day;
int month;
int year;

void next_day_generator(int d,int m,int y)
{
    if(((y%4 == 0 && y%100 != 0) || y%400 == 0) && m==2  )
    {
        if(d==29)
        {
            day=1;
            month=m+1;
            year=y;
        }
        else
        {
            day=d+1;
            month=m;
            year=y;
        }
    }
    else if(d==31 && m==12)
    {
        day=1;
        month=1;
        year=y+1;
    }
    else if(d==31 && (m==1 || m==3 || m==5 || m==7 || m==8 || m==10 ))
    {
        day=1;
        month=m+1;
        year=y;
    }
    else if(d==30 && (m==4 || m==6 || m==9 || m==11))
    {
        day=1;
        month=m+1;
        year=y;
    }
    else if(d==28 && m==2)
    {
        day=1;
        month=m+1;
        year=y;
    }
    else
    {
        day=d+1;
        month=m;
        year=y;
    }
    return;
}

int main()
{
    data arr[1000];
    int n,i,count,sum;
    while(scanf("%d",&n)==1 && n)
    {
        count=0;
        sum=0;
        for(i=0; i<n; i++)
        {
            scanf("%d %d %d %d",&arr[i].dd,&arr[i].mm,&arr[i].yy,&arr[i].read);
        }

        for(i=0; i<n-1; i++)
        {
            day=month=year=0;
            if(arr[i+1].dd-arr[i].dd > 1 || arr[i+1].mm-arr[i].mm > 1 || arr[i+1].yy-arr[i].yy > 1)
                continue;
            next_day_generator(arr[i].dd,arr[i].mm,arr[i].yy);

            if(day==arr[i+1].dd && month==arr[i+1].mm && year==arr[i+1].yy)
            {
                ++count;
                sum+=arr[i+1].read-arr[i].read;
            }
        }

        printf("%d %d\n",count,sum);
    }
    return 0;
}
