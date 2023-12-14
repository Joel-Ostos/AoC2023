#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include "../data_structures.h"
#define CASES 1000 

typedef struct tupla tupla;

arraylist(char)
arraylist(int)
struct tupla {
  char str[5];
  int num;
};
arraylist(tupla)

void insertion_sort_int(int* arr)
{
  int i = 1;
  while (i < 5) {
    int t = 0;
    while (arr[i-t] < arr[i-t-1] && i >= t) {
      int tmp = arr[i-t];
      arr[i-t] = arr[i-t-1];
      arr[i-t-1] = tmp;
      t++;
    }
    i++;
  }
}

bool compare(char* first, char* second)
{
  int jer[13] = {'A', 'K', 'Q', 'J', 'T', '9', '8', '7', '6', '5', '4', '3', '2'};
  for (int i = 0; i < 5; i++) {
    if (first[i] == second[i]) continue;
    for (int j = 0; i < 13; j++) {
      if (first[i] == jer[j] ) return false;
      if (second[i] == jer[j] ) return true;
    }
  }
  return false;
}

void sort(ArrayList_tupla* st)
{
  size_t i = 1;
  while (i < st->occupied) {
    size_t t = 0;
    //while (arr[i-t] < arr[i-t-1] && i >= t) {
    while (compare(st->array[i-t].str, st->array[i-t-1].str) == true && i >= t ) {
      tupla tmp = st->array[i-t];
      st->array[i-t] = st->array[i-t-1];
      st->array[i-t-1] = tmp;
      t++;
    }
    i++;
  }
}

int evaluate(tupla* tmp)
{
  char* arr = tmp->str;
  ArrayList_int nums = init_array_int(5);
  for (int i = 0; i < 5; i++) {
    int contador = 0;
    for (int j = 0; j < 5; j++) {
      if (arr[i] == arr[j]) contador += 1;
    }
    push_back_array_int(&nums, contador);
  }
  insertion_sort_int(nums.array);
  char trad[5];
  for (int i = 0; i < 5; i++) {
    trad[i] = nums.array[i] + '0';
  }
  //55555 14444 22333 11333 12222 11122 11111
  if (strcmp("55555",trad) == 0) {
    return 5;
  } else if (strcmp("14444",trad) == 0) {
    return 4;
  } else if (strcmp("22333",trad) == 0) {
    return 6;
  } else if (strcmp("11333",trad) == 0) {
    return 3;
  } else if (strcmp("12222",trad) == 0) {
    return 2;
  } else if (strcmp("11122",trad) == 0) {
    return 1;
  } else if (strcmp("11111",trad) == 0) {
    return 0;
  }
  return -1;
}

void day1()
{
  ArrayList_tupla diff = init_array_tupla(1);
  ArrayList_tupla one = init_array_tupla(1);
  ArrayList_tupla two = init_array_tupla(1);
  ArrayList_tupla three = init_array_tupla(1);
  ArrayList_tupla four = init_array_tupla(1);
  ArrayList_tupla five = init_array_tupla(1);
  ArrayList_tupla full = init_array_tupla(1);
  for (size_t i = 0; i < CASES; i++) {
    tupla tmp;
    scanf("%s", tmp.str);
    scanf("%d", &tmp.num);
    switch (evaluate(&tmp)) {
	case 1: {
	  push_back_array_tupla(&one, tmp);
	  break;
	};
	case 2: {
	  push_back_array_tupla(&two, tmp);
	  break;
	};
	case 3: {
	  push_back_array_tupla(&three, tmp);
	  break;
	};
	case 4: {
	  push_back_array_tupla(&four, tmp);
	  break;
	};
	case 5: {
	  push_back_array_tupla(&five, tmp);
	  break;
	};
	case 6: {
	  push_back_array_tupla(&full, tmp);
	  break;
	};
	case 0: {
	  push_back_array_tupla(&diff, tmp);
	  break;
	};
      };
  }
  clock_t start = clock();
  sort(&diff);
  sort(&one);
  sort(&two);
  sort(&three);
  sort(&four);
  sort(&five);
  sort(&full);
  long long mul = 0;
  printf("\n diff -> %zu one -> %zu two -> %zu three -> %zu full -> %zu four -> %zu five -> %zu \n", diff.occupied, one.occupied, two.occupied, three.occupied, full.occupied, four.occupied, five.occupied
);
  int index = 1;
  for (size_t i = 0; i < diff.occupied; i++) {
    mul += diff.array[i].num * (index);
    index+=1;
  }
  for (size_t i = 0; i < one.occupied; i++) {
    mul += one.array[i].num * (index);
    printf("\n%d   %s", one.array[i].num, one.array[i].str);
    index+=1;
  }
  for (size_t i = 0; i < two.occupied; i++) {
    mul += two.array[i].num * (index);
    printf("\n%d   %s", two.array[i].num, two.array[i].str);
    index+=1;
  }
  for (size_t i = 0; i < three.occupied; i++) {
    mul += three.array[i].num * (index);
    printf("\n%d   %s", three.array[i].num, three.array[i].str);
    printf("\n------------%d   %s------------------", three.array[64].num, three.array[64].str);
    index+=1;
  }
  for (size_t i = 0; i < full.occupied; i++) {
    mul += full.array[i].num * (index);
    printf("\n%d   %s", full.array[i].num, full.array[i].str);
    index+=1;
  }
  for (size_t i = 0; i < four.occupied; i++) {
    mul += four.array[i].num * (index);
    printf("\n%d   %s", four.array[i].num, four.array[i].str);
    index+=1;
  }
  for (size_t i = 0; i < five.occupied; i++) {
    mul += five.array[i].num * (index);
    printf("\n%d   %s", five.array[i].num, five.array[i].str);
    index+=1;
  }
  printf("\nResult -> %lld", mul);
  clock_t stop = clock();
  double elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
  printf("\nTime elapsed in ms: %f", elapsed);
}

int main(void)
{
  clock_t start = clock();
  day1();
  clock_t stop = clock();
  double elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
  printf("\nTime elapsed in ms: %f", elapsed);
}
