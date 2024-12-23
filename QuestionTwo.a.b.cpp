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
