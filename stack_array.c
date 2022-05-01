#include "stack_array.h"

// --------------------------------------------------------------------
// ���� ����
// --------------------------------------------------------------------

// ���� �ʱ�ȭ
void stack_init_as(Array_Stack* stack)
{
    stack->top = 0;
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
bool is_empty_as(Array_Stack* stack)
{
    if (stack->top==0)
        return true;
    else return false;
}

/*
* ������ ����á���� Ȯ��, true/false ��ȯ
* ������ �ִ� ������ ������ MAX_STACK_SIZE
*/
bool is_full_as(Array_Stack* stack)
{
    if (stack->top==MAX_STACK_SIZE)
        return true;
    else return false;
}

// ���ÿ� ���� ����
void push_as(Array_Stack* stack, int data)
{
    if (is_full_as(stack)) printf("stack full");
    else {
        stack->array[stack->top] = data;
        stack->top += 1;
    }
}

// ������ �ֻ��� ����(top)�� �����ϰ� ��ȯ
int pop_as(Array_Stack* stack)
{
    int r = 0;
    if (is_empty_as(stack))
        printf("stack empty");
    else {
        r = stack->array[stack->top-1];
        stack->top -= 1;
    }
    return r;
}


// --------------------------------------------------------------------
// ��ȭ ���� ����
// --------------------------------------------------------------------

// ���� ���� ���� ���� ��ȯ
int get_stack_size_as(Array_Stack* stack)
{
    return stack->top;
}

// ������ �ֻ��� ����(top) �� ��ȯ
int get_top_as(Array_Stack* stack)
{
    if (is_empty_as(stack)) {
        return -1;
    }
    else{
        return stack->array[stack->top-1];
    }
}

/*
* ������ �ֻ��� ���Һ��� ������� ��� (pop X)
* top ... bottom 
* ex) 5 10 12 4 3
*/
void print_stack_as(Array_Stack* stack)
{
    int i;
    if (is_empty_as(stack)) {
        printf(" ");
    }
    else {
        for (i = stack->top - 1; i >= 0; i--) {
            printf("%2d", stack->array[i]);
        }
    }
}

