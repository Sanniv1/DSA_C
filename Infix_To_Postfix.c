#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 50

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

void infixToPostfix(char* expression) {
    int i, j = 0, top = -1;
    char stack[MAX_SIZE], postfix[MAX_SIZE];

    for (i = 0; expression[i]; i++) {
        if (expression[i] == '(') {
            stack[++top] = '(';
        } else if (isalnum(expression[i])) {
            postfix[j++] = expression[i];
        } else if (expression[i] == ')') {
            while (stack[top] != '(')
                postfix[j++] = stack[top--];
            top--;
        } else {
            while (top >= 0 && precedence(stack[top]) >= precedence(expression[i]))
                postfix[j++] = stack[top--];
            stack[++top] = expression[i];
        }
    }
    while (top >= 0)
        postfix[j++] = stack[top--];
    postfix[j] = '\0';
    printf("Postfix: %s\n", postfix);
}

int main() {
    char expression[MAX_SIZE];
    printf("Enter infix expression: ");
    fgets(expression, MAX_SIZE, stdin);
    expression[strcspn(expression, "\n")] = 0;
    infixToPostfix(expression);
    return 0;
}