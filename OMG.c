#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

// Global stacks and top pointers
int operandStack[MAX], operatorStack[MAX];
int operandTop = -1, operatorTop = -1;

// Function prototypes
void pushOperand(int value);
int popOperand();
void pushOperator(char op);
char popOperator();
char peekOperator();
int precedence(char op);
int applyOperation(int a, int b, char op);
int evaluateInfix(const char* expression);

int main() {
    char expression[MAX];

    printf("Enter infix expression: ");
    scanf("%s", expression);

    int result = evaluateInfix(expression);
    printf("Result: %d\n", result);

    return 0;
}

// Function to push an operand onto the stack
void pushOperand(int value) {
    if (operandTop == MAX - 1) {
        printf("Operand stack overflow\n");
        exit(1);
    }
    operandStack[++operandTop] = value;
}

// Function to pop an operand from the stack
int popOperand() {
    if (operandTop == -1) {
        printf("Operand stack underflow\n");
        exit(1);
    }
    return operandStack[operandTop--];
}

// Function to push an operator onto the stack
void pushOperator(char op) {
    if (operatorTop == MAX - 1) {
        printf("Operator stack overflow\n");
        exit(1);
    }
    operatorStack[++operatorTop] = op;
}

// Function to pop an operator from the stack
char popOperator() {
    if (operatorTop == -1) {
        printf("Operator stack underflow\n");
        exit(1);
    }
    return operatorStack[operatorTop--];
}

// Function to get the top operator without popping
char peekOperator() {
    if (operatorTop == -1) return -1;
    return operatorStack[operatorTop];
}

// Function to return precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Function to apply an operation to two operands
int applyOperation(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        default: printf("Invalid operator\n"); exit(1);
    }
}

// Function to evaluate an infix expression
int evaluateInfix(const char* expression) {
    int i;
    for (i = 0; expression[i] != '\0'; i++) {
        // If the character is a digit, push it to the operand stack
        if (isdigit(expression[i])) {
            int num = 0;
            while (isdigit(expression[i])) {
                num = num * 10 + (expression[i] - '0');
                i++;
            }
            i--;
            pushOperand(num);
        }
        // If the character is '(', push it to the operator stack
        else if (expression[i] == '(') {
            pushOperator(expression[i]);
        }
        // If the character is ')', solve the entire brace
        else if (expression[i] == ')') {
            while (peekOperator() != '(') {
                int val2 = popOperand();
                int val1 = popOperand();
                char op = popOperator();
                pushOperand(applyOperation(val1, val2, op));
            }
            popOperator(); // Pop '('
        }
        // If the character is an operator
        else {
            while (operatorTop != -1 && precedence(peekOperator()) >= precedence(expression[i])) {
                int val2 = popOperand();
                int val1 = popOperand();
                char op = popOperator();
                pushOperand(applyOperation(val1, val2, op));
            }
            pushOperator(expression[i]);
        }
    }

    // Entire expression has been parsed at this point, apply remaining operators
    while (operatorTop != -1) {
        int val2 = popOperand();
        int val1 = popOperand();
        char op = popOperator();
        pushOperand(applyOperation(val1, val2, op));
    }

    // The final result is in the operand stack
    return popOperand();
}

