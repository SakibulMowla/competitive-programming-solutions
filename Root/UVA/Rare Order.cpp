#include <stdio.h>
#include <string.h>

int count[26];
int main()
{
    int i=0,j,k,len;
    char arr[5000][21],temp[21];
    while(scanf("%s",temp) == 1)
    {
        if(temp[0] == '#')break;
        len = strlen(temp);
        for(j=0;j<len;j++)
            arr[i][j] = temp[j];
        while(j<21)
            arr[i][j++] = '?';
        i++;
    }
    for(j=0;j<21;j++)
    {
        for(k=0;k<i;k++)
        {
            if(arr[k][j]>='A' && arr[k][j]<='Z')
                count[arr[k][j]-'A']++;
            if(count[arr[k][j]-'A'] == 1)
                printf("%c",arr[k][j]);
        }
    }
    printf("\n");

    return 0;
}
