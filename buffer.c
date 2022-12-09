#include <stdio.h>
#include <stdlib.h>
#include "buffer.h"

NumberBuffer initBuffer() {
  NumberBuffer buffer;

  buffer.capacity = STARTING_CAPACITY;
  buffer.size = 0;
  buffer.digits = (char*)malloc(sizeof(char) * STARTING_CAPACITY);

  return buffer;
}

void pushCharacter(NumberBuffer* buffer, char c) {
  int newCapacity;
  if (buffer->size >= buffer->capacity) {
    newCapacity = buffer->capacity * 2;
    buffer->digits = (char*)realloc(buffer->digits, newCapacity);
    // printf("buffer increased to %d\n", newCapacity);
    buffer->capacity = newCapacity;
  }

  buffer->digits[buffer->size] = c;
  buffer->size++;
}

char peekDigit(NumberBuffer* buffer) {
  return buffer->digits[buffer->size - 1];
}

int isNumber(char c) {
  int number = c - '0';
  if (number >= 0 && number <= 9) {
    return 1;
  }
  return 0;
}

void printBuffer(NumberBuffer* buffer) {
  return;
  printf("buffer: ");
  for (int i = 0; i < buffer->size; i++) {
    printf("%c", buffer->digits[i]);
  }
  printf("\n");
}
