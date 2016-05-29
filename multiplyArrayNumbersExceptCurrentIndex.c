//
//  main.c
//  multiplyArrayElementsExceptCurrentIndex
//
//  Created by padmavb on 5/29/16.
//  Copyright © 2016 padmavb. All rights reserved.
//

#include <stdio.h>
void printArray(int * inpArray, int size){
    int index = 0;
    for(;index < size;index++)
        printf("%d\t", inpArray[index]);
}
void modifyArray(int * inpArray, int size){
    int result = 1, index, noOfZeros = 0;
    for(index = 0; index < size; index++){
        if(inpArray[index] == 0 ){
            noOfZeros++;
        }
        else if(noOfZeros <= 1){
            result *= inpArray[index];
        }
        else
            break;
    }
    for(index = 0; index < size; index++)
        if(noOfZeros == 0)
          inpArray[index] = result/inpArray[index];
        else if(inpArray[index] == 0 && noOfZeros == 1)
            inpArray[index] = result;
        else
            inpArray[index] = 0;
}
int main(int argc, const char * argv[]) {
    int size, index;
    scanf("%d", &size);
    int * inpArray = (int *)malloc(size* sizeof(int));
    for(index = 0; index < size; index++)
        scanf("%d", &inpArray[index]);
    modifyArray(inpArray, size);
    printArray(inpArray, size);
    return 0;
}
