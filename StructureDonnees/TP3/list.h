#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define charSize 20

enum bool {FALSE, TRUE};


typedef struct list List;
typedef struct node Node;


struct list {
  Node * head;
};

struct node {
  int id;
  char nom[charSize];
  char prenom[charSize];
  int age;
  int siege;
  Node * next;
};

List * newList(){
  List * new = malloc(sizeof(List));
  return new;
}

Node * newNode(int id,char prenom[],char nom[],int age,int siege){
  Node * new = malloc(sizeof(Node));
  new->id = id;
  strcpy(new->prenom, prenom);
  strcpy(new->nom, nom);
  new->age = age;
  new->siege = siege;
  new->next = NULL;
  return new;
}

void listAddNode(int id,char prenom[],char nom[],int age,int siege, Node * node){
  if(node->next == NULL){
    node->next = newNode(id,prenom,nom,age,siege);
  }else{
    listAddNode(id,prenom,nom,age,siege, node->next);
  }
}

void listAdd(int id,char prenom[],char nom[],int age,int siege, List * list){
  if(list->head == NULL){
    list->head = newNode(id,prenom,nom,age,siege);

  }else{
    listAddNode(id,prenom,nom,age,siege,list->head);
  }
}

void listSupNode(int id, Node * node){
  if(node->next != NULL){
    if(node->next->id == id){
      Node * temp = node->next;
      node->next = temp->next;
      free(temp);
    }else{
      listSupNode(id,node->next);
    }
  }
}

void listSup(int id, List * list){
  if(list->head != NULL){
    if(list->head->id == id){
      Node * temp = list->head;
      list->head = temp->next;
      free(temp);
    }else{
      listSupNode(id,list->head);
    }
  }
}

void listShowNode(Node * node){
  printf("ID:%d\n Prenom: %s\n Nom:%s\n Age: %d\tSiege: %d", node->id, node->prenom, node->nom, node->age, node->siege);
  if(node->next != NULL){
    printf("\n");
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

enum bool findNode(int id, Node * node){
    if(node->id == id){
      return TRUE;
    }else if(node->next == NULL){
      return FALSE;
    }else{
      findNode(id, node->next);
    }
}

enum bool find(int id, List * list){
  if(list->head != NULL){
    return findNode(id, list->head);
  }else{
    return FALSE;
  }
}

void lireFichie(List * list){
  int id,age,siege;
  char nom[charSize];
  char prenom[charSize];
  char linea[1024];
  FILE *fich;
  fich = fopen("passagers.txt", "r");
  printf("fichie load\n");
  //Lee línea a línea y escribe en pantalla hasta el fin de fichero
  while (fgets(linea, 1024, (FILE *)fich))
  {
    char seps[]   = "\t";
    char *token;
        token = strtok( linea, seps );
        id = atoi(token);
        token = strtok( NULL, seps );
        strcpy(prenom, token);
        token = strtok( NULL, seps );
        strcpy(nom, token);
        token = strtok( NULL, seps );
        age = atoi(token);
        token = strtok( NULL, seps );
        siege = atoi(token);
        token = strtok( NULL, seps );
        //printf("%d %s %s %d %d\n", id,prenom,nom,age,siege);
        listAdd(id,prenom,nom,age,siege,list);

  }
  fclose(fich);
}
