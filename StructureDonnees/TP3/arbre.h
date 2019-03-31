#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define charSize 20

typedef struct arbre ARBRE;
typedef struct node_arbre NODE_ARBRE;
typedef struct passager PASSAGER;

struct passager
{
  int id;
  char nom[charSize];
  char prenom[charSize];
  int age;
  int siege;
};

struct node_arbre
{
  PASSAGER * passager;
  NODE_ARBRE * left;
  NODE_ARBRE * right;
};

struct arbre
{
  NODE_ARBRE * premier;
};

PASSAGER * newPassager(int id,char prenom[],char nom[],int age,int siege){
  PASSAGER * new = malloc(sizeof(PASSAGER));
  return new;
}

NODE_ARBRE * newNodeArbre(int id,char prenom[],char nom[],int age,int siege){
  NODE_ARBRE * new = malloc(sizeof(NODE_ARBRE));
  new->passager = newPassager(id,prenom,nom,age,siege);
  new->left = NULL;
  new->right = NULL;
  return new;
}

ARBRE * newArbre(){
  ARBRE * new = malloc(sizeof(ARBRE));
  return new;
}

void addNodeAide(int id,char prenom[],char nom[],int age,int siege, NODE_ARBRE * currentNode){
  printf("aide\n");
  if(currentNode== NULL){
    printf("aide insert %s \n", nom);
    currentNode = newNodeArbre(id,prenom,nom,age,siege);
  }else{
    char currentNom[charSize];
    strcpy(currentNom, currentNode->passager->nom);
    if(currentNom[0]>nom[0]){
      printf("left");
      addNodeAide(id,prenom,nom,age,siege,currentNode->left);
    }else{
      printf("right\n");
      addNodeAide(id,prenom,nom,age,siege,currentNode->right);
    }
  }
}

void addNodeArbre(int id,char prenom[],char nom[],int age,int siege, ARBRE * arbre){
  if(arbre->premier == NULL){
    printf("insert %s \n", nom);
    arbre->premier = newNodeArbre(id,prenom,nom,age,siege);
  }else{
    char currentNom[charSize];
    NODE_ARBRE * current = arbre->premier;
    strcpy(currentNom, current->passager->nom);

    if(currentNom[0]>nom[0]){
      printf("left");
      addNodeAide(id,prenom,nom,age,siege,current->left);
    }else{
      printf("right\n");
      addNodeAide(id,prenom,nom,age,siege,current->right);
    }
  }
}

void showPassager(PASSAGER * node){
  printf("ID:%d\n Prenom: %s\n Nom:%s\n Age: %d\n Siege: %d\n", node->id, node->prenom, node->nom, node->age, node->siege);
}

void showNodeArbre(NODE_ARBRE * current){
  if(current->passager != NULL){
    if(current->left!=NULL){
      showNodeArbre(current->left);
    }
    showPassager(current->passager);
    if(current->right!=NULL){
      showNodeArbre(current->right);
    }
  }
}


void showArbre(ARBRE * arbre){
  if(arbre->premier == NULL){
    printf("l'arbre est vide\n");
  }else{
    showNodeArbre(arbre->premier);
  }
}

void saveInArbre(ARBRE * arbre){
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
        printf("%d %s %s %d %d\n", id,prenom,nom,age,siege);
        addNodeArbre(id,prenom,nom,age,siege,arbre);

  }
  fclose(fich);
}
