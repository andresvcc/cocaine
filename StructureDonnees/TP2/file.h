#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define charSize 20


typedef struct fifo FIFO;
typedef struct node Node;
enum bool {FALSE, TRUE};



struct fifo {
  Node * head;
  int size;
  char nom[charSize];
  enum bool fait;
  int type;
  FIFO * next;
};

struct node {
  int id;
  char nom[charSize];
  enum bool fait;
  Node * next;
};

FIFO * newFIFO(char nom[], int xtype){
  FIFO * new = malloc(sizeof(FIFO));
  new->size = 0;
  new-> fait = FALSE;
  strcpy(new->nom, nom);
  new->type = xtype;
  new->next = NULL;
  return new;
}

Node * newNode(int xid,char nom[]){
  Node * new = malloc(sizeof(Node));
  new->id = xid;
  strcpy(new->nom, nom);
  new->fait = FALSE;
  new->next = NULL;
  return new;
}

void AddNode(int xid, char nom[], Node * node){
  if(node->next == NULL){
    node->next = newNode(xid,nom);
  }else{
    AddNode(xid, nom, node->next);
  }
}

void addTache(char nom[], FIFO * fifo){
  if(fifo->next == NULL){
    fifo->size = fifo->size + 1;
    int xid = fifo->size;
    if(fifo->head == NULL){
      fifo->head = newNode(xid, nom);
    }else{
      AddNode(xid, nom,fifo->head);
    }
  }else{
    addTache(nom,fifo->next);
  }
}

void addCategorie(char nom[], int xtype, FIFO * fifo){
  if(fifo->next == NULL){
    fifo->next = newFIFO(nom, xtype);
  }else{
    addCategorie(nom, xtype, fifo->next);
  }
}

void showNode(Node * node){
  printf("(%d : %s : %d), ", node->id, node->nom, node->fait);
  if(node->next != NULL){
    showNode(node->next);
  }
}

void show(FIFO * fifo){
  if(fifo->head == NULL){
    printf("(vide!!)\n");
  }else{
    showNode(fifo->head);
    printf("\n");
  }
}

void allFalse(Node * node){
  node->fait = FALSE;
  if(node->next != NULL){
    allFalse(node->next);
  }
}

int dernierVerification(Node * node){
  if(node->fait == TRUE){
    if(node->next != NULL){
      dernierVerification(node->next);
    }else{
      return 1;
    }
  }else{
    return 0;
  }
}

void verifierNode(Node * node, FIFO * fifo){
  printf("  la tache %s est fait? \n", node->nom);
  int requ;
  printf("-> ");
  scanf("%d",&requ);
  if (requ == 1){
    node->fait = TRUE;
    if(node->next != NULL){
      verifierNode(node->next, fifo);
    }
  }else{
    printf("on va repeter la derniere sous categorie\n");
    allFalse(fifo->head);
    verifierNode(fifo->head, fifo);
  }
}

void defileCategorie(FIFO * fifo){
    FIFO * temp = fifo;
    fifo = temp->next;
    free(temp);
}

void verifier(FIFO * fifo){


  if(fifo->type == 1){
    printf("--------------------------\n");
    printf("categorie %s\n",fifo->nom );
  }else if(fifo->type == 2){
    printf("  verification de sub-categorie %s\n",fifo->nom );
  }else{
    printf("Error %s n'a pas de type definie \n",fifo->nom );
  }



  if(fifo->head == NULL){
    if(fifo->type == 1){
      if(fifo->next != NULL){
        verifier(fifo->next);
      }
    }else{
      printf("(vide!!)\n");
    }
  }else{
    verifierNode(fifo->head, fifo);
    if(dernierVerification(fifo->head)){
      printf("la verification du %s es fait (OK)\n", fifo->nom );
      defileCategorie(fifo);
      if(fifo->next != NULL ){
        verifier(fifo->next);
      }else{
        printf("verification finalice, tout est bon !!!\n");
      }
    }else{
      printf("categorie inacheve, on va repeter la categorie\n");
      allFalse(fifo->head);
      verifierNode(fifo->head, fifo);
    }
    printf("\n");
  }
}

Node * defile(FIFO * fifo){
  if(fifo->head == NULL){
    printf("vide\n");
    return NULL;
  }else {
    Node * temp = fifo->head;
    fifo->head = fifo->head->next;
    return temp;
  }
}

void tranfers(FIFO * fifo, FIFO * newFifo){
  if(fifo->head != NULL){
    Node * temp = defile(fifo);
    addTache(temp->nom,newFifo);
    free(temp);
  }else{
    printf("vide\n");
  }
}
