#include <stdio.h>
#include <limits.h>
int mx=INT_MIN,mi=INT_MAX;
struct pair
{
    int max;
    int min;
};
void MinMax(int i,int j,int *a,int *max,int *min)
{
    struct pair m;
    struct pair m2;
    // only one element
    if (i==j)
    {
       *max=a[i];
       *min=a[j];
    }

    else
    {
        // two elements are presenet 
        if(i==j-1)
        {
            if(a[i]<a[j])
            {
                *max=a[j];
                *min=a[i];
            }
            else
            {
                *max=a[i];
                *min=a[j];
            }
        }
        
        // more than two element
        else
        {
           int mid=(i+j)/2; 
           MinMax(i,mid,a,&m.max,&m.min);
           MinMax(mid+1,j,a,&m2.max,&m2.min);
            if(m.max<m2.max)
            {
                m.max=m2.max;
                mx=m2.max;
            }
            else
            {
                 mx=m.max;
            }
            if (m.min<m2.min)
            {
              mi=m.min;              
            }
            else
            {
                 mi=m2.min;
                 m.min=m2.min;
            }
            
        }  
    }
    
}
int main()
{
    int n=5;
    int a[5]={4,520,102,54,84};
    MinMax(0,n-1,a,&mx,&mi);
    printf("MAX=%d MIN=%d",mx,mi);
    return 0;
}