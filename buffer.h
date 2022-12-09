#ifndef buffer_h
#define buffer_h

#define STARTING_CAPACITY 2

typedef struct NumberBuffer {
  int capacity;
  int size;
  char *digits;
} NumberBuffer;

NumberBuffer initBuffer();
void printBuffer(NumberBuffer* buffer);
char peekDigit(NumberBuffer* buffer);
int isNumber(char c);
void pushCharacter(NumberBuffer* buffer, char c);

#endif