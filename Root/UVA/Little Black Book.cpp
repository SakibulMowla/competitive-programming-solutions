#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct data
{
    string title , first, last, street, H_phone, W_phone, mail , dept;
};

bool comp(data p,data q)
{
    return p.last < q.last;
}

vector <data> v;

int main()
{
    data u;
    int test,i,j,k;
    char arr[1000],dept[1000];
    while(scanf("%d",&test)==1)
    {
        getchar();
        v.clear();
        i = 0;
        while(test--)
        {
            scanf(" %[^\n]",dept);
            getchar();
            while(gets(arr))
            {
                if(strlen(arr) == 0) break;
                char *str;
                str = strtok(arr,",");
                j = 0;
                while(str != NULL)
                {
                    if(j==0) u.title = str;
                    else if(j==1) u.first = str;
                    else if(j==2) u.last = str;
                    else if(j==3) u.street = str;
                    else if(j==4) u.H_phone = str;
                    else if(j==5) u.W_phone = str;
                    else if(j==6) u.mail = str;

                    j++;
                    str = strtok(NULL,",");
                }
                u.dept = dept;
                v.push_back(u);
                i++;
            }
        }
        sort(v.begin(),v.end(),comp);
        for(j=0;j<i;j++)
        {
            printf("----------------------------------------\n");
            cout<<v[j].title<<" "<<v[j].first<<" "<<v[j].last<<endl;
            cout<<v[j].street<<endl;
            printf("Department: "); cout<<v[j].dept<<endl;
            printf("Home Phone: "); cout<<v[j].H_phone<<endl;
            printf("Work Phone: "); cout<<v[j].W_phone<<endl;
            printf("Campus Box: "); cout<<v[j].mail<<endl;

        }
    }

    return 0;
}
