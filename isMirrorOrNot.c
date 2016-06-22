
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};
int flag = 1;
int * inOrderTraversalArray;
struct node * findNodeInTheGivenTree(struct node *root, int value){
    struct node ** queue = (struct node **)malloc(20*sizeof(struct node *));
    int front = 0, rare = -1;
    if(root != NULL && root -> data ==  value)
        return root;
    while(root){
        if(root -> data ==  value)
            return root;
        if(root -> left != NULL)
            queue[++rare] = root -> left;
        if(root -> right != NULL)
            queue[++rare] = root -> right;
        if(front > rare)
            return NULL;
        root = queue[front++];
    }
    return NULL;
}
void inOrderTraversal(struct node * root, int *index){
    if(root != NULL){
        inOrderTraversalArray[(*index)++] = root -> data;
        inOrderTraversal(root -> left, index);
        inOrderTraversal(root -> right, index);
    }
}
int IsMirror(int index){
    int i = 1;
    if(index == 0)
        return 0;
    for(index -= 1; i < index;i++, index--){
        if(inOrderTraversalArray[i] != inOrderTraversalArray[index])
            return 0;
    }
    return 1;
}
int isMirrorTreeForChildsOfGivenNode(struct node  * root, int value){
    struct node * nodeOfValue = findNodeInTheGivenTree(root, value);
    int index =0;
    if(nodeOfValue != NULL){
        if(nodeOfValue -> left == NULL || nodeOfValue -> right == NULL || nodeOfValue -> left -> data != nodeOfValue -> right -> data)
            return 0;
        inOrderTraversal(nodeOfValue, &index);
        return IsMirror(index);
    }
    return 0;
}
void createBInaryTree(struct node * root, int element){
    if(!root -> left){
        root -> left = (struct node *)malloc(sizeof(struct node));
        root -> left -> data = element;
        root -> left -> left = root -> left -> right = NULL;
        return;
    }
    else if(!root -> right){
        root -> right = (struct node *)malloc(sizeof(struct node));
        root -> right -> data = element;
        root -> right -> left = root -> right -> right = NULL;
        return;
    }
    if(flag %2){
        createBInaryTree(root -> left, element);
        flag++;
    }
    else{
        createBInaryTree(root -> right, element);
    }
}
struct node * createTree(){
    int element, choice;
    struct node * root = NULL;
    do{
        
        printf("Enter your choice\n 1 - insert an element in a tree\n 0- Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1 : printf("enter a value to insert\n");
                scanf("%d", &element);
                if(!root){
                    root = (struct node *)malloc(sizeof(struct node));
                    root -> data = element;
                    root -> left = root -> right = NULL;
                }
                else{
                    createBInaryTree(root, element);
                }
                break;
            case 0 : break;
            default: printf("Enter a valid choice\n");
                
        }
    }while(choice);
    return root;
}
int main(void) {
    int value;
    inOrderTraversalArray = (int *)malloc(20 *sizeof(int));
    struct node * root = createTree();
    printf("Enter value to search\n");
    scanf("%d",&value);
    printf("%d\n",isMirrorTreeForChildsOfGivenNode(root, value));
    return 0;
}