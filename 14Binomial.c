#include <stdio.h>
int binomial(int n,int k)
{
    if (k>n)
    {
        return 0;
    }
    if(k==0 || k==n)
    {
        return 1;
    }
    return binomial(n-1,k-1)+binomial(n-1,k);
    
}
int main()
{
    int n,k;
    printf("Enter the nck value of n:");
    scanf("%d",&n);
    printf("Enter the nck value of k:");
    scanf("%d",&k);
    int result=binomial(n,k);
    printf("%dC%d = %d",n,k,result);
    return 0;
}