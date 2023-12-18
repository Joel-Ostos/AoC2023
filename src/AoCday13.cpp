#include <iostream>
#include <bits/stdc++.h>

#define CASES 100
using namespace std;

bool is__row(vector<vector<char>> map, size_t index)
{
  for (int i = index, j = index+1; i >= 0 && (size_t) j < map.size(); i--, j++){
    if (strcmp(map[i], map[j]) != 0) {
      //printf("\nDiferencia en %d %d: \n%s\n%s", i,j,map.array[i].array, map.array[j].array);
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
	vector<vector<char>> map1 = init_array_ArrayList_char(10);
	getline(&str,&size,stdin);
	while(str[0] != '\n'){
	  vector<char> tmp = str;
 	  map1.push_back(tmp);
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

	vector<vector<char>> map1_inverse;

	if (!is_row) {
	  for (size_t j = 0; j < (map1.array[0].occupied)-2; j++) {
	    vector<char> current;
	    for (size_t k = 0; k < (map1.occupied); k++) {
	      current.push_back(map1[k][j]);
	    }            
	    map1_inverse.push_back(current, true);
	  }

	  for (size_t j = 0; j < (map1_inverse.occupied)-1; j++) {
	    index_column += 1;
	    if (strcmp(map1_inverse.array[j].array, map1_inverse.array[j+1].array) == 0) { 
	      if ((is__row(map1_inverse, index_column) && index_column > max_index_c)) {
		max_index_c = index_column;
	      }
	    }
	  }
	}
        long num_r = (100)*(max_index_r+1), num_c = max_index_c+1;
	//printf("\nCase -> %d \t%ld\t%ld\n", i, 100*(max_index_r+1), max_index_c+1);
        if (is_row) {
	  r_rows += num_r;
	} else {
	  r_columns += num_c;
	}      
    }
    printf("\nResult -> %ld, %ld, %ld", r_columns , r_rows, r_columns+r_rows);
}

int main(void)
{
    day1();
}
