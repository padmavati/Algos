//
//  main.c
//  missingElementFromDuplicateArray
//
//  Created by padmavb on 5/18/16.
//  Copyright © 2016 padmavb. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
int * readInput(int size){
    int * input = (int *)malloc(size*sizeof(int));
    int index =0;
    for(;index < size; index++)
        scanf("%d",&input[index]);
    return input;
}
int findMissingElement(int *inpArray1, int size1, int * inpArray2, int size2){
    int missingNumber=0;
    missingNumber = missingNumber^inpArray1[size1-1];
    for(size2-=1;size2 >=0;size2--){
        missingNumber = missingNumber^inpArray1[size2];
        missingNumber = missingNumber^inpArray2[size2];
    }
    return missingNumber;
}
int main(int argc, const char * argv[]) {
    int sizeOfArray;
    int * array1, *array2;
    scanf("%d",&sizeOfArray);
    array1 = readInput(sizeOfArray);
    array2 = readInput(sizeOfArray-1);
    printf("%d\n",findMissingElement(array1,sizeOfArray,array2, sizeOfArray-1));
    return 0;
}
