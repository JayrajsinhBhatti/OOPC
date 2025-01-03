#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    int sum=0;
    
    for(int i=1;i<number;i++)
    {
        if (number%i==0)
        {
            sum+=i;
        }
    }
    if (sum==number)
    {
        printf("It is a perfect number");
    }
    else{
        printf("It is a not perfect number");
    }
    
    
    return 0;
}