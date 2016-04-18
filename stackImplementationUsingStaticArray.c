//
//  main.c
//  stackImplementation
//
//  Created by padmavb on 4/16/16.
//  Copyright © 2016 padmavb. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
void push(int);
int pop();
int peak();
int top = -1;
int * stack;
int readInput();
int main() {
    stack = (int *)calloc(10, sizeof(int));
    int userChoice, element;
    while(1){
        userChoice = readInput();
        switch(userChoice){
            case 1 : scanf("%d",&element);
                push(element);
                break;
            case 2 : pop();
                  break;
            case 3 :  peak();
                  break;
            case 4 : return  0;
                
            default : printf("Enter valid input\n");
        }
    }
    return 0;
}
int readInput(){
    int userChoice;
    printf("1 - push element\n2 - pop\n3 - peak\n4 - Quit\n");
    scanf("%d",&userChoice);
    return userChoice;
}
void push(int element){
    if(top == 9){
        printf("stack is already full, can't push more elements");
        return;
    }
    stack[++top] = element;
}
int peak(){
    return stack[top] || 0;
}
int pop(){
    return stack[top--] || 0;
}