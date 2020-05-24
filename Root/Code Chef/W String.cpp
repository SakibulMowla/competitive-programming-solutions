#include "stdio.h"
#include "string.h"
#include "vector"
#include "iostream"
using namespace std;
#define SZ 10100

int cnt[30][SZ];
char arr[SZ];
vector <int> v;

int main()
{
    int t, i, j, k, len, ans, tmp, tmp1, pos, pos1, pos2;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%s",arr+1);
        len = strlen(arr+1);

        v.clear();

        for(i=1; i<=len; i++)
        {
            if(arr[i] == '#')  v.push_back(i) , j = -1;
            else j = arr[i]-'a';
            for(k=0; k<26; k++)
            {
                if(k==j) cnt[k][i] = cnt[k][i-1] + 1;
                else cnt[k][i] = cnt[k][i-1];
            }
        }

        k = v.size();
        ans = -1;

        for(i=0; i<k-2; i++)
        {
            tmp = 0;
            pos = v[i];

            tmp1 = -1;

            for(j=0; j<26; j++)
            {
                tmp1 = max(tmp1, cnt[j][pos-1]);
            }

            if(tmp1 <= 0) continue;

            tmp += tmp1;

            pos1 = v[i+1];

            tmp1 = -1;

            for(j=0; j<26; j++)
            {
                tmp1 = max(tmp1, cnt[j][pos1-1]-cnt[j][pos]);
            }

            if(tmp1 <= 0) continue;

            tmp += tmp1;

            pos2 = v[i+2];

            tmp1 = -1;

            for(j=0; j<26; j++)
            {
                tmp1 = max(tmp1, cnt[j][pos2-1]-cnt[j][pos1]);
            }

            if(tmp1 <= 0) continue;

            tmp += tmp1;

            tmp1 = -1;

            for(j=0; j<26; j++)
            {
                tmp1 = max(tmp1, cnt[j][len]-cnt[j][pos2]);
            }

            if(tmp1 <= 0) continue;

            tmp += tmp1;

            if(tmp > ans) ans = tmp;
        }

        if(ans > 0) ans += 3;

        if(ans <=0 ) printf("0\n");
        else printf("%d\n",ans);
    }

    return 0;
}
