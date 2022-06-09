#include<stdio.h>
void swap(int *x,int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}
void swapname(char *x,char *y)
{
    char temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

void sort(int *l,char *n,int num)
{
    for (int i = 0; i <num-1; i++)
    {
        for (int j = 0; j <num-1-i; j++)
        {
           if(l[j]>l[j+1])
           {
                swap(&l[j], &l[j + 1]);
                swapname(&n[j],&n[j+1]);
           }
        }
        
    }
     for (int i = 0; i < num; i++)
    {
        printf("%c ",n[i]);
    }

    int sum;
    float MRT=0;
    for (int i = 0; i < num; i++) {
        int sum = 0;
        for (int j = 0; j <= i; j++)
            sum += l[j];
        MRT += sum;
    }
    MRT=MRT/num;
    printf("\nMRT = %.2f",MRT);
}
int main()
{
    int num;
    printf("Enter total number of tapes:");
    scanf("%d",&num);
    int l[num]; //to store lenght of tape
    char n[num];//to store name of tape

  
    for (int i = 0; i <num; i++)
    {
        printf("Enter Name of tape:");
        scanf("%s",&n[i]);
        printf("Enter length of tape :");
        scanf("%d",&l[i]);
    }
    sort(l,n,num);
    return 0;
}

// time complexity is same as sort funtion only we have to sort that 
// O(n^2)