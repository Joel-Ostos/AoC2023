#include <stdio.h>
#include <stdlib.h>
#include "../data_structures.h"
#include <math.h>

arraylist(int)
arraylist(char)
arraylist(ArrayList_char)
arraylist(ArrayList_int)
extension(char)
extension(int)

#define pow(arg1,arg2) (int)pow(arg1,arg2)

#define CASES 203

void day1()
{
  ArrayList_ArrayList_char matrix = init_array_ArrayList_char(CASES);

  for (int i = 0; i < CASES; i++) {
    char* str;
    size_t size = 0; 
    getline(&str, &size, stdin);
    ArrayList_char arr = set_array_char(str, size); 
    push_back_arraymatrix_char(&matrix, &arr, true);
  }

  ArrayList_ArrayList_int matw = init_array_ArrayList_int(CASES);
  ArrayList_ArrayList_int mato = init_array_ArrayList_int(CASES);
  
  for (size_t i = 0; i < matrix.occupied; i++) {
    ArrayList_int winners = init_array_int(1);
    ArrayList_int own = init_array_int(1);

    for (size_t j = 10; j < 41; j+=3) {
      char tmp[2] = {matrix.array[i].array[j], matrix.array[i].array[j+1]};
      push_back_array_int(&winners, atoi(tmp));
    }
    for (size_t j = 42; j < 117; j+=3) {
      char tmp[2] = {matrix.array[i].array[j], matrix.array[i].array[j+1]};
      push_back_array_int(&own, atoi(tmp));
    }
    push_back_arraymatrix_int(&matw, &winners, true);
    push_back_arraymatrix_int(&mato, &own, true);
  }

  int suma = 0;
  for (size_t i = 0; i < mato.occupied; i++) {
    int pote = -1;
    for (size_t j = 0; j < mato.array[i].occupied; j++) {
      for (size_t l = 0; l < matw.array[i].occupied; l++) {
	if (mato.array[i].array[j] == matw.array[i].array[l]) pote += 1;
      }
    }
    if (pote != -1) suma += pow(2, pote);
  }

  printf("%d", suma);
}

void day2()
{
  ArrayList_ArrayList_char matrix = init_array_ArrayList_char(CASES);

  for (int i = 0; i < CASES; i++) {
    char* str;
    size_t size = 0; 
    getline(&str, &size, stdin);
    ArrayList_char arr = set_array_char(str, size); 
    push_back_arraymatrix_char(&matrix, &arr, true);
  }

  ArrayList_ArrayList_int matw = init_array_ArrayList_int(CASES);
  ArrayList_ArrayList_int mato = init_array_ArrayList_int(CASES);
  
  for (size_t i = 0; i < matrix.occupied; i++) {
    ArrayList_int winners = init_array_int(1);
    ArrayList_int own = init_array_int(1);

    for (size_t j = 10; j < 40; j+=3) {
      char tmp[2] = {matrix.array[i].array[j], matrix.array[i].array[j+1]};
      push_back_array_int(&winners, atoi(tmp));
    }
    for (size_t j = 42; j < 115; j+=3) {
      char tmp[2] = {matrix.array[i].array[j], matrix.array[i].array[j+1]};
      push_back_array_int(&own, atoi(tmp));
    }
    push_back_arraymatrix_int(&matw, &winners, true);
    push_back_arraymatrix_int(&mato, &own, true);
  }

  int cards[CASES];
  for (int i = 0; i < CASES; i++) {
    cards[i] = 1;
  }
  int matchings[CASES];

  for (size_t i = 0; i < mato.occupied; i++) {
    int cases = 0;
    for (size_t j = 0; j < mato.array[i].occupied; j++) {
      for (size_t l = 0; l < matw.array[i].occupied; l++) {
	if (mato.array[i].array[j] == matw.array[i].array[l]) cases += 1;
      }
    }
    matchings[i] = cases;
  }

  for (int i = 0; i < CASES; i++) {
    for (int j = 0; j < cards[i]; j++) {
      for (int k = i+1; k <= i+matchings[i]; k++) {
	cards[k] += 1;
      }
    }
  }
  int result = 0;
    for (int j = 0; j < CASES; j++) {
      result += cards[j];
    }
  printf("%d ", result);
}

int main(void)
{
  //day1();
  day2();
}
