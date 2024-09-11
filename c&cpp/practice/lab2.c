#include <stdio.h>
#include <ctype.h>

#define STACK_SIZE 50

typedef struct {
    char items[STACK_SIZE];
    int top;
} Stack;

void push(Stack *stack, char elem) {
    if (stack->top == STACK_SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack->items[++stack->top] = elem;
}

char pop(Stack *stack) {
    if (stack->top == -1) {
        printf("Stack Underflow\n");
        return '\0';
    }
    return stack->items[stack->top--];
}

int precedence(char op) {
    switch (op) {
        case '#': return 0;
        case '(': return 1;
        case '+':
        case '-': return 2;
        case '*':
        case '/':
        case '%': return 3;
        case '^': return 4;
        default: return -1; // Handle invalid operators
    }
}

int main() {
    char infix[50], postfix[50], ch;
    int i = 0, k = 0;
    Stack stack;
    stack.top = -1;

    printf("Enter the Infix Expression: ");
    scanf("%s", infix);
    push(&stack, '#');

    while ((ch = infix[i++]) != '\0') {
        if (ch == '(') {
            push(&stack, ch);
        } else if (isalnum(ch)) {
            postfix[k++] = ch;
        } else if (ch == ')') {
            while (stack.items[stack.top] != '(')
                postfix[k++] = pop(&stack);
            pop(&stack); // Remove '('
        } else { // Operator
            while (precedence(stack.items[stack.top]) >= precedence(ch))
                postfix[k++] = pop(&stack);
            push(&stack, ch);
        }
    }

    while (stack.items[stack.top] != '#')
        postfix[k++] = pop(&stack);

    postfix[k] = '\0';

    printf("Infix Expression: %s\nPostfix Expression: %s\n", infix, postfix);
    
    return 0;
}
