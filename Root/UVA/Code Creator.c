#include<stdio.h>
#include<string.h>

typedef struct
{
    char line[100];
    int a[100];
} data;
int main()
{
    int n,m,i,j,k,l=0,len;
    data arr[100];
    while(scanf("%d",&n)==1)
    {
        l++;
        if(n==0)
            break;
        for(i=0; i<n; i++)
        {
            scanf(" %[^\n]",arr[i].line);
            arr[i].a[i]=strlen(arr[i].line);
        }

        printf("Case %d:\n",l);
        printf("#include<string.h>\n#include<stdio.h>\nint main()\n{\n");

        for(i=0; i<n; i++)
        {
            printf("printf(\"");
            for(j=0; j<arr[i].a[i]; j++)
            {
                if(arr[i].line[j]=='"' || arr[i].line[j]==92)
                    printf("%c",92);
                printf("%c",arr[i].line[j]);
            }

            printf("\\n\");\n");
        }
        printf("printf(\"\\n\");\nreturn 0;\n}\n");
    }
    return 0;
}
