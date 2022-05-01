#include "queue_array.h"

// --------------------------------------------------------------------
// ���� ����
// --------------------------------------------------------------------

// �ʱ�ȭ
void queue_init_aq(Array_Queue* queue)
{
    queue->front = 0;
    queue->rear = 0;
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

// true/false ��ȯ
bool is_empty_aq(Array_Queue* queue)
{
    if (queue->front == queue->rear)
        return true;
    else
        return false;
}

// true/false ��ȯ
bool is_full_aq(Array_Queue* queue)
{
    if (queue->rear == MAX_QUEUE_SIZE_ARR - 1)
        return true;
    else
        return false;
}

// Enqueue ���� : 0 ��ȯ / ���� : -1 ��ȯ
int enqueue_aq(Array_Queue* queue, int data)
{
    if (is_full_aq(queue))
        return -1;
    else {
        queue->array[queue->rear] =data;
        queue->rear = queue->rear++;
        return 0;
    }
        
}

// Dequeue ���� : Dequeue �� ��ȯ / ���� : -1 ��ȯ
int dequeue_aq(Array_Queue* queue)
{
    if (is_empty_aq(queue))
        return -1;
    else {
        int deque_n = queue->front;
        queue->front = queue->front++;
        return queue->array[deque_n];


    }


}
