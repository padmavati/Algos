//
//  main.c
//  findingTheCommonElementInTwoSortedArrays
//
//  Created by padmavb on 5/31/16.
//  Copyright © 2016 padmavb. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
int commonElement(int * inpArray1, int size1, int * inpArray2, int size2){
    int index1 =0, index2 = 0;
    for(;index1 < size1 && index2 < size2;){
        if(inpArray1[index1] < inpArray2[index2])
            index1++;
        else if(inpArray1[index1] > inpArray2[index2])
            index2++;
        else
            return inpArray1[index1];
    }
    return 0;
}
int main(int argc, const char * argv[]) {
    
    int size1, size2, index;
    scanf("%d%d", &size1, &size2);
    int * inpArray1 = (int *)malloc(size1* sizeof(int));
    int * inpArray2 = (int *)malloc(size2* sizeof(int));
    for(index = 0; index < size1; index ++)
        scanf("%d",&inpArray1[index]);
    for(index = 0; index < size2; index++)
        scanf("%d", &inpArray2[index]);
    printf("%d\n",commonElement(inpArray1, size1, inpArray2, size2));
    return 0;
}
