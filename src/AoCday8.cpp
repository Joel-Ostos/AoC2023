#include <iostream>
#include <bits/stdc++.h>

#define CASES 754
#define ORDERS 293

using namespace std;
typedef struct tupla tupla;

struct tupla {
  string left;
  string right;
};

void day1()
{
  unordered_map<string, tupla> mapa;
  string ordenes;
  cin >> ordenes;
  for (int i = 0; i < CASES; i++){
    string key;
    tupla tmp;
    cin >> key;
    cin >> tmp.left;
    cin >> tmp.right;
    mapa.insert({key,tmp});
  }

  int cont = 0;
  int pasos = 0;
  string actual = "AAA";
  while (actual != "ZZZ") {
    if (ordenes[cont%ORDERS] == 'L') {
      actual = mapa[actual].left;
    } else if (ordenes[cont%ORDERS] == 'R') {
      actual = mapa[actual].right;
    }
    cout << actual  << " "<< cont%ORDERS << '\n';
    cont+=1;
    pasos+=1;
  }
  cout << pasos << '\n';
}

void day2()
{
  unordered_map<string, tupla> mapa;
  string ordenes;
  cin >> ordenes;
  for (int i = 0; i < CASES; i++){
    string key;
    tupla tmp;
    cin >> key;
    cin >> tmp.left;
    cin >> tmp.right;
    mapa.insert({key,tmp});
  }

  int cont = 0;
  int pasos = 0;

  string actual1 = "AAA";
  int n1 = 0;
  string actual2 = "QRA";
  int n2 = 0;
  string actual3 = "KQA";
  int n3 = 0;
  string actual4 = "DFA";
  int n4 = 0;
  string actual5 = "DBA";
  int n5 = 0;
  string actual6 = "HJA";
  int n6 = 0;
  int arreglo[6];

  while (actual1[2] != 'Z') {
    if (ordenes[cont%ORDERS] == 'L') {
      actual1= mapa[actual1].left;
    } else if (ordenes[cont%ORDERS] == 'R') {
      actual1 = mapa[actual1].right;
    }
    cont+=1;
    pasos+=1;
  }
  arreglo[0] = pasos;
  pasos = 0;
  cont = 0;

  while (actual2[2] != 'Z') {
    if (ordenes[cont%ORDERS] == 'L') {
      actual2= mapa[actual2].left;
    } else if (ordenes[cont%ORDERS] == 'R') {
      actual2 = mapa[actual2].right;
    }
    cont+=1;
    pasos+=1;
  }
  arreglo[1] = pasos;
  pasos = 0;
  cont = 0;
  while (actual3[2] != 'Z') {
    if (ordenes[cont%ORDERS] == 'L') {
      actual3= mapa[actual3].left;
    } else if (ordenes[cont%ORDERS] == 'R') {
      actual3 = mapa[actual3].right;
    }
    cont+=1;
    pasos+=1;
  }
  arreglo[2] = pasos;
  pasos = 0;
  cont = 0;

  while (actual4[2] != 'Z') {
    if (ordenes[cont%ORDERS] == 'L') {
      actual4= mapa[actual4].left;
    } else if (ordenes[cont%ORDERS] == 'R') {
      actual4 = mapa[actual4].right;
    }
    cont+=1;
    pasos+=1;
  }
  arreglo[3] = pasos;
  pasos = 0;
  cont = 0;
  while (actual5[2] != 'Z') {
    if (ordenes[cont%ORDERS] == 'L') {
      actual5= mapa[actual5].left;
    } else if (ordenes[cont%ORDERS] == 'R') {
      actual5 = mapa[actual5].right;
    }
    cont+=1;
    pasos+=1;
  }
  arreglo[4] = pasos;
  pasos = 0;
  cont = 0;
  while (actual6[2] != 'Z') {
    if (ordenes[cont%ORDERS] == 'L') {
      actual6= mapa[actual6].left;
    } else if (ordenes[cont%ORDERS] == 'R') {
      actual6 = mapa[actual6].right;
    }
    cont+=1;
    pasos+=1;
  }
  arreglo[5] = pasos;
  n1 = arreglo[0];
  n2 = arreglo[1];
  n3 = arreglo[2];
  n4 = arreglo[3];
  n5 = arreglo[4];
  n6 = arreglo[5];
  long long l = 1;
  while (1) {
    long long max = 21389;
    max*=l;
    if ((max % n1 == 0) && (max % n2 == 0) && (max % n3 == 0) && (max % n4 == 0) && (max % n5 == 0) && (max % n6 == 0)) {
      printf("%lld",max);
      break;
    }
    l++;
  }
}

int main(void)
{
  day1();
  //day2();
}
