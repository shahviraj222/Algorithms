#include<stdio.h>
struct data
{
    char name;
    int profit;
    int weight;
};

int max(int a,int b)
{
    // if a is grater means hum log ne usko select kiya to usko add karna padega
    if(a>b)
    {
        return a;
    }
    return b;
    
}
int knapsack(struct data *data,int n,int capacity)
{   
    // base condition 
    if(n==-1 || capacity==0)
    {
        return 0;
    } 

    // choise diagram
    if(data[n].weight<=capacity)
    {
        int a=capacity-data[n].weight;
        // two possibility one is select item and check for next other is reject item and check for other one 
        return max(data[n].profit+knapsack(data,n-1,a),knapsack(data,n-1,capacity));
    }
    // if weight of item is grater than capacity item is rejected
    else
    {
        return knapsack(data,n-1,capacity);
    }
}
int main()
{
    int n,c;
    printf("Enter total number of items:");
    scanf("%d",&n);

    printf("Enter Capacity of bag:");
    scanf("%d",&c);

    struct data data[n]; 

    for(int i=0;i<n;i++)
    {
       printf("Enter the name of item:");
       scanf("%s",&data[i].name);
       printf("Enter Profit of item");
       scanf("%d",&data[i].profit);
       printf("Enter weight of item");
       scanf("%d",&data[i].weight);
    }

    int profit=knapsack(data,n-1,c);
    printf("\nProfit=%d",profit);
    return 0;
}
