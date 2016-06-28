//
//  main.c
//  constructCompleteBinaryTree
//
//  Created by padmavb on 6/28/16.
//  Copyright © 2016 padmavb. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node * left, * right;
};
void heapifyTree(struct node ** root){
    
    if(!root)
        return;
    heapifyTree(&(*root) -> left);
    heapifyTree(&(*root) -> right);
    if((*root) -> left && (*root) -> data < (*root) -> left -> data){
        (*root) -> data += (*root) -> left -> data;
        (*root) -> left -> data = (*root) -> data - (*root) -> left -> data;
        (*root) -> data = (*root) -> data - (*root) -> left -> data;
    }
    if((*root) -> right && (*root) -> data < (*root) -> right -> data){
        (*root) -> data += (*root) -> right -> data;
        (*root) -> right -> data = (*root) -> data - (*root) -> right -> data;
        (*root) -> data = (*root) -> data - (*root) -> right -> data;
    }
    
}
void construct(struct node * root, int value){
    while(1){
        if(!root -> left){
            root -> left = (struct node *)malloc(sizeof(struct node *));
            root -> left -> data = value;
            root -> left -> left = root -> left -> right = NULL;
            return;
        }
        else if(!root -> right){
            root -> right = (struct node *)malloc(sizeof(struct node *));
            root -> right -> data = value;
            root -> right -> left =  root -> right -> right = NULL;
            return;
        }
        else if(root -> left -> left && root -> left -> right && (!root -> right -> left || !root -> right -> right))
            root = root -> right;
        else
            root = root -> left;
    }
    
}
struct node * constructTree(int * inpArray, int size){
    struct node * root = (struct node *)malloc(sizeof(struct node *));
    root -> data = inpArray[0];
    root -> left = root -> right = NULL;
    for(int index = 1; index < size; index++){
        construct(root, inpArray[index]);
    }
    return root;
    
}
void printTree(struct node * root){
    if(!root)
        return;
    printf("%d\n", root -> data);
    printTree(root-> left);
    printTree(root -> right);
}
int main(int argc, const char * argv[]) {
    int size, index;
    scanf("%d",&size);
    int * inpArray = (int *)malloc(size *sizeof(int));
    for(index = 0; index < size; index++)
        scanf("%d", &inpArray[index]);
    if( size < 1)
        return 0;
    struct node * root = constructTree(inpArray, size);
    heapifyTree(&root);
    printTree(root);
    return 0;
}
