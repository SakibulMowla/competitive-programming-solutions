#include "stdio.h"
#include "string.h"
#include "string"
#include "stdlib.h"
#include "math.h"
#include "map"
#include "vector"
#include "queue"
#include "stack"
#include "set"
#include "iostream"
#include "algorithm"

#define sz(a) ((int)a.size())

using namespace  std;

vector <int> inp1, inp2;
int powe[110];

bool comp(int a,int b)
{
    return a > b;
}

int main()
{
    int n, m, i, j, start, ok, ans, ans1, ans2;
    char arr[10];

    while(scanf("%d %d",&m,&n) == 2)
    {
        ans = ans1 = ans2 = 0;
        inp1.clear();
        inp2.clear();
        for(i=0; i<m; i++)
        {
            scanf("%s %d",arr,&j);
            if(strcmp(arr,"ATK") == 0) inp1.push_back(j);
            else inp2.push_back(j);
        }
        for(i=0; i<n; i++)
            scanf("%d",&powe[i]);
        sort(powe,powe+n,comp);
        sort(inp1.begin(),inp1.end());
        sort(inp2.begin(),inp2.end());
        j = ok = 0;
        for(i=n-1; i>=0; i--)
            if(j<sz(inp1)&&powe[i] > inp1[j])
                ok++,j++;
//                printf("ok = %d\n",ok);
        j=0;
        for(i=0; i<n&&j<ok; i++,j++)
//            if(j < inp1.size() && powe[i] >= inp1[j])
            ans1 += powe[i] - inp1[j];
//        else break;
        j=0;
        for(i=0; i<n; i++,j++)
            if(j < inp1.size() && powe[i] >= inp1[j])
                ans2 += powe[i] - inp1[j];
            else break;

//        printf("ans = %d\n",ans);
        if(j == inp1.size())
        {
//            printf("yes\n");
            start = 0;
            if(inp2.size())
                for(i=n-1; i>=inp1.size(); i--)
                {
                    if(powe[i] > inp2[0])
                    {
                        start = i;
                        break;
                    }
                }
            else start = n-1;
            ok = j = 0;

            for(i=start; i>=inp1.size() && j<inp2.size(); i--,j++)
                if(powe[i] > inp2[j])
                    ok++;
//            printf("s %d %d\n",start,start-inp2.size());
            if(ok == inp2.size())
                for(i=start-inp2.size(); i>=(int)inp1.size(); i--)
                    ans1 += powe[i];
        }

        if(ok == inp1.size())
        {
//            printf("yes\n");
            start = 0;
            if(inp2.size())
                for(i=n-1; i>=inp1.size(); i--)
                {
                    if(powe[i] > inp2[0])
                    {
                        start = i;
                        break;
                    }
                }
            else start = n-1;
            ok = j = 0;

            for(i=start; i>=inp1.size() && j<inp2.size(); i--,j++)
                if(powe[i] > inp2[j])
                    ok++;
//            printf("s %d %d\n",start,start-inp2.size());
            if(ok == inp2.size())
                for(i=start-inp2.size(); i>=(int)inp1.size(); i--)
                    ans1 += powe[i];
        }
printf("%d %d\n",ans1,ans2);

        printf("%d\n",max(ans1,ans2));
    }

    return 0;
}
/*
13 14
ATK 2896
ATK 2919
ATK 2117
ATK 2423
ATK 2636
ATK 2003
ATK 2614
ATK 2857
ATK 2326
ATK 2958
ATK 2768
ATK 3017
ATK 2788
3245
3274
3035
3113
2982
3312
3129
2934
3427
3316
3232
3368
3314
3040
*/
