#include <stdio.h>
#include <stdlib.h>
#include "../data_structures.h"
#define ROWS 100
#define COLUMNS 100

arraylist(char)
arraylist(ArrayList_char)
extension(char)

void day1()
{
  ArrayList_ArrayList_char map = init_array_ArrayList_char(ROWS);
  size_t ca = ROWS;
  long suma = 0;
  while (ca>0) {
    char tmp[COLUMNS];  
    scanf("%s", tmp);
    ArrayList_char str = set_array_char(tmp, COLUMNS);
    push_back_arraymatrix_char(&map, &str, true);
    ca--;
  }

  for (size_t i = 1; i < map.occupied; i++) {
    for (size_t j = 0; j < map.array[i].occupied; j++) {
      if (map.array[i].array[j] == 'O') {
	int cont = i-1;
	while (cont >= 0 && map.array[cont].array[j] == '.') {
	  map.array[cont+1].array[j] = '.';
	  map.array[cont].array[j] = 'O';
	  cont--;
	}
      }
    }
  }
  for (size_t i = 0; i < map.occupied; i++) {
    int cont = 0;
    for (size_t j = 0; j < map.array[i].occupied; j++) {
      if (map.array[i].array[j] == 'O') cont+= 1;
    }
    suma += cont*(ROWS-i);
  }
  printf("----\n");
  for (size_t i = 0; i < map.occupied; i++) {
    printf("%s\n",map.array[i].array);
  }
  printf("\n%ld\n", suma);
}

int main(void)
{
  day1();
}
