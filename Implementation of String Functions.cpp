﻿

#include<stdio.h>
#include<conio.h>
#include<string.h>

int STRLEN(char*);
int STRCPY(char*,char*);
int STRCMP(char*,char*);
int STRCAT(char*,char*,char*);
int STRREV(char*);
void main()
{
    int c;
    char str[20],str1[10],str2[10],str3[20];
    clrscr();
    re:
    printf("
Enter choice=>");
    printf("
        ۱:string len.
        ۲:string copy
        ۳:string
cmp.
        ۴:string cat.
        ۵:string rev.");
    printf("
        ۶:for exit=>");
    scanf("%d",&c);switch(c)
    {
        case 1:
            printf("Enter the string=>");
            scanf("%s",&str1);
            printf("string length=>%d
",STRLEN(str1));
            break;
        case 2:
            printf("
Enter the string=>");
            scanf("%s",str1);
            STRCPY(str2,str1);
            printf("copied string=>");
            puts(str2);
            break;
        case 3:
            printf("Enter two string=>");
            scanf("%s",&str1);
            scanf("%s",&str2);
            if(STRCMP(str2,str1))
                printf("string is equal");
            else
                printf("String is not equal");
            break;
        case 4:
            printf("Enter two string=>");
            scanf("%s",str1);
            scanf("%s",str2);
            STRCAT(str3,str2,str1);
            puts(str3);
            break;
        case 5:
            printf("Enter the string=>");
            scanf("%s",str1);
            STRREV(str1);
            printf("Reverse stringis=>");
            puts(str1);
            break;
        default:
            goto end;
    }
    goto re;
end:
getch();
}
int STRLEN(char *s)
{
    int i=0;
    while(*s!=NULL)
    {
        i++;
        s++;
    }
    return i;
}
int STRCPY(char *s2,char *s1)
{
    while(*s1!=NULL)
    {
        *s2=*s1;
        s2++;
        s1++;
    }
    *s2=NULL;
    return 1;
}
int STRCMP(char *s2,char *s1)
{
    int i=0,len1,len2;
    len1=strlen(s1);
    len2=strlen(s2);
    if(len1==len2)
    {
        while(*s2==*s1 && *s2 != NULL && *s1!=NULL)
        {
            i++;
            s1++;
            s2++;
        }
        if(i==len1)
            return 1;
        else
            return 0;
    }
    else
    {
        return 0;
    }
}
int STRREV(char *s)
{
    int len;
    char *s1;
    char *ptr;
    len=strlen(s);
    s1=(char *)malloc(sizeof(char));
    strcpy(s1,s);
    ptr=s1+len-1;
    while(*s!=NULL)
    {
        *s=*ptr;
        ptr--;
        s++;
        s1++;
    }
    *s=NULL;
    return 1;
}
int STRCAT(char *s3,char *s2,char *s1)
{
    while(*s1!=NULL)
    {
        *s3=*s1;
        s3++;
        s1++;
    }
    s3++;
    while(*s2!=NULL)
    {
        *s3=*s2;
        s3++;
        s2++;
    }
    *s3=NULL;
    return 1;
}