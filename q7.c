#include<stdio.h>
#include<math.h>
int main()
{
    int m,n,a;
    printf("Enter length of Square: ");
    scanf("%d", &m);
    printf("Enter breadth of Square: ");
    scanf("%d", &n);
    printf("Enter length of flag: ");
    scanf("%d", &a);
    int area1, area2;
    area1 = m*m;
    area2 = a*a;
    int count=area1/area2;

    if (m<=1 || n<=1 || a<=1 || a>pow(10,9))
    {
        printf("Invalid Input");
        return 0;
    }
    
    while (area2 <= area1)
    {
        count+=1;
        area2 = area2 + a*a;
    }
    printf("Total flags: %d\n", count);
    printf("Total area: %d", area2);
    
    return 0;
}