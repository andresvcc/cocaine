#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define charSize 20

void help(){
  printf("-------------------------------------------------------------\n");
  printf("Voici une liste de commandes de tout ce que vous pouvez faire\n");
  printf("-------------------------------------------------------------\n");
  printf("new vol              creer un nouveau vol\n");
  printf("show all vol         montrer tout la liste des vols\n");
  printf("show active vol      montrer les vols en route\n");
  printf("show scheduled vol   montrer les vol qui sont planifie\n");
  printf("show finished vol    montrer les vols qui ont ete deja efectues\n");
  printf("find vol             chercher un vol\n");
  printf("find employe         chercher un employe\n");
  printf("find client          chercher un client/passage\n");
  printf("exit                 sortir du program\n");
  printf("-------------------------------------------------------------\n");
}

void menuNewVol(ListVol * listVol, ListAvion * listAvion, ListEquipage * listEquipage){
  int idAvion;
  int idEquipage;
  int xheureDep;
  int xheureDes;
  char xaeroDep[charSize];
  char xaeroDes[charSize];
  printf("----------------------------------\n");
  printf("pour créer un nouveau vol, entrez \n");
  printf("----------------------------------\n");
  printf("heure de depart: ");
  scanf("%d",&xheureDep);
  printf("\nheure de d'arrivage: ");
  scanf("%d",&xheureDes);
  printf("\naeroport de depart: ");
  scanf("%s",xaeroDep);
  printf("\naeroport d'arrivage: ");
  scanf("%s",xaeroDes);
  printf("\n liste des avion \n");
  int okAvion = showAvion(listAvion);
  if(okAvion >= 0){
    printf("\nid Avion: ");
    scanf("%d",&idAvion);
    Avion * xavion = findAvion(idAvion,listAvion);
    if(xavion != NULL){
      int okEquipage = showEquipage(listEquipage);
      if(okEquipage >= 0){
        printf("\nid Equipage: ");
        scanf("%d",&idEquipage);
        Equipage * xequipage = findEquipage(listEquipage);
        if(xequipage != NULL){
          Vol * xvol = newVol(1, xheureDep, xheureDes, xaeroDep, xaeroDes, xavion, xequipage);
          addVol(xvol,listVol);
        }else{
          printf("imposible id d'equipage inconue\n");
        }
      }else{
        printf("imposible il n'y a pas dequipage, SVP creer un equipage avant avec la commande new-equipage\n");
      }
    }else{
      printf("imposible id d'avion inconue\n");
    }

  }else{
    printf("imposible il n'y a pas d'avion dans la liste, SVP ajouter un avion avant, utilise la comande new-avion\n");
  }
  printf("----------------------------------\n");

}

void menuNewAvion(ListAvion * listAvion){
  int xid;
  char xmodele[charSize];
  int xnomChaisse;
  int xdateMisCirculation;
  printf("--------------------------------------\n");
  printf("pour ajouter un nouveau Avion, entrez \n");
  printf("--------------------------------------\n");
  printf("id: ");
  scanf("%d",&xid);
  printf("\nmodele: ");
  scanf("%s",xmodele);
  printf("\nnombre des chaises: ");
  scanf("%d",&xnomChaisse);
  printf("\ndate de mis en circulation: ");
  scanf("%d",&xdateMisCirculation);
  Avion * nodeAvion = newAvion(xid,xmodele,xnomChaisse,xdateMisCirculation);
  addAvion(nodeAvion, listAvion);
  printf("--------------------------------------\n");
  showAvion(listAvion);
}

void menuNewEquipage(ListEquipage * listEquipage, ListEmploye * listEmploye){
  int xid;
  char xmodele[charSize];
  int xnomChaisse;
  int xdateMisCirculation;
  printf("--------------------------------------\n");
  printf("pour un nouveau Equipage, choisissez\n");
  printf("--------------------------------------\n");
  int idPilot;
  int idCopilot;
  int idChef;
  int sizeHotesse;
  Employe * xpilot;
  Employe * xcopilot;
  Employe * xchefHotesse;
  printf("liste des pilot\n");
  showEmployebyCompetence(1,listEmploye);
  printf("\n: choisissez un pilot dans la liste de pilot");
  printf("id: ");
  scanf("%d",&idPilot);
  printf("\n: choisissez un copilot dans la liste de pilot");
  printf("id: ");
  scanf("%d",&idCopilot);
  showEmployebyCompetence(2,listEmploye);

  Equipage * nodeEquipage = newEquipage(xid,xpilot,xcopilot,xchefHotesse);

  printf("combien d'hotesses voulez vous ajouter? : ");
  scanf("%d \n",&sizeHotesse);
  showEmployebyCompetence(3,listEmploye);

  int idHotesse;
  for (int i = 0; i < sizeHotesse; i++) {
    printf("\nhotesse n°%d : ", i );
    scanf("%d",&idHotesse);
    Employe * hotesse = findEmploye(idHotesse,listEmploye);
    addHotesse(nodeEquipage, hotesse);
  }

  addEquipage(nodeEquipage, listEquipage);
  printf("--------------------------------------\n");
}

Employe * findEmploye(int id, ListEmploye * listEmploye){
  ListEmploye * current = NULL;

  if(listEmploye->data == NULL){
    printf("liste des Avion vide !!\n");
    return NULL;
  }else {
    current = listEmploye;
    while (current->data!=NULL){
      if(current->data->id == id){
          return current->data;
      }
      current = current->next;
    }
    return NULL;
  }
}

Avion * findAvion(int id, ListAvion * listAvion){
  ListAvion * current = NULL;

  if(listAvion->data == NULL){
    printf("liste des Avion vide !!\n");
    return NULL;
  }else {
    current = listAvion;
    while (current->data!=NULL){
      if(current->data->id == id){
          return current->data;
      }
      current = current->next;
    }
    return NULL;
  }
}

Equipage * findEquipage(int id, ListEquipage * listEquipage){
  ListEquipage * current = NULL;

  if(listEquipage->data == NULL){
    printf("liste des Avion vide !!\n");
    return NULL;
  }else {
    current = listEquipage;
    while (current->data!=NULL){
      if(current->data->id == id){
          return current->data;
      }
      current = current->next;
    }
    return NULL;
  }
}

int showEquipage(ListEquipage * listEquipage){
  ListEquipage * current = NULL;

  if(listEquipage->data == NULL){
    printf("liste des Equipage vide !!\n");
    return -1;
  }else {
    current = listEquipage;
    while (current->data!=NULL){
      //printf("id: %d modele: %s N°chaisse: %d \n", current->data->id, current->data->modele, current->data->nombreChaises);
      current = current->next;
    }
    return 0;
  }
}

void showEmployebyCompetence(int competence, ListEmploye * listEmploye){
  ListEmploye * current = NULL;
  current = listEmploye;
  while (current->data!=NULL){
    if(competence == current->data->competence){
      printf("id: %d | nom: %s %s \n",current->data->id,current->data->nom, current->data->prenom);
    }
    current = current->next;
  }
}

int showEmploye(int competence, ListEmploye * listEmploye){
  ListEmploye * current = NULL;

  if(listEmploye->data == NULL){
    printf("liste des Equipage vide !!\n");
    return -1;
  }else {
    current = listEmploye;
    while (current->data!=NULL){
      printf("id: %d | nom: %s %s | ",current->data->id,current->data->nom, current->data->prenom);
      switch (current->data->competence) {
        case 1:printf("pilot\n");
        case 2:printf("chef d'hotesse\n");
        case 3:printf("hotesse\n");
      }
      current = current->next;
    }
    return 0;
  }
}

int showAvion(ListAvion * listAvion){
  ListAvion * current = NULL;

  if(listAvion->data == NULL){
    printf("liste des Avion vide !!\n");
    return -1;
  }else {
    current = listAvion;
    while (current->data!=NULL){
      printf("id: %d |modele: %s |N°chaisse: %d \n", current->data->id, current->data->modele, current->data->nombreChaises);
      current = current->next;
    }
    printf("-----------\n");
    return 0;
  }
}

Avion * newAvion(int xid, char xmodele[], int xnomChaisse, int xdateMisCirculation){
  Avion * newNode = malloc(sizeof(Avion));
  if(!newNode){
    return NULL;
  }
  newNode->id = xid;
  strcpy(newNode->modele, xmodele);
  newNode->nombreChaises = xnomChaisse;
  newNode->dateMisCirculation = xdateMisCirculation;
  return newNode;
}

Employe * newEmploye(int xid, char xnom[], char xprenom[], int xdateNaissance, int xcompetence){
  Employe * newNode = malloc(sizeof(Employe));
  if (!newNode) {
    return NULL;
  }
  newNode->id = xid;
  strcpy(newNode->nom, xnom);
  strcpy(newNode->prenom, xprenom);
  newNode->dateNaissance = xdateNaissance;
  // competences 1:pilot, 2:chefHotesse, 3:hotesse.
  newNode->competence = xcompetence;
  return newNode;
}

Passage * newPassage(int xid, char xnom[], char xprenom[], int xchaisse){
  Passage * newNode = malloc(sizeof(Passage));
  if (!newNode) {
    return NULL;
  }
  newNode->id = xid;
  strcpy(newNode->nom, xnom);
  strcpy(newNode->prenom, xprenom);
  newNode->chaisse = xchaisse;
  return newNode;
}

Equipage * newEquipage(int xid, Employe * xpilot, Employe * xcopilot, Employe * xchefHotesse){
  Equipage * newNode = malloc(sizeof(Equipage));
  if (!newNode) {
    return NULL;
  }
  newNode->id = xid;
  newNode->pilot = xpilot;
  newNode->copilot = xcopilot;
  newNode->chefHotesse = xchefHotesse;
  newNode->listHotesse = newlistHotesse();
  return newNode;
}

Vol * newVol(int xid, int xheureDep, int xheureDes, char xaeroDep[], char xaeroDes[], Avion * xavion, Equipage * xequipage){
  Vol * newNode = malloc(sizeof(Vol));
  if (!newNode) {
    return NULL;
  }
  newNode->id = xid;
  newNode->heureDepart = xheureDep;
  newNode->heureDarrivage = xheureDes;
  strcpy(newNode->aeroportDepart, xaeroDep);
  strcpy(newNode->aeroportDestination, xaeroDes);
  newNode->avion = xavion;
  newNode->equipage = xequipage;
  newNode->listPassages = newlistPassages();
  return newNode;
}

ListAvion * newlistAvion(){
  ListAvion * list = malloc(sizeof(ListAvion));
  if (!list) {
    return NULL;
  }
  list->data = NULL;
  list->next = NULL;
  return list;
}

ListEmploye * newlistEmploye(){
  ListEmploye * list = malloc(sizeof(ListEmploye));
  if (!list) {
    return NULL;
  }
  list->data = NULL;
  list->next = NULL;
  return list;
}

ListVol * newlistVol(){
  ListVol * list = malloc(sizeof(ListVol));
  if (!list) {
    return NULL;
  }
  list->data = NULL;
  list->next = NULL;
  return list;
}

ListHotesse * newlistHotesse(){
  ListHotesse * list = malloc(sizeof(ListHotesse));
  if (!list) {
    return NULL;
  }
  list->data = NULL;
  list->next = NULL;
  return list;
}

ListPassage * newlistPassages(){
  ListPassage * list = malloc(sizeof(ListPassage));
  if (!list) {
    return NULL;
  }
  list->data = NULL;
  list->next = NULL;
  return list;
}

ListEquipage * newlistEquipage(){
  ListEquipage * list = malloc(sizeof(ListEquipage));
  if (!list) {
    return NULL;
  }
  list->data = NULL;
  list->next = NULL;
  return list;
}

void addHotesse(Equipage * equipage, Employe * hotesse){
  if(hotesse->competence == 3){
    ListHotesse * current = NULL;

    if(equipage->listHotesse->data == NULL){
      equipage->listHotesse->data = hotesse;
      equipage->listHotesse->next = malloc(sizeof(ListHotesse));
    }else {
      current = equipage->listHotesse->next;
      while (current->data!=NULL){
        current = current->next;
      }
      current->data = hotesse;
      current->next = malloc(sizeof(ListHotesse));
    }
  }else{
    printf("Employe: %s n'a pas la competence hotesse\n", hotesse->nom);
  }
}

void addPassage(Vol * vol, Passage * passage){
  ListPassage * current = NULL;

  if(vol->listPassages->data == NULL){
    vol->listPassages->data = passage;
    vol->listPassages->next = malloc(sizeof(ListPassage));
  }else {
    current = vol->listPassages->next;
    while (current->data!=NULL){
      current = current->next;
    }
    current->data = passage;
    current->next = malloc(sizeof(ListPassage));
  }
}

void addEquipage(Equipage * equipage, ListEquipage * listEquipage){
  ListEquipage * current = NULL;

if(listEquipage->data == NULL){
    listEquipage->data = equipage;
    listEquipage->next = malloc(sizeof(ListEquipage));
  }else {
    current = listEquipage->next;
    while (current->data!=NULL){
      current = current->next;
    }
    current->data = equipage;
    current->next = malloc(sizeof(ListEquipage));
  }
}

void addAvion(Avion * avion, ListAvion * listAvion){
  ListAvion * current = NULL;

if(listAvion->data == NULL){
    listAvion->data = avion;
    listAvion->next = malloc(sizeof(ListAvion));
  }else {
    current = listAvion->next;
    while (current->data!=NULL){
      current = current->next;
    }
    current->data = avion;
    current->next = malloc(sizeof(ListAvion));
  }
}

void addVol(Vol * vol, ListVol * listVol){
  ListVol * current = NULL;

if(listVol->data == NULL){
    listVol->data = vol;
    listVol->next = malloc(sizeof(ListVol));
  }else {
    current = listVol->next;
    while (current->data!=NULL){
      current = current->next;
    }
    current->data = vol;
    current->next = malloc(sizeof(ListVol));
  }
}
