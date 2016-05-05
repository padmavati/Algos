//
//  main.c
//  AddOneToArrayNumber
//
//  Created by padmavb on 5/3/16.
//  Copyright © 2016 padmavb. All rights reserved.
//

#include <stdio.h>
int* plusOne(int* A, int n1, int *length_of_array) {
    int * result = (int *)malloc(n1*sizeof(int));
    int index = n1-1, carry = 1, index2=0;
    for(;index >=0; index--){
        result[index] = (A[index]+carry)%10;
        carry = (A[index]+carry)/10;
    }
    if(carry == 1){
        n1+=1;
        result = (int *)realloc(result,n1*sizeof(int));
        for(index = n1-1; index > 0; index--){
            result[index] = result[index-1];
        }
        result[index] = carry;
    }
    if(result[0]==0){
        for(index=0; result[index]==0; index++);
        for(; index < n1; index++){
            result[index2++] = result[index];
        }
        n1 = index2;
    }
    *length_of_array = n1;
    return result;
}
int main(int argc, const char * argv[]) {
    int n,  index;
    int * input;
    int * len = (int *)malloc(sizeof(int));
    scanf("%d",&n);
    input = (int *) malloc(n*sizeof(int));
    for(index=0; index<n; index++){
        scanf("%d",&input[index]);
    }
    plusOne(input, n, len);
    return 0;
}
