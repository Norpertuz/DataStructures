#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct Element {
    int data;
    struct Element* next;
};

struct Stack {
    struct Element* top;
    int size;
};


struct Stack* initStack(){
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));

    if (!stack) {
        return NULL;
    }
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

void push(struct Stack* stack, int data) {
    struct Element* newElement = (struct Element*)malloc(sizeof(struct Element));
    if (!newElement) {
        return;
    }
    newElement->data = data;
    newElement->next = stack->top;
    stack->top = newElement;
    stack->size++;
}

int pop(struct Stack* stack){
    if (isEmpty(stack)) {
        return -1;  
    }
    int data = stack->top->data;
    struct Element* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    stack->size--;
    return data;
}

int isEmpty(struct Stack* stack) {
    return stack->size == 0;
}

int size(struct Stack* stack){
    return stack->size;
}

void freeStack(struct Stack* stack){
    printf("Data in stack: ");
    while(!isEmpty(stack)){
        printf("%d ",pop(stack));
    }
    printf("\n");
    free(stack);
}

void returnData(struct Stack* stack){
    struct Stack* displayedStack = initStack();
    struct Element* currentElement = stack->top;
    while (currentElement != NULL) {
        int data = currentElement->data;
        push(displayedStack, data);
        currentElement = currentElement->next;
    }
    freeStack(displayedStack);
}

int main(){
    struct Stack* stack = initStack();
    char choice;
    while(1){
    printf("Select the appropriate operation: \n");
    printf("1.Push element to stack\n");
    printf("2.Pop element from stack\n");
    printf("3.Display size of the stack\n");
    printf("4.Display data elements within stack\n");
    printf("5.Exit\n");
    scanf(" %c", &choice);

    switch(choice){
        case '1':
            int data;
            printf("Enter the number: ");
            scanf("%d", &data);
            printf("\n");
            push(stack,data);
        break;
        case '2':
            pop(stack);
        break;
        case '3':
            printf("Stack size: %d\n",size(stack));
        break;
        case '4':
            returnData(stack);
        break;
        case '5':
            freeStack(stack);
            return 0;
        break;
    }

    }
}