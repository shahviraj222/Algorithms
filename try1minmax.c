#include <stdio.h>
#include<limits.h>

int MaxMin(int *a,int i,int j,int max , int min)
{
    int max;
    int min;
    // only one element 
    if(i==j)
    {
        max=a[0];
        min=a[0];
        return 0;
    }
    else if(i==j-1)
    {
        if(a[i]<a[j])
        {
            max=a[j];
            min=a[i];
        }
       else
       {
          max=a[i];
          min=a[j];
       }
    }

    else
    {
        int mid=(i+j)/2;
        MaxMin(a,i,mid,max,min);
        MaxMin(a,mid+1,j,max,min);

    }    
}
int main()
{
    int n;
    printf("Enter the total number of element:");
    scanf("%d",&n);
    printf("Enter value of Array\n");
    int a[n];
    for (int i = 0; i <n; i++)
    {
        scanf("%d",&a[i]);
    }
    MaxMin(a,0,n-1,0,0);
    
    return 0;
}