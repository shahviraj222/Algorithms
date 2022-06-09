#include <stdio.h>
struct item
{
    int profit;
    int weight;
    float pbyw;
};
void sort(struct item *item, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (item[j].pbyw < item[j + 1].pbyw)
            {
                float temp;
                temp = item[j].pbyw;
                item[j].pbyw = item[j + 1].pbyw;
                item[j + 1].pbyw = temp;

                int temp2;
                temp2 = item[j].profit;
                item[j].profit = item[j + 1].profit;
                item[j + 1].profit = temp2;

                temp2 = item[j].weight;
                item[j].weight = item[j + 1].weight;
                item[j + 1].weight = temp2;
            }
        }
    }
}
int main()
{
    int n;
    float c;
    float total=0;
    printf("Enter the total number of item:");
    scanf("%d", &n);
    printf("Enter the capacity of the Bag:");
    scanf("%f", &c);
    
    struct item item[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter profit %d item:", i);
        scanf("%d", &item[i].profit);
        printf("Enter Weight %d item:", i);
        scanf("%d", &item[i].weight);
    }
    for (int i = 0; i < n; i++)
    {
        item[i].pbyw = (float)item[i].profit / (float)item[i].weight;
    }

    sort(item, n);
    for (int i = 0; i < n && c>0; i++)
    {
        if (c > (float)item[i].weight)
        {
            // printf("Loop is runing");
            total=total+(float)item[i].profit;
            c=c-item[i].weight;
        }

        // c is less than item weight item must be taken so remaining (weight * profit)/weight 
        // c becomes less than zero
        else
        {
            total=total+((c*item[i].profit)/item[i].weight);
            c=c-item[i].weight;
        }
    }

    printf("Profit Weigth PbyW\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d %d %.2f\n", item[i].profit, item[i].weight, item[i].pbyw);
    }

    printf("Total profit is %.2f",total);
    return 0;
}