#include<stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;


void enqueue(int value){
    if ((rear + 1) % SIZE == front){
        printf("Queue is full !!\n");
        return;
    }
    if (front == -1) {
        front = 0;  
    }
    rear = (rear + 1) % SIZE;  
    queue[rear] = value;
    printf("%d inserted into queue.\n", value);
}

void dequeue(){
    if (front == -1){
        printf("Queue is empty!\n");
        return;
    }
    printf("%d removed from queue. \n", queue[front]);
    if (front == rear) { 
        front = rear = -1;  
    } else {
        front = (front + 1) % SIZE;  
    }
}


void display(){
    if (front == -1) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    int i = front;
    while (i != rear) {
        printf("%d ", queue[i]);
        i = (i + 1) % SIZE;  // Circular increment of index
    }
    printf("%d\n", queue[rear]);  // Print the last element
}

int main(){
    int choice, value;
    while (1){
        printf("\n==== Queue Menu ====\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice){
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
