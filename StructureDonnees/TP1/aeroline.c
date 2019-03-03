#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aeroline.h"
#include "aerolinefonction.h"

#define charSize 20



int main(void){
  ListVol * volEnRoute   = newlistVol();
  ListVol * volPlanifie  = newlistVol();
  ListVol * volEffectues = newlistVol();
  ListAvion * listAvion = newlistAvion();
  ListEmploye * listEmploye = newlistEmploye();
  ListEquipage * listEquipage = newlistEquipage();
  ListPassage * listClient = newlistPassages();

  char cmd[10];

  printf(" Sofware pour enrregistrer des vols\n");
  printf(" commande help pour voir tout la liste des commandes\n");
  while (1) {
    printf("-> ");
    scanf("%s",cmd);
    printf("---------\n");
    if (strcmp(cmd,"help") == 0) {help();}
    else if(strcmp(cmd,"new-vol") == 0){menuNewVol(volPlanifie, listAvion, listEquipage);}
    else if(strcmp(cmd,"new-avion") == 0){menuNewAvion(listAvion);}
    else if(strcmp(cmd,"new-avion") == 0){menuNewEquipage(listEquipage, listEmploye);}
    else if(strcmp(cmd,"show-all-avion") == 0){ }
    else if(strcmp(cmd,"show-all-vol") == 0){ }
    else if(strcmp(cmd,"show-active-vol") == 0){ }
    else if(strcmp(cmd,"show-scheduled-vol") == 0){ }
    else if(strcmp(cmd,"show-finished-vol") == 0){ }
    else if(strcmp(cmd,"find-vol") == 0){ }
    else if(strcmp(cmd,"find-employe") == 0){ }
    else if(strcmp(cmd,"find-client") == 0){ }
    else if(strcmp(cmd,"exit") == 0){printf("exit fin du programe\n");break;}
    else{printf("la commande n'existe pas, écrivez help pour voir la liste des commandes prises en charge\n");}
  }
  return 0;
}
