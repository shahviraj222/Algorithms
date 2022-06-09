// sort according to profit (in decending order)
// take job and fill in time solt if that is occupied than go for previous one
#include <stdio.h>
struct data
{
    char name;
    int deadline;
    int profit;
};

void sort(struct data *data, int n)
{
    // decending order
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (data[j].profit < data[j + 1].profit)
            {
                int temp;
                temp = data[j].profit;
                data[j].profit = data[j + 1].profit;
                data[j + 1].profit = temp;

                temp = data[j].deadline;
                data[j].deadline = data[j + 1].deadline;
                data[j + 1].deadline = temp;

                char temp2;
                temp2 = data[j].name;
                data[j].name = data[j + 1].name;
                data[j + 1].name = temp2;
            }
        }
    }
}
int max(struct data *data, int n)
{
    int max = data[0].deadline;
    for (int i = 0; i < n; i++)
    {
        if (max < data[i].deadline)
        {
            max = data[i].deadline;
        }
    }
    return max;
}
int main()
{
    int n;
    int profit = 0;
    printf("Enter the total number of jobs:");
    scanf("%d", &n);
    struct data data[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter the Name of %d Job:", i + 1);
        scanf("%s", &data[i].name);
        printf("Enter the Profit of %d Job:", i + 1);
        scanf("%d", &data[i].profit);
        printf("Enter the DeadLine of %d Job:", i + 1);
        scanf("%d", &data[i].deadline);
    }
    int m = max(data, n);
    char s[m+1];

    sort(data, n);
    s[0]=0;
    // deadline is starting with 1 onwards and my array is starting from 0 so some problem occur to avoid that start array from 1 onward
    for (int i = 1; i < m+1; i++)
    {
        s[i] = 0;
    }

    for (int i = 0; i < m; i++)
    {
        if (s[data[i].deadline] == 0)
        {
            s[data[i].deadline] = data[i].name;
            profit = profit + data[i].profit;
        }
        else
        {
            // if i stop at 5th deadline than i shold go untill the end of array or start
            for (int j = data[i].deadline-1; j > 0; j--)
            {
                // please check name
                if (s[j] == 0)
                {
                    s[j] = data[i].name;
                    profit = profit + data[i].profit;
                    break;                
                }
            }
        }
    }

    for (int i = 1; i < m+1; i++)
    {
        printf("%c ",s[i]);
    }
    printf("\nProfit is equal to %d",profit);
    return 0;
}
