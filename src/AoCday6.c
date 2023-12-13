#include <stdio.h>
#include <stdlib.h>
#include "../data_structures.h"

#define CASES 1

typedef struct tupla tupla;
struct tupla {
  long long ff;
  long long ss;
};

arraylist(tupla)

void day1()
{
  ArrayList_tupla lista = init_array_tupla(CASES);

  for (int i = 0; i < CASES; i++) {
    tupla tmp;
    scanf("%d", &tmp.ff);
    push_back_array_tupla(&lista, tmp);
  }

  for (int i = 0; i < lista.occupied; i++) {
    scanf("%d", &lista.array[i].ss);
  }

  int mul = 1;
  for (int i = 0; i < lista.occupied; i++) {
    tupla res;
    for (int j = 1; j <= lista.array[i].ff; j++) {
      int time_res = lista.array[i].ff - j;
      if (time_res * j > lista.array[i].ss) {
	res.ff = j;
	break;
      } 
    }

    for (int j = lista.array[i].ff; j > 0; j--) {
      int time_res = lista.array[i].ff - j;
      if (time_res * j > lista.array[i].ss ) {
	res.ss = j;
	break;
      } 
    }
    printf("\nfirst = %d \t second = %d result = %d", res.ff,res.ss,(res.ss - res.ff)+1);
    mul *= (res.ss - res.ff)+1;
  }
  printf("\n%d", mul);
}

void day2()
{
  ArrayList_tupla lista = init_array_tupla(CASES);

  for (int i = 0; i < CASES; i++) {
    tupla tmp;
    scanf("%lld", &tmp.ff);
    push_back_array_tupla(&lista, tmp);
  }

  for (int i = 0; i < lista.occupied; i++) {
    scanf("%lld", &lista.array[i].ss);
  }

  long long mul = 1;
  for (long long i = 0; i < lista.occupied; i++) {
    tupla res;
    for (long long  j = 1; j <= lista.array[i].ff; j++) {
      long long time_res = lista.array[i].ff - j;
      if (time_res * j > lista.array[i].ss) {
	res.ff = j;
	break;
      } 
    }

    for (long long j = lista.array[i].ff; j > 0; j--) {
      long long time_res = lista.array[i].ff - j;
      if (time_res * j > lista.array[i].ss ) {
	res.ss = j;
	break;
      } 
    }
    printf("\nfirst = %d \t second = %d result = %d", res.ff,res.ss,(res.ss - res.ff)+1);
    mul *= (res.ss - res.ff)+1;
  }
  printf("\n%lld", mul);
}
int main(void)
{
  day1();
  //day2();
}
