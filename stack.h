#ifndef stack_h
#define stack_h
typedef struct Stack {
  int top;
  int capacity;
  double* elements;
} Stack;

double pop(Stack* stack);
void push(Stack* stack, double number);
Stack initStack();
void printStack(Stack* stack, char operation[]);

#endif