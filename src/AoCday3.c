#include <stdio.h>
#include <stdlib.h>
#include "../data_structures.h"
#define TEST 140

arraylist(char)
arraylist(ArrayList_char)
extension(char)


bool analize(ArrayList_ArrayList_char* str, int i, int j, int type)
{
  if (type == 1) {
    for (int k = i-1; k < i+2; k++) {
      for (int l = j-1; l < j+2; l++) {
	if (k >= 0 && k < 140 && l >= 0 && l < 140){
	  if (str->array[k].array[l] != '.' && (str->array[k].array[l] - 0 < 48 || str->array[k].array[l] - 0 > 57)) return true;
	}
      }
    }
    return false;
  } else if (type == 2) {
    for (int k = i-1; k < i+2; k++) {
      if (k >= 0 && k < 140 && j-2 >= 0 && j-2 < 140){
	if (str->array[k].array[j-2] != '.' && (str->array[k].array[j-2] - 0 < 48 || str->array[k].array[j-2] - 0 > 57)) return true;
      }
      for (int l = j-1; l < j+2; l++) {
	if (k >= 0 && k < 140 && l >= 0 && l < 140){
	  if (str->array[k].array[l] != '.' && (str->array[k].array[l] - 0 < 48 || str->array[k].array[l] - 0 > 57)) return true;
	}
      }
    }
  } else if (type == 3) {
    for (int k = i-1; k < i+2; k++) {
      if (k >= 0 && k < 140){
	if (j-2 >= 0 && j-2 < 140){
	  if (str->array[k].array[j-2] != '.' && (str->array[k].array[j-2] - 0 < 48 || str->array[k].array[j-2] - 0 > 57)) return true;
	}
	if(j+2 >= 0 && j+2 < 140) {
	  if (str->array[k].array[j+2] != '.' && (str->array[k].array[j+2] - 0 < 48 || str->array[k].array[j+2] - 0 > 57)) return true;
	}
      }
      for (int l = j-1; l < j+2; l++) {
	if (k >= 0 && k < 140 && l >= 0 && l < 140){
	  if (str->array[k].array[l] != '.' && (str->array[k].array[l] - 0 < 48 || str->array[k].array[l] - 0 > 57)) return true;
	}
      }
    }
  }
  return false;
}

void day1()
{
  int sum = 0;
  int parent[140][140];
  for (int i = 0; i < 140; i++) {
    for (int j = 0; j < 140; j++) {
      parent[i][j] = -1;
    }
  }
  ArrayList_ArrayList_char str = init_array_ArrayList_char(140);
  for (int i = 0; i < 140; i++) {
    char input[140];
    scanf("%s", input);
    ArrayList_char arr = set_array_char(input,140);
    push_back_arraymatrix_char(&str, &arr, 1) ;
  }

  for (int i = 0; i < 140; i++) {
    for (int j = 0; j < 140; j++) {
      if (parent[i][j] != -1) continue;
      if (str.array[i].array[j] == '.') continue;
      if (str.array[i].array[j] - 0 >= 48
	  && str.array[i].array[j] - 0 <= 57
	  && (str.array[i].array[j-1] - 0 < 48 || str.array[i].array[j-1] - 0 > 57) 
	  && (str.array[i].array[j+1] - 0 < 48 || str.array[i].array[j+1] - 0 > 57)) {
	if (analize(&str, i,j,1)) sum += (str.array[i].array[j]-0)-48;
	parent[i][j] = 1;
      } else if (str.array[i].array[j] - 0 >= 48
	  && str.array[i].array[j] - 0 <= 57
	  && str.array[i].array[j-1] - 0 >= 48 
	  && str.array[i].array[j-1] - 0 <= 57 
	  && (str.array[i].array[j+1] - 0 < 48 || str.array[i].array[j+1] - 0 > 57)) {
	ArrayList_char tmp = init_array_char(2);
	push_back_array_char(&tmp, str.array[i].array[j-1]);
	push_back_array_char(&tmp, str.array[i].array[j]);
	if (analize(&str, i,j,2)) sum += atoi(tmp.array);
	deinit_array_char(&tmp);
	parent[i][j] = 1;
	parent[i][j-1] = 1;
      } else if (str.array[i].array[j] - 0 >= 48
	  && str.array[i].array[j] - 0 <= 57
	  && str.array[i].array[j-1] - 0 >= 48 
	  && str.array[i].array[j-1] - 0 <= 57 
	  && str.array[i].array[j+1] - 0 >= 48
	  && str.array[i].array[j+1] - 0 <= 57
	  && parent[i][j-1] == -1) {
	parent[i][j] = 1;
	parent[i][j-1] = 1;
	parent[i][j+1] = 1;
	ArrayList_char tmp = init_array_char(3);
	push_back_array_char(&tmp, str.array[i].array[j-1]);
	push_back_array_char(&tmp, str.array[i].array[j]);
	push_back_array_char(&tmp, str.array[i].array[j+1]);
	if (analize(&str, i,j,3)) sum += atoi(tmp.array);
	deinit_array_char(&tmp);
      }
    }
  }
  printf("\n%d", sum);
  deinit_array_ArrayList_char(&str);
}

void day2()
{
  ArrayList_ArrayList_char str = init_array_ArrayList_char(TEST);
  int parents[TEST][TEST];
  size_t suma = 0;
  for (int i = 0; i < TEST; i++) {
    for (int k = 0; k < TEST; k++) {
      parents[i][k] = -1;
    }
  }
  for (int i = 0; i < TEST; i++) {
    char subs[TEST];
    scanf("%s", subs);
    ArrayList_char sub = set_array_char(subs, TEST);
    push_back_arraymatrix_char(&str, &sub, true);
  }

  for (int i = 0; i < TEST; i++) {
    for (int j = 0; j < TEST; j++) {
      if (str.array[i].array[j] != '*') continue;
      int cont = 0;
      long long mult1 = -1, mult2 = -1;

      for (int k = i-1; k < i+2; k++) {
	for (int l = j-1; l < j+2; l++) {
	  if (k >= 0 && k < TEST && l >= 0 && l < TEST) {
	    if (str.array[k].array[l] >= 48 && str.array[k].array[l] <= 57) {
	      if (l-2 >= 0 && l-2 < TEST && str.array[k].array[l-2] >= 48 && str.array[k].array[l-2] <= 57
		  && l-1 >= 0 && l-1 < TEST && str.array[k].array[l-1] >= 48 && str.array[k].array[l-1] <= 57
		  && parents[k][l] == -1 && parents[k][l-2] == -1 && parents[k][l-1] == -1) {
		char tmp[3] = {str.array[k].array[l-2], str.array[k].array[l-1], str.array[k].array[l]};
		tmp[3]='\0';
		cont++;
		if (cont==1) mult1 = atoi(tmp);else if(cont==2) mult2 = atoi(tmp);
		parents[k][l] = 1 ;
		parents[k][l-2] = 1;
		parents[k][l-1] = 1;
	      } else if (l-1 >= 0 && l-1 < TEST && str.array[k].array[l-1] >= 48 && str.array[k].array[l-1] <= 57
			 && l+1 >= 0 && l+1 < TEST && (str.array[k].array[l+1] < 48 || str.array[k].array[l+1] > 57)
			 && parents[k][l] == -1 && parents[k][l-1] == -1) {

		char tmp[2] = {str.array[k].array[l-1], str.array[k].array[l]};
		tmp[2]='\0';
		cont++;
		if (cont==1) mult1 = atoi(tmp);else if(cont==2) mult2 = atoi(tmp);
		parents[k][l] = 1 ;
		parents[k][l-1] = 1;
		
	      } else if (l+2 >= 0 && l+2 < TEST && str.array[k].array[l+2] >= 48 && str.array[k].array[l+2] <= 57
			 && l+1 >= 0 && l+1 < TEST && str.array[k].array[l+1] >= 48 && str.array[k].array[l+1] <= 57
			 && parents[k][l] == -1 && parents[k][l+2] == -1 && parents[k][l+1] == -1) {
		char tmp[3] = { str.array[k].array[l], str.array[k].array[l+1], str.array[k].array[l+2]};
		tmp[3]='\0';
		cont++;
		if (cont==1) mult1 = atoi(tmp);else if(cont==2) mult2 = atoi(tmp);
		parents[k][l] = 1 ;
		parents[k][l+1] = 1;
		parents[k][l+2] = 1;

	      } else if (l+1 >= 0 && l+1 < TEST && str.array[k].array[l+1] >= 48 && str.array[k].array[l+1] <= 57
			 && l-1 >= 0 && l-1 < TEST && (str.array[k].array[l-1] < 48 || str.array[k].array[l-1] > 57)
			 && parents[k][l] == -1 && parents[k][l+1] == -1) {
		char tmp[2] = {str.array[k].array[l], str.array[k].array[l+1]};
		tmp[2]='\0';
		cont++;
		if (cont==1) mult1 = atoi(tmp); else if(cont==2) mult2 = atoi(tmp);
		parents[k][l] = 1 ;
		parents[k][l+1] = 1;
		
	      } else if (l+1 >= 0 && l+1 < TEST && str.array[k].array[l+1] >= 48 && str.array[k].array[l+1] <= 57
			 && l-1 >= 0 && l-1 < TEST && str.array[k].array[l-1] >= 48 && str.array[k].array[l-1] <= 57
			 && l >= 0 && l < TEST && str.array[k].array[l] >= 48 && str.array[k].array[l] <= 57
			 && parents[k][l] == -1 
			 && parents[k][l-1] == -1
			 && parents[k][l+1] == -1) {
		char tmp[3] = { str.array[k].array[l-1], str.array[k].array[l], str.array[k].array[l+1]};
		tmp[3]='\0';
		cont++;
		if (cont==1) mult1 = atoi(tmp);else if(cont==2) mult2 = atoi(tmp);
		parents[k][l] = 1 ;
		parents[k][l-1] = 1;
		parents[k][l+1] = 1;
	      } else if (l+1 >= 0 && l+1 < TEST && (str.array[k].array[l+1] < 48 || str.array[k].array[l+1] > 57)
			 && l-1 >= 0 && l-1 < TEST && (str.array[k].array[l-1] < 48 || str.array[k].array[l-1] > 57)
			 && l >= 0 && l < TEST && str.array[k].array[l] >= 48 && str.array[k].array[l-1] <= 57
			 && parents[k][l] == -1) {
		cont++;
		if (cont==1) mult1 =(str.array[k].array[l]-0)-48;else if(cont==2) mult2 = (str.array[k].array[l]-0)-48;
		parents[k][l] = 1 ;
	      }
	    }
	  }
	}
      }
      if (cont == 2) {
	printf("\n %lld %lld", mult1, mult2);
	suma += mult1*mult2;
      }
    }
  }
  printf("%ld", suma);
}

int main()
{
  //day1();
  day2();
}
