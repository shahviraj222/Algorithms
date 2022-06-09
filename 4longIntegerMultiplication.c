#include <stdio.h>
#include <conio.h>
#include <math.h>

long prod(long, long);
long noOfDigit(long, long);

void main()
{
    long m, n;
    printf("\n-----------------------------------------------");
    printf("\nMULTIPLICATION USING DIVIDE & CONQUER");
    printf("\n-----------------------------------------------");
    printf("\n Enter number1:");
    scanf("%ld", &m);
    printf("\n Enter number2:");
    scanf("%ld", &n);
    printf("\n-----------------------------------------------");
    printf("\n multiplication of %ld and %ld is:%ld", m, n, prod(m, n));
    printf("\n-----------------------------------------------");
}

long prod(long u, long v)
{
    long x, y, w, z;
    long n, m, p, q, r;

    n = noOfDigit(u, v);

    if (u == 0 || v == 0)
    {
        return 0;
    }

    else if (n <= 2)
    {
        return (u * v);
    }
    else
    {
        m = floor(n / 2);

        w = u / pow(10, m);      //Xh
        x = u % (int)pow(10, m); //Xl
        y = v / pow(10, m);      //Yh
        z = v % (int)pow(10, m); //Yl

        p = prod(w, y);           //s1
        q = prod(x, z);          //s2
        r = prod(w + x, y + z);  //s3
        // s4=s3-s2-s1

        // s1 * b^n + s4 * b^n/2 + s2 return this 
        return p * pow(10, 2 * m) + (r - p - q) * pow(10, m) + q;
    }
}

long noOfDigit(long m, long n)
{
    long max;
    long b = 0;
    if (m >= n)
        max = m;
    else
        max = n;
    while (max > 0)
    {
        max = max / 10;
        b++;
    }
    return b;
}

// using traditional method o(n^2)
// karatsuba reduce the coplexity to O(n^1.58)