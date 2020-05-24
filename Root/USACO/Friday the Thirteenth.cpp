/*
ID: sakibul1
PROG: friday
LANG: C++
*/

#include "bits/stdc++.h"

int leap(int n)
{
    if(n%400 == 0 || (n%4 == 0 && n%100 != 0)) return 1;
    return 0;
}

int week[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int day(int year, int month)
{
    int ans;
    if(month == 2)
        ans = week[month]+leap(year)-13;
    else
        ans = week[month]-13;
    ans += 13;
    return ans;
}

int days[10];

int main()
{
    freopen("friday.in", "r", stdin);
    freopen("friday.out", "w", stdout);

    int n, cur, i, year, month;

    scanf("%d",&n);

    cur = 0;

    for(year=1900; year<=1900+n-1; year++)
    {
        for(month=1; month<=12; month++)
        {
            days[cur]++;
            cur = (cur + day(year, month)) % 7;
        }
    }

    for(i=0; i<7; i++)
    {
        if(i) printf(" ");
        printf("%d",days[i]);
    }
    puts("");

    return 0;
}
