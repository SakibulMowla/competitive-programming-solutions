#include<stdio.h>
int main(void) {
    int n;
    static char months[13][20]= {"","January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    printf("enter the month's number: ");
    scanf("%d", &n);
    printf("%s\n", months[n]);
}
