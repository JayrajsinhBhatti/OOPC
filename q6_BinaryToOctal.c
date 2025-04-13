#include<stdio.h>

int toDecimal(int binary)
{
    int base=1, decimal=0;
    while (binary>0)
    {
        int lastDigit = binary%10;
        decimal += lastDigit*base;
        base*=2;
        binary/=10;
    }
    return decimal;
}

int toOctal(int decimal)
{
    int octal=0, base=1;
    while (decimal>0)
    {   
        int remainder = decimal%8;
        octal += remainder*base;
        base*=10;
        decimal/=8;       
    }
    return octal;
}

int main()
{
    int binary, decimal;
    printf("Enter binary value: ");
    scanf("%d", &binary);

    decimal = toDecimal(binary);
    printf("%d", toOctal(decimal));
    
    return 0;
}
