//
//  main.c
//  moveAllZerosToEndOfTheArray
//
//  Created by padmavb on 5/7/16.
//  Copyright © 2016 padmavb. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
int * readInput(int);
void moveZerosToEnd(int *, int);
int main(int argc, const char * argv[]) {
    int size;
    scanf("%d",&size);
    int * input = readInput(size);
    moveZerosToEnd(input, size);
    return 0;
}
int * readInput(int size){
    int * inpArray = (int *)malloc(size*sizeof(int));
    int index;
    for(index = 0; index < size; index++){
        scanf("%d", &inpArray[index]);
    }
    return inpArray;
}
void moveZerosToEnd(int * inpArray, int size){
    int  i,j;
    for(i=0,j=1;j<size;j++){
        if(inpArray[i] == 0 && inpArray[j]!=0){
            inpArray[i++]= inpArray[j];
            inpArray[j]=0;
        }
        else if(inpArray[i]!=0){
            i++;
        }
    }
    for(i=0; i< size; i++){
        printf("%d\t",inpArray[i]);
    }
}
