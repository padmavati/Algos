//
//  main.c
//  findingTwoPairsInArray
//
//  Created by padmavb on 6/2/16.
//  Copyright © 2016 padmavb. All rights reserved.
//

#include <stdio.h>
#include<stdlib.h>

void printPair(int * inpArray, int size){
    
    int aIndex, bIndex, cIndex, dIndex;
    for(aIndex = 0, bIndex = aIndex+1; bIndex < size;){
        
        for(cIndex = 0, dIndex = cIndex+1; dIndex < size;){
            if((aIndex != cIndex && aIndex != dIndex)&&(bIndex != cIndex && bIndex != dIndex) &&
               inpArray[aIndex]+inpArray[bIndex] == inpArray[cIndex] + inpArray[dIndex]){
                printf("Pairts are %d\t%d\n and %d\t%d\n", inpArray[aIndex], inpArray[bIndex],inpArray[cIndex],inpArray[dIndex]);
                           }
            
                cIndex++, dIndex++;
        
        }
        bIndex++;
            if(bIndex == size){
                aIndex++;
                bIndex = aIndex +1;
            }
        
        
        
    }
}
int main(int argc, const char * argv[]) {
    
    int size, index;
    scanf("%d", &size);
    int * inpArray = (int *)malloc(size * sizeof(int));
    for(index = 0; index < size; index++)
        scanf("%d", &inpArray[index]);
    printPair(inpArray, index);
    return 0;
}
