#include<stdio.h>
#include<math.h>

int main()
{
    int n;
    printf("Enter number of forces: ");
    scanf("%d", &n);

    if (n<1 || n>100)
    {
        printf("Invalid input.");
        return 0;
    }

    int sum_x = 0, sum_y = 0, sum_z = 0;
    int Validation=0;

    for(int i=0;i<n;i++)
    {
        int x,y,z;
        printf("Enter coordinates of force-%d: ",i+1);
        scanf("%d %d %d", &x, &y, &z);

        if(x<-100 || x>100 || y<-100 || y>100 || z<-100 || z>100)
        {
            Validation=1;
            break;
        }

        sum_x+=x;
        sum_y+=y;
        sum_z+=z;
    }

    if (Validation==1)
    {
        printf("Please enter coordinates between -100 and 100");
        return 0;
    }
    

    if (sum_x==0 && sum_y==0 && sum_z==0)
    {
        printf("Body is in equilibrium");
    }else {
        printf("Body is not in equilibrium");
    }
    
    return 0;
}