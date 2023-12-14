#include <stdio.h>
#include <stdlib.h>
#include "../data_structures.h"

#define ROWS 140
#define COLS 140

arraylist(char)
arraylist(int)
arraylist(long)
arraylist(ArrayList_char)
extension(char)


typedef struct tupla {
  int ff;
  int ss;
} tupla;

queue(tupla)

int movs_S1[4] = {1,-1,0,0}, movs_S2[4] = {0,0,1,-1};
void day1()
{
  ArrayList_ArrayList_char map = init_array_ArrayList_char(ROWS);
  tupla parent[ROWS][COLS];
  tupla A = {.ff=0,.ss=0};
  for (int i = 0; i < ROWS; i++) {
    char tmp[COLS];
    scanf("%s", tmp);
    ArrayList_char str = set_array_char(tmp, COLS);
    push_back_arraymatrix_char(&map, &str, true);
  }
  for (size_t i = 0; i < map.occupied; i++) {
    for (size_t j = 0; j < map.array[i].occupied; j++) {
      if (map.array[i].array[j] == 'S') {
	A.ff = i;
	A.ss = j;
	parent[A.ff][A.ss].ff = -2;
	parent[A.ff][A.ss].ss = -2;
      } else  {
	parent[i][j].ff = -1;
	parent[i][j].ss = -1;
      }
    }
  }

  Queue_tupla Q = init_Queue_tupla();
  Queue_tupla_push(&Q, A);
  //printf("%d %d", A.ff, A.ss);
  
  while (!Queue_tupla_empty(&Q)) {
    tupla nx = Queue_tupla_pop(&Q);
    if (map.array[nx.ff].array[nx.ss] == 'S') {
      for (int i = 0; i < 4; i++) {
	tupla new;
	new.ff = nx.ff+movs_S1[i];
	new.ss = nx.ss+movs_S2[i];
	if (new.ff > ROWS || new.ss > COLS || new.ff < 0 || new.ss < 0) continue;
	if (new.ff < ROWS && new.ss < COLS && new.ff >= 0 && new.ss >= 0 && map.array[new.ff].array[new.ss] == '.') continue;
	if (parent[new.ff][new.ss].ff == -1 && parent[new.ff][new.ss].ss == -1) {
	  parent[new.ff][new.ss] = nx; 
	  Queue_tupla_push(&Q, new);
	}
      }
    }
    else if (map.array[nx.ff].array[nx.ss] == '|') {
      int posible[2] = {1,-1};
      for (int i = 0; i < 2; i++) {
	tupla new;
	new.ff = nx.ff+posible[i];
	new.ss = nx.ss;
	if (new.ff > ROWS || new.ss > COLS || new.ff < 0 || new.ss < 0) continue;
	if (new.ff < ROWS && new.ss < COLS && new.ff >= 0 && new.ss >= 0 && map.array[new.ff].array[new.ss] == '.') continue;
	if (parent[new.ff][new.ss].ff == -1 && parent[new.ff][new.ss].ss == -1) {
	  parent[new.ff][new.ss] = nx; 
	  Queue_tupla_push(&Q, new);
	}
      }
    }
    else if (map.array[nx.ff].array[nx.ss] == '-') {
      int posible[2] = {1,-1};
      for (int i = 0; i < 2; i++) {
	tupla new;
	new.ff = nx.ff;
	new.ss = nx.ss+posible[i];
	if (new.ff > ROWS || new.ss > COLS || new.ff < 0 || new.ss < 0) continue;
	if (new.ff < ROWS && new.ss < COLS && new.ff >= 0 && new.ss >= 0 && map.array[new.ff].array[new.ss] == '.') continue;
	if (parent[new.ff][new.ss].ff == -1 && parent[new.ff][new.ss].ss == -1) {
	  parent[new.ff][new.ss] = nx; 
	  Queue_tupla_push(&Q, new);
	}
      }
    }
    else if (map.array[nx.ff].array[nx.ss] == 'L') {
      int posible1[2] = {0,-1}, posible2[2] = {1,0};
      for (int i = 0; i < 2; i++) {
	tupla new;
	new.ff = nx.ff+posible1[i];
	new.ss = nx.ss+posible2[i];
	if (new.ff > ROWS || new.ss > COLS || new.ff < 0 || new.ss < 0) continue;
	if (new.ff < ROWS && new.ss < COLS && new.ff >= 0 && new.ss >= 0 && map.array[new.ff].array[new.ss] == '.') continue;
	if (parent[new.ff][new.ss].ff == -1 && parent[new.ff][new.ss].ss == -1) {
	  parent[new.ff][new.ss] = nx; 
	  Queue_tupla_push(&Q, new);
	}
      }
    }
    else if (map.array[nx.ff].array[nx.ss] == 'J') {
      int posible1[2] = {0,-1}, posible2[2] = {-1,0};
      for (int i = 0; i < 2; i++) {
	tupla new;
	new.ff = nx.ff+posible1[i];
	new.ss = nx.ss+posible2[i];
	//printf("\nJ -> %d %d\n", new.ff,new.ss);
	if (new.ff > ROWS || new.ss > COLS || new.ff < 0 || new.ss < 0) continue;
	if (new.ff < ROWS && new.ss < COLS && new.ff >= 0 && new.ss >= 0 && map.array[new.ff].array[new.ss] == '.') continue;
	if (parent[new.ff][new.ss].ff == -1 && parent[new.ff][new.ss].ss == -1) {
	  parent[new.ff][new.ss] = nx; 
	  Queue_tupla_push(&Q, new);
	}
      }
    }
    else if (map.array[nx.ff].array[nx.ss] == '7') {
      int posible1[2] = {0,1}, posible2[2] = {-1,0};
      for (int i = 0; i < 2; i++) {
	tupla new;
	new.ff = nx.ff+posible1[i];
	new.ss = nx.ss+posible2[i];
	if (new.ff >= ROWS || new.ss >= COLS || new.ff < 0 || new.ss < 0) continue;
	if (new.ff < ROWS && new.ss < COLS && new.ff >= 0 && new.ss >= 0 && map.array[new.ff].array[new.ss] == '.') continue;
	if (parent[new.ff][new.ss].ff == -1 && parent[new.ff][new.ss].ss == -1) {
	  parent[new.ff][new.ss] = nx; 
	  Queue_tupla_push(&Q, new);
	}
      }
    }
    else if (map.array[nx.ff].array[nx.ss] == 'F') {
      int posible1[2] = {0,1}, posible2[2] = {1,0};
      for (int i = 0; i < 2; i++) {
	tupla new;
	new.ff = nx.ff+posible1[i];
	new.ss = nx.ss+posible2[i];
	//printf("\nF -> %d %d\n", new.ff,new.ss);
	if (new.ff > ROWS || new.ss > COLS || new.ff < 0 || new.ss < 0) continue;
	if (new.ff < ROWS && new.ss < COLS && new.ff >= 0 && new.ss >= 0 && map.array[new.ff].array[new.ss] == '.') continue;
	if (parent[new.ff][new.ss].ff == -1 && parent[new.ff][new.ss].ss == -1) {
	  parent[new.ff][new.ss] = nx; 
	  Queue_tupla_push(&Q, new);
	}
      }
    }
    else if (map.array[nx.ff].array[nx.ss] == '.') continue;
  }
  
  //printf("\n%d %d -> %c", parent[2][4].ff,parent[2][4].ss, map.array[2].array[4]);
  //printf("\n%d %d -> %c", parent[2][3].ff,parent[2][3].ss, map.array[2].array[3]);
  //printf("\n%d %d -> %c", parent[0][2].ff,parent[0][2].ss, map.array[0].array[2]);
  //printf("\n%d %d -> %c", parent[0][3].ff,parent[0][3].ss, map.array[0].array[3]);
  ArrayList_long dist = init_array_long(300);
  for (size_t i = 0; i < map.occupied; i++) {
    for (size_t j = 0; j < map.array[i].occupied; j++) {
      if (map.array[i].array[j] != '.' && parent[i][j].ff != -1) {
	tupla actual; actual.ff = i; actual.ss = j;
	long long cont = 0;
	while (actual.ff != A.ff || actual.ss != A.ss) {
	  if (parent[actual.ff][actual.ss].ff == -2 && parent[actual.ff][actual.ss].ss == -2){
	    break;
	  }
	  actual = parent[actual.ff][actual.ss];
	  cont += 1;
	}
	push_back_array_long(&dist, cont);
      }
    }
  }
  long long max = 0;
  printf("\n%zu \n", dist.occupied);
  for (size_t i = 0; i < dist.occupied; i++) {
    if (dist.array[i] > max) max = dist.array[i];
  }
  printf("\n%lld", max);
}

int main(void)
{
  day1();
}
