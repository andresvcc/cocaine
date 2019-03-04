#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list List;
typedef struct node Node;
enum bool {FALSE, TRUE};

struct list {
  Node * head;
};

struct node {
  int in;
  Node * next;
};

List * newList(){
  List * new = malloc(sizeof(List));
  return new;
}

Node * newNode(int data){
  Node * new = malloc(sizeof(Node));
  new->in = data;
  new->next = NULL;
  return new;
}

void listAddNode(int data, Node * node){
  if(node->next == NULL){
    node->next = newNode(data);
  }else{
    listAddNode(data, node->next);
  }
}

void listAdd(int data, List * list){
  if(list->head == NULL){
    list->head = newNode(data);
  }else{
    listAddNode(data,list->head);
  }
}

int listDepilerNode(Node * node){
if(node->next->next == NULL){
    int dataTemp = node->next->in;
    Node * temp = node->next;
    node->next = NULL;
    free(temp);
    return dataTemp;
  }else{
    listDepilerNode(node->next);
  }
}

void listDepiler(List * list){
  if(list->head == NULL){
    printf("vide\n");
  }else if(list->head->next == NULL){
    printf("%d\n",list->head->in);
    Node * temp = list->head;
    list->head = NULL;
    free(temp);
  }else{
    printf("%d\n", listDepilerNode(list->head));
  }
}

void listSupNode(int data, Node * node){
  if(node->next != NULL){
    if(node->next->in == data){
      Node * temp = node->next;
      node->next = temp->next;
      free(temp);
    }else{
      listSupNode(data,node->next);
    }
  }
}

void listSup(int data, List * list){
  if(list->head != NULL){
    if(list->head->in == data){
      Node * temp = list->head;
      list->head = temp->next;
      free(temp);
    }else{
      listSupNode(data,list->head);
    }
  }
}

void listShowNode(Node * node){
  printf("%d ", node->in);
  if(node->next != NULL){
    listShowNode(node->next);
  }
}

void listShow(List * list){
  if(list->head == NULL){
    printf("(vide!!)\n");
  }else{
    listShowNode(list->head);
    printf("\n");
  }
}

enum bool findNode(int data, Node * node){
    if(node->in == data){
      return TRUE;
    }else if(node->next == NULL){
      return FALSE;
    }else{
      findNode(data, node->next);
    }
}

enum bool find(int data, List * list){
  if(list->head != NULL){
    return findNode(data, list->head);
  }else{
    return FALSE;
  }
}
