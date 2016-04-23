//
//  main.c
//  findingFactors
//
//  Created by padmavb on 4/22/16.
//  Copyright © 2016 padmavb. All rights reserved.
//

#include <stdio.h>
int* allFactors(int A, int *length_of_array) {
    // SAMPLE CODE
    /*
     * *length_of_array = 1000; // length of result array
     * int *result = (int *) malloc(*length_of_array * sizeof(int));
     * // DO STUFF HERE. NOTE: length_of_array is inaccurate in this example.
     * return result;
     */
    
    int * result= (int *)malloc(500*sizeof(int));
    int index = 0, i, maxLimit, size=0;
    if(A%2 == 0){
        maxLimit = A/2;
        i = 2;
    }
    else{
        maxLimit = A/3;
        i = 3;
    }
    result[0] = 1;
    for( ; i < maxLimit; i+=1){
        if(A % i == 0){
            for(index = size ; i < result[index] && index >= 0 ;index--){
                result[index+1] = result[index];
            }
            result[index+1] = i;
            size +=1;
            for(index = size; i < result[index] && index >= 0;index--){
                result[index+1] = result[index];
            }
            if(A/i != i){
                result[index+1] = A/i;
                size +=1;
            }
            
            maxLimit = A/i;
        }
    }
    result[++size] = A;
    if(A!=1){
        size +=1;
    }
    for(index = 0; index < size; index++){
        printf("%d\n",result[index]);
    }
    *length_of_array = size;
    return result;
}

int main(int argc, const char * argv[]) {
    int * p = 1000;
    allFactors(, p);
    return 0;
}
