//
//  main.c
//  maxTripletProductInArray
//
//  Created by padmavb on 6/3/16.
//  Copyright © 2016 padmavb. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
void sortTheArray(int **temp, int size){
    int i = 1, j, x;
    while(i < size){
        j = i-1;
        x = (*temp)[i];
        while(j >= 0 && x > (*temp)[j]){
            (*temp)[j+1] = (*temp)[j];
            j--;
        }
        (*temp)[j+1] = x;
        i++;
    }
}
int maxTripletProduct(int * inpArray, int size){
    if(size < 3)
        return 0;
    int * temp = (int *)malloc(4*sizeof(int));
    temp[0] = inpArray[0];
    temp[1] = inpArray[1];
    temp[2] = inpArray[2];
    for(int index=3; index < size; index++){
        if(inpArray[index] > temp[0] || inpArray[index] > temp[1] || inpArray[index] > temp[2]){
            temp[3] = inpArray[index];
            sortTheArray(&temp, 4);
        }
    }
    printf("%d\t%d\t%d\n",temp[0], temp[1], temp[2]);
    return temp[0]*temp[1]*temp[2];
}
int main(int argc, const char * argv[]) {
     int size, index;
    scanf("%d", &size);
    int * inpArray = (int *)malloc(size *sizeof(int));
    for(index = 0; index < size; index++){
        scanf("%d", &inpArray[index]);
    }
    printf("%d\n", maxTripletProduct(inpArray, size));
    return 0;
}
