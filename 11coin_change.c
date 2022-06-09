#include<stdio.h>
void currencyFind(int cost,int *coins,int n)
{
    int j=0;
    int currencyList[20];
    for (int i = n-1; cost>0; i--)
    {
        while (cost>=coins[i])
        {
            cost=cost-coins[i];
            currencyList[j]=coins[i];
            j++;
        }
        
    }
    printf("currency is ");
    for (int i = 0; i <j; i++)
    {
      printf("%d ",currencyList[i]);
    }
    
    
}
int main()
{
    int n,t;
    printf("Enter total number of currency:");
    scanf("%d",&t);
    int coins[t];
    for (int i = 0; i <t; i++)
    {
        printf("Enter The Cureency Amount:");
        scanf("%d",&coins[i]);
    }
    
    printf("Enter the amount:");
    scanf("%d",&n);
    currencyFind(n,coins,t);
    return 0;
}