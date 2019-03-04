#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

int main(int argc, char const *argv[]) {
  List * list = newList();
  listAdd(1,list);
  listAdd(2,list);
  listAdd(3,list);
  listAdd(4,list);
  listAdd(5,list);
  listAdd(6,list);
  listShow(list);
  listSup(2,list);
  listSup(5,list);
  listSup(6,list);
  listAdd(7,list);
  listShow(list);
  listDepiler(list);
  listShow(list);
  listDepiler(list);
  listShow(list);
  listDepiler(list);
  listShow(list);
  listDepiler(list);
  listShow(list);
  printf("%d\n",find(8,list));

  return 0;
}
