//
//  main.c
//  noOfDeletions
//
//  Created by padmavb on 5/14/16.
//  Copyright © 2016 padmavb. All rights reserved.
//

#include "stdio.h"
#include "stdlib.h"
int noOfDeletionsForIndividualInput(char * input){
    int noOfDeletions = 0, index=1;
    for(;input[index]!='\0';index++){
        if(input[index] == input[index-1])
            noOfDeletions++;
    }
    return noOfDeletions;
}
void noOfDeletions(char ** input, int noOfInputs){
    int index = 0;
    for(;index < noOfInputs; index++){
        printf("%d\n",noOfDeletionsForIndividualInput(input[index]));
    }
}
int main() {
    int noOfInputs, index;
    scanf("%d",&noOfInputs);
    char **input = (char **)malloc(noOfInputs* sizeof(char *));
    for(index = 0; index < noOfInputs; index++){
        input[index] = (char *)malloc(pow(10,5)*sizeof(int));
        scanf("%s",input[index]);
    }
    noOfDeletions(input, noOfInputs);
    return 0;
}