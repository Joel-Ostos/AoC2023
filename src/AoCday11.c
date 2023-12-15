#include <stdio.h>
#include <stdlib.h>
#include "../data_structures.h"

#define ROWS 148
#define COLS 147

arraylist(char)
arraylist(int)
arraylist(long)
arraylist(ArrayList_char)
extension(char)


typedef struct tupla {
  int ff;
  int ss;
} tupla;

arraylist(tupla)
queue(tupla)

int movs_S1[4] = {1,-1,0,0}, movs_S2[4] = {0,0,1,-1};
void day1()
{
  ArrayList_ArrayList_char map = init_array_ArrayList_char(ROWS);
  ArrayList_tupla set_n = init_array_tupla(10);
  tupla parent[ROWS][COLS];
  long result = 0;

  for (int i = 0; i < ROWS; i++) {
    char tmp[COLS];
    scanf("%s", tmp);
    ArrayList_char str = set_array_char(tmp, COLS);
    push_back_arraymatrix_char(&map, &str, true);
  }

  for (size_t i = 0; i < map.occupied; i++) {
    for (size_t j = 0; j < map.array[i].occupied; j++) {
      if (map.array[i].array[j] == '#') {
	tupla tmp = {i,j};
	push_back_array_tupla(&set_n, tmp);
	parent[i][j].ff = -1;
	parent[i][j].ss = -1;
      } else {
	parent[i][j].ff = -1;
	parent[i][j].ss = -1;
      }
    }
  }

  for (size_t i = 0; i < set_n.occupied; i++) {
    parent[set_n.array[i].ff][set_n.array[i].ss].ff = -2;
    parent[set_n.array[i].ff][set_n.array[i].ss].ss = -2;
    Queue_tupla Q = init_Queue_tupla();
    Queue_tupla_push(&Q, set_n.array[i]);
    while (!Queue_tupla_empty(&Q)) {
      tupla nx = Queue_tupla_pop(&Q);
      for (int i = 0; i < 4; i++) {
	tupla new = {nx.ff+movs_S1[i], nx.ss+movs_S2[i]};
	if (new.ff >= ROWS || new.ss >= COLS || new.ff < 0 || new.ss < 0) continue;
	if (parent[new.ff][new.ss].ff == -1 && parent[new.ff][new.ss].ss == -1) {
	  parent[new.ff][new.ss] = nx; 
	  Queue_tupla_push(&Q, new);
	}
      }
    }
    for (size_t j = 0; j < set_n.occupied; j++) {
      if (j > i) {
	tupla actual = set_n.array[j];
	long sum = 0;
	while (actual.ff != -2 && actual.ss != -2) {
	  if (actual.ff > -1){
	    actual = parent[actual.ff][actual.ss];
	    sum+=1;
	  }
	}
	sum -=1;
	result += sum;
	printf("Desde Galaxia -> %zu, hasta -> %zu dist -> %ld -> %ld\n", i+1, j+1, sum, result);
      }
    }
    for (size_t k = 0; k < map.occupied; k++) {
      for (size_t l = 0; l < map.array[k].occupied; l++) {
	parent[k][l].ff = -1;
	parent[k][l].ss = -1;
      }
    }
  }
  printf("Resultado -> %ld", result);
}

int main(void)
{
  day1();
}
