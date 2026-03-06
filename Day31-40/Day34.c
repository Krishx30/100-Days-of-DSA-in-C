#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void push(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

int pop()
{
    if (top == NULL)
    {
        printf("Stack Underflow\n");
        return 0;
    }

    struct Node *temp = top;
    int value = temp->data;
    top = top->next;
    free(temp);

    return value;
}

int evaluatePostfix(char *expr)
{
    char *token = strtok(expr, " ");

    while (token != NULL)
    {
        // Operand
        if (isdigit(token[0]))
        {
            push(atoi(token));
        }
        // Operator
        else
        {
            int b = pop();
            int a = pop();
            int result;

            switch (token[0])
            {
            case '+':
                result = a + b;
                break;
            case '-':
                result = a - b;
                break;
            case '*':
                result = a * b;
                break;
            case '/':
                result = a / b;
                break;
            }

            push(result);
        }

        token = strtok(NULL, " ");
    }

    return pop();
}

int main()
{
    char expression[200];

    printf("Enter postfix expression (space separated):\n");
    fgets(expression, sizeof(expression), stdin);

    int result = evaluatePostfix(expression);

    printf("Result: %d\n", result);

    return 0;
}