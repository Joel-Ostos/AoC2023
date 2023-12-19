#include <stdio.h>
#include <stdlib.h>
#include "../data_structures.h"

arraylist(char)

long process(ArrayList_char str)
{
  int actual = 0;
  for (size_t i = 0; i < str.occupied; i++) {
    if (str.array[i] == '\n') break;
    char character = str.array[i];
    actual = ((actual+(character-0))*17)%256;
  }
  return actual;
} 

void day1()
{
  char* tmp = NULL;
  size_t size = 0;
  if (getline(&tmp, &size, stdin) == -1) {perror("Error: "); exit(1);}
  ArrayList_char str = set_array_char(tmp, strlen(tmp)+1);
  long long suma = 0, cont = 0;
  for (size_t i = 0; i < str.occupied; i++) {
    cont = i;
    ArrayList_char actual = init_array_char(1);
    while (1) {
      if (str.array[cont] == ',' || str.array[cont] == '\0') {
	suma+=process(actual);
	break;
      }
      push_back_array_char(&actual, str.array[cont]);
      cont++;
    }
    deinit_array_char(&actual);
    i = cont;
  }
  printf("Result -> %lld", suma);
}

int main(void)
{
  day1();
}
