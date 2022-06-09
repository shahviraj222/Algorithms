#include <iostream>
using namespace std;
template <class T> 

T max(T x , T y)
{
    if(x>y)
    {
       return x; 
    }
    else
    {
        return y;
    }
    
}



int main()
{   int a=20;
    int b=510;
    int *c;
    c= new int[b];
    int min;
    min = max<int>(a,b);
    cout<<min;
    return 0; 
}
