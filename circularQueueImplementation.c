#include <stdio.h>
#include <stdlib.h>
int readUserChoice();
void enqueue(int);
int dequeue();
int peak();
int * queue, front = 0, rare  =0, size;
int main(int argc, const char * argv[]) {
    
    int userChoice, element;
    scanf("%d",&size);
    queue = (int *)malloc(size * sizeof(int));
    while(1){
        userChoice = readUserChoice();
        switch(userChoice){
            case 1: scanf("%d",&element);
                enqueue(element);
                break;
            case 2: printf("%d\n",dequeue());
                break;
            case 3 : printf("%d\n",peak());
                break;
            case 4: return 0;
            default: printf("Enter valid input\n");
        }
    }
    return 0;
}
void enqueue(int element){
    if(rare - front == size){
        printf("Queue is full\n");
        return;
    }
    queue[rare%size] = element;
    rare++;
}
int dequeue(){
    if(front == rare){
        printf("Queue is empty\n");
        return 0;
    }
    front ++;
    return queue[(front-1)%size];
}
int peak(){
    if(front == rare){
        printf("Queue is empty\n");
        return 0;
    }
    return queue[front];
}
int readUserChoice(){
    int userChoice;
    printf("1 - Enqueue\n2 - Dequeue\n3 - Peak\n4 - Quit\n");
    scanf("%d",&userChoice);
    return userChoice;
}
