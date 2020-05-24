#include <stdio.h>
#include <string.h>
#include <queue>
#include <map>
#include <iostream>

using namespace std;

#define SZ 1010

int main()
{
    queue <int> q[SZ];
    map <int , int> m;
    char arr[100],str[100];
    int team,member,t,i,j,len,test=0,k,flag;
//    freopen("1.txt","r",stdin);
    while(scanf("%d",&team) == 1 && team)
    {
        m.clear();
        for(i=1; i<=team; i++)
        {
            scanf("%d",&member);
            for(j=1; j<=member; j++)
            {
                scanf("%d",&len);
                m[len] = i;
            }
        }
        printf("Scenario #%d\n",++test);
        k = 0;
        while(scanf(" %[^\n]",arr) == 1 && strcmp(arr,"STOP"))
        {
            flag = 0;
            len = sscanf(arr,"%s %d",str,&member);
            if(len == 2)
            {
                for(i=0;i<=k;i++)
                {
                    if( !q[i].empty() )
                    {
                        j = q[i].front();
                        if(m[j] == m[member])
                        {
                            q[i].push(member);
                            flag = 1;
                            break;
                        }
                        if(k == 0)
                        {
                            q[k].push(member);
                            flag = 1;
                            break;
                        }
                    }
                }
                if(flag == 0)
                    q[++k].push(member);
            }
            else
            {
                for(i=0; i<=k; i++)
                    if( !q[i].empty() )
                    {
                        j = q[i].front();
                        q[i].pop();
                        printf("%d\n",j);
                        break;
                    }
            }
        }
        printf("\n");
        for(i=0; i<=k; i++)
            while( !q[i].empty() )
                q[i].pop();
    }

    return 0;
}
