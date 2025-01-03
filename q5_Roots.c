#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int main()
{
    float a,b,c;
    printf("Enter a,b,c of quedratic eqn: ");
    scanf("%f %f %f", &a, &b, &c);
    float discriminant = (b*b) - (4*a*c);
    float root1 = (-b + sqrt(discriminant))/(2*a);
    float root2 = (-b - sqrt(discriminant))/(2*a);

    if (discriminant>0)
    {
        printf("Two real roots are possible.");
        printf("Root-1: %f\n", root1);
        printf("Root-2: %f", root2);
    }
    else if (discriminant==0)
    {
        printf("One real root is possible.");
        printf("Root is: %f", root1);
    }
    else{
        printf("No real roots are possible.");
    }

    return 0;
}