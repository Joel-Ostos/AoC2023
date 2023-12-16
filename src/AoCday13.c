#include <stdio.h>
#include <stdlib.h>
#include "../data_structures.h"
#define CASES 1

arraylist(char)
arraylist(ArrayList_char)
arraylist(long)
extension(char)

bool is__row(ArrayList_ArrayList_char map, size_t index)
{
    for (size_t i = index, j = index+1; i >= 0 && j < map.occupied; i--, j++){
        if (strcmp(map.array[i].array, map.array[j].array) != 1) return false;
    }
}
void day1() 
{
    long r_columns = 0;
    long r_rows = 0;
    for (int i = 0; i < CASES; i++) {
        char actual[70] = "a";
        ArrayList_ArrayList_char map1 = init_array_ArrayList_char(10);
        ArrayList_ArrayList_char map2 = init_array_ArrayList_char(10);
        while(strcmp(actual,"\n") == 1){
            scanf("%s", actual);
            char* str = NULL;
            size_t size = 0;
            getline(&str,&size,stdin);
            ArrayList_char tmp = set_array_char(str,size);
            push_back_arraymatrix_char(&map1,&tmp,true);
            deinit_array_char(&tmp);
        }
        scanf("%s", actual);
        while(strcmp(actual,"\n") == 1){
            scanf("%s", actual);
            char* str = NULL;
            size_t size = 0;
            getline(&str,&size,stdin);
            ArrayList_char tmp = set_array_char(str,size);
            push_back_arraymatrix_char(&map2,&tmp,true);
            deinit_array_char(&tmp);
        }
        bool is_row = false, is_row2 = false;
        long index_row = -1, index_row2 = -1, index_column = -1, index_column2 = -1;
        for (size_t j = 0; j < (map1.occupied)-1; j++) {
            ArrayList_char current = map1.array[j];
            ArrayList_char next = map1.array[j+1];
            index_row += 1;
            if (strcmp(current.array, next.array) == 1) { 
                break;
            }
        }
        if (is__row(map1,index_row)) is_row = true;
        
        if (!is_row) {
            for (size_t j = 0; j < (map1.array[0].occupied)-1; j++) {
                ArrayList_char current = init_array_char(map1.occupied);
                ArrayList_char next = init_array_char(map1.occupied);
                index_column += 1;
                for (size_t k = 0; k < (map1.occupied)-1; k++) {
                    push_back_array_char(&current, map1.array[k].array[j]);
                    push_back_array_char(&next, map1.array[k].array[j+1]);
                }            
                if (strcmp(current.array, next.array) == 1) {
                    is_row = true; 
                    break;
                }
            }
        }

        for (size_t j = 0; j < (map2.occupied)-1; j++) {
            ArrayList_char current = map2.array[j];
            ArrayList_char next = map2.array[j+1];
            index_row2 += 1;
            if (strcmp(current.array, next.array) == 1) break;
        }   
        
        if (is__row(map2, index_row2)) is_row2 = true ;

        if (!is_row){
            for (size_t j = 0; j < (map1.array[0].occupied)-1; j++) {
                ArrayList_char current = init_array_char(map1.occupied);
                ArrayList_char next = init_array_char(map1.occupied);
                index_column2 += 1;
                for (size_t k = 0; k < (map1.occupied)-1; k++) {
                    push_back_array_char(&current, map1.array[k].array[j]);
                    push_back_array_char(&next, map1.array[k].array[j+1]);
                }            
                if (strcmp(current.array, next.array) == 1) break;
            }    
        }
        long num_r = index_row;
        long num_r2 = map1.occupied - index_row;
        long num_r3 = index_row2;
        long num_r4 = map2.occupied - index_row2;
        
        long num_c = index_column;
        long num_c2 = map1.array[0].occupied - index_column;
        long num_c3 = index_column2;
        long num_c4 = map1.array[0].occupied - index_column2;


        if (is_row && is_row2) {
            r_rows += num_r > num_r2? num_r2 : num_r;
            r_rows += num_r3 > num_r4? num_r4 : num_r3;
        } else if (is_row && !(is_row2)) {
            r_rows += num_r > num_r2? num_r2 : num_r;
            r_columns += num_c3 > num_c4? num_c4 : num_c3;
        } else if (!(is_row) && !(is_row2)) {
            r_columns += num_c > num_c2? num_c2 : num_c;
            r_columns += num_c3 > num_c4? num_c4 : num_c3;
        } else {
            r_columns += num_c > num_c2? num_c2 : num_c;
            r_rows += num_r3 > num_r4? num_r4 : num_r3;
        }      
    }
    printf("result -> %ld", r_columns+(400*r_rows));
}

int main(void)
{
    day1();
}
