#include "stdio.h"
#include "string.h"
#include "string"
#include "iostream"
#include "algorithm"

using namespace std;

const int inf = (1LL<<28);

int mat[30][30];
char arr[30][30];

void floyd()
{
    int i,j,k;
    for(k=0; k<26; k++)
        for(i=0; i<26; i++)
            for(j=0; j<26; j++)
            {
                if(mat[i][k] + mat[j][k] < mat[i][j])
                {
                    mat[i][j] = mat[i][k] + mat[j][k];
                    arr[i][j] = arr[j][k];
                }
            }
//    for(k=0;k<26;k++)
//    for(i=0;i<26;i++)
//    for(j=0;j<26;j++)
//    {
//        if(mat[i][k] + mat[j][k] < mat[i][j])
//        {
//            mat[i][j] = mat[i][k] + mat[j][k];
//            arr[i][j] = k + 'a';
//        }
//    }
}

int main()
{
    int i,j,k,n,m,p,q,cost;
    string s,t,ans;
    char a,b;
    while(cin >> s >> t)
    {
        cin >> n;
        for(i=0; i<30; i++) for(j=0; j<30; j++)
            {
                mat[i][j] = inf;
                mat[i][i] = 0;
            }
        while(n--)
        {
            cin >> a >> b >> m;
            if(mat[a-'a'][b-'a'] > m)
            {
                mat[a-'a'][b-'a'] = min(mat[a-'a'][b-'a'] , m);
                mat[b-'a'][a-'a'] = min(mat[b-'a'][a-'a'] , m);
                arr[a-'a'][b-'a'] = b;
                arr[b-'a'][a-'a'] = b;
            }
        }
        floyd();
        if(s.size() != t.size())
        {
            printf("-1\n");
            return 0;
        }
        k = s.size();
        ans = "";
        cost = 0;
        for(i=0; i<k; i++)
        {
            if(s[i] == t[i])
            {
                ans += s[i];
                continue;
            }
            p = s[i]-'a';
            q = t[i]-'a';
            j = min(mat[p][q] , mat[q][p]);
            if(j == inf)
            {
//                printf("I = %d jad\n",i);
                printf("-1\n");
                return 0;
            }
            if(mat[p][q] < mat[q][p])
            {
                cost += mat[p][q];
                ans += arr[p][q];
            }
            else
            {
                cost += mat[q][p];
                ans += arr[q][p];
            }
        }
        printf("%d\n%s\n",cost,ans.c_str());
    }

    return 0;
}
