#include "bits/stdc++.h"

int main()
{
    char arr[50];
    int i, j, t, k;
    int val[10];

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&k);
        for(i=0; i<8; i++) val[i] = 0;

        scanf("%s",arr);
        for(i=1; i<39; i++)
        {
            if(arr[i-1]=='T' && arr[i] == 'T' && arr[i+1] == 'T')
                val[0]++;
            else if(arr[i-1]=='T' && arr[i] == 'T' && arr[i+1] == 'H')
                val[1]++;
            else if(arr[i-1]=='T' && arr[i] == 'H' && arr[i+1] == 'T')
                val[2]++;
            else if(arr[i-1]=='T' && arr[i] == 'H' && arr[i+1] == 'H')
                val[3]++;
            else if(arr[i-1]=='H' && arr[i] == 'T' && arr[i+1] == 'T')
                val[4]++;
            else if(arr[i-1]=='H' && arr[i] == 'T' && arr[i+1] == 'H')
                val[5]++;
            else if(arr[i-1]=='H' && arr[i] == 'H' && arr[i+1] == 'T')
                val[6]++;
            else if(arr[i-1]=='H' && arr[i] == 'H' && arr[i+1] == 'H')
                val[7]++;
        }

        printf("%d %d %d %d %d %d %d %d %d\n",k,val[0],val[1],val[2],val[3],val[4],val[5],val[6],val[7]);
    }

    return 0;
}
