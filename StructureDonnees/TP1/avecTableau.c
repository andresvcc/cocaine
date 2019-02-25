#include <stdio.h>
#include <string.h>

#define arraySize 100
#define arraySizeVoiture 100
#define charSize 20


//declaracion infix des fonction

void addClient();
void supClient();
void updateCLientByNom();
int findCLientByName();
int findCLientByPrenom();
int findCLientByAddress();

void addVoiture();
void supVoiture();
void setStatusVoiture();
int findVoiture();

void printVoitureId();
void printCLientId();
void printAllClient();
void printAllVoiture();
void printAllVoitureRepare();



//tableaux des donnes;

char nomClient[arraySize][charSize];
char prenomClient[arraySize][charSize];
char adressClient[arraySize][charSize];
int propieterVoiture[arraySize];
char marqueVoiture[arraySize][charSize];
char modeleVoiture[arraySize][charSize];
char immatriculation[arraySize][charSize];
int voitureStatus[arraySize];

//variables des operations
int i,j;
int maxClient = 0;
int maxVoiture = 0;


int main () {

  addClient("Andres","Caballero","Lignon");
  addClient("Bruce","Wayne","Gotham City");
  addClient("Tony","stark","New York City");
  addClient("Dominic","Toretto","Angeles City");

  addVoiture("Andres","ford","mondeo","123");
  addVoiture("Bruce","Batmobile","V12.4","xxx");
  addVoiture("Tony","Audi","R8","321");
  addVoiture("Dominic","Dodge","Charger R/T","456");

  printAllVoiture();

  supVoiture(findVoiture("123"));
  supVoiture(findVoiture("321"));

  printAllVoiture();

  setStatusVoiture("123",1);
  setStatusVoiture("321",1);
  updateCLientByNom("Andres","Andres Vicente","Caballero Cantillo", "geneve 1200");

  printAllVoitureRepare();


  return 0;
  }


  int findCLientByName(char nom[])
  {
    for(i=0;i<maxClient;i++){
      if (strcmp(nomClient[i], nom) == 0)
      {
        return i;
      }
    }
  }

  void updateCLientByNom(char nom[],char newnom[],char newprenom[], char newaddress[])
  {
    for(i=0;i<maxClient;i++){
      if (strcmp(nomClient[i], nom) == 0)
      {
        strcpy(nomClient[i], newnom);
        strcpy(prenomClient[i], newprenom);
        strcpy(adressClient[i], newaddress);
      }
    }
  }

  int findCLientByAddress(char address[])
  {
    for(i=0;i<maxClient;i++){
      if (strcmp(adressClient[i], address) == 0)
      {
        return i;
      }
    }
  }

  void addClient(char nom[], char prenom[], char adress[])
  {
    if(maxVoiture < arraySizeVoiture ){
      strcpy(nomClient[maxClient], nom);
      strcpy(prenomClient[maxClient], prenom);
      strcpy(adressClient[maxClient], adress);
      maxClient++;
    }else{
      printf("\nil est impossible d'ajouter ce client car le nombre maximal de clients a déjà été atteint\n");
    }
  }

  void supClient(int id)
  {
    for(i=id;i<maxClient;i++){
      strcpy(nomClient[i], nomClient[i+1]);
      strcpy(prenomClient[i], prenomClient[i+1]);
      strcpy(adressClient[i], adressClient[i+1]);
    }
    maxClient--;
  }

  void addVoiture(char proprieter[],char marque[], char modele[], char immatri[])
  {
    if(maxVoiture < arraySizeVoiture ){
      propieterVoiture[maxVoiture] = findCLientByName(proprieter);
      strcpy(marqueVoiture[maxVoiture], marque);
      strcpy(modeleVoiture[maxVoiture], modele);
      strcpy(immatriculation[maxVoiture], immatri);
      voitureStatus[maxVoiture] = 0;
      maxVoiture++;
    }else{
      printf("\nil est impossible d'ajouter ce voiture car le nombre maximal des voiture a déjà été atteint\n");
    }

  }

  void supVoiture(int id)
  {
    for(i=id;i<maxClient;i++){
      propieterVoiture[i] = propieterVoiture[i+1];
      strcpy(marqueVoiture[i], marqueVoiture[i+1]);
      strcpy(modeleVoiture[i], modeleVoiture[i+1]);
      strcpy(immatriculation[i], immatriculation[i+1]);
      voitureStatus[i] = voitureStatus[i+1];
    }
    maxVoiture--;
  }

  void setStatusVoiture(char immatri[], int status)
  {
    voitureStatus[findVoiture(immatri)] = status;
  }

  int findVoiture(char immatri[])
  {
    for(i=0;i<maxClient;i++){
      if (strcmp(immatriculation[i], immatri) != 0)
      {
        return i;
      }
    }
  }

  void printCLientId(int id)
  {
    printf("client id: %d \n",id);
    printf("  nombre: %s ",nomClient[id]);
    printf("  apellido: %s ",prenomClient[id]);
    printf("  direccion: %s \n",adressClient[id]);
  }

  void printAllClient()
  {
    printf("\nliste de client\n");
    for(i=0;i<maxClient;i++){
      printCLientId(i);
    }
  }



  void printVoitureId(int id)
  {
    printf("proprieter: %s \n",nomClient[propieterVoiture[id]]);
    printf("  marque: %s ",marqueVoiture[id]);
    printf("  modele: %s ",modeleVoiture[id]);
    printf("  immatriculation: %s\n",immatriculation[id]);
  }

  void printAllVoitureRepare()
  {
    printf("\nliste de voitures deja repare\n");
    for(i=0;i<maxVoiture;i++){
      if(voitureStatus[i] > 0){
        printVoitureId(i);
      }
    }
  }

  void printAllVoiture()
  {
    printf("\nliste de voitures\n");
    for(i=0;i<maxVoiture;i++){
      printVoitureId(i);
    }
  }



/*
char nomClient[maxClient], char prenomClient[maxClient], char prenomClient[maxClient]


*/
