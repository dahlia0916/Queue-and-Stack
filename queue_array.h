#include <stdio.h>
#include <stdbool.h>

// rear �� �ϳ��� ������ �����ϰ� �ֱ� ������, 
// ť�� ������ �� �ִ� �ڷ��� ������ MAX_QUEUE_SIZE-1
#define MAX_QUEUE_SIZE_ARR 11    

typedef struct Array_Queue {
    int array[MAX_QUEUE_SIZE_ARR];
    int front;
    int rear;
}Array_Queue;

void queue_init_aq(Array_Queue* queue);

bool is_empty_aq(Array_Queue* queue);
bool is_full_aq(Array_Queue* queue);

int enqueue_aq(Array_Queue* queue, int data);
int dequeue_aq(Array_Queue* queue);
