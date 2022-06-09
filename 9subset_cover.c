//  Let I represents set of elements included so far.  Initialize I = {}

// 2) Do following while I is not same as U.
//     a) Find the set Si in {S1, S2, ... Sm} whose cost effectiveness is 
//        smallest, i.e., the ratio of cost C(Si) and number of newly added 
//        elements is minimum. 
//        Basically we pick the set for which following value is minimum.
//            Cost(Si) / |Si - I|
//     b) Add elements of above picked Si to I, i.e.,  I = I U Si

#include<stdio.h>
int main()
{
    
}