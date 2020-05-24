#include "stdio.h"
#include "string.h"
#include "string"
#include "map"
#include "vector"
#include "iostream"

using namespace std;

char input[25][100];
map <string ,int> M;
vector <int> ans;

int main()
{
    int i,j,k,n,m,l,cnt,best,p,t=0;
    char arr[100];
    while(scanf("%d %d",&n,&k) == 2)
    {
        M.clear();
        for(i=0;i<n;i++)
        {
            scanf("%s",arr);
            M[arr] = 1;
        }
        best = -1;
        ans.clear();
        for(i=0;i<k;i++)
        {
//            printf("i = %d\n",i);
            scanf(" %[^\n]",input[i]);
//            printf("out = %s\n",input[i]);
            m = strlen(input[i]);
            cnt = l = 0;
            for(j=l;j<m;j++)
            {
                l = j;
                p = 0;
                while(l < m)
                {
                    if(tolower(input[i][l]) >= 'a' && tolower(input[i][l]) <= 'z')
                    {
                        arr[p++] = tolower(input[i][l]);
                        l++;
                    }
                    else
                    {
                        l++;
                        break;
                    }
                }
                arr[p] = '\0';
                if(M.find(arr) != M.end()) cnt++;
                l--;
            }
            if(cnt > best)
            {
                best = cnt;
                ans.clear();
                ans.push_back(i);
            }
            else if(cnt == best)
            {
                ans.push_back(i);
            }
        }
        printf("Excuse Set #%d\n",++t);
        for(i=0;i<ans.size();i++)
            printf("%s\n",input[ans[i]]);
        printf("\n");
    }

    return 0;
}
