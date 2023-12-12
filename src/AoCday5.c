#include <stdio.h>
#include <stdlib.h>
#include "../data_structures.h"

#define CASES          20
#define soil           42
#define fertilizer     45
#define water          35
#define light          46
#define temperature    38
#define humidity       23
#define location       39

typedef struct tripla tripla;
struct tripla {
  long int ff;
  long int ss;
  long int tt;
};
//#define CASES 20
arraylist(tripla)
arraylist(long)
arraylist(ArrayList_tripla)
extension(tripla)


long convert(ArrayList_tripla* st, long num)
{
  for (size_t i = 0; i < st->occupied; i++) {
    if (st->array[i].tt >= num && st->array[i].ss <= num) {
      return st->array[i].ff + (num - st->array[i].ss);
    }
  }
  return num;
}

void day1()
{
  ArrayList_long seeds_a = init_array_long(1);
  ArrayList_tripla soil_a = init_array_tripla(1);
  ArrayList_tripla fertilizer_a = init_array_tripla(1);
  ArrayList_tripla water_a = init_array_tripla(1);
  ArrayList_tripla light_a = init_array_tripla(1);
  ArrayList_tripla temperature_a = init_array_tripla(1);
  ArrayList_tripla humidity_a = init_array_tripla(1);
  ArrayList_tripla location_a = init_array_tripla(1);

  for (int i = 0; i < CASES; i++) {
    long num = 0;
    scanf("%ld", &num);
    push_back_array_long(&seeds_a,num);
  }

  for (int i = 0; i < soil; i++) {
    long ff,ss,tt;
    scanf("%ld", &ff);
    scanf("%ld", &ss);
    scanf("%ld", &tt);
    tripla tr = {ff,ss,ss+(tt-1)};
    push_back_array_tripla(&soil_a, tr);
  }

  for (int i = 0; i < fertilizer; i++) {
    long ff,ss,tt;
    scanf("%ld", &ff);
    scanf("%ld", &ss);
    scanf("%ld", &tt);
    tripla tr = {ff,ss,ss+(tt-1)};
    push_back_array_tripla(&fertilizer_a, tr);
  }
  for (int i = 0; i < water; i++) {
    long ff,ss,tt;
    scanf("%ld", &ff);
    scanf("%ld", &ss);
    scanf("%ld", &tt);
    tripla tr = {ff,ss,ss+(tt-1)};
    push_back_array_tripla(&water_a, tr);
  }
  for (int i = 0; i < light; i++) {
    long ff,ss,tt;
    scanf("%ld", &ff);
    scanf("%ld", &ss);
    scanf("%ld", &tt);
    tripla tr = {ff,ss,ss+(tt-1)};
    push_back_array_tripla(&light_a, tr);
  }
  for (int i = 0; i < temperature; i++) {
    long ff,ss,tt;
    scanf("%ld", &ff);
    scanf("%ld", &ss);
    scanf("%ld", &tt);
    tripla tr = {ff,ss,ss+(tt-1)};
    push_back_array_tripla(&temperature_a, tr);
  }
  for (int i = 0; i < humidity; i++) {
    long ff,ss,tt;
    scanf("%ld", &ff);
    scanf("%ld", &ss);
    scanf("%ld", &tt);
    tripla tr = {ff,ss,ss+(tt-1)};
    push_back_array_tripla(&humidity_a, tr);
  }
  for (int i = 0; i < location; i++) {
    long ff,ss,tt;
    scanf("%ld", &ff);
    scanf("%ld", &ss);
    scanf("%ld", &tt);
    tripla tr = {ff,ss,ss+(tt-1)};
    push_back_array_tripla(&location_a, tr);
  }

  long results[CASES];

  for (size_t i = 0; i < seeds_a.capacity; i++) {
    long seed_soil = convert(&soil_a, seeds_a.array[i]);
    long soil_fert = convert(&fertilizer_a, seed_soil);
    long fert_wat = convert(&water_a, soil_fert);
    long wat_light = convert(&light_a, fert_wat);
    long light_temp = convert(&temperature_a, wat_light);
    long temp_hum = convert(&humidity_a, light_temp);
    long final = convert(&location_a, temp_hum);
    results[i] = final;
  }
  long min = results[0];
  for (int i = 0; i < CASES; i++) {
    if (results[i] < min) {
      min = results[i];
    }
  }
  printf("\nResultado:%ld ", min);
}

void day2()
{
  ArrayList_long seeds_a = init_array_long(1);
  ArrayList_tripla soil_a = init_array_tripla(1);
  ArrayList_tripla fertilizer_a = init_array_tripla(1);
  ArrayList_tripla water_a = init_array_tripla(1);
  ArrayList_tripla light_a = init_array_tripla(1);
  ArrayList_tripla temperature_a = init_array_tripla(1);
  ArrayList_tripla humidity_a = init_array_tripla(1);
  ArrayList_tripla location_a = init_array_tripla(1);

  for (int i = 0; i < CASES/2; i++) {
    long num = 0, range = 0;
    scanf("%ld", &num);
    scanf("%ld", &range);
    for (long j = 0; j < range; j++) {
      push_back_array_long(&seeds_a,num+j);
    }
  }

  for (int i = 0; i < soil; i++) {
    long ff,ss,tt;
    scanf("%ld", &ff);
    scanf("%ld", &ss);
    scanf("%ld", &tt);
    tripla tr = {ff,ss,ss+(tt-1)};
    push_back_array_tripla(&soil_a, tr);
  }

  for (int i = 0; i < fertilizer; i++) {
    long ff,ss,tt;
    scanf("%ld", &ff);
    scanf("%ld", &ss);
    scanf("%ld", &tt);
    tripla tr = {ff,ss,ss+(tt-1)};
    push_back_array_tripla(&fertilizer_a, tr);
  }
  for (int i = 0; i < water; i++) {
    long ff,ss,tt;
    scanf("%ld", &ff);
    scanf("%ld", &ss);
    scanf("%ld", &tt);
    tripla tr = {ff,ss,ss+(tt-1)};
    push_back_array_tripla(&water_a, tr);
  }
  for (int i = 0; i < light; i++) {
    long ff,ss,tt;
    scanf("%ld", &ff);
    scanf("%ld", &ss);
    scanf("%ld", &tt);
    tripla tr = {ff,ss,ss+(tt-1)};
    push_back_array_tripla(&light_a, tr);
  }
  for (int i = 0; i < temperature; i++) {
    long ff,ss,tt;
    scanf("%ld", &ff);
    scanf("%ld", &ss);
    scanf("%ld", &tt);
    tripla tr = {ff,ss,ss+(tt-1)};
    push_back_array_tripla(&temperature_a, tr);
  }
  for (int i = 0; i < humidity; i++) {
    long ff,ss,tt;
    scanf("%ld", &ff);
    scanf("%ld", &ss);
    scanf("%ld", &tt);
    tripla tr = {ff,ss,ss+(tt-1)};
    push_back_array_tripla(&humidity_a, tr);
  }
  for (int i = 0; i < location; i++) {
    long ff,ss,tt;
    scanf("%ld", &ff);
    scanf("%ld", &ss);
    scanf("%ld", &tt);
    tripla tr = {ff,ss,ss+(tt-1)};
    push_back_array_tripla(&location_a, tr);
  }

  long results[seeds_a.capacity];

  for (size_t i = 0; i < seeds_a.capacity; i++) {
    long seed_soil = convert(&soil_a, seeds_a.array[i]);
    long soil_fert = convert(&fertilizer_a, seed_soil);
    long fert_wat = convert(&water_a, soil_fert);
    long wat_light = convert(&light_a, fert_wat);
    long light_temp = convert(&temperature_a, wat_light);
    long temp_hum = convert(&humidity_a, light_temp);
    long final = convert(&location_a, temp_hum);
    results[i] = final;
  }
  long min = results[0];
  for ( size_t i = 0; i < seeds_a.capacity; i++) {
    if (results[i] < min) {
      min = results[i];
    }
  }
  printf("\nResultado:%ld ", min);
}

int main(void)
{
  //day1();
  day2();
}
