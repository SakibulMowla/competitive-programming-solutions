#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

const int inf = 1000000000;

int maty[30][30] , matm[30][30];

void floyd_y()
{
    int k,i,j;
    for(k=1; k<=26; k++)
        for(i=1; i<=26; i++)
            for(j=1; j<=26; j++)
                maty[i][j] = min( maty[i][j] , maty[i][k] + maty[k][j] );
}

void floyd_m()
{
    int k,i,j;
    for(k=1; k<=26; k++)
        for(i=1; i<=26; i++)
            for(j=1; j<=26; j++)
                matm[i][j] = min( matm[i][j] , matm[i][k] + matm[k][j] );
}

int main()
{
    int t,test,i,j,k,l,cost,meet;
    char age , dir , n1 , n2 , arr[100];
    vector <char> result;
    map <int , int > m;
    while(scanf("%d",&test) == 1 && test)
    {
        m.clear();
        for(i=1; i<=26; i++)
        {
            for(j=1; j<=26; j++)
                maty[i][j] = inf;
            maty[i][i] = 0;
        }
        for(i=1; i<=26; i++)
        {
            for(j=1; j<=26; j++)
                matm[i][j] = inf;
            matm[i][i] = 0;
        }
        for(i=1; i<=test; i++)
        {
            scanf(" %[^\n]",arr);
            sscanf(arr,"%c %c %c %c %d",&age,&dir,&n1,&n2,&cost);
            if(age == 'Y')
            {
                if(dir == 'U')
                    maty[n1-64][n2-64] = min(cost , maty[n1-64][n2-64]);
                else if(dir == 'B')
                    maty[n1-64][n2-64] = maty[n2-64][n1-64] = min(cost , maty[n1-64][n2-64]);
            }
            else if(age == 'M')
            {
                if(dir == 'U')
                    matm[n1-64][n2-64] = min(cost , matm[n2-64][n1-64]);
                else if(dir == 'B')
                    matm[n1-64][n2-64] = matm[n2-64][n1-64] = min(cost , matm[n2-64][n1-64]);
            }
            m[n1-64] = m[n2-64] = 1;
        }

        floyd_y();
        floyd_m();
        meet = inf;

        scanf(" %c %c",&n1,&n2);
        result.clear();
        if(n1 == n2)
        {
            printf("0");
            for(i=1; i<=26; i++)
            {
                if(maty[n1-64][i] + matm[n2-64][i] == 0)
                {
                    result.push_back(i+64);
                }
            }
            for(i=0; i<result.size(); i++)
                printf(" %c",result[i]);
            printf("\n");
            continue;
        }
        for(i=1; i<=26; i++)
        {
            if( m.find(i)==m.end())continue;
            if(maty[n1-64][i] + matm[n2-64][i] < meet)
            {
                meet = maty[n1-64][i] + matm[n2-64][i];
            }
        }
        if(meet == inf)
        {
            printf("You will never meet.\n");
            continue;
        }

        for(i=1; i<=26; i++)
        {
            if(maty[n1-64][i] + matm[n2-64][i] == meet)
            {
                result.push_back(i+64);
            }
        }
        printf("%d",meet);
        for(i=0; i<result.size(); i++)
            printf(" %c",result[i]);
        printf("\n");
    }

    return 0;
}
