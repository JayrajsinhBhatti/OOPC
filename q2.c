#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    char *p = str;

    while (*p!='\0')
    {
        if (isupper(*p))
        {
            *p = tolower(*p);
        }
        else if(islower(*p))
        {
            *p = toupper(*p);
        }
        *p++;
    }
    printf("Converted string: %s", str);
    
    return 0;
}