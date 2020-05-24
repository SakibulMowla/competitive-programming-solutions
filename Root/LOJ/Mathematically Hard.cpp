#include "stdio.h"

int phi[5000010];
unsigned long long cum_sum[5000010];

const int SZ = 5000001;

void euler_totient()
{
    int i, j;

    phi[1] = 1;

    for(i=2; i<SZ; i++)
        if(!phi[i])
            for(j=i; j<SZ; j+=i)
            {
                if(!phi[j])
                    phi[j] = j;
                phi[j] = phi[j] / i * (i-1);
            }
}

int main()
{
    euler_totient();

    int test = 0, t, a, b;

    for(a=2; a<SZ; a++)
        cum_sum[a] = (long long)phi[a] * (long long)phi[a], cum_sum[a] += cum_sum[a-1];

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d %d",&a,&b);
        printf("Case %d: %llu\n",++test,cum_sum[b]-cum_sum[a-1]);
    }

    return 0;
}
