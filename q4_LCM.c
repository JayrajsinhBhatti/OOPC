#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    int a, b;
    printf("Enter number 1: ");
    scanf("%d", &a);
    printf("Enter number 2: ");
    scanf("%d", &b);

    int max = (a > b) ? a : b;
    int lcm;

    while (1)
    {
        if (max%a==0 && max%b==0)
        {
            lcm = max;
            break;
        }
        max++;
    }
    printf("LCM is: %d", lcm);
    
    return 0;
}