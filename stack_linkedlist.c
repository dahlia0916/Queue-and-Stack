#include "stack_linkedlist.h"
#include <stdlib.h>

// --------------------------------------------------------------------
// ���� ����
// --------------------------------------------------------------------

// ���� �ʱ�ȭ
void stack_init_ls(LinkedList_Stack* stack)
{
    stack->top = NULL;
}

// --------------------------------------------------------------------

/*
* ������ ���ǻ���
* 1. �Լ���� �Ű������� �����Ͻ��� ������.
* 2. ��ȯ�� ��Ȯ�ϰ� �������ּ���. (bool, int)
*/

// --------------------------------------------------------------------
// ���� ���� ���� - ��� ���� B
// --------------------------------------------------------------------

// ������ ����ִ��� Ȯ��, true/false ��ȯ
bool is_empty_ls(LinkedList_Stack* stack)
{
    if (stack->top == NULL)
        return true;
    else {
        return false;
    }
 
}
int stacknum = 0;
/*
* ������ ����á���� Ȯ��, true/false ��ȯ
* ������ �ִ� ������ ������ MAX_STACK_SIZE
*/
bool is_full_ls(LinkedList_Stack* stack)
{
    if (stacknum == MAX_STACK_SIZE) {
        return true;
    }
    else {
        return false;
    }
}

// ���ÿ� ���� ����
void push_ls(LinkedList_Stack* stack, int data)
{
    if (is_full_ls(stack)) {
        printf("stack is full");
    }
    else{
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = data;
        newNode->next = stack->top;
        stack->top = newNode;
        stacknum++;
            
    }
    

}

// // ������ �ֻ��� ����(top)�� �����ϰ� ��ȯ
int pop_ls(LinkedList_Stack* stack)
{
    if (is_empty_ls(stack)) {
        printf("stack is empty");
        return -1;
    }
    else {
        int data = stack->top->data;
        Node* p = stack->top;
        stack->top = stack->top->next;
        stacknum--;
        free(p);
        return data;
    }
}


// --------------------------------------------------------------------
// ��ȭ ���� ����
// --------------------------------------------------------------------

// ���� ���� ���� ���� ��ȯ
int get_stack_size_ls(LinkedList_Stack* stack)
{
    return stacknum;
}

// ������ �ֻ��� ����(top) �� ��ȯ
int get_top_ls(LinkedList_Stack* stack)
{
    if (is_empty_ls(stack)) {
        return -1;
    }
    else {
        return stack->top->data;
    }
}

/*
* ������ �ֻ��� ���Һ��� ������� ��� (pop X)
* top ... bottom
* ex) 5 10 12 4 3
*/
void print_stack_ls(LinkedList_Stack* stack)
{
    if (is_empty_ls(stack)) {
        printf(" ");
    }
    else {
        while(stack->top != NULL) {
            printf("%2d", stack->top->data);
            stack->top = stack->top->next;
        }
    }
}
