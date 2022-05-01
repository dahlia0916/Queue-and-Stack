#include "queue_linkedlist.h"
#include <stdlib.h>


// --------------------------------------------------------------------
// 변경 금지
// --------------------------------------------------------------------

// 초기화
void queue_init_lq(LinkedList_Queue* queue)
{
    queue->front = NULL;
    queue->rear = NULL;
}

// --------------------------------------------------------------------


/*
* 구현시 유의사항
* 1. 함수명과 매개변수는 수정하시지 마세요.
* 2. 반환값 정확하게 구현해주세요. (bool, int)
* 3. 발생할 수 있는 모든 예외사항을 처리해주세요.  (underflow/overflow)
*/

// --------------------------------------------------------------------
// Queue 구현
// --------------------------------------------------------------------
int queuenum = 0;
// true/false 반환
bool is_empty_lq(LinkedList_Queue* queue)
{
    if (queue->front == NULL)
        return true;
    else
        return false;
}

// true/false 반환
bool is_full_lq(LinkedList_Queue* queue)
{
    if (queuenum == MAX_QUEUE_SIZE_LL)
        return true;
    else
        return false;
}

// Enqueue 성공 : 0 반환 / 실패 : -1 반환
int enqueue_lq(LinkedList_Queue* queue, int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (is_full_lq(queue))
        return -1;
    else if (queue->front==NULL) {
        queue->rear = newNode;
        queue->front = newNode;
        queuenum++;
        return 0;
    }
    else{
        queue->rear->next = newNode;
        queue->rear = newNode;
        queuenum++;
        return 0;
    }
}

// Dequeue 성공 : Dequeue 값 반환 / 실패 : -1 반환
int dequeue_lq(LinkedList_Queue* queue)
{
    Node* p;
    if (is_empty_lq(queue))
        return -1;
    else {
        p = queue->front;
        int deque_n = p->data;
        queue->front = p->next;
        free(p); 
        queuenum--;
        return deque_n;
    }
}
