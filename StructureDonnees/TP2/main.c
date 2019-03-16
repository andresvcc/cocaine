#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file.h"


int main(int argc, char const *argv[]) {
  int compteur_ligne = 0;
  int compteur_sous_categorie = 0;
  int echec = -1;
  int i;

  FILE* fichier = NULL;
  FIFO * fifo = newFIFO("cockpit",1);
  addCategorie("pilote",2, fifo);
  addTache("manette_A",fifo);
  addTache("manette_B",fifo);
  addCategorie("co-pilote",2, fifo);
  addTache("bouton_c",fifo);
  addTache("bouton_d",fifo);
  addCategorie("fuselage",1, fifo);
  addCategorie("aile_droite",2, fifo);
  addTache("reacteur_A",fifo);
  addTache("reacteur_B",fifo);
  addCategorie("aile_gauche",2, fifo);
  addTache("reacteur_C",fifo);
  addTache("reacteur_D",fifo);

  printf("\n verification de checklist\n");
  printf("\n marque 1 pour ok / 0 pour Non\n");
  verifier(fifo);
  return 0;
}
