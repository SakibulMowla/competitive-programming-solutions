#include "stdio.h"
#include "string.h"
#include "string"
#include "algorithm"
#include "vector"
#include "iostream"

using namespace std;

struct data
{
    char ch;int ocur;
};

bool comp(data p,data q)
{
    return p.ocur > q.ocur;
}

char M[300];
vector <data> input , output;

int main()
{
    int t,i,j,k,n,m;
    data u;
    string str1,str2,s;
    scanf("%d",&t);
    while(t--)
    {
        cin >> str1 >> str2;
        s = str2;
        stable_sort(str1.begin(),str1.end());
        stable_sort(str2.begin(),str2.end());
        input.clear();
        output.clear();
        k = str1.size();
        for(i=0;i<k;i++)
        {
            j = i;
            m = 1;
            while(j+1 < k)
            {
                if(str1[j+1] == str1[j]) j++ , m++;
                else break;
            }
            u.ch = str1[i];
            u.ocur = m;
            input.push_back(u);
            i = j;
        }
        stable_sort(input.begin(),input.end(),comp);
        k = str2.size();
        for(i=0;i<k;i++)
        {
            j = i;
            m = 1;
            while(j+1 < k)
            {
                if(str2[j+1] == str2[j]) j++ , m++;
                else break;
            }
            u.ch = str2[i];
            u.ocur = m;
            output.push_back(u);
            i = j;
        }
        stable_sort(output.begin(),output.end(),comp);
        k = input.size();
        for(i=0;i<k;i++)
            M[ output[i].ch ] = input[i].ch;
        k = str2.size();
        for(i=0;i<k;i++)
            printf("%c",M[ s[i] ]);
        printf("\n");
        if(t) printf("\n");
    }

    return 0;
}
