//incluir des librairies
#include <stdio.h>
#include <stdlib.h>

//definir des constant
#define TRUE 1
#define FALSE 2

//declaration des types a utiliser
typedef struct list List;
typedef struct node Node;

//declaration des structures
struct list{
  Node * head;
};

struct node{
  int in;
  Node * next;
};

int main() {
  List * myList = malloc(sizeof(List));

  myList->head = malloc(sizeof(Node));

  myList->head->in = 1;
  myList->head->next= malloc(sizeof(Node));

  myList->head->next->in = 2;
  myList->head->next->next = malloc(sizeof(Node));

  myList->head->next->next->in = 3;
  myList->head->next->next->next = NULL;

  printf("%d\n", myList->head->in);
  printf("%d\n", myList->head->next->in);
  printf("%d\n", myList->head->next->next->in);

  return 0;
}
