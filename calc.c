#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "buffer.h"

void processCharacter(Stack* stack, NumberBuffer* buffer, char c) {
  char lastCharInBuffer;
  int val2;
  switch(c) {
    case '*':
      push(stack, pop(stack) * pop(stack));
      printStack(stack, "*");
      break;
    case '+':
      push(stack, pop(stack) + pop(stack));
      printStack(stack, "+");
      break;
    case '-':
      val2 = pop(stack);
      push(stack, pop(stack) - val2);
      printStack(stack, "-");
      break;
    case '/':
      val2 = pop(stack);
      push(stack, pop(stack) / val2);
        printStack(stack, "/");
      break;
    case ' ': case '\t':
      lastCharInBuffer = peekDigit(buffer);
      if (isNumber(lastCharInBuffer)) {
        pushCharacter(buffer, '\0');
        push(stack, atof(buffer->digits));
        printStack(stack, "space");
        buffer->size = 0;
      }
      break;
    case '\n':
      // assumes enter finishes the end of the calculation
      printf("Result: %f\n", pop(stack));
      break;
    default:
      pushCharacter(buffer, c);
      printBuffer(buffer);
  }
}