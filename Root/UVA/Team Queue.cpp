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
    freopen("1.txt","r",stdin);
    while(scanf("%d",&team) == 1 && team)
    {
        m.clear();
        for(i=0; i<team; i++)
        {
            scanf("%d",&member);
            for(j=0; j<member; j++)
            {
                scanf("%d",&len);
                m[len] = i;
            }
        }
        printf("Scenario #%d\n",++test);
        flag = k = 0;
        while(scanf(" %[^\n]",arr) == 1 && strcmp(arr,"STOP"))
        {
            len = sscanf(arr,"%s %d",str,&member);
            if(len == 2)
            {
                if(m.find(member) == m.end())
                {
                    if(flag == 0)
                    {
                        flag = ++k;
                        q[flag].push(member);
                    }
                    else
                    {
                        q[flag].push(member);
                    }
                }
                else
                {
                    if(flag == 0)
                    {
                        q[m[member]].push(member) , k = max(k,m[member]);
                    }
                    else
                    {
                        if(m[member] >= flag)
                            q[m[member]+1].push(member) , k = max(k,m[member]+1);
                        else
                            q[m[member]].push(member) , k = max(k,m[member]);
                    }

                }

            }
            else
            {
                for(i=0; i<=team; i++)
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
        for(i=0; i<team; i++)
            while( !q[i].empty() )
                q[i].pop();
    }

    return 0;
}
