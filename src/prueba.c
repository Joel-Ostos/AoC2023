#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) 
{
  char* str;
  size_t size = 0;
  getline(&str, &size, stdin);
  while (str[0] != '\n') {
    printf("hola");
    getline(&str, &size, stdin);
  }
}
