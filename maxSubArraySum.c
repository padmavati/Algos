//
//  main.c
//  maxSubArray
//
//  Created by padmavb on 5/8/16.
//  Copyright © 2016 padmavb. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
void maxSubArraySum(int * input, int size){
    int index=1, maxSum = input[0], sum=input[0];
    for(;index < size; index++){
        if(sum >= 0 && sum + input[index] <= 0){
            maxSum = sum;
            sum = 0;
        }
        else if(sum < 0 && input[index] < 0){
            sum = input[index];
        }
        else
            sum += input[index];
        if(sum > maxSum)
            maxSum = sum;
    }
    printf("%d\n",maxSum);
}
int main(int argc, const char * argv[]) {
    int size,index;
    int * input;
    scanf("%d",&size);
    input = (int *)malloc(size*sizeof(int));
    for(index=0; index < size; index++)
        scanf("%d", &input[index]);
    maxSubArraySum(input, size);
    return 0;
}
