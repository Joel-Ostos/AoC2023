#include <stdio.h>
#include <stdlib.h>
#include "../data_structures.h"

#define ROWS 13
#define COLS 13

arraylist(char)
arraylist(ArrayList_char)
extension(char)

typedef struct tupla tupla;
struct tupla {
  int ff;
  int ss;
  int tt;
  char fo;
};

//int comb_s[4] = {-1,1,0,0}, comb[4] = {0,0,-1,1};
int comb[9] = {1, 2, 3, -1, -2, -3, 0, 0, 0},  comb_s[9] = {0, 0, 0, 0, 0, 0, 1, 2, 3};
queue(tupla)

void bfs()
{
  ArrayList_ArrayList_char map = init_array_ArrayList_char(ROWS); 
  tupla A = {0, 0, -1,'C'}, B = {ROWS-1, COLS-1, -1,'R'};

  for (int i = 0; i < ROWS; i++) {
    char tmp[COLS];
    scanf("%s", tmp);
    ArrayList_char str = set_array_char(tmp, strlen(tmp));
    push_back_arraymatrix_char(&map,&str, true);
  }

  A.tt = map.array[A.ff].array[A.ss] - '0';
  B.tt = map.array[B.ff].array[B.ss] - '0';

  Queue_tupla Q = init_Queue_tupla();

  Queue_tupla_push(&Q, A);
  
  while (B.tt < 10) {
    tupla actual = Queue_tupla_pop(&Q);
    for (int i = 0; i < 9; i++) {
      tupla new;
      if (actual.fo == 'A' || actual.fo == 'C') {
	if (i >= 0 && i < 6) {
	  new.ff = actual.ff + comb[i]; new.ss = actual.ss + comb_s[i];
	  if (new.ff >= COLS || new.ss >= ROWS || new.ff < 0 || new.ss < 0) continue;
	  new.fo = 'B';
	  if (comb[i] == 1) {
	    new.tt = map.array[new.ff].array[new.ss] - '0';
	    new.tt += actual.tt;
	  } else if  (comb[i] == 2) {
	    new.tt = map.array[new.ff].array[new.ss] - '0';
	    new.tt += map.array[new.ff-1].array[new.ss] - '0';
	    new.tt += actual.tt;
	  } else if (comb[i] == 3) {
	    new.tt = map.array[new.ff].array[new.ss] - '0';
	    new.tt += map.array[new.ff-1].array[new.ss] - '0';
	    new.tt += map.array[new.ff-2].array[new.ss] - '0';
	    new.tt += actual.tt;
	  } else if (comb[i] == -1) {
	    new.tt = map.array[new.ff].array[new.ss] - '0';
	    new.tt += actual.tt;
	  } else if  (comb[i] == -2) {
	    new.tt = map.array[new.ff].array[new.ss] - '0';
	    new.tt += map.array[new.ff+1].array[new.ss] - '0';
	    new.tt += actual.tt;
	  } else if (comb[i] == -3) {
	    new.tt = map.array[new.ff].array[new.ss] - '0';
	    new.tt = actual.tt;
	    new.tt += map.array[new.ff+1].array[new.ss] - '0';
	    new.tt += map.array[new.ff+2].array[new.ss] - '0';
	  }
	  Queue_tupla_push(&Q, new);
	}
      }
      if (actual.fo == 'B' || actual.fo == 'C') {
	if (i >= 6 && i < 9) {
	  new.ff = actual.ff + comb[i]; new.ss = actual.ss + comb_s[i];
	  if (new.ff >= COLS || new.ss >= ROWS || new.ff < 0 || new.ss < 0) continue;
	  new.fo = 'A';
	  if (comb_s[i] == 1) {
	    new.tt = map.array[new.ff].array[new.ss] - '0';
	    new.tt += actual.tt;
	  } else if  (comb_s[i] == 2) {
	    new.tt = map.array[new.ff].array[new.ss] - '0';
	    new.tt += map.array[new.ff].array[new.ss-1] - '0';
	    new.tt += actual.tt;
	  } else if (comb_s[i] == 3) {
	    new.tt = map.array[new.ff].array[new.ss] - '0';
	    new.tt += map.array[new.ff].array[new.ss-1] - '0';
	    new.tt += map.array[new.ff].array[new.ss-2] - '0';
	    new.tt += actual.tt;
	  }
	  Queue_tupla_push(&Q, new);
	}
      }
    }
  }
  printf("\n%d\n", B.tt);

}

int main(void)
{
  bfs();
}
