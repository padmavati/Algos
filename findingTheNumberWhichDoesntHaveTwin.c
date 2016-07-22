//
//  main.c
//  findingAnumberWhichDoesn'tHaveTwin
//
//  Created by padmavb on 7/17/16.
//  Copyright © 2016 padmavb. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
int findNonRepeteativeElement(int * inpArray, int lowerIndex, int upperIndex){
    int middle = (lowerIndex+upperIndex)/2;
    if(upperIndex - lowerIndex <= 1)
        return inpArray[lowerIndex];
    
    if(middle%2){
        if(inpArray[middle] != inpArray[middle+1]){
            return findNonRepeteativeElement(inpArray, middle+1, upperIndex);
        }
        else
            return findNonRepeteativeElement(inpArray, lowerIndex, middle-1);
    }
    else{
        if(inpArray[middle] != inpArray[middle+1])
            return findNonRepeteativeElement(inpArray, lowerIndex, middle+1);
        else
            return findNonRepeteativeElement(inpArray, middle, upperIndex);
           
    }
}
int main(int argc, const char * argv[]) {
    int size, index;
    scanf("%d",&size);
    int * input = (int *)malloc(size *sizeof(int));
    for(index = 0; index < size; index++)
        scanf("%d",&input[index]);
    printf("%d\n", findNonRepeteativeElement(input,0,size));
    return 0;
}
