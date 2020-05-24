//56 45 25 7

#include "stdio.h"

int main(){
    double a, b, c, d;
    int cnt = 0, t;

    scanf("%d",&t);

    while(t--){
        scanf("%lf %lf %lf %lf",&a,&b,&c,&d);
        if(((a<=56.0 && b<=45.0 && c<=25.0) || (a+b+c <= 125.0)) && d<=7.0){
            puts("1");
            cnt++;
        }
        else
            puts("0");
    }

    printf("%d\n",cnt);

    return 0;
}
