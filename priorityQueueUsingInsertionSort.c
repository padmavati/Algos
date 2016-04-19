
#include <stdio.h>
#include <stdlib.h>

int * queue, size, front, rare;
void enqueue();
int dequeue();
int peak();
int main(int argc, const char * argv[]) {

    int userChoice;
    scanf("%d",&size);
    queue = (int *)malloc(size * sizeof(int));
    while(1){
        printf("1 - Enque\n2 -  Dequeue\n3 - peak\nAny other input - Exit\n");
        scanf("%d",&userChoice);
        userChoice == 1 ? enqueue() : (userChoice == 2 ? printf("%d\n",dequeue()) : (userChoice == 3 ? printf("%d\n",peak()) : exit(0)));
    }
    return 0;
}
void enqueue(){
    if(rare == size){
        printf("Queue is full\n");
        return;
    }
    int element, index = rare -1;
    scanf("%d",&element);
    while(queue[index] < element && index >= 0){
            queue[index+1] = queue[index];
            index--;
    }
    queue[index+1] = element;
    rare++;
}
int peak(){
    if(front == rare)
    {
        printf("Queue is empty\n");
        return 0;
    }
    return queue[front];
}
int dequeue(){
    if(front == rare)
    {
        printf("Queue is empty\n");
        return 0;
    }
    return queue[front++];

}
