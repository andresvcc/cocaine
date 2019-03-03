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

  addEmploye(newEmploye(1,"andres","caballero",1988,1), listEmploye);
  addEmploye(newEmploye(2,"jeisy","mina",1988,1), listEmploye);
  addEmploye(newEmploye(3,"bruno","follie",1955,2), listEmploye);
  addEmploye(newEmploye(4,"riche","chocolate",1955,2), listEmploye);
  addEmploye(newEmploye(5,"haz","kepchu",1955,2), listEmploye);
  addEmploye(newEmploye(6,"luz"," britche",1966,3), listEmploye);
  addEmploye(newEmploye(7,"luz","gutier",1967,3), listEmploye);
  addEmploye(newEmploye(8,"linda","kouki",1967,3), listEmploye);
  addAvion(newAvion(1,"RZ1",18,2015),listAvion);
  addAvion(newAvion(2,"MG5",23,2010),listAvion);
  addAvion(newAvion(3,"TZu",45,2018),listAvion);

  char cmd[10];
  printf("-----------------------------------\n");
  printf(" Sofware pour enrregistrer des vols\n");
  printf("-----------------------------------\n");
  help();
  while (1) {
    printf("-> ");
    scanf("%s",cmd);
    printf("---------\n");
    if (strcmp(cmd,"help") == 0) {help();}
    else if(strcmp(cmd,"new-vol") == 0){menuNewVol(volPlanifie, listAvion, listEquipage);}
    else if(strcmp(cmd,"new-avion") == 0){menuNewAvion(listAvion);}
    else if(strcmp(cmd,"new-equipage") == 0){menuNewEquipage(listEquipage, listEmploye);}
    else if(strcmp(cmd,"new-employe") == 0){menuNewEmploye(listEmploye);}
    else if(strcmp(cmd,"show-all-avion") == 0){ showAvion(listAvion);}
    else if(strcmp(cmd,"show-vol") == 0){ showVol(volPlanifie);}
    else if(strcmp(cmd,"show-active-vol") == 0){ showVol(volEnRoute);}
    else if(strcmp(cmd,"show-finished-vol") == 0){ showVol(volEffectues); }
    else if(strcmp(cmd,"show-employe") == 0){showEmploye(listEmploye);}
    else if(strcmp(cmd,"show-avion") == 0){showAvion(listAvion);}
    else if(strcmp(cmd,"show-pilot") == 0){showEmployebyCompetence(1,listEmploye);}
    else if(strcmp(cmd,"show-chef-hotesse") == 0){showEmployebyCompetence(2,listEmploye);}
    else if(strcmp(cmd,"show-hotesses") == 0){showEmployebyCompetence(3,listEmploye);}
    else if(strcmp(cmd,"find-employe") == 0){menuFindEmploye(listEmploye);}
    else if(strcmp(cmd,"exit") == 0){printf("exit fin du programe\n");break;}
    else{printf("la commande n'existe pas, écrivez help pour voir la liste des commandes prises en charge\n");}
  }
  return 0;
}
