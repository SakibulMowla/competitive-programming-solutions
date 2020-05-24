#include <stdio.h>
#include <string.h>

int main()
{
    char z,arr1[1000],arr2[1000],s2[1000],s3[1000],s4[1000],s5[1000];
    int i,j,k,l,n,m,len1,len2,c,f,p;
    scanf("%d%c",&n,&z);
    for(m=0; m<n; m++)
    {
        gets(arr1);
        gets(arr2);
        len1=strlen(arr1);
        len2=strlen(arr2);
        for(i=0; i<len1; i++)
        {
            f=0;
            if(arr1[i]=='<' && f==0)
            {
                f++;
                for(j=i+1,c=0; j<len1; j++,c++)
                {
                    if(arr1[j]=='>')
                    {
                        s2[c]='\0';
                        break;
                    }
                    s2[c]=arr1[j];
                    printf("%c",arr1[j]);
                }
                for(k=j+1,c=0; k<len1; k++,c++)
                {
                    if(arr1[k]=='<')
                    {
                        s3[c]='\0';
                        break;
                    }
                    s3[c]=arr1[k];
                    printf("%c",arr1[k]);
                }
                for(l=k+1,c=0; l<len1; l++,c++)
                {
                    if(arr1[l]=='>')
                    {
                        s4[c]='\0';
                        break;
                    }
                    s4[c]=arr1[l];
                    printf("%c",arr1[l]);
                }
                for(p=l+1,c=0; p<len1; p++,c++)
                {
                    s5[c]=arr1[p];
                    printf("%c",arr1[p]);
                }
                s5[c]='\0';
            }
            else
                printf("%c",arr1[i]);
            if(f==1)
            {
                printf("\n");
                break;
            }
        }
        for(i=0; i<len2; i++)
        {
            if(arr2[i]=='.'&&arr2[i+1]=='.'&&arr2[i+2]=='.')
            {
                printf("%s%s%s%s",s4,s3,s2,s5);
                i=i+2;
            }
            else
                printf("%c",arr2[i]);
        }
        printf("\n");
    }
    return 0;
}
