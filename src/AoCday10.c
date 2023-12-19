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
  int cont = 0;
  for (size_t i = 0; i < map.occupied; i++) {
    for (size_t j = 0; j < map.array[i].occupied; j++) {
      if (map.array[i].array[j] != '.' && parent[i][j].ff != -1) {
	cont+=1;
      }
    }
  }
  printf("\n%d", cont/2);
}

int main(void)
{
  day1();
}
