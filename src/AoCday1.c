#include <stdio.h>
#include <stdlib.h>
#include "../data_structures.h"

arraylist(char)
arraylist(int)
arraylist(ArrayList_char)
extension(char)

void sum(ArrayList_int* nums)
{
  int suma = 0;
  for (size_t i = 0; i < nums->occupied; i++) {
    suma += nums->array[i];
  }
  printf("%d", suma);
}

void part1()
{
  int t = 1;
  char str[100];
  ArrayList_int nums = init_array_int(0);
  while (t--) {
    scanf("%s", str);
    char uno = 'a', dos = 'a';
    for (int i = 0; i < 100; i++){
      char current = str[i];
      if (current - 0 <= 57 && current - 0 >= 48) {
	uno = current;
	break;
      }
    }

    for (int i = 99; i >= 0; i--){
      char current = str[i];
      if (current - 0 <= 57 && current - 0 >= 48) {
	dos = current;
	break;
      }
    }

    ArrayList_char a = init_array_char(2);
    push_back_array_char(&a,uno);
    push_back_array_char(&a,dos);
    push_back_array_int(&nums,atoi(a.array));
  }
  sum(&nums);
}

void part2()
{
  char* digits[] = {"one","two","three","four","five", "six", "seven", "eight", "nine"};
  int t = 1;
  char str[100];
  ArrayList_int nums = init_array_int(0);
  while (t--) {
    bool an = false;
    bool sera = false;
    scanf("%s", str);
    char uno = 'a', dos = 'a';
    for (int i = 0; i < 100 && sera == false; i++){
      char current = str[i];
      if (current - 0 <= 57 && current - 0 >= 48) {
	uno = current;
	sera = true;
	break;
      }
      for (int j = 3; j < 6 && sera == false; j++) {
      	char word[j]; 
	word[j] = '\0';
	memcpy(word, str+i, j);
	for (int  k = 0; k < 9 && sera == false; k++) {
      	  if (strcmp(word, digits[k]) == 0){
	    uno = (char) 48+k+1;
      	    sera = true;
      	    break;
      	  }
      	}
      }
    }
    for (int i = 100; i >= 0 && an == false; i--) {
      char current = str[i];
      if (current - 0 <= 57 && current - 0 >= 48) {
	dos = current;
	an = true;
	break;
      }
      for (int j = 3; j < 6 && an == false; j++) {
      	char word[j]; 
	word[j] = '\0';
      	memcpy(word, str+(i-j), sizeof(char)*j);
	for (int  k = 0; k < 9 && an == false; k++) {
      	  if (strcmp(word, digits[k]) == 0){
	    dos = (char) 48+k+1;
      	    an = true;
      	    break;
      	  }
      	}
      }
    }
    for (int i = 0; i < 100; i++) {
      str[i] = '\0';
    }
    ArrayList_char a = init_array_char(2);
    push_back_array_char(&a,uno);
    push_back_array_char(&a,dos);
    push_back_array_int(&nums, atoi(a.array));
    deinit_array_char(&a);
  }
  sum(&nums);
  deinit_array_int(&nums);
}

int main(void)
{
  //part1();
  part2();
  return 0;
}
