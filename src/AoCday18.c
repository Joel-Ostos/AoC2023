#include <stdio.h>
#include <stdlib.h>
#include "../data_structures.h"

#define CASES 20

arraylist(char)
arraylist(ArrayList_char)
extension(char)

typedef struct tupla tupla;

struct tupla {
  int ff;
  int ss;
};

void day1()
{
  ArrayList_ArrayList_char map = init_array_ArrayList_char(10);
  tupla ptr = {0,0};
  for (int i = 0; i < CASES; i++) {
    char dir; int num;
    scanf("%c", &dir);
    scanf("%d", &num);
    if (dir == 'U') {
      for (size_t i = 0; i < num; i++) {
      }
    } else if (dir == 'D') {
    } else if (dir == 'L') {
    } else if (dir == 'R') {
    }
  }
}

int main(void)
{
  day1();
}
