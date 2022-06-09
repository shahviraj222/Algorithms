#include <stdio.h>
#include <stdio.h>
int max, min;
int a[100];
void maxmin(int i, int j)
{
    int max1, min1, mid;
    // if one element 
    if (i == j)
    {
        max = min = a[i];
    }
    // more than one element
    else
    {
        // if two element 
        if (i == j - 1)
        {
            if (a[i] < a[j])
            {
                max = a[j];
                min = a[i];
            }
            else
            {
                max = a[i];
                min = a[j];
            }
        }
        // more than two element 
        else
        {
            mid = (i + j) / 2;
            maxmin(i, mid);
            max1 = max;
            min1 = min;
            maxmin(mid + 1, j);
            if (max < max1)
                max = max1;
            if (min > min1)
                min = min1;
        }
    }
}
int main()
{
    int i, num;
    printf("\nEnter the total number of numbers : ");
    scanf("%d", &num);
    printf("Enter the numbers : \n");
    for (i = 0; i <= num; i++)
        scanf("%d", &a[i]);

    max = a[0];
    min = a[0];
    maxmin(0, num);
    printf("Minimum element in an array : %d\n", min);
    printf("Maximum element in an array : %d\n", max);
    return 0;
}

// time complexity is o(n)

// equation of above is
// T(n)=T(n/2)+T(n/2)+2  n>2
// T(n)=1                n=2 
// T(n)=1                n=0