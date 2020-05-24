#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct data { int num , indx; };
bool comp(data p,data q) { return p.num < q.num; };

bool mark[1010];

vector <data> input;

int main()
{
    data u;
    int t,test,maxim,num,i,j,n,sum,last;
    t = 0;
    scanf("%d",&test);
    while(test--)
    {
        input.clear();
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&num);
            u.num = num;
            u.indx = i;
            input.push_back(u);
        }
        sort(input.begin(),input.end(),comp);
        for(i=0;i<n;i++)
        printf(" %d",input[i].num);
        printf("\n");
        for(i=0;i<=n;i++) mark[i] = 0;
        maxim = 0;

        for(i=0;i<n;i++)
        {
            if(mark[i] == 0)
            {
                sum = input[i].num;
                printf("sum = %d\n",sum);
                last = input[i].indx;
                for(j=i+1;j<n;j++)
                {
                    if(input[j].indx > last)
                    {
                        sum += input[j].num;
                        printf("sum = %d\n",sum);
                        last = input[j].indx;
                        mark[j] = 1;
                    }
                }
                if(sum > maxim)
                    maxim = sum;
            }
        }
        printf("Case %d: %d\n",++t,maxim);
    }

    return 0;
}
