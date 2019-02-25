#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define arraySize 100
#define arraySizeVoiture 100
#define charSize 20

typedef struct voiture Voiture;
typedef struct client Client;
typedef struct listClient ListClient;
typedef struct listVoiture ListVoiture;


ListClient * makelist();
ListVoiture * makelistVoiture();
Client * newclient();
void addClient();
void supClient();
void updateClientById();
Client * findClientById();
Voiture * newVoiture();
void addVoiture();
void addV();
void supVoiture();
void reparerVoiture();
void printAll();
void printAllVoitureRepare();
void destroy();




struct voiture {
  int id;
  char marque[charSize];
  char modele[charSize];
  char immatriculation[charSize];
  int status;
  struct voiture * next;
};

struct client {
  int data;
  int   id;
  char  nom[charSize];
  char  prenom[charSize];
  char  address[charSize];
  struct client * next;
  struct listVoiture * veicle;
};

struct listClient {
  Client * head;
};

struct listVoiture {
  Voiture * head;
};

int main(void){
  ListClient * listClient = makelist();

  addClient(listClient,1,1,"Andres","Caballero","le Lignon");
  addClient(listClient,2,2,"Bruce","Wayne","Gotham City");
  addClient(listClient,3,3,"Tony","stark","New York City");
  addClient(listClient,4,4,"Dominic","Toretto","Angeles City");

  addVoiture(listClient,1, 1, "ford","mondeo","123");
  addVoiture(listClient,2, 2, "Batmobile","V12.4","xxx");
  addVoiture(listClient,3, 3, "Audi","R8","321");
  addVoiture(listClient,4, 4, "Dodge","Charger R/T","456");
  addVoiture(listClient,1, 5, "mazda", "r8", "789");
  addVoiture(listClient,1, 6, "honda", "vtf", "002");

  printAll(listClient);


  supClient(2, listClient);
  supVoiture(listClient,4,4);
  reparerVoiture(listClient,1,1);
  reparerVoiture(listClient,3,3);
  updateClientById(listClient, 1, "Andres Vicente", "Caballero Cantillo", "Geneve 1200");



  printAll(listClient);
  printAllVoitureRepare(listClient);

  destroy(listClient);
  return 0;
}

ListClient * makelist(){
  ListClient * listClient = malloc(sizeof(ListClient));
  if (!listClient) {
    return NULL;
  }
  listClient->head = NULL;
  return listClient;
}

ListVoiture * makelistVoiture(){
  ListVoiture * listVoiture = malloc(sizeof(ListVoiture));
  if (!listVoiture) {
    return NULL;
  }
  listVoiture->head = NULL;
  return listVoiture;
}

Voiture * newVoiture(int xid, char xmarque[], char xmodele[], char ximmatriculation[]){
  Voiture * newNode = malloc(sizeof(Voiture));
  if (!newNode) {
    return NULL;
  }
  newNode->id = xid;
  strcpy(newNode->marque, xmarque);
  strcpy(newNode->modele, xmodele);
  strcpy(newNode->immatriculation, ximmatriculation);
  newNode->status = 0;
  newNode->next = NULL;
  return newNode;
}

Client * newClient(int data, int xid, char xnom[], char xprenom[], char xaddress[]){
  Client * newNode = malloc(sizeof(Client));
  if (!newNode) {
    return NULL;
  }
  newNode->data = data;
  newNode->id = xid;
  strcpy(newNode->nom, xnom);
  strcpy(newNode->prenom, xprenom);
  strcpy(newNode->address, xaddress);
  newNode->next = NULL;
  newNode->veicle = NULL;
  return newNode;
}

void addVoiture(ListClient * listClient,int clientId, int xid, char xmarque[], char xmodele[], char ximmatriculation[]){
  Client * user = findClientById(clientId, listClient);
  addV(user, xid, xmarque, xmodele, ximmatriculation);
}

void addV(Client * client, int xid, char xmarque[], char xmodele[], char ximmatriculation[]){
  Voiture * current = NULL;
  if(client->veicle == NULL){
    client->veicle = makelistVoiture();
    client->veicle->head = newVoiture(xid, xmarque, xmodele, ximmatriculation);
  }
  else {
    current = client->veicle->head;
    while (current->next!=NULL){
      current = current->next;
    }
    current->next = newVoiture(xid, xmarque, xmodele, ximmatriculation);
  }
}

void reparerVoiture(ListClient * listClient, int idClient, int idVoiture ){
      Client * client = findClientById(idClient,listClient);
      Voiture * currentVoiture = client->veicle->head;
      while(currentVoiture != NULL){
        if(currentVoiture->id == idVoiture){
          printf("reparerVoiture id:%d, %s %s de client %s %s\n",currentVoiture->id,currentVoiture->marque,currentVoiture->modele,client->nom,client->prenom);
          currentVoiture->status = 1;
        }
        currentVoiture = currentVoiture->next;
      }
}

Client * findClientById(int data, ListClient * listClient){
  Client * current = listClient->head;
  while(current != NULL){
    if(current->data == data){

      return current;
    }
    current = current->next;
  }
}

void updateClientById(ListClient * listClient, int idClient, char xnom[], char xprenom[], char xaddress[]){
  Client * current = listClient->head;
  while(current != NULL){
    if(current->id == idClient){
      printf("modification du client %d, %s %s %s pour \n  -> %s %s %s \n", current->id, current->nom, current->prenom, current->address, xnom, xprenom, xaddress);
      strcpy(current->nom, xnom);
      strcpy(current->prenom, xprenom);
      strcpy(current->address, xaddress);
    }
    current = current->next;
  }
}

void supClient(int data, ListClient * listClient){
  Client * current = listClient->head;
  Client * previous = current;
  while(current != NULL){
    if(current->data == data){
      printf("supClient id %d %s %s\n", current->id, current->nom, current->prenom );
      previous->next = current->next;
      if(current == listClient->head)
        listClient->head = current->next;
      free(current);
      return;
    }
    previous = current;
    current = current->next;
  }
}

void supVoiture(ListClient * listClient, int idClient, int xid){
  Client * client = findClientById(idClient,listClient);
  Voiture * current = client->veicle->head;
  Voiture * previous = current;
  while(current != NULL){
    if(current->id == xid){
      printf("supVoiture id:%d, %s %s de client %s %s\n",current->id,current->marque,current->modele,client->nom,client->prenom);
      previous->next = current->next;
      if(current == client->veicle->head)
        client->veicle->head = NULL;
      free(current);
      return;
    }
    previous = current;
    current = current->next;
  }
}

void destroy(ListClient * listClient){
  Client * current = listClient->head;
  Client * next = current;
  while(current != NULL){
    next = current->next;
    free(current);
    current = next;
  }
  free(listClient);
}

void printAll(ListClient * listClient) {
  printf("\n--------------------\nliste des clients avec voitures \n");
  Client * current = listClient->head;
  if(listClient->head == NULL)
    return;

  for(; current != NULL; current = current->next) {
    if( current->veicle->head == NULL){
    }else{
      printf("id: %d, ", current->id);
      printf("%s ", current->nom);
      printf("%s, ", current->prenom);
      printf("-> %s\n", current->address);
      Voiture * voitu = current->veicle->head;
      for(; voitu != NULL; voitu = voitu->next){
        char statusReparation[charSize];
        if(voitu->status == 1){
          strcpy(statusReparation, "deja repare");
        }else{
          strcpy(statusReparation, "en reparation");
        }
        printf("  %s %s : %s \n",voitu->marque,voitu->modele,statusReparation);
      }
    }
  }
  printf("-----------------------\n");
}

void printAllVoitureRepare(ListClient * listClient) {
  printf("\nliste de voitures deja repare\n");
  Client * current = listClient->head;
  if(listClient->head == NULL)
    return;

  for(; current != NULL; current = current->next) {
    Voiture * voitu = current->veicle->head;
    if( current->veicle == NULL){
    }else{
      for(; voitu != NULL; voitu = voitu->next){
        if(voitu->status == 1){
          printf("id:%d %s %s %s de client %s %s\n",voitu->id,voitu->marque,voitu->modele,voitu->immatriculation,current->nom, current->prenom);
        }
      }
    }
  }
  printf("\n");
}

void addClient(ListClient * listClient, int data, int xid, char xnom[], char xprenom[], char xaddress[]){
  Client * current = NULL;
  if(listClient->head == NULL){
    listClient->head = newClient(data, xid, xnom, xprenom, xaddress);
  }
  else {
    current = listClient->head;
    while (current->next!=NULL){
      current = current->next;
    }
    current->next = newClient(data, xid, xnom, xprenom, xaddress);
  }
}
