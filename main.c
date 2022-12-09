#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "buffer.h"
#include "calc.h"
#include "file.h"

/*
  Example:
  34 56 / 57 7 * + 234 - => 165
*/ 
int main(int argc, char* argv[]) {
  Stack stack = initStack();
  NumberBuffer buffer = initBuffer();
  char c;
  char* file;
  char* filePointer;
  if (argc == 1) {
    while((c = getchar()) != EOF) {
      processCharacter(&stack, &buffer, c);
    }
  } else if (argc == 2) {
    file = readFile(argv[1]);
    filePointer = file;
    while(*filePointer != '\0') {
      processCharacter(&stack, &buffer, *filePointer);
      filePointer++;
    }
  } else {
    // Raise some sort of error here
  }
  free(buffer.digits);
  free(file);
}
