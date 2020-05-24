#include<iostream>
#include<cstdio>
#include<string.h>
#define MAX 1800
using namespace std;

int ANS[MAX+1][MAX+1], TEM[MAX+1];

int main()
{
    int N, K;
    while(cin>>N>>K)
    {
        memset(ANS, 0, sizeof(ANS));
        ANS[0][MAX] = (K-1);
        ANS[1][MAX] = K*(K-1);
        for(int i=2; i<N; i++)
        {
            memset(TEM, 0, sizeof(TEM));
            int k;
            for(k=MAX; k>=0; k--) TEM[k] = ANS[i-1][k] + ANS[i-2][k];
            for(k=MAX; k>=0; k--)
            {
                if(TEM[k]>9)
                {
                    TEM[k-1] += TEM[k]/10;
                    TEM[k] %= 10;
                }
            }
            int l;
            for(l=MAX; l>=0; l--) ANS[i][l] = TEM[l]*(K-1);
            for(l=MAX; l>=0; l--)
            {
                if(ANS[i][l]>9)
                {
                    ANS[i][l-1] += ANS[i][l]/10;
                    ANS[i][l] %= 10;
                }
            }
        }
        int g=0;
        while(ANS[N-1][g]==0) g++;
        for(; g<=MAX; g++) cout<<ANS[N-1][g];
        cout<<endl;
    }
    return 0;
}

