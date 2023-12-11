#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../data_structures.h"

#define CASES 100

arraylist(char)
arraylist(ArrayList_char)
extension(char)

void day1()
{
  int blue = 14, green = 13, red = 12;
  ArrayList_ArrayList_char matrix = init_array_ArrayList_char(CASES);

  for (int i = 0; i < CASES; i++) {
    char* str;
    size_t size = 0;
    if (getline(&str, &size, stdin) == -1) exit(1);
    ArrayList_char aaa = set_array_char(str,size);
    push_back_arraymatrix_char(&matrix, &aaa, true);
  }

  int suma = 0;
  for (size_t i = 0; i < matrix.occupied; i++) {
    bool casel = true;
    for (size_t j = 0; j < matrix.array[i].occupied; j++) {
      if (matrix.array[i].array[j] == 'b') {
	char tmp[2] = {matrix.array[i].array[j-3], matrix.array[i].array[j-2]};
	if (atoi(tmp) > blue) {
	  casel = false;
	}
      }
      else if (matrix.array[i].array[j] == 'g' && matrix.array[i].array[j+1] == 'r') {
	char tmp[2] = {matrix.array[i].array[j-3], matrix.array[i].array[j-2]};
	if (atoi(tmp) > green) {
	  casel = false;
	}
      } else if (matrix.array[i].array[j] == 'r' && matrix.array[i].array[j+1] == 'e' && matrix.array[i].array[j+2] == 'd') {
	char tmp[2] = {matrix.array[i].array[j-3], matrix.array[i].array[j-2]};
	if (atoi(tmp) > red) {
	  casel = false;
	}
      }
    }
    if (casel) {
      suma += (i+1);
    }
  }
  printf("%d", suma);
}

void day2()
{
  int blue = 0, green = 0, red = 0;
  ArrayList_ArrayList_char matrix = init_array_ArrayList_char(CASES);

  for (int i = 0; i < CASES; i++) {
    char* str;
    size_t size = 0;
    if (getline(&str, &size, stdin) == -1) exit(1);
    ArrayList_char aaa = set_array_char(str,size);
    push_back_arraymatrix_char(&matrix, &aaa, true);
  }

  int suma = 0;
  for (size_t i = 0; i < matrix.occupied; i++) {
    int pot = 0;
    blue = 0;
    red = 0;
    green = 0;
    for (size_t j = 0; j < matrix.array[i].occupied; j++) {
      if (matrix.array[i].array[j] == 'b') {
	char tmp[2] = {matrix.array[i].array[j-3], matrix.array[i].array[j-2]};
	if (atoi(tmp) > blue) {
	  blue = atoi(tmp);
	}
      }
      else if (matrix.array[i].array[j] == 'g') {
	char tmp[2] = {matrix.array[i].array[j-3], matrix.array[i].array[j-2]};
	if (atoi(tmp) > green) {
	  green = atoi(tmp);
	}
      } else if (matrix.array[i].array[j] == 'r' && matrix.array[i].array[j+1] == 'e' && matrix.array[i].array[j+2] == 'd') {
	char tmp[2] = {matrix.array[i].array[j-3], matrix.array[i].array[j-2]};
	if (atoi(tmp) > red) {
	  red = atoi(tmp);
	}
      }
    }
    pot = blue * green * red;
    suma += pot;
  }
  printf("%d", suma);
}

int main(void)
{
  //day1();
  //day2();
}
