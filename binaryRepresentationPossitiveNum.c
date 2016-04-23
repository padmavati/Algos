//
//  main.c
//  binaryRepresentationOfNum
//
//  Created by padmavb on 4/23/16.
//  Copyright © 2016 padmavb. All rights reserved.
//

#include <stdio.h>

char* findDigitsInBinary(int A) {
    // SAMPLE CODE
    /*
     * char* result = (char *)malloc(100 * sizeof(char));
     * // DO STUFF HERE
     * return result;
     */
    int index=0, size = 1;
    char * binaryRepresentationOfNum = (char *)malloc(32*sizeof(char));
    if(A >= 0 && A <= 1){
        binaryRepresentationOfNum[index] = A%2+'0';
    }else{
        for(index = 0; A;A/=2){
            index = size-1;
            while(index >0){
                binaryRepresentationOfNum[index]=binaryRepresentationOfNum[index-1];
                index--;
            }
            binaryRepresentationOfNum[index] = A%2+'0';
            size++;
        }
    }
    binaryRepresentationOfNum[size] = '\0';
    return binaryRepresentationOfNum;
}

int main(int argc, const char * argv[]) {
    findDigitsInBinary(2);
    return 0;
}
