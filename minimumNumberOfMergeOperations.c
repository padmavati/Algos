//
//  main.c
//  minimumNoOfMergeOperations
//
//  Created by padmavb on 5/9/16.
//  Copyright © 2016 padmavb. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
int * readInput(int size){
    int * input = (int *)malloc(size*sizeof(int));
    int index = 0;
    for(;index<size; index++)
        scanf("%d",&input[index]);
    return input;
}
int minimumMergeOperations(int * inpArray, int size){
    int minimumMergeOperations = 0, startIndex = 0;
    size -= 1;
    for(;startIndex<= size;){
        if(inpArray[startIndex] == inpArray[size]){
            startIndex++;
            size--;
        }
        else if(inpArray[startIndex] > inpArray[size]){
            inpArray[size-1]= inpArray[size]+ inpArray[size-1];
            size--;
            minimumMergeOperations++;
        }
        else{
            inpArray[startIndex+1] = inpArray[startIndex]+inpArray[startIndex+1];
            startIndex++;
            minimumMergeOperations++;
        }
    }
    return minimumMergeOperations;
}
int main(int argc, const char * argv[]) {
    int size;
    int * inpArray;
    scanf("%d",&size);
    inpArray = readInput(size);
    printf("%d\n",minimumMergeOperations(inpArray, size));
    return 0;
}
