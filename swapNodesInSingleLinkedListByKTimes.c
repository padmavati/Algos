//
//  main.c
//  swapNodesByNTimes
//
//  Created by padmavb on 8/12/16.
//  Copyright © 2016 padmavb. All rights reserved.
//

#include <stdio.h>
#include "stdlib.h"
struct node {
    int data;
    struct node * next;
};

struct node * createLinkedList(int element, struct node * tail){
    
    if(tail == NULL)
        tail = (struct node *)malloc(sizeof(struct node));
    else{
        tail -> next = (struct node *)malloc(sizeof(struct node));
        tail = tail -> next;
    }
    tail -> data = element;
    tail -> next = NULL;
    return tail;
}
struct node * swapNodes(struct node * head, int nValue){
    
    struct node *next = NULL, *traversal = head, *prev = NULL;
    int count = 1;
    if(nValue == 1)
        return head;
    while (traversal != NULL && count <= nValue)
    {
        next  = traversal->next;
        traversal->next = prev;
        prev = traversal;
        traversal = next;
        count++;
    }
    
    if (next !=  NULL)
        head->next = swapNodes(next, nValue);
    return prev;
    
}
void printTree(struct node * head){
    
    for(;head!= NULL; printf("%d\t", head->data),head = head -> next);
    printf("\n");
}
int main(int argc, const char * argv[]) {
    
    int choice, element, nValue;
    struct node * head = NULL, * tail = NULL;
    do{
        printf("Please enter your choice\n1 - Continue creating linked list\n2 - Stop creating linked list\n");
        scanf("%d",&choice);
        switch (choice) {
            case 1:
                printf("Enter the value to insert into linked list\n");
                scanf("%d", &element);
                tail = createLinkedList(element, tail);
                if(head == NULL)
                    head = tail;
                break;
            case 2:
                break;
            default:
                printf("Please enter a valid choice\n");
                continue;
        }
        
    }while (choice != 2);
    printf("Please enter k value\n");
    scanf("%d",&nValue);
    printTree(head);
    head = swapNodes(head, nValue);
    printTree(head);
}
