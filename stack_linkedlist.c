#include "stack_linkedlist.h"
#include <stdlib.h>

// --------------------------------------------------------------------
// 변경 금지
// --------------------------------------------------------------------

// 스택 초기화
void stack_init_ls(LinkedList_Stack* stack)
{
    stack->top = NULL;
}

// --------------------------------------------------------------------

/*
* 구현시 유의사항
* 1. 함수명과 매개변수는 수정하시지 마세요.
* 2. 반환값 정확하게 구현해주세요. (bool, int)
*/

// --------------------------------------------------------------------
// 기초 스택 구현 - 모두 구현 B
// --------------------------------------------------------------------

// 스택이 비어있는지 확인, true/false 반환
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
* 스택이 가득찼는지 확인, true/false 반환
* 스택의 최대 원소의 개수는 MAX_STACK_SIZE
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

// 스택에 원소 삽입
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

// // 스택의 최상위 원소(top)를 삭제하고 반환
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
// 심화 스택 구현
// --------------------------------------------------------------------

// 현재 스택 원소 개수 반환
int get_stack_size_ls(LinkedList_Stack* stack)
{
    return stacknum;
}

// 스택의 최상위 원소(top) 값 반환
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
* 스택의 최상위 원소부터 순서대로 출력 (pop X)
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
