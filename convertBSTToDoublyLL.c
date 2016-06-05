//
//  main.c
//  convertBSTToDoublyLL
//
//  Created by padmavb on 6/5/16.
//  Copyright © 2016 padmavb. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node * left;
    struct node * right;
};
struct doubleLLNode{
    int data;
    struct doubleLLNode * prev, * next;
};
struct doubleLLNode * tail = NULL;
void createBST(struct node ** root, int value){
    
    if(!*root){
        *root = (struct node *)malloc(sizeof(struct node*));
        (*root) -> data = value;
        ((*root) -> left) = ((*root) -> right) = NULL;
        return;
    }
    if(value > (*root) -> data)
        createBST(&((*root) -> right), value);
    else
        createBST(&((*root) -> left), value);
    
}
struct node * readInput(){
    
    int choice, valToInsert;
    struct node * root = NULL;
    do{
        printf("Enter your choice\n1 - Enter node\t0 - Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1: printf("enter value to insert\n");
                scanf("%d", &valToInsert);
                createBST(&root, valToInsert);
                break;
            case 0: break;
            default:printf("enter a valid choice\n");
        }
        
    }while(choice);
  
    return root;
}
void convertToDLL(struct node * root){
    
    if(!root)
        return;
    convertToDLL(root->left);
    struct doubleLLNode * temp = (struct doubleLLNode *)malloc(sizeof(struct doubleLLNode*));
    temp -> data = root -> data;
    temp ->prev = temp -> next = NULL;
    if(tail){
        tail -> next = temp;
        temp -> prev = tail;
    }
    tail = temp;
    convertToDLL(root -> right);
}
void printDLL(){
    
    while(tail){
        printf("%d\t", tail -> data);
        tail = tail -> prev;
    }
}
int main(int argc, const char * argv[]) {
    
    struct node * root = readInput();
    convertToDLL(root);
    printDLL();
    return 0;
}
