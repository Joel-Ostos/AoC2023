#include <stdio.h>
#include <stdlib.h>
#include "../data_structures.h"
#define CASES 100

arraylist(char)
arraylist(ArrayList_char)
arraylist(long)
extension(char)

bool is__row(ArrayList_ArrayList_char map, size_t index)
{
  for (int i = index, j = index+1; i >= 0 && (size_t) j < map.occupied; i--, j++){
    char* str1 = map.array[i].array;
    str1[map.array[i].occupied] = '\0';
    char* str2 = map.array[j].array;
    str2[map.array[j].occupied] = '\0';
    if (strcmp(str1, str2) != 0) {
      return false;
    }
  }
  return true;
}

void day1() 
{
    long r_columns = 0, r_rows = 0;
    for (int i = 0; i < CASES; i++) {
        char* str = NULL;
	size_t size = 0;
	ArrayList_ArrayList_char map1 = init_array_ArrayList_char(10);
	getline(&str,&size,stdin);
	while(str[0] != '\n'){
	  ArrayList_char tmp = set_array_char(str,strlen(str)+1);
	  push_back_arraymatrix_char(&map1,&tmp,true);
	  free(str);
	  str=NULL;
	  getline(&str,&size,stdin);
	}
	bool is_row = false;
	long index_row = -1, index_column = -1, max_index_r = -1,max_index_c = -1;

	for (size_t j = 0; j < (map1.occupied)-1; j++) {
	  index_row += 1;
	  if (strcmp(map1.array[j].array, map1.array[j+1].array) == 0) { 
	    if ((is__row(map1,index_row) && index_row > max_index_r)) {
	      is_row = true;
	      max_index_r = index_row;
	    }
	  }
	}

	ArrayList_ArrayList_char map1_inverse = init_array_ArrayList_char(1);

	if (!is_row) {
	  for (size_t j = 0; j < (map1.array[0].occupied)-2; j++) {
	    ArrayList_char current = init_array_char(map1.occupied);
	    for (size_t k = 0; k < (map1.occupied); k++) {
	      push_back_array_char(&current, map1.array[k].array[j]);
	    }            
	    push_back_arraymatrix_char(&map1_inverse,&current, true);
	    deinit_array_char(&current);
	  }

	  for (size_t j = 0; j < (map1_inverse.occupied)-1; j++) {
	    index_column += 1;
	    char* str1 = map1_inverse.array[j].array;
	    str1[map1_inverse.array[j].occupied] = '\0';
	    char* str2 = map1_inverse.array[j+1].array;
	    str2[map1_inverse.array[j+1].occupied] = '\0';
	    if (strcmp(str1, str2) == 0) { 
	      if ((is__row(map1_inverse, index_column) && index_column > max_index_c)) {
		max_index_c = index_column;
	      }
	    }
	  }
	}

        long num_r = (100)*(max_index_r+1), num_c = max_index_c+1;

        if (is_row) {
	  r_rows += num_r;
	} else {
	  r_columns += num_c;
	}      
	free(str);
	str=NULL;
	deinit_array_ArrayList_char(&map1);
	deinit_array_ArrayList_char(&map1_inverse);
    }
    printf("Result -> %ld", r_columns+r_rows);
}

int main(void)
{
    day1();
}
