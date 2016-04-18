//
//  main.c
//  stackImplementationUsingDynamicArray
//
//  Created by padmavb on 4/16/16.
//  Copyright © 2016 padmavb. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int readUserChoice();
int push(int, int);
int pop();
int peak();
int topIndex = -1;
int * inpArray;
int main(int argc, const char * argv[]) {

    int size, userChoice, element;
    scanf("%d", &size);
    inpArray = (int *)malloc(size*sizeof(int));
    while(1){
        userChoice = readUserChoice();
        switch(userChoice){
            case 1: scanf("%d",&element);
                size = push(size, element);
                break;
                
            case 2 : printf("%d\n",pop());
                break;
            case 3 : printf("%d\n", peak());
                break;
            case 4 : return 0;
            default:  printf("Enter valid input");
            
        }
    }
    return 0;
}
int push(int size, int element){
    if(topIndex == size -1){
        inpArray = (int *)realloc(inpArray, size);
        size *= 2;
    }
    inpArray[++topIndex] = element;
    return size;
}
int pop(){
    if(topIndex == -1){
        printf("Can't pop");
        return topIndex;
    }
    return inpArray[topIndex--];
        
}
int peak(){
    if(topIndex != -1){
        printf("Can't pop");
        return inpArray[topIndex];
    }
    return topIndex;
}
int readUserChoice(){
    int userChoice;
    printf("1 - Push element\n2-pop\n3-peak\n4-quit\n");
    scanf("%d", &userChoice);
    return userChoice;
}