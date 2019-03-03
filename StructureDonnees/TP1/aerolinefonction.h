#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define charSize 20

void help(){
  printf("-------------------------------------------------------------\n");
  printf("Voici une liste de commandes de tout ce que vous pouvez faire\n");
  printf("-------------------------------------------------------------\n");
  printf("help                 voir toutes les comandes disponibles\n");
  printf("new-vol              creer un nouveau vol\n");
  printf("new-avion            enrregistrer un nouveau avion\n");
  printf("new-equipage         enrregistrer un nouveau equipage\n");
  printf("new-employe          enrregistrer un nouveau employe\n");
  printf("show-employe         montrer toutes les employes\n");
  printf("show-avion           montrer toutes les avion\n");
  printf("show-pilot           montrer toutes les pilot\n");
  printf("show-chef-hotesse    montrer toutes les chef de hotesse\n");
  printf("show-hotesse         montrer toutes les hotesse\n");
  printf("show-vol             montrer les vol qui sont planifie\n");
  printf("show-active-vol      montrer les vols en route\n");
  printf("show-finished-vol    montrer les vols qui ont ete deja efectues\n");
  printf("find-employe         chercher un employe\n");
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
    printf("\nrentrez la id de l'avion: ");
    scanf("%d",&idAvion);
    Avion * xavion = findAvion(idAvion,listAvion);
    if(xavion != NULL){
      int okEquipage = showEquipage(listEquipage);
      if(okEquipage >= 0){
        printf("\nrentrez la id de l'equipage: ");
        scanf("%d",&idEquipage);
        Equipage * xequipage = findEquipage(idEquipage, listEquipage);
        if(xequipage != NULL){
          Vol * xvol = newVol(1, xheureDep, xheureDes, xaeroDep, xaeroDes, xavion, xequipage);
          addVol(xvol,listVol);
          if(xvol == NULL){
            printf("un probleme est sourvenue le vol n'est pas enrregistre\n");
          }else{
            printf("creation du vol %d reussi, %s, %d H -> %s, %d H:\n", xvol->id, xvol->aeroportDepart,xvol->heureDepart,xvol->aeroportDestination,xvol->heureDarrivage);
          }
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

void menuNewEmploye(ListEmploye * listEmploye){
  int xid;
  char xnom[charSize];
  char xprenom[charSize];
  int xcompetence;
  int xdate;
  printf("--------------------------------------\n");
  printf("pour ajouter un nouveau Employe, entrez \n");
  printf("--------------------------------------\n");
  printf("id: ");
  scanf("%d",&xid);
  printf("nom: ");
  scanf("%s",xnom);
  printf("prenom: ");
  scanf("%s",xprenom);
  printf("anne de naissance: ");
  scanf("%d",&xdate);
  printf("pilot:1, chefHotesse:2, hotesse:3\n");
  printf("competence: ");
  scanf("%d",&xcompetence);
  Employe * nodeEmploye = newEmploye(xid,xnom,xprenom,xdate,xcompetence);
  addEmploye(nodeEmploye, listEmploye);
  printf("--------------------------------------\n");
  showEmploye(listEmploye);
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
  printf("liste des pilot\n");
  showEmployebyCompetence(1,listEmploye);
  printf("\n: choisissez un pilot dans la liste de pilot");
  printf("id: ");
  scanf("%d",&idPilot);
  printf("\n: choisissez un copilot dans la liste de pilot");
  printf("id: ");
  scanf("%d",&idCopilot);
  printf("liste des chef d'hotesse\n");
  showEmployebyCompetence(2,listEmploye);
  printf("\n choisissez un chef d'hotesse dans la liste");
  printf("id: ");
  scanf("%d",&idChef);

  printf("\nrentrez un id pour identifier cette equipage");
  printf("\nid: ");
  scanf("%d",&xid);

  Employe * xpilot = findEmploye(idPilot,listEmploye);
  Employe * xcopilot = findEmploye(idCopilot,listEmploye);
  Employe * xchefHotesse = findEmploye(idChef,listEmploye);
  Equipage * nodeEquipage = newEquipage(xid,xpilot,xcopilot,xchefHotesse);

  printf("combien d'hotesses voulez vous ajouter? :");
  scanf("%d",&sizeHotesse);
  printf("\nliste des hotesses\n");
  showEmployebyCompetence(3,listEmploye);
  printf("Choissize\n");
  int idHotesse;
  for (int i = 0; i < sizeHotesse; i++) {
    int temp = i+1;
    printf("id hotesse n° %d : ", temp );
    scanf("%d",&idHotesse);
    printf("\n");
    Employe * hotesse = findEmploye(idHotesse,listEmploye);
    addHotesse(nodeEquipage, hotesse);
  }

  addEquipage(nodeEquipage, listEquipage);
  printf("--------------------------------------\n");
}

void menuFindEmploye(ListEmploye * listEmploye){
  int id;
  printf("--------------------------------\n");
  printf("recherche d'employe par id\n");
  printf("--------------------------------\n");
  printf("rentrez le id\n");
  scanf("%d\n",&id);
  Employe * employe = findEmploye(id,listEmploye);
  printf("nom: %s\n",employe->nom);
  printf("prenom: %s\n",employe->prenom);
  printf("anne de naissance: %d\n",employe->dateNaissance);
  printf("competence: ");
  switch (employe->competence) {
    case 1:printf("pilot\n");break;
    case 2:printf("chef d'hotesse\n");break;
    case 3:printf("hotesse\n");break;
  }
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
    printf("liste des equipage vide !!\n");
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
  printf("---------------------------------\n");
  printf("liste des equipages\n");
  printf("---------------------------------\n");
  if(listEquipage->data == NULL){
    printf("liste des Equipage vide !!\n");
    return -1;
  }else {
    current = listEquipage;
    while (current->data!=NULL){
      printf("id: %d | pilot: %s | copilot: %s | chef d'hotesse: %s \n", current->data->id, current->data->pilot->prenom, current->data->copilot->prenom, current->data->chefHotesse->prenom);
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
      printf("id: %d | %s %s \n",current->data->id,current->data->nom, current->data->prenom);
    }
    current = current->next;
  }
  printf("---------------------------------\n");
}

int showEmploye(ListEmploye * listEmploye){
  ListEmploye * current = NULL;
  printf("---------------------------------\n");
  printf("liste des employes\n");
  printf("---------------------------------\n");
  if(listEmploye->data == NULL){
    printf("liste des Equipage vide !!\n");
    return -1;
  }else {
    current = listEmploye;
    while (current->data!=NULL){
      printf("id: %d | %s %s ->",current->data->id,current->data->nom, current->data->prenom);
      switch (current->data->competence) {
        case 1:printf("pilot/copilot\n");break;
        case 2:printf("chef d'hotesse\n");break;
        case 3:printf("hotesse\n");break;
      }
      current = current->next;
    }
    printf("---------------------------------\n");
    return 0;
  }
}

int showAvion(ListAvion * listAvion){
  ListAvion * current = NULL;
  printf("---------------------------------\n");
  printf("liste des Avion\n");
  printf("---------------------------------\n");
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

int showVol(ListVol * listVol){
  ListVol * current = NULL;
  printf("---------------------------------\n");
  printf("liste des vols\n");
  printf("---------------------------------\n");
  if(listVol->data == NULL){
    printf("liste des Vol vide !!\n");
    return -1;
  }else {
    current = listVol;
    while (current->data!=NULL){
      printf("----------------------------------------------\n");
      printf("id%d  | Heure depart: %d | Heure arrivage: %d \n",current->data->id,current->data->heureDepart,current->data->heureDarrivage );
      printf("      | depart de: %s    | arrivage a : %s \n", current->data->aeroportDepart, current->data->aeroportDestination);
      printf("      | avion id: %d  modele %s\n", current->data->avion->id,current->data->avion->modele);
      printf("      | equipage id: %d pilot: %s %s copilot: %s %s chef d'hotesse: %s %s\n",current->data->equipage->id,current->data->equipage->pilot->nom,current->data->equipage->pilot->prenom,current->data->equipage->copilot->nom,current->data->equipage->copilot->prenom,current->data->equipage->chefHotesse->nom,current->data->equipage->chefHotesse->prenom);
      printf("----------------------------------------------\n");
      current = current->next;
    }
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

void addEmploye(Employe * employe, ListEmploye * listEmploye){
  ListEmploye * current = NULL;

if(listEmploye->data == NULL){
    listEmploye->data = employe;
    listEmploye->next = malloc(sizeof(ListEmploye));
  }else {
    current = listEmploye->next;
    while (current->data!=NULL){
      current = current->next;
    }
    current->data = employe;
    current->next = malloc(sizeof(ListEmploye));
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
    current = listVol;
    while (current->data!=NULL){
      current = current->next;
    }
    current->data = vol;
    current->next = malloc(sizeof(ListVol));
  }
}
