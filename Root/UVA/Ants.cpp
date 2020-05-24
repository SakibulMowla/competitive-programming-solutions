#include <stdio.h>
#include <math.h>

int main()
{
    int maxim , minim , test , length , n , i , pos , shortest , longest;
    scanf("%d",&test);
    while(test--)
    {
        maxim = minim = -1;
        scanf("%d %d",&length,&n);
        while(n--)
        {
            scanf("%d",&pos);
            shortest = length - pos;
            longest = pos;
            if(shortest > longest)
            {
                longest ^= shortest ^= longest ^= shortest;
            }
            if(shortest > minim) minim = shortest;
            if(longest > maxim) maxim = longest;
        }
        printf("%d %d\n",minim,maxim);
    }

    return 0;
}
