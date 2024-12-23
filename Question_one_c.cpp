
Question Two
a)	     
#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int *arr;
    int front, rear, size;
};

struct Queue* create_queue(int size) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->arr = (int*)malloc(size * sizeof(int));
    queue->front = 0;
    queue->rear = -1;
    queue->size = size;
    return queue;
}

int is_empty(struct Queue* queue) {
    return queue->rear < queue->front;
}

int is_full(struct Queue* queue) {
    return queue->rear == queue->size - 1;
}

void enqueue(struct Queue* queue, int value) {
    if (is_full(queue)) {
        printf("Queue Overflow\n");
        return;
    }
    queue->arr[++queue->rear] = value;
}

int dequeue(struct Queue* queue) {
    if (is_empty(queue)) {
        printf("Queue Underflow\n");
        return -1;
    }
    return queue->arr[queue->front++];
}

int size(struct Queue* queue) {
    return queue->rear - queue->front + 1;
}

int find_max(struct Queue* queue) {
    int max = dequeue(queue);  
    enqueue(queue, max);       

    int queue_size = size(queue);
    
    for (int i = 1; i < queue_size; i++) {
        int temp = dequeue(queue);
        if (temp > max) {
            max = temp;
        }
        enqueue(queue, temp);
    }

    return max;
}

int main() {
    struct Queue* queue = create_queue(5);
    
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 5);
    enqueue(queue, 25);
    
    printf("Maximum Element in Queue: %d\n", find_max(queue));
    
    return 0;
}     
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define size 20

struct stack{
    int top;
    char name[size][20];
    int age[size];
}st;

void push(char name[], int age){
    if(st.top==size-1){
        printf("Stack is full\n");
        return;
    }
    st.top++;
    strcpy(st.name[st.top], name);
    st.age[st.top] = age;
}

void pop(){
    if(st.top==-1){
        printf("Stack is empty\n");
        return;
    }
    printf("Name: %s\n", st.name[st.top]);
    printf("Age: %d\n", st.age[st.top]);
    st.top--;
}

void display(){
    int i;
    if(st.top==-1){
        printf("Stack is empty\n");
        return;
    }
    for(i=st.top;i>=0;i--){
        printf("Name: %s\n", st.name[i]);
        printf("Age: %d\n", st.age[i]);
    }
}

int main(){
    st.top=-1;
    int n,i;
    printf("Enter the number of students\n");
    scanf("%d",&n);
    printf("Enter the names and ages of the students\n");
    for(i=0;i<n;i++){
        char name[20];
        int age;
        scanf("%s %d",name,&age);
        push(name, age);
    }
    printf("The students in the stack are\n");
    display();
    printf("The students in the stack after popping are\n");
    for(i=0;i<n;i++){
        pop();
    }
    return 0;
}