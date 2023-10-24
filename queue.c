#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
struct Element{
    uint8_t data;
    struct Element* next;
};

struct Queue{
    struct Element* front;
    struct Element* back;
    uint8_t size;
};

struct Queue* createQueue(){
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));

    if (!queue) {
        return NULL;  // Memory allocation failure
    }

    queue->front = queue->back = NULL;
    queue->size = 0;
    return queue;
}

bool isEmpty(struct Queue* queue){
    return queue->front == NULL;
}

uint8_t size(struct Queue* queue){
    return queue->size;
}

void addElement(struct Queue* queue,  uint8_t data){
    struct Element* newElement = (struct Element*)malloc(sizeof(struct Element));

    if (!newElement) {
        return NULL;  // Memory allocation failure
    }
    newElement->data = data;
    newElement->next = NULL;

    if (isEmpty(queue)) {
        queue->front = queue->back = newElement;
        return;
    }

    queue->back->next = newElement;
    queue->back = newElement;
    queue->size++;
}

uint8_t removeElement(struct Queue* queue){
    if (isEmpty(queue)) {
        return -1;
    }

    struct Element* temp = queue->front;
    uint8_t data = temp->data;
    queue->front = queue->front->next;
    free(temp);
    queue->size--;

    if(queue->front == NULL){
        queue->back = NULL;
    }
    return data;
}

void displayElements(struct Queue* queue){
    struct Queue* displayedQueue = createQueue();
    struct Element* currentElement = queue->front;
    while (currentElement != NULL) {
        uint8_t data = currentElement->data;
        addElement(displayedQueue, data);
        currentElement = currentElement->next;
    }
    printf("Data in queue: ");
    while(!isEmpty(displayedQueue)){
        printf("%d ",removeElement(displayedQueue));
    }
    printf("\n");
    free(displayedQueue);
}
   

int main(){
    
    struct Queue* queue = createQueue();
    char choice;
    while(1){
    printf("Select the appropriate operation: \n");
    printf("1.Push element to queue\n");
    printf("2.Pop element from queue\n");
    printf("3.Display size of the queue\n");
    printf("4.Display data elements within queue\n");
    printf("5.Exit\n");
    scanf(" %c", &choice);

    switch(choice){
        case '1':
            uint8_t data;
            printf("Enter the number: ");
            scanf("%hhd", &data);
            printf("\n");
            addElement(queue,data);
        break;
        case '2':
            removeElement(queue);
        break;
        case '3':
            printf("Queue size: %hhd\n",size(queue));
        break;
        case '4':
            displayElements(queue);
        break;
        case '5':
            free(queue);
            return 0;
        break;
    }

    }

    return 0;
}