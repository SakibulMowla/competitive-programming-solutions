#include<iostream>
#include<cstdio>
#include<cstring>
#define MAX 10005
#define LI long long int
using namespace std;
LI DATA[MAX], MAXSUM[MAX], MINSUM[MAX], N;
LI maxi(LI a, LI b)
{
    return a>b?a:b;
}
LI mini(LI a, LI b)
{
    return a<b?a:b;
}
void maxsum()
{
    memset(MAXSUM,0,sizeof(MAXSUM));
    LI sum=0;
    LI mx = -(1LL<<40);
    for(int i=0; i<N; i++)
    {
        sum+=DATA[i];
        sum = maxi(sum, DATA[i]);
        mx = maxi(mx,sum);
        MAXSUM[i] = mx;
    }
}
void maxsumr()
{
    memset(MAXSUM,0,sizeof(MAXSUM));
    LI sum=0;
    LI mx = -(1LL<<40);
    for(int j=N-1; j>=0; j--)
    {
        sum+=DATA[j];
        sum = maxi(sum, DATA[j]);
        mx = maxi(mx,sum);
        MAXSUM[j] = mx;
    }
}
void minsumr()
{
    memset(MINSUM,0,sizeof(MINSUM));
    LI sum=0;
    LI mi = (1LL<<40);
    for(int j=N-1; j>=0; j--)
    {
        sum+=DATA[j];
        sum = mini(sum, DATA[j]);
        mi = mini(mi,sum);
        MINSUM[j] = mi;
    }
}
void minsum()
{
    memset(MINSUM,0,sizeof(MINSUM));
    LI sum=0;
    LI mi = (1LL<<40);
    for(int i=0; i<N; i++)
    {
        sum+=DATA[i];
        sum = mini(sum, DATA[i]);
        mi = mini(mi,sum);
        MINSUM[i] = mi;
    }
}
int main()
{
    int Test;
    cin>>Test;
    while(Test--)
    {
        cin>>N;
        for(int i=0; i<N; i++) cin>>DATA[i];
        maxsumr();
        minsum();
        LI mm1, mm2;
        mm1=mm2=-(1LL<<40);
        for(int i=1; i<N; i++)
        {
            mm1 = maxi(mm1,(MAXSUM[i]-MINSUM[i-1])<0?(MAXSUM[i]-MINSUM[i-1])*(-1LL):(MAXSUM[i]-MINSUM[i-1]));
        }
        maxsum();
        minsumr();
        for(int i=0; i<N-1; i++)
        {
            mm2 = maxi(mm2, (MAXSUM[i]-MINSUM[i+1])<0?(MAXSUM[i]-MINSUM[i+1])*(-1LL):(MAXSUM[i]-MINSUM[i+1]));
        }
        cout<<maxi(mm1,mm2)<<endl;
    }
    return 0;
}
