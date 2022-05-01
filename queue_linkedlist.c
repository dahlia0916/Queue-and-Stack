#include "queue_linkedlist.h"
#include <stdlib.h>


// --------------------------------------------------------------------
// ���� ����
// --------------------------------------------------------------------

// �ʱ�ȭ
void queue_init_lq(LinkedList_Queue* queue)
{
    queue->front = NULL;
    queue->rear = NULL;
}

// --------------------------------------------------------------------


/*
* ������ ���ǻ���
* 1. �Լ���� �Ű������� �����Ͻ��� ������.
* 2. ��ȯ�� ��Ȯ�ϰ� �������ּ���. (bool, int)
* 3. �߻��� �� �ִ� ��� ���ܻ����� ó�����ּ���.  (underflow/overflow)
*/

// --------------------------------------------------------------------
// Queue ����
// --------------------------------------------------------------------
int queuenum = 0;
// true/false ��ȯ
bool is_empty_lq(LinkedList_Queue* queue)
{
    if (queue->front == NULL)
        return true;
    else
        return false;
}

// true/false ��ȯ
bool is_full_lq(LinkedList_Queue* queue)
{
    if (queuenum == MAX_QUEUE_SIZE_LL)
        return true;
    else
        return false;
}

// Enqueue ���� : 0 ��ȯ / ���� : -1 ��ȯ
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

// Dequeue ���� : Dequeue �� ��ȯ / ���� : -1 ��ȯ
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
