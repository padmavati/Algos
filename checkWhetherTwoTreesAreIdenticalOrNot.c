

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left, *right;
};
int twoTreesAreEqualOrNot(struct node * tree1, struct node * tree2){
    if((!tree1 && tree2) || (tree1 && !tree2))
        return 0;
    if(tree1 && tree2 && tree1 -> data != tree2 -> data)
        return 0;
    if(!tree1 && !tree2)
        return 1;
    return twoTreesAreEqualOrNot(tree1 -> left , tree2 -> left) && twoTreesAreEqualOrNot(tree1 -> right, tree2 -> right);

}
void createChild(struct node ** root, int value){
    if((*root) -> left == NULL){
        (*root) -> left = (struct node *)malloc(sizeof(struct node));
        (*root) -> left -> data = value;
        (*root) -> left -> left = (*root) -> left -> right = NULL;
        return;
    }
    else if((*root) -> right == NULL){
        (*root) -> right = (struct node *)malloc(sizeof(struct node));
        (*root) -> right -> data = value;
        (*root) -> right -> left = (*root) -> right -> right = NULL;
        return;
    }
    else if(((*root) -> left == NULL || (*root) -> right == NULL ) ||
            ((*root) -> right ->left!= NULL && (*root) -> right -> right != NULL))
        createChild(&((*root) -> left), value);
    else
        createChild(&((*root) -> right), value);
}
struct node * createTree(int * array, int size){
    if(size <= 0)
        return NULL;
    struct node * root = (struct node *)malloc(sizeof(struct node));
    root -> data = array[0];
    root -> left = root -> right = NULL;
    for(int index = 1; index < size; index++)
        createChild(&root, array[index]);
    return root;
}
int * readInputElements(int size){
    
    int * inpArray = (int *)malloc(size * sizeof(int));
    for(int index = 0; index < size ; index++)
        scanf("%d", &inpArray[index]);
    return inpArray;
}
int main(int argc, const char * argv[]) {
    int size;
    printf("Enter size of first tree\n");
    scanf("%d",&size);
    int * inpArray = readInputElements(size);
    struct node * tree1 = createTree(inpArray, size);
    printf("Enter size of second tree\n");
    scanf("%d", &size);
    inpArray = readInputElements(size);
    struct node * tree2 = createTree(inpArray, size);
    printf("%d\n", twoTreesAreEqualOrNot(tree1, tree2));
    return 0;
}
