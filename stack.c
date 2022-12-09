#include <stdio.h>
#include "stack.h"

#define MAX_DEPTH 100
double pop(Stack* stack) {
  stack->top--;
  return stack->elements[stack->top];
}

void push(Stack* stack, double number) {
  stack->elements[stack->top] = number;
  stack->top++;
}

Stack initStack() {
  Stack stack;
  stack.top = 0;
  double elements[MAX_DEPTH];
  stack.elements = elements;

  return stack;
}

void printStack(Stack* stack, char operation[]) {
  return;
  printf("%s, Stack top %d: ", operation, stack->top);
  for (int i = 0; i < stack->top; i++) {
    printf("%f ", stack->elements[i]);
  }
  printf("\n");
}
