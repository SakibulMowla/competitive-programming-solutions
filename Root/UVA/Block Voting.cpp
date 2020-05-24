#include <stdio.h>
#include <string.h>

int vote[25];
int party , sum , coalision , n , need , total_vote;

void backtrack(int x)
{
    if(sum <= need)
        if(sum + vote[party] > need)
            coalision++;
    int i;
    for(i=x;i<n;i++)
        if(i != party)
        {
            sum += vote[i];
            backtrack(i+1);
            sum -= vote[i];
        }
}

int main()
{
    int test,i;
    scanf("%d",&test);
    while(test--)
    {
        total_vote = 0;
        scanf("%d",&n);
        for(i=0; i<n; i++)
            scanf("%d",&vote[i]) , total_vote += vote[i];
        need = total_vote / 2;
        for(party=0; party<n; party++)
        {
            sum = 0;
            coalision = 0;
            backtrack(0);
            printf("party %d has power index %d\n",party+1,coalision);
        }
        printf("\n");
    }

    return 0;
}
